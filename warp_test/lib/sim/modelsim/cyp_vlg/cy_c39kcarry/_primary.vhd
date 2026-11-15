library verilog;
use verilog.vl_types.all;
entity cy_c39kcarry is
    port(
        selin           : in     vl_logic;
        cpt0            : in     vl_logic;
        cpt1            : in     vl_logic;
        selout          : out    vl_logic
    );
end cy_c39kcarry;
