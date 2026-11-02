//! Espresso heuristic minimization loop: EXPAND / IRREDUNDANT / REDUCE
//! (plus MAKE_SPARSE for multi-output PLAs).
//!
//! Supports both single-output ([`Cover`]) and multi-output ([`MvCover`])
//! functions with an optional don't-care set. Termination is guaranteed because
//! a new iteration is accepted only if the cost strictly decreases
//! lexicographically.

use crate::cover::{Cover, MvCover};
use crate::cube::{
    cube_contains, cube_distance, cube_intersect, mv_cube_contains, mv_cube_distance, Cube,
    MvCube, ParseError, Part,
};

/// EXPAND: make every cube prime by raising literals while the cube stays
/// disjoint from the OFF-set; cubes swallowed by an expanded cube are dropped.
pub fn expand(f: &Cover, off: &Cover) -> Cover {
    let n = f.len();
    let nv = f.nvars();
    let fc = f.cubes();

    // Weight = how many cubes of F "agree" with each part of the cube.
    // Light (unusual) cubes are expanded first, as in Espresso.
    let weights: Vec<usize> = fc
        .iter()
        .map(|c| {
            (0..nv)
                .map(|v| {
                    let p = c.get(v) as u8;
                    fc.iter().filter(|o| (o.get(v) as u8) & p == p).count()
                })
                .sum()
        })
        .collect();
    let mut order: Vec<usize> = (0..n).collect();
    order.sort_by_key(|&i| weights[i]);

    let feasible = |cand: &Cube| off.iter().all(|o| cube_distance(cand, o) > 0);

    let mut covered = vec![false; n];
    let mut out = Cover::new(nv);
    for &i in &order {
        if covered[i] {
            continue;
        }
        let mut c = fc[i].clone();
        // A raise rejected once stays infeasible: the cube only grows.
        let mut rejected = vec![false; nv];
        loop {
            let mut best: Option<(usize, Cube)> = None;
            for v in 0..nv {
                if rejected[v] || c.get(v) == Part::DontCare {
                    continue;
                }
                let mut cand = c.clone();
                cand.set(v, Part::DontCare);
                if !feasible(&cand) {
                    rejected[v] = true;
                    continue;
                }
                // Prefer the raise that swallows the most uncovered cubes.
                let score = (0..n)
                    .filter(|&j| j != i && !covered[j] && cube_contains(&cand, &fc[j]))
                    .count();
                if best.as_ref().map_or(true, |(s, _)| score > *s) {
                    best = Some((score, cand));
                }
            }
            match best {
                Some((_, cand)) => c = cand,
                None => break,
            }
        }
        for j in 0..n {
            if cube_contains(&c, &fc[j]) {
                covered[j] = true;
            }
        }
        covered[i] = true;
        out.add(c);
    }
    out.single_cube_containment();
    out
}

/// REDUCE: shrink each cube (largest first) to the smallest cube that still
/// covers everything only it covers; fully redundant cubes are removed.
pub fn reduce(f: &Cover, d: &Cover) -> Cover {
    let nv = f.nvars();
    let mut cubes: Vec<Cube> = f.cubes().to_vec();
    let mut alive = vec![true; cubes.len()];
    let mut order: Vec<usize> = (0..cubes.len()).collect();
    order.sort_by_key(|&i| cubes[i].literals());

    for &i in &order {
        let c = cubes[i].clone();
        let mut rest = Cover::new(nv);
        for (j, o) in cubes.iter().enumerate() {
            if j != i && alive[j] {
                rest.add(o.clone());
            }
        }
        rest.extend(d);
        // Parts of c not covered by the others = complement of cofactor, within c.
        let uncovered = rest.cofactor(&c).complement();
        match uncovered.supercube() {
            None => alive[i] = false,
            Some(sc) => cubes[i] = cube_intersect(&c, &sc),
        }
    }
    let kept = cubes
        .into_iter()
        .zip(alive)
        .filter_map(|(c, a)| a.then_some(c))
        .collect();
    Cover::from_cubes(nv, kept)
}

