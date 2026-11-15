library verilog;
use verilog.vl_types.all;
entity c16v8m is
    generic(
        registered      : integer := 4;
        inv_setting     : integer := 0;
        bta_sel         : integer := 1;
        tpd             : integer := 10000;
        ten             : integer := 10000;
        tdis            : integer := 10000;
        tco             : integer := 7000;
        tsu             : integer := 7000;
        th              : integer := 0;
        twh             : integer := 8000;
        twl             : integer := 8000;
        tcf             : integer := 6000
    );
    port(
        d               : in     vl_logic;
        clk             : in     vl_logic;
        oe              : in     vl_logic;
        adj             : in     vl_logic;
        y               : inout  vl_logic;
        fb              : out    vl_logic;
        yfb             : out    vl_logic
    );
end c16v8m;
