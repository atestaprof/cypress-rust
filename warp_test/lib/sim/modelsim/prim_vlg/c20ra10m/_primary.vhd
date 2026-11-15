library verilog;
use verilog.vl_types.all;
entity c20ra10m is
    generic(
        ibr             : integer := 0;
        tpd             : integer := 15000;
        tpzx            : integer := 12000;
        tpxz            : integer := 12000;
        tco             : integer := 15000;
        tsu             : integer := 7000;
        th              : integer := 3000;
        twh             : integer := 10000;
        twl             : integer := 10000;
        ts              : integer := 15000;
        tr              : integer := 15000;
        tarw            : integer := 15000;
        tasw            : integer := 15000;
        tar             : integer := 10000;
        twp             : integer := 15000;
        tsup            : integer := 15000;
        thp             : integer := 15000
    );
    port(
        d               : in     vl_logic;
        clk             : in     vl_logic;
        oe              : in     vl_logic;
        pl              : in     vl_logic;
        as              : in     vl_logic;
        ar              : in     vl_logic;
        y               : inout  vl_logic;
        yfb             : out    vl_logic
    );
end c20ra10m;
