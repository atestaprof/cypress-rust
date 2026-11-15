library verilog;
use verilog.vl_types.all;
entity mbuf is
    generic(
        lpm_width       : integer := 1;
        lpm_hint        : integer := 0
    );
    port(
        data            : in     vl_logic_vector;
        result          : out    vl_logic_vector
    );
end mbuf;
