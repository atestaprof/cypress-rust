library verilog;
use verilog.vl_types.all;
entity cy_c39ksingleport is
    generic(
        datawidth       : integer := 1;
        addresswidth    : integer := 1;
        indata_reg      : integer := 1;
        addr_ctrl_reg   : integer := 1;
        outdata_reg     : integer := 0;
        filename        : string  := ""
    );
    port(
        din             : in     vl_logic_vector;
        addr            : in     vl_logic_vector;
        we              : in     vl_logic;
        inclk           : in     vl_logic;
        outclk          : in     vl_logic;
        outreg_ar       : in     vl_logic;
        dout            : out    vl_logic_vector
    );
end cy_c39ksingleport;
