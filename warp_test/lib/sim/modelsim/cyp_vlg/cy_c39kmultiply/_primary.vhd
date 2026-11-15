library verilog;
use verilog.vl_types.all;
entity cy_c39kmultiply is
    generic(
        issigned        : integer := 0;
        datawidtha      : integer := 1;
        datawidthb      : integer := 1;
        datawidthp      : integer := 2;
        hint            : integer := 3
    );
    port(
        data_a          : in     vl_logic_vector;
        data_b          : in     vl_logic_vector;
        product         : out    vl_logic_vector
    );
end cy_c39kmultiply;
