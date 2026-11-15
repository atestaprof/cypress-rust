library verilog;
use verilog.vl_types.all;
entity c39kcm is
    generic(
        cfgbits         : integer := 0;
        xcmreadaddrwthhi: integer := 100;
        xcmwritaddrwthhi: integer := 100;
        xcmwrienawthhi  : integer := 100;
        xcmaddratwrienafallsetup: integer := 100;
        xcmaddratwrienarisesetup: integer := 100;
        xcmaddratwrienafallhold: integer := 100;
        xcmdinatwrienafallsetup: integer := 100;
        xcmdinatwrienafallhold: integer := 100;
        xcmaddr2doutregd: integer := 100;
        xcmwriena2doutregd: integer := 100;
        xcmdin2doutregd : integer := 100;
        xcmdoutregd2dout: integer := 100;
        xcmclkinwthcy   : integer := 100;
        xcmclkinwthhi   : integer := 100;
        xcmclkinwthlo   : integer := 100;
        xcmaddratclkinsetup: integer := 100;
        xcmaddratclkinhold: integer := 100;
        xcmwrienaatclkinsetup: integer := 100;
        xcmwrienaatclkinhold: integer := 100;
        xcmdinatclkinsetup: integer := 100;
        xcmdinatclkinhold: integer := 100;
        xcmclkin2doutregd: integer := 100;
        xcmdoutregckwthcy: integer := 100;
        xcmdoutregckwthhi: integer := 100;
        xcmdoutregckwthlo: integer := 100;
        xcmdoutregsetup : integer := 100;
        xcmdoutreghold  : integer := 100;
        xcmdoutregrewthhi: integer := 100;
        xcmdoutregrercr : integer := 100;
        xcmreset2dout   : integer := 100;
        xcmclkout2dout  : integer := 100;
        xcmaddrtransdetect: integer := 800;
        unk             : string  := " Setting output unknown."
    );
    port(
        din_a           : in     vl_logic_vector(7 downto 0);
        din_b           : in     vl_logic_vector(7 downto 0);
        addr_a          : in     vl_logic_vector(11 downto 0);
        addr_b          : in     vl_logic_vector(11 downto 0);
        we_a            : in     vl_logic;
        we_b            : in     vl_logic;
        iclk_a          : in     vl_logic;
        iclk_b          : in     vl_logic;
        oclk_a          : in     vl_logic;
        oclk_b          : in     vl_logic;
        reset_a         : in     vl_logic;
        reset_b         : in     vl_logic;
        addr_matchb     : out    vl_logic;
        dout_a          : out    vl_logic_vector(7 downto 0);
        dout_b          : out    vl_logic_vector(7 downto 0)
    );
end c39kcm;
