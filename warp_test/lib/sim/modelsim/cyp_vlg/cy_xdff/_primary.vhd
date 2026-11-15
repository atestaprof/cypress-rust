library verilog;
use verilog.vl_types.all;
entity cy_xdff is
    port(
        x1              : in     vl_logic;
        x2              : in     vl_logic;
        clk             : in     vl_logic;
        q               : out    vl_logic
    );
end cy_xdff;
