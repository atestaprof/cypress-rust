library verilog;
use verilog.vl_types.all;
entity c39kcf is
    generic(
        cfgbits         : integer := 0;
        xcmfclockwthcy  : integer := 100;
        xcmfclockwthhi  : integer := 100;
        xcmfclockwthlo  : integer := 100;
        xcmfdinatclkwrsetup: integer := 100;
        xcmfdinatclkwrhold: integer := 100;
        xcmfenxatclocksetup: integer := 100;
        xcmfenxatclockhold: integer := 100;
        xcmfefbinatclkrdsetup: integer := 100;
        xcmfefbinatclkrdhold: integer := 100;
        xcmfhfbinatclkrdsetup: integer := 100;
        xcmfhfbinatclkrdhold: integer := 100;
        xcmfefbinatclkwrsetup: integer := 100;
        xcmfefbinatclkwrhold: integer := 100;
        xcmfhfbinatclkwrsetup: integer := 100;
        xcmfhfbinatclkwrhold: integer := 100;
        xcmfmrbwthlo    : integer := 100;
        xcmfmrbrcr      : integer := 100;
        xcmfrdwrskewefb : integer := 100;
        xcmfrdwrskewhfb : integer := 100;
        xcmfrdwrskewpafeb: integer := 100;
        xcmfdoutregrewthhi: integer := 100;
        xcmfdoutregrercr: integer := 100;
        xcmfclkwr2flagout: integer := 100;
        xcmfclkrd2flagout: integer := 100;
        xcmfmrb2output  : integer := 100;
        xcmfclock2dout  : integer := 100;
        xcmfreset2dout  : integer := 100;
        unk             : string  := " Setting output unknown.";
        write2read_skew1: string  := "Write to read skew insufficient for current cycle empty/full update.";
        write2read_skew2: string  := "Write to read skew insufficient for current cycle almost empty update";
        read2write_skew2: string  := "Read to write skew insufficient for current cycle half full update.";
        read2write_skew3: string  := "Read to write skew insufficient for current cycle almost full update.";
        refflag_setup   : string  := "Read clock to E/F flag setup violation.";
        refflag_hold    : string  := "E/F flag to read clock hold violation.";
        rhfflag_setup   : string  := "Read clock to H/F flag setup violation.";
        rhfflag_hold    : string  := "H/F flag to read clock hold violation.";
        wefflag_setup   : string  := "Write clock to E/F flag setup violation.";
        wefflag_hold    : string  := "E/F flag to write clock hold violation.";
        whfflag_setup   : string  := "Write clock to H/F flag setup violation.";
        whfflag_hold    : string  := "H/F flag to write clock hold violation."
    );
    port(
        din             : in     vl_logic_vector(7 downto 0);
        dout            : inout  vl_logic_vector(7 downto 0);
        enr             : in     vl_logic;
        enw             : in     vl_logic;
        ckr             : in     vl_logic;
        ckw             : in     vl_logic;
        mrb             : in     vl_logic;
        efb             : inout  vl_logic;
        hfb             : inout  vl_logic;
        pafeb           : out    vl_logic
    );
end c39kcf;
