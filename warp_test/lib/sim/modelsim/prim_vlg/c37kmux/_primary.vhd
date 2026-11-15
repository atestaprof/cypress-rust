library verilog;
use verilog.vl_types.all;
entity c37kmux is
    generic(
        tsop            : integer := 4500
    );
    port(
        x               : in     vl_logic;
        fb              : out    vl_logic
    );
end c37kmux;
