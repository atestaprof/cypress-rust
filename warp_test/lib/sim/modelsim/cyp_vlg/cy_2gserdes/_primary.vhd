library verilog;
use verilog.vl_types.all;
entity cy_2gserdes is
    port(
        txd             : in     vl_logic_vector(15 downto 0);
        fifo_rstb       : in     vl_logic;
        loop_time       : in     vl_logic;
        diagloop        : in     vl_logic;
        loopa           : in     vl_logic;
        lineloop        : in     vl_logic;
        resetb          : in     vl_logic;
        pwrdnb          : in     vl_logic;
        lockrefb        : in     vl_logic;
        refclk_n        : in     vl_logic;
        refclk_p        : in     vl_logic;
        serial_in_n     : in     vl_logic;
        serial_in_p     : in     vl_logic;
        sd              : in     vl_logic;
        serial_out_n    : out    vl_logic;
        serial_out_p    : out    vl_logic;
        fifo_err        : out    vl_logic;
        txclk           : out    vl_logic;
        rxd             : out    vl_logic_vector(15 downto 0);
        rxclk           : out    vl_logic;
        lfib            : out    vl_logic
    );
end cy_2gserdes;
