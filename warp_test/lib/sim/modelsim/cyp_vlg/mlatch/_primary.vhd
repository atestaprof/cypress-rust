library verilog;
use verilog.vl_types.all;
entity mlatch is
    generic(
        lpm_width       : integer := 1;
        lpm_avalue      : string  := "NULL";
        lpm_pvalue      : string  := "NULL";
        lpm_hint        : integer := 0
    );
    port(
        data            : in     vl_logic_vector;
        gate            : in     vl_logic;
        q               : out    vl_logic_vector;
        aset            : in     vl_logic;
        aclr            : in     vl_logic
    );
end mlatch;
