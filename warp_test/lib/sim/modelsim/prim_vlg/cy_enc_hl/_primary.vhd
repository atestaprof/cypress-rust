library verilog;
use verilog.vl_types.all;
entity cy_enc_hl is
    port(
        scd             : in     vl_logic;
        rdin            : in     vl_logic;
        biston          : in     vl_logic;
        hlin            : in     vl_logic_vector(7 downto 0);
        hlout           : out    vl_logic_vector(9 downto 0);
        c21             : out    vl_logic;
        eof             : in     vl_logic;
        rdout           : out    vl_logic
    );
end cy_enc_hl;
