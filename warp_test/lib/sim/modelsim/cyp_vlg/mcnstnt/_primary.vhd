library verilog;
use verilog.vl_types.all;
entity mcnstnt is
    generic(
        lpm_width       : integer := 1;
        lpm_cvalue      : string  := "NULL";
        lpm_hint        : integer := 0;
        lpm_strength    : integer := 0
    );
    port(
        result          : out    vl_logic_vector
    );
end mcnstnt;
