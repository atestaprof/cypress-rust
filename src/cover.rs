//! Covers: sets of cubes representing a sum of products (Espresso's `pcover`),
//! for both single-output ([`Cover`]) and multi-output ([`MvCover`]) functions.

use std::collections::BTreeMap;

use crate::cube::{
    cube_contains, cube_intersect, mv_cube_contains, mv_cube_distance, Cube, MvCube, ParseError,
    Part,
};

/// A set of cubes over a fixed number of variables.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct Cover {
    nvars: usize,
    cubes: Vec<Cube>,
}

impl Cover {
    /// Empty cover (constant 0).
    pub fn new(nvars: usize) -> Cover {
        Cover { nvars, cubes: Vec::new() }
    }

    /// Cover consisting of just the universe cube (constant 1).
    pub fn universe(nvars: usize) -> Cover {
        Cover { nvars, cubes: vec![Cube::universe(nvars)] }
    }

    /// Build from cubes.
    pub fn from_cubes(nvars: usize, cubes: Vec<Cube>) -> Cover {
        debug_assert!(cubes.iter().all(|c| c.nvars() == nvars));
        Cover { nvars, cubes }
    }

    /// Parse textual cubes like `"01-"`.
    pub fn parse<S: AsRef<str>>(nvars: usize, rows: &[S]) -> Result<Cover, ParseError> {
        let mut cv = Cover::new(nvars);
        for r in rows {
            cv.add(Cube::parse(nvars, r.as_ref())?);
        }
        Ok(cv)
    }

    /// Cover of minterm cubes (variable 0 = MSB of the minterm index).
    pub fn from_minterms(nvars: usize, minterms: &[u64]) -> Cover {
        Cover {
            nvars,
            cubes: minterms.iter().map(|&m| Cube::from_minterm(nvars, m)).collect(),
        }
    }

