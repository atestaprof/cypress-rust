library verilog;
use verilog.vl_types.all;
entity mram_dq is
    generic(
        lpm_width       : integer := 1;
        lpm_widthad     : integer := 1;
        lpm_numwords    : integer := 1;
        lpm_indata      : integer := 0;
        lpm_address_control: integer := 0;
        lpm_outdata     : integer := 0;
        lpm_file        : string  := "NULL";
        lpm_hint        : integer := 0
    );
    port(
        data            : in     vl_logic_vector;
        address         : in     vl_logic_vector;
        q               : out    vl_logic_vector;
        inclock         : in     vl_logic;
        outclock        : in     vl_logic;
        we              : in     vl_logic;
        outreg_ar       : in     vl_logic
    );
end mram_dq;