/// Branch-and-bound state for the minimum covering step of IRREDUNDANT.
struct MinCov<'a> {
    nv: usize,
    base: &'a [Cube],
    partial: &'a [Cube],
    chosen: Vec<bool>,
    kept: usize,
    best: Vec<bool>,
    best_count: usize,
    budget: usize,
}

impl MinCov<'_> {
    /// Does `base ∪ chosen` still cover every partially redundant cube?
    fn valid(&self) -> bool {
        let mut cv = Cover::new(self.nv);
        for b in self.base {
            cv.add(b.clone());
        }
        for (i, p) in self.partial.iter().enumerate() {
            if self.chosen[i] {
                cv.add(p.clone());
            }
        }
        self.partial
            .iter()
            .enumerate()
            .all(|(i, p)| self.chosen[i] || cv.covers_cube(p))
    }

    fn dfs(&mut self, idx: usize) {
        if self.budget == 0 || self.kept >= self.best_count {
            return;
        }
        self.budget -= 1;
        if idx == self.partial.len() {
            self.best = self.chosen.clone();
            self.best_count = self.kept;
            return;
        }
        // Branch 1: drop cube idx.
        self.chosen[idx] = false;
        if self.valid() {
            self.dfs(idx + 1);
        }
        self.chosen[idx] = true;
        // Branch 2: keep it.
        self.kept += 1;
        self.dfs(idx + 1);
        self.kept -= 1;
    }
}

/// IRREDUNDANT: remove redundant cubes. Relatively essential cubes are always
/// kept; totally redundant ones dropped; among the partially redundant ones a
/// minimum subset is searched (greedy start + bounded branch and bound).
pub fn irredundant(f: &Cover, d: &Cover) -> Cover {
    let nv = f.nvars();
    let fc = f.cubes();

    // Classify: essential if not covered by the other cubes plus DC.
    let mut essential: Vec<Cube> = Vec::new();
    let mut redundant: Vec<Cube> = Vec::new();
    for i in 0..fc.len() {
        let mut others = Cover::new(nv);
        for (j, o) in fc.iter().enumerate() {
            if j != i {
                others.add(o.clone());
            }
        }
        others.extend(d);
        if others.covers_cube(&fc[i]) {
            redundant.push(fc[i].clone());
        } else {
            essential.push(fc[i].clone());
        }
    }

    // Base = essential ∪ DC. Redundant cubes covered by it are totally redundant.
    let mut base = essential.clone();
    base.extend(d.iter().cloned());
    let base_cover = Cover::from_cubes(nv, base.clone());
    let mut partial: Vec<Cube> =
        redundant.into_iter().filter(|c| !base_cover.covers_cube(c)).collect();
    // Smallest cubes first: they are the best candidates to drop.
    partial.sort_by_key(|c| std::cmp::Reverse(c.literals()));

    let mut mc = MinCov {
        nv,
        base: &base,
        partial: &partial,
        chosen: vec![true; partial.len()],
        kept: 0,
        best: Vec::new(),
        best_count: 0,
        budget: 2000,
    };
    // Greedy initial solution.
    for i in 0..partial.len() {
        mc.chosen[i] = false;
        if !mc.valid() {
            mc.chosen[i] = true;
        }
    }
    mc.best = mc.chosen.clone();
    mc.best_count = mc.best.iter().filter(|&&b| b).count();
    mc.chosen = vec![true; partial.len()];
    mc.dfs(0);

    let mut out = essential;
    for (i, p) in partial.iter().enumerate() {
        if mc.best[i] {
            out.push(p.clone());
        }
    }
    Cover::from_cubes(nv, out)
}

