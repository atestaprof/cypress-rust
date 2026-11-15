library verilog;
use verilog.vl_types.all;
entity c20r is
    generic(
        tpd             : integer := 25000;
        tea             : integer := 25000;
        ter             : integer := 25000;
        tpzx            : integer := 20000;
        tpxz            : integer := 20000;
        tco             : integer := 15000;
        ts              : integer := 20000;
        th              : integer := 0;
        tw              : integer := 15000
    );
    port(
        d               : in     vl_logic;
        oe              : in     vl_logic;
        clk             : in     vl_logic;
        y               : out    vl_logic;
        qfb             : out    vl_logic
    );
end c20r;
