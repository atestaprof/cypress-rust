library verilog;
use verilog.vl_types.all;
entity c39kcr is
    generic(
        cfgbits         : integer := 0;
        xcrreadaddrwthhi: integer := 100;
        xcrwritaddrwthhi: integer := 100;
        xcrwrienawthhi  : integer := 100;
        xcraddratwrienafallsetup: integer := 100;
        xcraddratwrienarisesetup: integer := 100;
        xcraddratwrienafallhold: integer := 100;
        xcrdinatwrienafallsetup: integer := 100;
        xcrdinatwrienafallhold: integer := 100;
        xcraddr2doutregd: integer := 100;
        xcrwriena2doutregd: integer := 100;
        xcrdin2doutregd : integer := 100;
        xcrdoutregd2dout: integer := 100;
        xcrclkinwthcy   : integer := 100;
        xcrclkinwthhi   : integer := 100;
        xcrclkinwthlo   : integer := 100;
        xcraddratclkinsetup: integer := 100;
        xcraddratclkinhold: integer := 100;
        xcrwrienaatclkinsetup: integer := 100;
        xcrwrienaatclkinhold: integer := 100;
        xcrdinatclkinsetup: integer := 100;
        xcrdinatclkinhold: integer := 100;
        xcrclkin2doutregd: integer := 100;
        xcrdoutregckwthhi: integer := 100;
        xcrdoutregckwthlo: integer := 100;
        xcrdoutregckwthcy: integer := 100;
        xcrdoutregsetup : integer := 100;
        xcrdoutreghold  : integer := 100;
        xcrdoutregrercr : integer := 100;
        xcrdoutregrewthhi: integer := 100;
        xcrclkout2dout  : integer := 100;
        xcrreset2dout   : integer := 100;
        xcraddrtransdetect: integer := 800;
        unk             : string  := " Setting output unknown."
    );
    port(
        din             : in     vl_logic_vector(7 downto 0);
        addr            : in     vl_logic_vector(12 downto 0);
        we              : in     vl_logic;
        iclk            : in     vl_logic;
        oclk            : in     vl_logic;
        reset           : in     vl_logic;
        dout            : out    vl_logic_vector(7 downto 0)
    );
end c39kcr;
