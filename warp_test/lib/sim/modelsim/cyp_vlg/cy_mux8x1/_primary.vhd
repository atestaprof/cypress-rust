library verilog;
use verilog.vl_types.all;
entity cy_mux8x1 is
    port(
        a0              : in     vl_logic;
        a1              : in     vl_logic;
        a2              : in     vl_logic;
        a3              : in     vl_logic;
        a4              : in     vl_logic;
        a5              : in     vl_logic;
        a6              : in     vl_logic;
        a7              : in     vl_logic;
        s0              : in     vl_logic;
        s1              : in     vl_logic;
        s2              : in     vl_logic;
        y               : out    vl_logic
    );
end cy_mux8x1;
