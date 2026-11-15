library verilog;
use verilog.vl_types.all;
entity cy_fifo_9532 is
    port(
        data_in         : in     vl_logic_vector(15 downto 0);
        rstb            : in     vl_logic;
        wrclk           : in     vl_logic;
        out_2d          : out    vl_logic_vector(15 downto 0);
        rdclk           : in     vl_logic;
        fifoerr         : out    vl_logic;
        fifoempty       : out    vl_logic
    );
end cy_fifo_9532;
