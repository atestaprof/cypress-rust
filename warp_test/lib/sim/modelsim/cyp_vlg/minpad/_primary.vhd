library verilog;
use verilog.vl_types.all;
entity minpad is
    generic(
        lpm_width       : integer := 1;
        lpm_hint        : integer := 0
    );
    port(
        result          : out    vl_logic_vector;
        pad             : in     vl_logic_vector
    );
end minpad;
