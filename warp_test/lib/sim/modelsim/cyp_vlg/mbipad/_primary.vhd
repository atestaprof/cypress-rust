library verilog;
use verilog.vl_types.all;
entity mbipad is
    generic(
        lpm_width       : integer := 1;
        lpm_hint        : integer := 0
    );
    port(
        data            : in     vl_logic_vector;
        enable          : in     vl_logic;
        result          : out    vl_logic_vector;
        pad             : inout  vl_logic_vector
    );
end mbipad;
