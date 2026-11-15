library ieee;
use ieee.std_logic_1164.all;
use work.cypress.all;

entity gal_native is
    port (
        a : in  std_logic;
        b : in  std_logic;
        y : out std_logic
    );
    attribute pin_numbers of gal_native : entity is "a:13 b:10 y:2";
end gal_native;

architecture rtl of gal_native is
begin
    y <= a and b;
end rtl;
