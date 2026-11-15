library verilog;
use verilog.vl_types.all;
entity c37kinp is
    generic(
        iregister       : integer := 1;
        tclk            : integer := 2000;
        tird            : integer := 500;
        ticomb          : integer := 1000;
        tilat           : integer := 3500;
        tirsu           : integer := 4000;
        tirh            : integer := 0;
        twl             : integer := 2500;
        twh             : integer := 2500
    );
    port(
        d               : in     vl_logic;
        clk             : in     vl_logic;
        fb              : out    vl_logic
    );
end c37kinp;
