library verilog;
use verilog.vl_types.all;
entity cy_framer is
    generic(
        pk28_5          : integer := 773;
        nk28_5          : integer := 250;
        mask1           : integer := 1023;
        mask2           : integer := 1020;
        pcomma          : integer := 772;
        ncomma          : integer := 248
    );
    port(
        output_port     : out    vl_logic_vector(9 downto 0);
        slipsync        : out    vl_logic;
        odd_even        : out    vl_logic;
        input_port      : in     vl_logic_vector(9 downto 0);
        framchar        : in     vl_logic;
        rfen            : in     vl_logic;
        rfmode          : in     vl_logic;
        clock           : in     vl_logic;
        resetb          : in     vl_logic;
        decmode         : in     vl_logic;
        rxrate          : in     vl_logic
    );
end cy_framer;