/// Minimize the ON-set `on` given the don't-care set `dc`.
///
/// The result covers `on`, is contained in `on ∪ dc`, and is prime and
/// irredundant.
pub fn minimize(on: &Cover, dc: &Cover) -> Cover {
    let nv = on.nvars();
    let mut f = on.clone();
    f.remove_empty();
    f.single_cube_containment();
    if f.is_empty() {
        return f;
    }
    let mut d = dc.clone();
    d.remove_empty();

    // OFF-set = complement of (ON ∪ DC).
    let mut fd = f.clone();
    fd.extend(&d);
    let off = fd.complement();
    debug_assert_eq!(off.nvars(), nv);

    let mut best = irredundant(&expand(&f, &off), &d);
    // Strictly decreasing cost => guaranteed termination.
    loop {
        let t = irredundant(&expand(&reduce(&best, &d), &off), &d);
        if t.cost() < best.cost() {
            best = t;
        } else {
            break;
        }
    }
    best
}

/// Minimize from text cubes (`'0'`, `'1'`, `'-'`); returns minimized rows.
pub fn minimize_strings<S: AsRef<str>>(
    nvars: usize,
    on: &[S],
    dc: &[S],
) -> Result<Vec<String>, ParseError> {
    let on = Cover::parse(nvars, on)?;
    let dc = Cover::parse(nvars, dc)?;
    Ok(minimize(&on, &dc).to_strings())
}

/// Minimize from minterm indices (variable 0 = MSB); returns minimized rows.
pub fn minimize_minterms(nvars: usize, on: &[u64], dc: &[u64]) -> Vec<String> {
    minimize(&Cover::from_minterms(nvars, on), &Cover::from_minterms(nvars, dc)).to_strings()
}

// ---------------------------------------------------------------------------
// Multi-output (MV) Espresso: EXPAND / REDUCE / IRREDUNDANT / MAKE_SPARSE
// ---------------------------------------------------------------------------

fn mv_cube_weights(fc: &[MvCube], nin: usize, nout: usize) -> Vec<usize> {
    fc.iter()
        .map(|c| {
            let in_w: usize = (0..nin)
                .map(|v| {
                    let p = c.input().get(v) as u8;
                    fc.iter().filter(|o| (o.input().get(v) as u8) & p == p).count()
                })
                .sum();
            let out_w: usize = (0..nout)
                .filter(|&k| c.out_get(k))
                .map(|k| fc.iter().filter(|o| o.out_get(k)).count())
                .sum();
            in_w + out_w
        })
        .collect()
}

/// Multi-output EXPAND: raise binary input literals (`0`/`1` -> `-`) and output
/// bits (`0` -> `1`) while staying disjoint from `off`, enabling product-term
/// sharing across outputs.
pub fn expand_mv(f: &MvCover, off: &MvCover) -> MvCover {
    let n = f.len();
    let nin = f.nin();
    let nout = f.nout();
    let fc = f.cubes();

    let weights = mv_cube_weights(fc, nin, nout);
    let mut order: Vec<usize> = (0..n).collect();
    order.sort_by_key(|&i| weights[i]);

    let feasible = |cand: &MvCube| off.iter().all(|o| mv_cube_distance(cand, o) > 0);

    let mut covered = vec![false; n];
    let mut out = MvCover::new(nin, nout);
    for &i in &order {
        if covered[i] {
            continue;
        }
        let mut c = fc[i].clone();
        let mut rejected_in = vec![false; nin];
        let mut rejected_out = vec![false; nout];

        loop {
            let mut best: Option<((usize, bool, usize), MvCube)> = None;

            for v in 0..nin {
                if rejected_in[v] || c.input().get(v) == Part::DontCare {
                    continue;
                }
                let mut cand = c.clone();
                cand.input_mut().set(v, Part::DontCare);
                if !feasible(&cand) {
                    rejected_in[v] = true;
                    continue;
                }
                let swallowed = (0..n)
                    .filter(|&j| j != i && !covered[j] && mv_cube_contains(&cand, &fc[j]))
                    .count();
                let overlap = (0..n)
                    .filter(|&j| j != i && !covered[j] && cube_contains(cand.input(), fc[j].input()))
                    .count();
                let score = (swallowed, true, overlap);
                if best.as_ref().map_or(true, |(s, _)| score > *s) {
                    best = Some((score, cand));
                }
            }

            for k in 0..nout {
                if rejected_out[k] || c.out_get(k) {
                    continue;
                }
                let mut cand = c.clone();
                cand.out_set(k, true);
                if !feasible(&cand) {
                    rejected_out[k] = true;
                    continue;
                }
                let swallowed = (0..n)
                    .filter(|&j| j != i && !covered[j] && mv_cube_contains(&cand, &fc[j]))
                    .count();
                let overlap = (0..n)
                    .filter(|&j| {
                        j != i
                            && !covered[j]
                            && fc[j].out_get(k)
                            && cube_distance(cand.input(), fc[j].input()) == 0
                    })
                    .count();
                let score = (swallowed, false, overlap);
                if best.as_ref().map_or(true, |(s, _)| score > *s) {
                    best = Some((score, cand));
                }
            }

            match best {
                Some((_, cand)) => c = cand,
                None => break,
            }
        }

        for j in 0..n {
            if mv_cube_contains(&c, &fc[j]) {
                covered[j] = true;
            }
        }
        covered[i] = true;
        out.add(c);
    }
    out.single_cube_containment();
    out
}

