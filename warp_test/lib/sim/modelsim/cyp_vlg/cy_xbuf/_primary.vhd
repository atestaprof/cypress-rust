library verilog;
use verilog.vl_types.all;
entity cy_xbuf is
    port(
        x1              : in     vl_logic;
        x2              : in     vl_logic;
        q               : out    vl_logic
    );
end cy_xbuf;
