library verilog;
use verilog.vl_types.all;
entity madd_sub is
    generic(
        lpm_width       : integer := 1;
        lpm_representation: integer := 1;
        lpm_direction   : integer := 0;
        lpm_hint        : integer := 0;
        lpm_pipeline    : integer := 0
    );
    port(
        dataa           : in     vl_logic_vector;
        datab           : in     vl_logic_vector;
        cin             : in     vl_logic;
        add_sub         : in     vl_logic;
        result          : out    vl_logic_vector;
        cout            : out    vl_logic;
        overflow        : out    vl_logic;
        clock           : in     vl_logic;
        aclr            : in     vl_logic
    );
end madd_sub;
