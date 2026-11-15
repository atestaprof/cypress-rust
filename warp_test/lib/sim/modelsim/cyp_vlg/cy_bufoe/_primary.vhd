library verilog;
use verilog.vl_types.all;
entity cy_bufoe is
    port(
        x               : in     vl_logic;
        oe              : in     vl_logic;
        y               : inout  vl_logic;
        yfb             : out    vl_logic
    );
end cy_bufoe;