/// Multi-output REDUCE: shrink both the input cube and the active output mask
/// of each cube (largest first) to the smallest MV cube covering what only it
/// covers; completely redundant cubes are removed.
pub fn reduce_mv(f: &MvCover, d: &MvCover) -> MvCover {
    let nin = f.nin();
    let nout = f.nout();
    let mut cubes: Vec<MvCube> = f.cubes().to_vec();
    let mut alive = vec![true; cubes.len()];
    let mut order: Vec<usize> = (0..cubes.len()).collect();
    order.sort_by_key(|&i| (cubes[i].input_literals(), std::cmp::Reverse(cubes[i].output_ones())));

    for &i in &order {
        let c = cubes[i].clone();
        let mut reduced_in: Option<Cube> = None;
        let mut active_outs: Vec<usize> = Vec::new();

        for k in 0..nout {
            if !c.out_get(k) {
                continue;
            }
            let mut rest_k = Cover::new(nin);
            for (j, o) in cubes.iter().enumerate() {
                if j != i && alive[j] && o.out_get(k) {
                    rest_k.add(o.input().clone());
                }
            }
            for dc in d.iter() {
                if !dc.is_empty() && dc.out_get(k) {
                    rest_k.add(dc.input().clone());
                }
            }
            let uncovered_k = rest_k.cofactor(c.input()).complement();
            if let Some(sc_k) = uncovered_k.supercube() {
                let bound_k = cube_intersect(c.input(), &sc_k);
                reduced_in = Some(match reduced_in {
                    None => bound_k,
                    Some(acc) => acc.supercube(&bound_k),
                });
                active_outs.push(k);
            }
        }

        match reduced_in {
            None => alive[i] = false,
            Some(inp) => cubes[i] = MvCube::from_parts(inp, nout, &active_outs),
        }
    }

    let kept = cubes
        .into_iter()
        .zip(alive)
        .filter_map(|(c, a)| a.then_some(c))
        .collect();
    MvCover::from_cubes(nin, nout, kept)
}

struct MvMinCov<'a> {
    nin: usize,
    nout: usize,
    base: &'a [MvCube],
    partial: &'a [MvCube],
    chosen: Vec<bool>,
    kept: usize,
    best: Vec<bool>,
    best_count: usize,
    budget: usize,
}

