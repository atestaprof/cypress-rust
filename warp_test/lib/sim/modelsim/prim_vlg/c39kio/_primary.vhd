library verilog;
use verilog.vl_types.all;
entity c39kio is
    generic(
        cfgbits         : integer := 0;
        xioclockwthhi   : integer := 100;
        xioclockwthlo   : integer := 100;
        xioclockwthcy   : integer := 100;
        xioresetrcr     : integer := 100;
        xioresetwthhi   : integer := 100;
        xioioregsetup   : integer := 100;
        xioioreghold    : integer := 100;
        xioioregensup   : integer := 100;
        xioioregenhld   : integer := 100;
        xiooeregsetup   : integer := 100;
        xiooereghold    : integer := 100;
        xiofromchip2pin : integer := 100;
        xiofromchip2ioregd: integer := 100;
        xioioregck2pin  : integer := 100;
        xioioregre2pin  : integer := 100;
        xioioregre2tochip: integer := 100;
        xiooeregck2pinea: integer := 100;
        xiooeregck2piner: integer := 100;
        xiooeregre2piner: integer := 100;
        xiooutena2pinea : integer := 100;
        xiooutena2piner : integer := 100;
        xiopin2ioregd   : integer := 100;
        xioioregck2tochip: integer := 100;
        xiopin2tochip   : integer := 100;
        xioaddoslow     : integer := 100;
        xioaddeaslow    : integer := 100;
        xioadderslow    : integer := 100;
        xioadd          : integer := 100;
        unk             : string  := " Setting output unknown."
    );
    port(
        oe              : in     vl_logic;
        din             : in     vl_logic;
        en              : in     vl_logic;
        clk             : in     vl_logic;
        clr             : in     vl_logic;
        fb              : out    vl_logic;
        iop             : inout  vl_logic
    );
end c39kio;
