library verilog;
use verilog.vl_types.all;
entity cy_buf is
    port(
        x               : in     vl_logic;
        y               : out    vl_logic
    );
end cy_buf;
