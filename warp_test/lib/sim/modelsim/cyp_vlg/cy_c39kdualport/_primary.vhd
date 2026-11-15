library verilog;
use verilog.vl_types.all;
entity cy_c39kdualport is
    generic(
        datawidth       : integer := 1;
        addresswidth    : integer := 1;
        indata_reg      : integer := 1;
        add_ctrl_reg    : integer := 1;
        outdataa_reg    : integer := 0;
        outdatab_reg    : integer := 0;
        filename        : string  := ""
    );
    port(
        din_a           : in     vl_logic_vector;
        din_b           : in     vl_logic_vector;
        addr_a          : in     vl_logic_vector;
        addr_b          : in     vl_logic_vector;
        wea             : in     vl_logic;
        web             : in     vl_logic;
        inclk_a         : in     vl_logic;
        outclk_a        : in     vl_logic;
        outrega_ar      : in     vl_logic;
        inclk_b         : in     vl_logic;
        outclk_b        : in     vl_logic;
        outregb_ar      : in     vl_logic;
        dout_a          : out    vl_logic_vector;
        dout_b          : out    vl_logic_vector
    );
end cy_c39kdualport;
