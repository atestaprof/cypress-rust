library verilog;
use verilog.vl_types.all;
entity cy_dsrffe is
    port(
        d               : in     vl_logic;
        s               : in     vl_logic;
        r               : in     vl_logic;
        e               : in     vl_logic;
        clk             : in     vl_logic;
        q               : out    vl_logic
    );
end cy_dsrffe;
