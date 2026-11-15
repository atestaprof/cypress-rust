library verilog;
use verilog.vl_types.all;
entity cy_encodecmd is
    port(
        din             : in     vl_logic_vector(7 downto 0);
        dout            : out    vl_logic_vector(9 downto 0);
        rdin            : in     vl_logic;
        biston          : in     vl_logic;
        k285_plus       : out    vl_logic;
        k285_minus      : out    vl_logic
    );
end cy_encodecmd;
