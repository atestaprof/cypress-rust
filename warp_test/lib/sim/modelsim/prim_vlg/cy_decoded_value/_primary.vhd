library verilog;
use verilog.vl_types.all;
entity cy_decoded_value is
    port(
        input_port      : in     vl_logic_vector(9 downto 0);
        output_port     : out    vl_logic_vector(7 downto 0);
        invalid_data    : out    vl_logic;
        rd_vio          : out    vl_logic;
        currd           : in     vl_logic
    );
end cy_decoded_value;
