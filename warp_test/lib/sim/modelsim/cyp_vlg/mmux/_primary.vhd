library verilog;
use verilog.vl_types.all;
entity mmux is
    generic(
        lpm_width       : integer := 1;
        lpm_size        : integer := 1;
        lpm_widths      : integer := 1;
        lpm_hint        : integer := 0
    );
    port(
        data            : in     vl_logic_vector;
        sel             : in     vl_logic_vector;
        result          : out    vl_logic_vector
    );
end mmux;
