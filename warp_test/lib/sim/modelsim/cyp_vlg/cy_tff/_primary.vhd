library verilog;
use verilog.vl_types.all;
entity cy_tff is
    port(
        t               : in     vl_logic;
        clk             : in     vl_logic;
        q               : out    vl_logic
    );
end cy_tff;
