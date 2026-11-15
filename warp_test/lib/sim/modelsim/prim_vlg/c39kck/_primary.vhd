library verilog;
use verilog.vl_types.all;
entity c39kck is
    generic(
        cfgbits         : integer := 0;
        xplpulsewthlo   : integer := 100;
        xplpulsewthhi   : integer := 100;
        xplmininputduty : integer := 30;
        xplmaxinputduty : integer := 70;
        xpljitteruncertainty: integer := 100;
        xplzerofbuncertainty: integer := 100;
        xpltreefbuncertainty: integer := 100;
        xplminpinclkperiod: integer := 100;
        xplmaxpinclkperiod: integer := 100;
        xpllocktime     : integer := 100;
        xplclocktreeoffset: integer := 100;
        xckpin2gclkdirect: integer := 100;
        xplspreadfreqpercent: real    := 1.000000;
        xplspreadfreqkhz: real    := 1.000000;
        simlocktime     : integer := 3000000;
        clk_high        : string  := "Clock high width violation.";
        clk_low         : string  := "Clock low width violation.";
        clk_cycle_min   : string  := "Clock cycle minimum width violation.";
        clk_cycle_max   : string  := "Clock cycle maximum width violation.";
        clk_duty_cycle  : string  := "Clock duty cycle violation.";
        jitterspec      : real    := 0.010000
    );
    port(
        clk             : in     vl_logic_vector(3 downto 0);
        nios            : in     vl_logic;
        lock            : out    vl_logic;
        glclk           : out    vl_logic_vector(3 downto 0)
    );
end c39kck;
