library verilog;
use verilog.vl_types.all;
entity mparity is
    generic(
        lpm_width       : integer := 1;
        lpm_hint        : integer := 0;
        lpm_pipeline    : integer := 0
    );
    port(
        data            : in     vl_logic_vector;
        even            : out    vl_logic;
        odd             : out    vl_logic;
        clock           : in     vl_logic;
        aclr            : in     vl_logic
    );
end mparity;
