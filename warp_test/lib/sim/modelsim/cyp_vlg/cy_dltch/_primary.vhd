library verilog;
use verilog.vl_types.all;
entity cy_dltch is
    port(
        d               : in     vl_logic;
        e               : in     vl_logic;
        q               : out    vl_logic
    );
end cy_dltch;
