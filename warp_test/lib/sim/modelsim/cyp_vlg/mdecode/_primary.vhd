library verilog;
use verilog.vl_types.all;
entity mdecode is
    generic(
        lpm_width       : integer := 1;
        lpm_decodes     : integer := 1;
        lpm_hint        : integer := 0
    );
    port(
        data            : in     vl_logic_vector;
        enable          : in     vl_logic;
        eq              : out    vl_logic_vector
    );
end mdecode;