impl MvMinCov<'_> {
    fn valid(&self) -> bool {
        let mut cv = MvCover::new(self.nin, self.nout);
        for b in self.base {
            cv.add(b.clone());
        }
        for (i, p) in self.partial.iter().enumerate() {
            if self.chosen[i] {
                cv.add(p.clone());
            }
        }
        self.partial
            .iter()
            .enumerate()
            .all(|(i, p)| self.chosen[i] || cv.covers_cube(p))
    }

    fn dfs(&mut self, idx: usize) {
        if self.budget == 0 || self.kept >= self.best_count {
            return;
        }
        self.budget -= 1;
        if idx == self.partial.len() {
            self.best = self.chosen.clone();
            self.best_count = self.kept;
            return;
        }
        self.chosen[idx] = false;
        if self.valid() {
            self.dfs(idx + 1);
        }
        self.chosen[idx] = true;
        self.kept += 1;
        self.dfs(idx + 1);
        self.kept -= 1;
    }
}

/// Multi-output IRREDUNDANT: remove redundant MV cubes using essential/partial
/// classification and bounded branch-and-bound minimum covering.
pub fn irredundant_mv(f: &MvCover, d: &MvCover) -> MvCover {
    let nin = f.nin();
    let nout = f.nout();
    let fc = f.cubes();

    let mut essential: Vec<MvCube> = Vec::new();
    let mut redundant: Vec<MvCube> = Vec::new();
    for i in 0..fc.len() {
        let mut others = MvCover::new(nin, nout);
        for (j, o) in fc.iter().enumerate() {
            if j != i {
                others.add(o.clone());
            }
        }
        others.extend(d);
        if others.covers_cube(&fc[i]) {
            redundant.push(fc[i].clone());
        } else {
            essential.push(fc[i].clone());
        }
    }

    let mut base = essential.clone();
    base.extend(d.iter().cloned());
    let base_cover = MvCover::from_cubes(nin, nout, base.clone());
    let mut partial: Vec<MvCube> = redundant
        .into_iter()
        .filter(|c| !base_cover.covers_cube(c))
        .collect();
    partial.sort_by_key(|c| (std::cmp::Reverse(c.input_literals()), c.output_ones()));

    let mut mc = MvMinCov {
        nin,
        nout,
        base: &base,
        partial: &partial,
        chosen: vec![true; partial.len()],
        kept: 0,
        best: Vec::new(),
        best_count: 0,
        budget: 2000,
    };
    for i in 0..partial.len() {
        mc.chosen[i] = false;
        if !mc.valid() {
            mc.chosen[i] = true;
        }
    }
    mc.best = mc.chosen.clone();
    mc.best_count = mc.best.iter().filter(|&&b| b).count();
    mc.chosen = vec![true; partial.len()];
    mc.dfs(0);

    let mut out = essential;
    for (i, p) in partial.iter().enumerate() {
        if mc.best[i] {
            out.push(p.clone());
        }
    }
    MvCover::from_cubes(nin, nout, out)
}

