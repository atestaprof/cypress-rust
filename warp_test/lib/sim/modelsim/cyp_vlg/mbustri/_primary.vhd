library verilog;
use verilog.vl_types.all;
entity mbustri is
    generic(
        lpm_width       : integer := 1;
        lpm_hint        : integer := 0
    );
    port(
        tridata         : inout  vl_logic_vector;
        data            : in     vl_logic_vector;
        enabletr        : in     vl_logic;
        enabledt        : in     vl_logic;
        result          : out    vl_logic_vector
    );
end mbustri;
