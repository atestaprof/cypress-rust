library verilog;
use verilog.vl_types.all;
entity cy_softbuffer is
    port(
        bufin           : in     vl_logic;
        bufout          : out    vl_logic
    );
end cy_softbuffer;
