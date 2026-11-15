library verilog;
use verilog.vl_types.all;
entity c39kmc is
    generic(
        cfgbits         : integer := 2052;
        xlbregsetup     : integer := 100;
        xlbreghold      : integer := 100;
        xlbregckwthhi   : integer := 100;
        xlbregckwthlo   : integer := 100;
        xlbregckwthcy   : integer := 400;
        xlbregprrcr     : integer := 100;
        xlbregprwthhi   : integer := 100;
        xlbregrercr     : integer := 100;
        xlbregrewthhi   : integer := 100;
        xlbselin2selout : integer := 100;
        xlbcpt2selout   : integer := 100;
        xlbcpt2regd     : integer := 100;
        xlbeqn2regd     : integer := 100;
        xlbselin2regd   : integer := 100;
        xlbregq2regd    : integer := 100;
        xlbregd2topim   : integer := 100;
        xlbregck2topim  : integer := 100;
        xlbregpr2topim  : integer := 100;
        xlbregre2topim  : integer := 100;
        unk             : string  := " Setting output unknown."
    );
    port(
        selin           : in     vl_logic;
        cpt             : in     vl_logic_vector(1 downto 0);
        set             : in     vl_logic;
        clr             : in     vl_logic;
        clk             : in     vl_logic;
        din             : in     vl_logic;
        selout          : out    vl_logic;
        qout            : out    vl_logic
    );
end c39kmc;
