library verilog;
use verilog.vl_types.all;
entity mmult is
    generic(
        lpm_widtha      : integer := 1;
        lpm_widthb      : integer := 1;
        lpm_widths      : integer := 0;
        lpm_widthp      : integer := 2;
        lpm_representation: integer := 1;
        lpm_hint        : integer := 0;
        lpm_avalue      : string  := "NULL"
    );
    port(
        dataa           : in     vl_logic_vector;
        datab           : in     vl_logic_vector;
        sum             : in     vl_logic_vector;
        result          : out    vl_logic_vector
    );
end mmult;
