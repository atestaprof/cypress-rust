library verilog;
use verilog.vl_types.all;
entity c20g10m is
    generic(
        registered      : integer := 4;
        inv_setting     : integer := 1;
        bta_sel         : integer := 1;
        tpd             : integer := 25000;
        tpzx            : integer := 20000;
        tpxz            : integer := 20000;
        tco             : integer := 15000;
        ts              : integer := 15000;
        th              : integer := 0;
        twh             : integer := 12000;
        twl             : integer := 12000
    );
    port(
        d               : in     vl_logic;
        clk             : in     vl_logic;
        oe              : in     vl_logic;
        y               : inout  vl_logic;
        fb              : out    vl_logic
    );
end c20g10m;