    pub fn nvars(&self) -> usize {
        self.nvars
    }
    pub fn len(&self) -> usize {
        self.cubes.len()
    }
    pub fn is_empty(&self) -> bool {
        self.cubes.is_empty()
    }
    pub fn cubes(&self) -> &[Cube] {
        &self.cubes
    }
    pub fn iter(&self) -> std::slice::Iter<'_, Cube> {
        self.cubes.iter()
    }

    /// Append a cube.
    pub fn add(&mut self, c: Cube) {
        debug_assert_eq!(c.nvars(), self.nvars);
        self.cubes.push(c);
    }

    /// Remove (and return) the cube at `idx`, preserving order.
    pub fn remove(&mut self, idx: usize) -> Cube {
        self.cubes.remove(idx)
    }

    /// Append all cubes of `other`.
    pub fn extend(&mut self, other: &Cover) {
        self.cubes.extend(other.cubes.iter().cloned());
    }

    /// Total literal count.
    pub fn literals(&self) -> usize {
        self.cubes.iter().map(Cube::literals).sum()
    }

    /// Cost = (number of cubes, number of literals), compared lexicographically.
    pub fn cost(&self) -> (usize, usize) {
        (self.len(), self.literals())
    }

    /// Textual rows, one per cube.
    pub fn to_strings(&self) -> Vec<String> {
        self.cubes.iter().map(|c| c.to_string()).collect()
    }

    /// Does the cover contain the minterm `m`?
    pub fn contains_minterm(&self, m: u64) -> bool {
        let mc = Cube::from_minterm(self.nvars, m);
        self.cubes.iter().any(|c| cube_contains(c, &mc))
    }

    /// Drop empty cubes.
    pub fn remove_empty(&mut self) {
        self.cubes.retain(|c| !c.is_empty());
    }

    /// Single-cube containment: remove duplicates and cubes contained in another.
    pub fn single_cube_containment(&mut self) {
        let mut sorted = std::mem::take(&mut self.cubes);
        sorted.sort_by_key(|c| c.literals());
        let mut kept: Vec<Cube> = Vec::with_capacity(sorted.len());
        for c in sorted {
            if !kept.iter().any(|k| cube_contains(k, &c)) {
                kept.push(c);
            }
        }
        self.cubes = kept;
    }

    /// Supercube of all cubes, `None` if the cover is empty.
    pub fn supercube(&self) -> Option<Cube> {
        let mut it = self.cubes.iter();
        let first = it.next()?.clone();
        Some(it.fold(first, |acc, c| acc.supercube(c)))
    }

    /// Cofactor of the cover with respect to cube `c`.
    pub fn cofactor(&self, c: &Cube) -> Cover {
        Cover {
            nvars: self.nvars,
            cubes: self.cubes.iter().filter_map(|p| p.cofactor(c)).collect(),
        }
    }

    /// Per-variable counts of (Zero literals, One literals).
    fn column_counts(&self) -> Vec<(usize, usize)> {
        let mut counts = vec![(0usize, 0usize); self.nvars];
        for c in &self.cubes {
            for (v, cnt) in counts.iter_mut().enumerate() {
                match c.get(v) {
                    Part::Zero => cnt.0 += 1,
                    Part::One => cnt.1 += 1,
                    _ => {}
                }
            }
        }
        counts
    }

    /// Most binate variable (appears in both polarities, most occurrences).
    fn binate_var(&self) -> Option<usize> {
        self.column_counts()
            .iter()
            .enumerate()
            .filter(|(_, &(z, o))| z > 0 && o > 0)
            .max_by_key(|(v, &(z, o))| (z + o, usize::MAX - v))
            .map(|(v, _)| v)
    }

    /// Splitting variable: most binate, else the most frequently used.
    fn split_var(&self) -> Option<usize> {
        self.binate_var().or_else(|| {
            self.column_counts()
                .iter()
                .enumerate()
                .filter(|(_, &(z, o))| z + o > 0)
                .max_by_key(|(v, &(z, o))| (z + o, usize::MAX - v))
                .map(|(v, _)| v)
        })
    }

    /// Is the cover a tautology (equal to constant 1)? Unate recursive paradigm.
    pub fn is_tautology(&self) -> bool {
        if self.cubes.iter().any(Cube::is_universe) {
            return true;
        }
        if self.cubes.is_empty() {
            return false;
        }
        // A unate cover is a tautology only if it holds the universe cube.
        let Some(v) = self.binate_var() else { return false };
        [Part::Zero, Part::One]
            .iter()
            .all(|&p| self.cofactor(&Cube::literal(self.nvars, v, p)).is_tautology())
    }

    /// Is cube `c` covered by this cover? (`cofactor(c)` is a tautology.)
    pub fn covers_cube(&self, c: &Cube) -> bool {
        self.cofactor(c).is_tautology()
    }

    /// Complement of the cover via recursive Shannon expansion.
    pub fn complement(&self) -> Cover {
        let n = self.nvars;
        if self.cubes.is_empty() {
            return Cover::universe(n);
        }
        if self.cubes.iter().any(Cube::is_universe) {
            return Cover::new(n);
        }
        if self.cubes.len() == 1 {
            return Cover { nvars: n, cubes: self.cubes[0].complement() };
        }
        let v = self.split_var().expect("non-universe cubes have a literal");
        let mut out = Cover::new(n);
        for p in [Part::Zero, Part::One] {
            let lit = Cube::literal(n, v, p);
            for c in self.cofactor(&lit).complement().cubes {
                out.add(cube_intersect(&c, &lit));
            }
        }
        out.single_cube_containment();
        out
    }
}

/// A multi-output cover over `nin` binary inputs and `nout` binary outputs.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct MvCover {
    nin: usize,
    nout: usize,
    cubes: Vec<MvCube>,
}

impl MvCover {
    /// Empty cover (all outputs constant 0).
    pub fn new(nin: usize, nout: usize) -> MvCover {
        MvCover { nin, nout, cubes: Vec::new() }
    }

    /// Universe cover (all outputs constant 1).
    pub fn universe(nin: usize, nout: usize) -> MvCover {
        if nout == 0 {
            return MvCover::new(nin, 0);
        }
        MvCover {
            nin,
            nout,
            cubes: vec![MvCube::universe(nin, nout)],
        }
    }

    /// Build from MV cubes.
    pub fn from_cubes(nin: usize, nout: usize, cubes: Vec<MvCube>) -> MvCover {
        debug_assert!(cubes.iter().all(|c| c.nin() == nin && c.nout() == nout));
        MvCover { nin, nout, cubes }
    }

