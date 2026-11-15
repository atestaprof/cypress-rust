library verilog;
use verilog.vl_types.all;
entity c20tri is
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
        x               : in     vl_logic;
        oe              : in     vl_logic;
        y               : out    vl_logic
    );
end c20tri;
