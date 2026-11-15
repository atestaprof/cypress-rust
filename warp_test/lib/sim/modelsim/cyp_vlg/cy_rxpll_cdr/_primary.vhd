library verilog;
use verilog.vl_types.all;
entity cy_rxpll_cdr is
    port(
        refclk          : in     vl_logic;
        rxpll_in        : in     vl_logic;
        recovered_clk   : out    vl_logic;
        rxclko          : out    vl_logic;
        lfib            : out    vl_logic;
        rxcksel         : in     vl_logic;
        bisten          : in     vl_logic;
        resetb          : in     vl_logic;
        rxrate          : in     vl_logic;
        rx_disable      : in     vl_logic;
        rxmode          : in     vl_logic_vector(1 downto 0);
        ch_id           : in     vl_logic_vector(1 downto 0);
        rxclko_c        : out    vl_logic;
        oolin           : out    vl_logic;
        spdsel          : in     vl_logic;
        lesstime        : in     vl_logic;
        rxclkb          : in     vl_logic;
        rxclkd          : in     vl_logic;
        txrate          : in     vl_logic;
        slipsync        : in     vl_logic;
        odd_even        : in     vl_logic
    );
end cy_rxpll_cdr;
