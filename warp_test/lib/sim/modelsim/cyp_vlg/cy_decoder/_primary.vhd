library verilog;
use verilog.vl_types.all;
entity cy_decoder is
    port(
        output_port     : out    vl_logic_vector(10 downto 0);
        framing_symbol  : out    vl_logic;
        bist_framing_symbol: out    vl_logic;
        next_char_valid : out    vl_logic;
        input_port      : in     vl_logic_vector(9 downto 0);
        rxcksel         : in     vl_logic;
        framchar        : in     vl_logic;
        oolin           : in     vl_logic;
        decmode         : in     vl_logic;
        rxmode          : in     vl_logic_vector(1 downto 0);
        bist_enable     : in     vl_logic;
        clock           : in     vl_logic;
        resetb          : in     vl_logic
    );
end cy_decoder;
