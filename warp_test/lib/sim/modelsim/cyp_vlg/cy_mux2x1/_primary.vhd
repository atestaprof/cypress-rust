library verilog;
use verilog.vl_types.all;
entity cy_mux2x1 is
    port(
        a0              : in     vl_logic;
        a1              : in     vl_logic;
        s               : in     vl_logic;
        y               : out    vl_logic
    );
end cy_mux2x1;
