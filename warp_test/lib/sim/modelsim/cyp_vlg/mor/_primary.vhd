library verilog;
use verilog.vl_types.all;
entity mor is
    generic(
        lpm_width       : integer := 1;
        lpm_size        : integer := 1;
        lpm_hint        : integer := 0;
        lpm_data_pol    : string  := "NULL";
        lpm_result_pol  : string  := "NULL"
    );
    port(
        data            : in     vl_logic_vector;
        result          : out    vl_logic_vector
    );
end mor;
