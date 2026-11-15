library ieee;
use ieee.std_logic_1164.all;

entity mux_when is
    port (
        sel : in  std_logic_vector(1 downto 0);
        d0  : in  std_logic;
        d1  : in  std_logic;
        d2  : in  std_logic;
        d3  : in  std_logic;
        y   : out std_logic
    );
end mux_when;

architecture rtl of mux_when is
begin
    y <= d0 when sel = "00" else
         d1 when sel = "01" else
         d2 when sel = "10" else
         d3;
end rtl;
