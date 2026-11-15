library verilog;
use verilog.vl_types.all;
entity cy_c39kpll is
    generic(
        feedback        : integer := 0;
        multiply        : integer := 1;
        gclk0_phase     : integer := 0;
        gclk0_divide    : integer := 1;
        gclk1_phase     : integer := 0;
        gclk1_divide    : integer := 1;
        gclk2_phase     : integer := 0;
        gclk2_divide    : integer := 1;
        gclk3_phase     : integer := 0;
        gclk3_divide    : integer := 1;
        input_freq      : integer := 0;
        ext_fdbk_delay_ps: integer := 0;
        ext_fdbk_port_out: string  := "NULL"
    );
    port(
        pll_in          : in     vl_logic;
        ext_fdbk        : in     vl_logic;
        lock_detect     : out    vl_logic;
        gclk0           : out    vl_logic;
        gclk1           : out    vl_logic;
        gclk2           : out    vl_logic;
        gclk3           : out    vl_logic
    );
end cy_c39kpll;
