library verilog;
use verilog.vl_types.all;
entity cy_ram_dp is
    generic(
        lpm_width       : integer := 1;
        lpm_widthad     : integer := 1;
        lpm_numwords    : integer := 1;
        lpm_indata      : integer := 0;
        lpm_address_control: integer := 0;
        lpm_outdata_a   : integer := 0;
        lpm_outdata_b   : integer := 0;
        lpm_file        : string  := "NULL";
        lpm_hint        : integer := 0
    );
    port(
        data_a          : in     vl_logic_vector;
        data_b          : in     vl_logic_vector;
        address_a       : in     vl_logic_vector;
        address_b       : in     vl_logic_vector;
        q_a             : out    vl_logic_vector;
        q_b             : out    vl_logic_vector;
        addr_matchb     : out    vl_logic;
        wea             : in     vl_logic;
        web             : in     vl_logic;
        inclock_a       : in     vl_logic;
        inclock_b       : in     vl_logic;
        outclock_a      : in     vl_logic;
        outclock_b      : in     vl_logic;
        outrega_ar      : in     vl_logic;
        outregb_ar      : in     vl_logic
    );
end cy_ram_dp;
