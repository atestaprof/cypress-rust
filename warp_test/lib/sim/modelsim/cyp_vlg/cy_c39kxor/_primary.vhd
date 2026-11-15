library verilog;
use verilog.vl_types.all;
entity cy_c39kxor is
    port(
        sin             : in     vl_logic;
        ptmpts          : in     vl_logic;
        xorout          : out    vl_logic
    );
end cy_c39kxor;
