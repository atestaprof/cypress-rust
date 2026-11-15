library verilog;
use verilog.vl_types.all;
entity cy_dpram10x13 is
    port(
        data_in         : in     vl_logic_vector(12 downto 0);
        read_address    : in     vl_logic_vector(9 downto 0);
        write_address   : in     vl_logic_vector(9 downto 0);
        data_out        : out    vl_logic_vector(12 downto 0);
        read_clock      : in     vl_logic;
        write_clock     : in     vl_logic;
        reset           : in     vl_logic
    );
end cy_dpram10x13;
