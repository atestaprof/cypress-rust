library verilog;
use verilog.vl_types.all;
entity c335ireg is
    generic(
        iregister       : integer := 4;
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
        d               : in     vl_logic;
        iclk            : in     vl_logic;
        fb              : out    vl_logic
    );
end c335ireg;
