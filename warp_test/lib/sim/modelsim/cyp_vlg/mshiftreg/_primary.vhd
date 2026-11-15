library verilog;
use verilog.vl_types.all;
entity mshiftreg is
    generic(
        lpm_width       : integer := 1;
        lpm_direction   : integer := 0;
        lpm_avalue      : string  := "NULL";
        lpm_svalue      : string  := "NULL";
        lpm_pvalue      : string  := "NULL";
        lpm_hint        : integer := 0
    );
    port(
        data            : in     vl_logic_vector;
        clock           : in     vl_logic;
        enable          : in     vl_logic;
        shiftin         : in     vl_logic;
        load            : in     vl_logic;
        q               : out    vl_logic_vector;
        shiftout        : out    vl_logic;
        aset            : in     vl_logic;
        aclr            : in     vl_logic;
        sset            : in     vl_logic;
        sclr            : in     vl_logic;
        testenab        : in     vl_logic;
        testin          : in     vl_logic;
        testout         : out    vl_logic
    );
end mshiftreg;