/// MAKE_SPARSE: lower redundant output `1`s (OR-plane connections) and then
/// raise any newly unlocked binary input literals (AND-plane literals).
pub fn make_sparse_mv(f: &MvCover, d: &MvCover, off: &MvCover) -> MvCover {
    let nin = f.nin();
    let nout = f.nout();
    let mut cubes: Vec<MvCube> = f.cubes().to_vec();
    let mut alive = vec![true; cubes.len()];

    // Visit smallest input cubes (most literals) first so redundant output
    // connections are dropped from specific cubes in favor of broader ones.
    let mut order: Vec<usize> = (0..cubes.len()).collect();
    order.sort_by_key(|&i| (std::cmp::Reverse(cubes[i].input_literals()), cubes[i].output_ones()));

    for &i in &order {
        for k in 0..nout {
            if !cubes[i].out_get(k) {
                continue;
            }
            let mut others_k = Cover::new(nin);
            for (j, o) in cubes.iter().enumerate() {
                if j != i && alive[j] && o.out_get(k) {
                    others_k.add(o.input().clone());
                }
            }
            for dc in d.iter() {
                if !dc.is_empty() && dc.out_get(k) {
                    others_k.add(dc.input().clone());
                }
            }
            if others_k.covers_cube(cubes[i].input()) {
                cubes[i].out_set(k, false);
            }
        }
        if !cubes[i].has_any_output() {
            alive[i] = false;
        }
    }

    let kept: Vec<MvCube> = cubes
        .into_iter()
        .zip(alive)
        .filter_map(|(c, a)| a.then_some(c))
        .collect();

    // Expand binary input literals only (keeping output masks fixed).
    let n = kept.len();
    let weights = mv_cube_weights(&kept, nin, nout);
    let mut exp_order: Vec<usize> = (0..n).collect();
    exp_order.sort_by_key(|&i| weights[i]);

    let feasible = |cand: &MvCube| off.iter().all(|o| mv_cube_distance(cand, o) > 0);
    let mut covered = vec![false; n];
    let mut expanded = MvCover::new(nin, nout);

    for &i in &exp_order {
        if covered[i] {
            continue;
        }
        let mut c = kept[i].clone();
        let mut rejected = vec![false; nin];
        loop {
            let mut best: Option<(usize, MvCube)> = None;
            for v in 0..nin {
                if rejected[v] || c.input().get(v) == Part::DontCare {
                    continue;
                }
                let mut cand = c.clone();
                cand.input_mut().set(v, Part::DontCare);
                if !feasible(&cand) {
                    rejected[v] = true;
                    continue;
                }
                let score = (0..n)
                    .filter(|&j| j != i && !covered[j] && mv_cube_contains(&cand, &kept[j]))
                    .count();
                if best.as_ref().map_or(true, |(s, _)| score > *s) {
                    best = Some((score, cand));
                }
            }
            match best {
                Some((_, cand)) => c = cand,
                None => break,
            }
        }
        for j in 0..n {
            if mv_cube_contains(&c, &kept[j]) {
                covered[j] = true;
            }
        }
        covered[i] = true;
        expanded.add(c);
    }
    expanded.single_cube_containment();
    irredundant_mv(&expanded, d)
}

/// Minimize a multi-output ON-set `on` given the multi-output don't-care set `dc`.
///
/// Jointly optimizes all outputs with product-term sharing, returning a sparse,
/// irredundant [`MvCover`].
pub fn minimize_mv(on: &MvCover, dc: &MvCover) -> MvCover {
    debug_assert_eq!(on.nin(), dc.nin());
    debug_assert_eq!(on.nout(), dc.nout());
    let nin = on.nin();
    let nout = on.nout();

    let mut f = on.clone();
    f.remove_empty();
    f.single_cube_containment();
    if f.is_empty() || nout == 0 {
        return MvCover::new(nin, nout);
    }

    let mut d = dc.clone();
    d.remove_empty();
    d = d.subtract(&f);

    let mut fd = f.clone();
    fd.extend(&d);
    let off = fd.complement();

    let mut curr = irredundant_mv(&expand_mv(&f, &off), &d);
    loop {
        let next = irredundant_mv(&expand_mv(&reduce_mv(&curr, &d), &off), &d);
        if (next.len(), next.input_literals()) < (curr.len(), curr.input_literals()) {
            curr = next;
        } else {
            break;
        }
    }

    let mut best = make_sparse_mv(&curr, &d, &off);
    loop {
        let next = make_sparse_mv(
            &irredundant_mv(&expand_mv(&reduce_mv(&best, &d), &off), &d),
            &d,
            &off,
        );
        if next.cost() < best.cost() {
            best = next;
        } else {
            break;
        }
    }
    best
}

