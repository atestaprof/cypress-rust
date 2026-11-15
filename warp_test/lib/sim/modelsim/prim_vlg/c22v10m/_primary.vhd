library verilog;
use verilog.vl_types.all;
entity c22v10m is
    generic(
        registered      : integer := 4;
        inv_setting     : integer := 0;
        bta_sel         : integer := 1;
        tpd             : integer := 10000;
        tea             : integer := 10000;
        ter             : integer := 10000;
        tco             : integer := 7500;
        ts              : integer := 3600;
        th              : integer := 0;
        twh             : integer := 3000;
        twl             : integer := 3000;
        tcf             : integer := 6400;
        taw             : integer := 10000;
        tar             : integer := 6000;
        tap             : integer := 12000;
        tspr            : integer := 6000
    );
    port(
        d               : in     vl_logic;
        clk             : in     vl_logic;
        oe              : in     vl_logic;
        ss              : in     vl_logic;
        ar              : in     vl_logic;
        y               : inout  vl_logic;
        fb              : out    vl_logic
    );
end c22v10m;
