library verilog;
use verilog.vl_types.all;
entity cy_fifo_9294 is
    port(
        direct          : in     vl_logic;
        data_in         : in     vl_logic_vector(11 downto 0);
        rstb            : in     vl_logic;
        wrclk           : in     vl_logic;
        data_out        : out    vl_logic_vector(11 downto 0);
        rdclk           : in     vl_logic;
        fifoerr         : out    vl_logic;
        txrate          : in     vl_logic;
        txcksel         : in     vl_logic;
        realign         : in     vl_logic
    );
end cy_fifo_9294;