/// Minimize multiple outputs specified as `(on_minterms, dc_minterms)` slices.
pub fn minimize_multi_minterms(nin: usize, outputs: &[(&[u64], &[u64])]) -> MvCover {
    let nout = outputs.len();
    let mut on = MvCover::new(nin, nout);
    let mut dc = MvCover::new(nin, nout);
    for (k, &(on_m, dc_m)) in outputs.iter().enumerate() {
        for &m in on_m {
            on.add(MvCube::single_output(Cube::from_minterm(nin, m), nout, k));
        }
        for &m in dc_m {
            dc.add(MvCube::single_output(Cube::from_minterm(nin, m), nout, k));
        }
    }
    minimize_mv(&on, &dc)
}

#[cfg(test)]
mod tests {
    use super::*;

    /// Check: covers ON, never touches OFF (= outside ON ∪ DC).
    fn check(nvars: usize, on: &[u64], dc: &[u64], rows: &[String]) {
        let r = Cover::parse(nvars, rows).unwrap();
        for m in 0..(1u64 << nvars) {
            let inside = r.contains_minterm(m);
            if on.contains(&m) {
                assert!(inside, "minterm {m} lost");
            } else if !dc.contains(&m) {
                assert!(!inside, "minterm {m} wrongly covered");
            }
        }
    }

    fn run(nvars: usize, on: &[u64], dc: &[u64]) -> Vec<String> {
        let rows = minimize_minterms(nvars, on, dc);
        check(nvars, on, dc, &rows);
        rows
    }

    #[test]
    fn xor2_needs_two_terms() {
        assert_eq!(run(2, &[1, 2], &[]).len(), 2);
    }

    #[test]
    fn xor3_needs_four_terms() {
        assert_eq!(run(3, &[1, 2, 4, 7], &[]).len(), 4);
    }

    #[test]
    fn full_adder() {
        // Inputs a, b, cin (a = MSB).
        let sum = run(3, &[1, 2, 4, 7], &[]);
        let cout = run(3, &[3, 5, 6, 7], &[]);
        assert_eq!(sum.len(), 4);
        assert_eq!(cout.len(), 3); // ab + a·cin + b·cin
        let mut c = cout.clone();
        c.sort();
        assert_eq!(c, vec!["-11", "1-1", "11-"]);
    }

    #[test]
    fn expanded_minterms_collapse() {
        // a  = all 8 minterms with MSB = 1 (4 vars).
        let on: Vec<u64> = (8..16).collect();
        assert_eq!(run(4, &on, &[]), vec!["1---"]);
        // Tautology.
        let all: Vec<u64> = (0..16).collect();
        assert_eq!(run(4, &all, &[]), vec!["----"]);
    }

    #[test]
    fn classic_four_var_with_dont_cares() {
        let on = [4, 8, 10, 11, 12, 15];
        let dc = [9, 14];
        let rows = run(4, &on, &dc);
        assert!(rows.len() <= 3, "got {rows:?}"); // known minimum is 3 terms
    }

    #[test]
    fn strings_api_and_errors() {
        let empty: [&str; 0] = [];
        let r = minimize_strings(2, &["00", "01", "10", "11"], &empty).unwrap();
        assert_eq!(r, vec!["--"]);
        assert!(minimize_strings(2, &["0"], &empty).is_err());
    }

    #[test]
    fn empty_on_set() {
        assert!(run(3, &[], &[]).is_empty());
    }

    #[test]
    fn pseudo_random_functions_stay_equivalent() {
        let nvars = 5;
        let mut seed: u64 = 0x1234_5678;
        for _ in 0..25 {
            let (mut on, mut dc) = (Vec::new(), Vec::new());
            for m in 0..(1u64 << nvars) {
                seed = seed.wrapping_mul(6364136223846793005).wrapping_add(1442695040888963407);
                match (seed >> 33) % 4 {
                    0 | 1 => on.push(m),
                    2 => dc.push(m),
                    _ => {}
                }
            }
            let rows = run(nvars, &on, &dc);
            assert!(rows.len() <= on.len());
        }
    }

