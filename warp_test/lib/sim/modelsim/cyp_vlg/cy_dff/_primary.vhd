library verilog;
use verilog.vl_types.all;
entity cy_dff is
    port(
        d               : in     vl_logic;
        clk             : in     vl_logic;
        q               : out    vl_logic
    );
end cy_dff;
