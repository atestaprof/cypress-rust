library verilog;
use verilog.vl_types.all;
entity c37koreg is
    generic(
        oregister       : integer := 0;
        source          : integer := 0;
        tclk            : integer := 2000;
        tird            : integer := 500;
        tilat           : integer := 3500;
        tirsu           : integer := 4000;
        tirh            : integer := 0;
        tord            : integer := 1000;
        tocomb          : integer := 0;
        tolat           : integer := 3500;
        torsu           : integer := 1000;
        torh            : integer := 3500;
        tfb             : integer := 0;
        trst            : integer := 4500;
        tpst            : integer := 4500;
        twl             : integer := 2500;
        twh             : integer := 2500;
        trw             : integer := 1000;
        trr             : integer := 10000;
        tpw             : integer := 8000;
        tpr             : integer := 10000;
        tirsupt         : integer := 3500;
        tirhpt          : integer := 1000;
        torsupt         : integer := 2500;
        torhpt          : integer := 2500;
        cksel           : integer := 0
    );
    port(
        as              : in     vl_logic;
        x               : in     vl_logic;
        clk             : in     vl_logic;
        ar              : in     vl_logic;
        fb              : out    vl_logic;
        q               : out    vl_logic
    );
end c37koreg;
