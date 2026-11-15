library verilog;
use verilog.vl_types.all;
entity cy_triout is
    port(
        x               : in     vl_logic;
        oe              : in     vl_logic;
        y               : out    vl_logic
    );
end cy_triout;
