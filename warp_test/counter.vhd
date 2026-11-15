library ieee;
use ieee.std_logic_1164.all;

entity counter is
    port (
        clk   : in  std_logic;
        en    : in  std_logic;
        count : out std_logic_vector(3 downto 0)
    );
end counter;

architecture rtl of counter is
    signal cnt : std_logic_vector(3 downto 0);
begin
    process (clk)
    begin
        if rising_edge(clk) then
            if en = '1' then
                cnt(0) <= not cnt(0);
                cnt(1) <= cnt(1) xor cnt(0);
                cnt(2) <= cnt(2) xor (cnt(1) and cnt(0));
                cnt(3) <= cnt(3) xor (cnt(2) and cnt(1) and cnt(0));
            end if;
        end if;
    end process;

    count <= cnt;
end rtl;
