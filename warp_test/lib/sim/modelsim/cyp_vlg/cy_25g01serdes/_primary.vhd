library verilog;
use verilog.vl_types.all;
entity cy_25g01serdes is
    generic(
        txclk_period_min: integer := 6380;
        txclk_period_max: integer := 6470;
        txclk_period_vio: string  := "ERROR-001:  TXCLK Period Violation";
        txclk_dutycy_min: real    := 0.430000;
        txclk_dutycy_max: real    := 0.570000;
        txclk_dutycy_vio: string  := "ERROR-002:  TXCLK Duty-cycle Violation";
        rxclk_period_min: integer := 6380;
        rxclk_period_max: integer := 6470;
        rxclk_period_vio: string  := "ERROR-005:  RXCLK Period Violation";
        rxclk_dutycy_min: real    := 0.430000;
        rxclk_dutycy_max: real    := 0.570000;
        rxclk_dutycy_vio: string  := "ERROR-006:  RXCLK Duty Cycle Violation";
        refclk_period_min: integer := 6380;
        refclk_period_max: integer := 6470;
        refclk_period_vio: string  := "ERROR-007:  REFCLK Period Violation";
        refclk_dutycy_min: real    := 0.350000;
        refclk_dutycy_max: real    := 0.650000;
        refclk_dutycy_vio: string  := "ERROR-008:  REFCLK Duty Cycle Violation";
        refclk_freqtol  : real    := 0.000100;
        refclk_freqtol_vio: string  := "ERROR-009:  REFCLK Frequency Tolerance Violation";
        rxpd_min        : integer := -1000;
        rxpd_max        : integer := 1000
    );
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
end cy_25g01serdes;
