library verilog;
use verilog.vl_types.all;
entity c37km is
    generic(
        bsel            : integer := 1;
        ticomb          : integer := 1000;
        tod             : integer := 2000;
        txz             : integer := 5500;
        tzx             : integer := 5500;
        tsl             : integer := 2000;
        slsel           : integer := 0
    );
    port(
        x               : in     vl_logic;
        oe              : in     vl_logic;
        y               : inout  vl_logic;
        fb              : out    vl_logic
    );
end c37km;