    /// Combine `nout` single-output [`Cover`]s into a multi-output [`MvCover`].
    pub fn from_single_output_covers(nin: usize, covers: &[Cover]) -> MvCover {
        let nout = covers.len();
        let mut mv = MvCover::new(nin, nout);
        for (k, cv) in covers.iter().enumerate() {
            debug_assert_eq!(cv.nvars(), nin);
            for c in cv.iter() {
                mv.add(MvCube::single_output(c.clone(), nout, k));
            }
        }
        mv.single_cube_containment();
        mv
    }

    pub fn nin(&self) -> usize {
        self.nin
    }
    pub fn nout(&self) -> usize {
        self.nout
    }
    pub fn len(&self) -> usize {
        self.cubes.len()
    }
    pub fn is_empty(&self) -> bool {
        self.cubes.is_empty()
    }
    pub fn cubes(&self) -> &[MvCube] {
        &self.cubes
    }
    pub fn iter(&self) -> std::slice::Iter<'_, MvCube> {
        self.cubes.iter()
    }

    /// Append an MV cube.
    pub fn add(&mut self, c: MvCube) {
        debug_assert_eq!(c.nin(), self.nin);
        debug_assert_eq!(c.nout(), self.nout);
        self.cubes.push(c);
    }

    /// Remove (and return) the cube at `idx`.
    pub fn remove(&mut self, idx: usize) -> MvCube {
        self.cubes.remove(idx)
    }

    /// Append all cubes of `other`.
    pub fn extend(&mut self, other: &MvCover) {
        debug_assert_eq!(self.nin, other.nin);
        debug_assert_eq!(self.nout, other.nout);
        self.cubes.extend(other.cubes.iter().cloned());
    }

    /// Project onto single-output [`Cover`] for output `out`.
    pub fn output_cover(&self, out: usize) -> Cover {
        debug_assert!(out < self.nout);
        let mut cv = Cover::new(self.nin);
        for c in &self.cubes {
            if !c.is_empty() && c.out_get(out) {
                cv.add(c.input().clone());
            }
        }
        cv
    }

    /// Split into `nout` single-output [`Cover`]s.
    pub fn to_single_output_covers(&self) -> Vec<Cover> {
        (0..self.nout).map(|k| self.output_cover(k)).collect()
    }

    /// Total binary input literals (AND-plane connections).
    pub fn input_literals(&self) -> usize {
        self.cubes.iter().map(MvCube::input_literals).sum()
    }

    /// Total active output bits (OR-plane connections).
    pub fn output_ones(&self) -> usize {
        self.cubes.iter().map(MvCube::output_ones).sum()
    }

    /// Cost = `(cubes, input_literals, output_ones)`, compared lexicographically.
    pub fn cost(&self) -> (usize, usize, usize) {
        (self.len(), self.input_literals(), self.output_ones())
    }

    /// Does output `out` contain minterm `m` (variable 0 = MSB)?
    pub fn contains_minterm(&self, out: usize, m: u64) -> bool {
        debug_assert!(out < self.nout);
        let mc = Cube::from_minterm(self.nin, m);
        self.cubes
            .iter()
            .any(|c| !c.is_empty() && c.out_get(out) && cube_contains(c.input(), &mc))
    }

    /// Drop empty cubes (contradictory input or all-zero output).
    pub fn remove_empty(&mut self) {
        self.cubes.retain(|c| !c.is_empty());
    }

    /// Coalesce cubes with identical input parts (OR-ing their output masks)
    /// and remove any cube contained in another MV cube.
    pub fn single_cube_containment(&mut self) {
        let raw = std::mem::take(&mut self.cubes);
        let mut index_by_input: BTreeMap<Cube, usize> = BTreeMap::new();
        let mut coalesced: Vec<MvCube> = Vec::with_capacity(raw.len());
        for c in raw {
            if c.is_empty() {
                continue;
            }
            if let Some(&idx) = index_by_input.get(c.input()) {
                coalesced[idx].out_or_assign(&c);
            } else {
                let idx = coalesced.len();
                index_by_input.insert(c.input().clone(), idx);
                coalesced.push(c);
            }
        }
        coalesced.sort_by_key(|c| (c.input_literals(), std::cmp::Reverse(c.output_ones())));
        let mut kept: Vec<MvCube> = Vec::with_capacity(coalesced.len());
        for c in coalesced {
            if !kept.iter().any(|k| mv_cube_contains(k, &c)) {
                kept.push(c);
            }
        }
        self.cubes = kept;
    }

    /// Supercube of all non-empty cubes, `None` if empty.
    pub fn supercube(&self) -> Option<MvCube> {
        let mut it = self.cubes.iter().filter(|c| !c.is_empty());
        let first = it.next()?.clone();
        Some(it.fold(first, |acc, c| acc.supercube(c)))
    }

    /// MV cofactor of the cover with respect to `c`.
    pub fn cofactor(&self, c: &MvCube) -> MvCover {
        MvCover {
            nin: self.nin,
            nout: self.nout,
            cubes: self
                .cubes
                .iter()
                .filter(|p| !p.is_empty())
                .filter_map(|p| p.cofactor(c))
                .collect(),
        }
    }

    fn binate_input_var(&self) -> Option<usize> {
        let mut counts = vec![(0usize, 0usize); self.nin];
        for c in &self.cubes {
            if c.is_empty() {
                continue;
            }
            for (v, cnt) in counts.iter_mut().enumerate() {
                match c.input().get(v) {
                    Part::Zero => cnt.0 += 1,
                    Part::One => cnt.1 += 1,
                    _ => {}
                }
            }
        }
        counts
            .iter()
            .enumerate()
            .filter(|(_, &(z, o))| z > 0 && o > 0)
            .max_by_key(|(v, &(z, o))| (z + o, usize::MAX - v))
            .map(|(v, _)| v)
    }

    /// True if every output `0..nout` is identically `1` across all inputs.
    pub fn is_tautology(&self) -> bool {
        if self.nout == 0 {
            return true;
        }
        let full = MvCube::universe(self.nin, self.nout);
        let full_words = full.out_words();
        let nw = full_words.len();
        let mut univ_out = vec![0u32; nw];
        let mut all_out = vec![0u32; nw];

        for c in &self.cubes {
            if c.is_empty() {
                continue;
            }
            for (a, &w) in all_out.iter_mut().zip(c.out_words()) {
                *a |= w;
            }
            if c.input().is_universe() {
                for (u, &w) in univ_out.iter_mut().zip(c.out_words()) {
                    *u |= w;
                }
            }
        }

        if univ_out.as_slice() == full_words {
            return true;
        }
        if all_out.as_slice() != full_words {
            return false;
        }
        // When all binary inputs are unate, each output's projection is unate,
        // so it can only be a tautology if covered by universe-input cubes.
        let Some(v) = self.binate_input_var() else { return false };
        [Part::Zero, Part::One].iter().all(|&p| {
            let mut lit = MvCube::universe(self.nin, self.nout);
            lit.input_mut().set(v, p);
            self.cofactor(&lit).is_tautology()
        })
    }

    /// Is MV cube `c` covered by `self`?
    pub fn covers_cube(&self, c: &MvCube) -> bool {
        if c.is_empty() {
            return true;
        }
        self.cofactor(c).is_tautology()
    }

    /// True if `self` and `other` share at least one `(minterm, output)` point.
    pub fn intersects(&self, other: &MvCover) -> bool {
        debug_assert_eq!(self.nin, other.nin);
        debug_assert_eq!(self.nout, other.nout);
        self.cubes.iter().filter(|a| !a.is_empty()).any(|a| {
            other
                .cubes
                .iter()
                .filter(|b| !b.is_empty())
                .any(|b| mv_cube_distance(a, b) == 0)
        })
    }

    /// Complement of the multi-output cover over `{0,1}^nin × {0..nout-1}`.
    pub fn complement(&self) -> MvCover {
        let mut out = MvCover::new(self.nin, self.nout);
        for k in 0..self.nout {
            let comp_k = self.output_cover(k).complement();
            for c in comp_k.cubes {
                out.add(MvCube::single_output(c, self.nout, k));
            }
        }
        out.single_cube_containment();
        out
    }

    /// Set difference `self \ other` (`self ∩ ¬other`), returning a cover
    /// covering every `(minterm, output)` in `self` that is not in `other`.
    pub fn subtract(&self, other: &MvCover) -> MvCover {
        debug_assert_eq!(self.nin, other.nin);
        debug_assert_eq!(self.nout, other.nout);
        if self.is_empty() || other.is_empty() || !self.intersects(other) {
            return self.clone();
        }
        let mut out = MvCover::new(self.nin, self.nout);
        for k in 0..self.nout {
            let s_k = self.output_cover(k);
            if s_k.is_empty() {
                continue;
            }
            let o_k = other.output_cover(k);
            if o_k.is_empty() {
                for c in s_k.cubes {
                    out.add(MvCube::single_output(c, self.nout, k));
                }
            } else {
                let not_o_k = o_k.complement();
                let mut diff_k = Cover::new(self.nin);
                for a in &s_k.cubes {
                    for b in &not_o_k.cubes {
                        let inter = cube_intersect(a, b);
                        if !inter.is_empty() {
                            diff_k.add(inter);
                        }
                    }
                }
                diff_k.single_cube_containment();
                for c in diff_k.cubes {
                    out.add(MvCube::single_output(c, self.nout, k));
                }
            }
        }
        out.single_cube_containment();
        out
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn cov(rows: &[&str]) -> Cover {
        Cover::parse(rows[0].len(), rows).unwrap()
    }

    #[test]
    fn tautology_checks() {
        assert!(cov(&["1-", "0-"]).is_tautology());
        assert!(cov(&["11", "10", "0-"]).is_tautology());
        assert!(!cov(&["11", "00"]).is_tautology());
        assert!(!Cover::new(3).is_tautology());
    }

    #[test]
    fn complement_is_exact() {
        let f = cov(&["1-0", "01-", "-11"]);
        let g = f.complement();
        for m in 0..8u64 {
            assert_ne!(f.contains_minterm(m), g.contains_minterm(m), "minterm {m}");
        }
    }

    #[test]
    fn covers_and_scc() {
        let f = cov(&["1--", "-1-"]);
        assert!(f.covers_cube(&Cube::parse(3, "11-").unwrap()));
        assert!(!f.covers_cube(&Cube::parse(3, "00-").unwrap()));
        let mut g = cov(&["1--", "10-", "1--"]);
        g.single_cube_containment();
        assert_eq!(g.len(), 1);
    }

    #[test]
    fn add_remove() {
        let mut f = cov(&["1-", "0-"]);
        let r = f.remove(0);
        assert_eq!(r.to_string(), "1-");
        assert_eq!(f.len(), 1);
    }

    #[test]
    fn mv_tautology_complement_and_scc() {
        // Unate multi-output tautology: (--, 10) + (--, 01).
        let mut t = MvCover::new(2, 2);
        t.add(MvCube::parse(2, 2, "--", "10").unwrap());
        t.add(MvCube::parse(2, 2, "--", "01").unwrap());
        assert!(t.is_tautology());
        t.single_cube_containment();
        assert_eq!(t.len(), 1);
        assert!(t.cubes()[0].is_universe());

        // Binate multi-output tautology on output 0 + universe on output 1.
        let mut t2 = MvCover::new(2, 2);
        t2.add(MvCube::parse(2, 2, "1-", "10").unwrap());
        t2.add(MvCube::parse(2, 2, "0-", "10").unwrap());
        t2.add(MvCube::parse(2, 2, "--", "01").unwrap());
        assert!(t2.is_tautology());

        // Non-tautology: output 0 only covers 1-.
        let mut nt = MvCover::new(2, 2);
        nt.add(MvCube::parse(2, 2, "1-", "10").unwrap());
        nt.add(MvCube::parse(2, 2, "--", "01").unwrap());
        assert!(!nt.is_tautology());

        // Exactness of MV complement and subtract.
        let mut f = MvCover::new(3, 2);
        f.add(MvCube::parse(3, 2, "1-0", "11").unwrap());
        f.add(MvCube::parse(3, 2, "01-", "10").unwrap());
        f.add(MvCube::parse(3, 2, "-11", "01").unwrap());
        let g = f.complement();
        for m in 0..8u64 {
            for k in 0..2 {
                assert_ne!(f.contains_minterm(k, m), g.contains_minterm(k, m));
            }
        }

        let mut d = MvCover::new(3, 2);
        d.add(MvCube::parse(3, 2, "1--", "10").unwrap());
        let diff = d.subtract(&f);
        for m in 0..8u64 {
            for k in 0..2 {
                let expected = d.contains_minterm(k, m) && !f.contains_minterm(k, m);
                assert_eq!(diff.contains_minterm(k, m), expected);
            }
        }
    }
}
