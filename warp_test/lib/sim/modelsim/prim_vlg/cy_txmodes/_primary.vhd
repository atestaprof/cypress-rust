library verilog;
use verilog.vl_types.all;
entity cy_txmodes is
    port(
        bist            : in     vl_logic;
        txct            : in     vl_logic_vector(1 downto 0);
        txcta0          : in     vl_logic;
        txctb0          : in     vl_logic;
        txctalt         : in     vl_logic;
        txmode          : in     vl_logic_vector(1 downto 0);
        rxmode          : in     vl_logic_vector(1 downto 0);
        scsel           : in     vl_logic;
        txchar          : out    vl_logic_vector(1 downto 0);
        chanid          : in     vl_logic_vector(1 downto 0)
    );
end cy_txmodes;
