library verilog;
use verilog.vl_types.all;
entity mclshift is
    generic(
        lpm_width       : integer := 1;
        lpm_widthdist   : integer := 1;
        lpm_shifttype   : integer := 0;
        lpm_hint        : integer := 0
    );
    port(
        data            : in     vl_logic_vector;
        distance        : in     vl_logic_vector;
        direction       : in     vl_logic;
        result          : out    vl_logic_vector;
        overflow        : out    vl_logic;
        underflow       : out    vl_logic
    );
end mclshift;
