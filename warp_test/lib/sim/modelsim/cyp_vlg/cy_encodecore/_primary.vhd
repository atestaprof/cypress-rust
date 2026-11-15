library verilog;
use verilog.vl_types.all;
entity cy_encodecore is
    port(
        txdata          : in     vl_logic_vector(11 downto 0);
        rxcksel         : in     vl_logic;
        txmode          : in     vl_logic_vector(1 downto 0);
        txclko          : in     vl_logic;
        resetb          : in     vl_logic;
        alignbuf        : out    vl_logic;
        parity_dis      : out    vl_logic;
        txper           : out    vl_logic;
        fifoerr         : in     vl_logic;
        par_err         : in     vl_logic;
        txchar          : in     vl_logic_vector(1 downto 0);
        txfiforst       : out    vl_logic;
        bist            : in     vl_logic;
        txcode          : out    vl_logic_vector(9 downto 0)
    );
end cy_encodecore;
