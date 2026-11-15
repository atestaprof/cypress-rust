library verilog;
use verilog.vl_types.all;
entity c34xexp is
    generic(
        tin             : integer := 7000;
        texp            : integer := 14000;
        tpia            : integer := 16000;
        tlac            : integer := 12000;
        tlad            : integer := 14000;
        tic             : integer := 16000;
        tics            : integer := 2000;
        tclr            : integer := 6000;
        tpre            : integer := 6000;
        trsu            : integer := 8000;
        trh             : integer := 8000;
        tcomb           : integer := 4000;
        tlatch          : integer := 4000;
        trd             : integer := 2000;
        tio             : integer := 6000;
        tod             : integer := 5000;
        txz             : integer := 11000;
        tzx             : integer := 11000;
        tfd             : integer := 1000;
        tpcw            : integer := 6000;
        tpcr            : integer := 6000;
        tch             : integer := 10000;
        tcl             : integer := 10000
    );
    port(
        x               : in     vl_logic;
        expsrc          : in     vl_logic;
        exp             : in     vl_logic;
        fb              : out    vl_logic
    );
end c34xexp;
