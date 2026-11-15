library verilog;
use verilog.vl_types.all;
entity cy_inv is
    port(
        a               : in     vl_logic;
        y               : out    vl_logic
    );
end cy_inv;
