library verilog;
use verilog.vl_types.all;
entity cy_fifo is
    generic(
        lpm_width       : integer := 1;
        lpm_numwords    : integer := 1;
        lpm_pafe_length : integer := 0;
        lpm_hint        : integer := 0
    );
    port(
        data            : in     vl_logic_vector;
        q               : out    vl_logic_vector;
        enr             : in     vl_logic;
        enw             : in     vl_logic;
        readclock       : in     vl_logic;
        writeclock      : in     vl_logic;
        mrb             : in     vl_logic;
        efb             : out    vl_logic;
        hfb             : out    vl_logic;
        pafeb           : out    vl_logic
    );
end cy_fifo;
