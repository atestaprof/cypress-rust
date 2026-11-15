library verilog;
use verilog.vl_types.all;
entity c335m is
    generic(
        registered      : integer := 4;
        bta_sel         : integer := 1;
        tpd             : integer := 15000;
        twh             : integer := 5000;
        twl             : integer := 5000;
        tis             : integer := 2000;
        tih             : integer := 2000;
        tico            : integer := 18000;
        tpzx            : integer := 12000;
        tpxz            : integer := 12000;
        ts              : integer := 9000;
        th              : integer := 0;
        tco             : integer := 10000;
        tco2            : integer := 18000
    );
    port(
        x1              : in     vl_logic;
        x2              : in     vl_logic;
        clk             : in     vl_logic;
        iclk            : in     vl_logic;
        ss              : in     vl_logic;
        sr              : in     vl_logic;
        oe              : in     vl_logic;
        qfb             : out    vl_logic;
        fb              : out    vl_logic;
        y               : inout  vl_logic
    );
end c335m;