    fn check_mv(nin: usize, outputs: &[(&[u64], &[u64])], res: &MvCover) {
        for (k, &(on, dc)) in outputs.iter().enumerate() {
            for m in 0..(1u64 << nin) {
                let inside = res.contains_minterm(k, m);
                if on.contains(&m) {
                    assert!(inside, "output {k} lost minterm {m}");
                } else if !dc.contains(&m) {
                    assert!(!inside, "output {k} wrongly covered minterm {m}");
                }
            }
        }
    }

    #[test]
    fn multi_output_shares_product_terms() {
        // f0 = 001 + 11- ({1, 6, 7}), f1 = 0-1 + 01- ({1, 2, 3}).
        // Separate minimization uses 4 distinct cubes; joint MV uses 3 cubes
        // by sharing 001 across both outputs.
        let f0_on = [1u64, 6, 7];
        let f1_on = [1u64, 2, 3];
        let specs: [(&[u64], &[u64]); 2] = [(&f0_on, &[]), (&f1_on, &[])];
        let res = minimize_multi_minterms(3, &specs);
        check_mv(3, &specs, &res);
        assert_eq!(res.len(), 3, "expected 3 shared cubes, got {res:?}");
    }

    #[test]
    fn multi_output_bcd_seven_segment() {
        // 4-bit BCD (0..=9) to 7-segment display (a..g), with 10..=15 as DC.
        let dc: Vec<u64> = (10..16).collect();
        let a = [0u64, 2, 3, 5, 6, 7, 8, 9];
        let b = [0u64, 1, 2, 3, 4, 7, 8, 9];
        let c = [0u64, 1, 3, 4, 5, 6, 7, 8, 9];
        let d = [0u64, 2, 3, 5, 6, 8, 9];
        let e = [0u64, 2, 6, 8];
        let f = [0u64, 4, 5, 6, 8, 9];
        let g = [2u64, 3, 4, 5, 6, 8, 9];
        let specs: [(&[u64], &[u64]); 7] = [
            (&a, &dc),
            (&b, &dc),
            (&c, &dc),
            (&d, &dc),
            (&e, &dc),
            (&f, &dc),
            (&g, &dc),
        ];
        let res = minimize_multi_minterms(4, &specs);
        check_mv(4, &specs, &res);
        // Independently minimizing 7 segments takes ~19-20 terms; shared PLA takes <= 15.
        assert!(res.len() <= 15, "expected shared PLA <= 15 cubes, got {}", res.len());
    }

    #[test]
    fn multi_output_all_dc_and_constant_outputs() {
        // out 0: constant 0; out 1: all DC; out 2: constant 1.
        let all: Vec<u64> = (0..4).collect();
        let specs: [(&[u64], &[u64]); 3] = [(&[], &[]), (&[], &all), (&all, &[])];
        let res = minimize_multi_minterms(2, &specs);
        check_mv(2, &specs, &res);
        assert_eq!(res.len(), 1);
        assert_eq!(res.cubes()[0].to_string(), "-- 001");
    }

    #[test]
    fn pseudo_random_multi_output_stays_equivalent() {
        let nin = 4;
        let nout = 4;
        let mut seed: u64 = 0xCAFE_BABE;
        for _ in 0..15 {
            let mut ons = vec![Vec::new(); nout];
            let mut dcs = vec![Vec::new(); nout];
            for k in 0..nout {
                for m in 0..(1u64 << nin) {
                    seed = seed.wrapping_mul(6364136223846793005).wrapping_add(1);
                    match (seed >> 33) % 4 {
                        0 => ons[k].push(m),
                        1 => dcs[k].push(m),
                        _ => {}
                    }
                }
            }
            let specs: Vec<(&[u64], &[u64])> =
                (0..nout).map(|k| (ons[k].as_slice(), dcs[k].as_slice())).collect();
            let res = minimize_multi_minterms(nin, &specs);
            check_mv(nin, &specs, &res);
        }
    }
}
