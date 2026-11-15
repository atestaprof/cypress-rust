library ieee;
use ieee.std_logic_1164.all;

entity decoder_proc is
    port (
        en  : in  std_logic;
        sel : in  std_logic_vector(1 downto 0);
        y0  : out std_logic;
        y1  : out std_logic;
        y2  : out std_logic;
        y3  : out std_logic
    );
end decoder_proc;

architecture rtl of decoder_proc is
begin
    process (en, sel)
    begin
        y0 <= '0';
        y1 <= '0';
        y2 <= '0';
        y3 <= '0';
        if en = '1' then
            case sel is
                when "00" => y0 <= '1';
                when "01" => y1 <= '1';
                when "10" => y2 <= '1';
                when others => y3 <= '1';
            end case;
        elsif en = '0' then
            y0 <= '0';
        else
            y0 <= '0';
        end if;
    end process;
end rtl;
