library verilog;
use verilog.vl_types.all;
entity c37xoreg is
    generic(
        oregister       : integer := 0;
        source          : integer := 0;
        tclk            : integer := 4000;
        tird            : integer := 1000;
        ticomb          : integer := 3000;
        tilat           : integer := 5500;
        tirsu           : integer := 6000;
        tirh            : integer := 2000;
        tsop            : integer := 1500;
        tord            : integer := 1000;
        tocomb          : integer := 3000;
        tolat           : integer := 5500;
        torsu           : integer := 4500;
        torh            : integer := 0;
        tod             : integer := 1000;
        txz             : integer := 8500;
        tzx             : integer := 8500;
        tfb             : integer := 0;
        trst            : integer := 8500;
        tpst            : integer := 8500;
        twl             : integer := 2500;
        twh             : integer := 2500;
        trw             : integer := 8000;
        trr             : integer := 10000;
        tpw             : integer := 8000;
        tpr             : integer := 10000;
        tvcco           : integer := 0
    );
    port(
        as              : in     vl_logic;
        x               : in     vl_logic;
        clk             : in     vl_logic;
        ar              : in     vl_logic;
        fb              : out    vl_logic;
        q               : out    vl_logic
    );
end c37xoreg;
