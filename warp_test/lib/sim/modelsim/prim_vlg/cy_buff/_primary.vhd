library verilog;
use verilog.vl_types.all;
entity cy_buff is
    port(
        read_data       : out    vl_logic_vector(12 downto 0);
        read_pointer    : out    vl_logic_vector(9 downto 0);
        write_pointer   : out    vl_logic_vector(9 downto 0);
        write_eitherrun : out    vl_logic;
        read_overrun    : out    vl_logic;
        read_underrun   : out    vl_logic;
        insert_sync     : out    vl_logic;
        delete_sync     : out    vl_logic;
        write_data      : in     vl_logic_vector(12 downto 0);
        saved_read_pointer: in     vl_logic_vector(3 downto 0);
        load_read_pointer: in     vl_logic;
        remove_data_from_fifo: in     vl_logic;
        not_bonded_mode : in     vl_logic;
        read_enable     : in     vl_logic;
        reset           : in     vl_logic;
        read_clock      : in     vl_logic;
        write_clock     : in     vl_logic
    );
end cy_buff;
