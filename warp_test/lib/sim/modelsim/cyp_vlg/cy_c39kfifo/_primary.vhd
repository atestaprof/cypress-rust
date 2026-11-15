library verilog;
use verilog.vl_types.all;
entity cy_c39kfifo is
    generic(
        datawidth       : integer := 1;
        numwords        : integer := 1;
        pafe_distance   : integer := 0
    );
    port(
        din             : in     vl_logic_vector;
        dout            : out    vl_logic_vector;
        enr             : in     vl_logic;
        enw             : in     vl_logic;
        ckr             : in     vl_logic;
        ckw             : in     vl_logic;
        mrb             : in     vl_logic;
        efb             : out    vl_logic;
        hfb             : out    vl_logic;
        pafeb           : out    vl_logic
    );
end cy_c39kfifo;
