library verilog;
use verilog.vl_types.all;
entity c2gcor is
    port(
        txd             : in     vl_logic_vector(15 downto 0);
        txclki          : in     vl_logic;
        txclko          : out    vl_logic;
        rxd             : out    vl_logic_vector(15 downto 0);
        rxclk           : out    vl_logic;
        refclk          : in     vl_logic;
        lfib            : out    vl_logic;
        locked          : inout  vl_logic;
        resetb          : in     vl_logic;
        lockrefb        : in     vl_logic;
        sd              : in     vl_logic;
        fifo_err        : out    vl_logic;
        fifo_rstb       : in     vl_logic;
        pwrdnb          : in     vl_logic;
        diagloop        : in     vl_logic;
        lineloop        : in     vl_logic;
        loopa           : in     vl_logic;
        loop_time       : in     vl_logic;
        td_out          : out    vl_logic;
        rd_in           : in     vl_logic
    );
end c2gcor;
