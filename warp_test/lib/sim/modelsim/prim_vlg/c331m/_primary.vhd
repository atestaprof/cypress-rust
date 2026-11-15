library verilog;
use verilog.vl_types.all;
entity c331m is
    generic(
        tpd             : integer := 20000;
        tico            : integer := 35000;
        tioh            : integer := 5000;
        tis             : integer := 2000;
        tih             : integer := 11000;
        tiar            : integer := 35000;
        tirw            : integer := 35000;
        tirr            : integer := 35000;
        tias            : integer := 35000;
        tisw            : integer := 35000;
        tisr            : integer := 35000;
        twh             : integer := 12000;
        twl             : integer := 12000;
        tco             : integer := 20000;
        ts              : integer := 12000;
        th              : integer := 8000;
        toar            : integer := 20000;
        torw            : integer := 20000;
        torr            : integer := 20000;
        toas            : integer := 20000;
        tosw            : integer := 20000;
        tosr            : integer := 20000;
        tpzx            : integer := 20000;
        tpxz            : integer := 20000
    );
    port(
        x1              : in     vl_logic;
        x2              : in     vl_logic;
        clk             : in     vl_logic;
        iclk            : in     vl_logic;
        oe              : in     vl_logic;
        as              : in     vl_logic;
        ar              : in     vl_logic;
        ias             : in     vl_logic;
        iar             : in     vl_logic;
        qfb             : out    vl_logic;
        y               : inout  vl_logic;
        qifb            : out    vl_logic
    );
end c331m;
