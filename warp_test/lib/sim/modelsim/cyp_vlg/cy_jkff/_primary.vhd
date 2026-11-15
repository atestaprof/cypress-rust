library verilog;
use verilog.vl_types.all;
entity cy_jkff is
    port(
        j               : in     vl_logic;
        k               : in     vl_logic;
        clk             : in     vl_logic;
        q               : out    vl_logic
    );
end cy_jkff;
