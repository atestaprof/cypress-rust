library verilog;
use verilog.vl_types.all;
entity mgnd is
    generic(
        lpm_width       : integer := 1
    );
    port(
        x               : out    vl_logic_vector
    );
end mgnd;
