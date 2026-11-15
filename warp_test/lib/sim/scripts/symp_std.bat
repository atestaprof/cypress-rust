@echo off
REM
REM	Copyright Cypress Semiconductor, 2001
REM

vhdlp -s -work cypress "%CYPRESS_DIR%\lib\sim\presynth\vhd\cypress.vhd"
vhdlp -s -work cypress "%CYPRESS_DIR%\lib\sim\presynth\vhd\rtlpkg.vhd"
vhdlp -s -work cypress "%CYPRESS_DIR%\lib\sim\presynth\vhd\lpmpkg.vhd"
vhdlp -s -work cypress "%CYPRESS_DIR%\lib\sim\presynth\vhd\sim.vhd"
vhdlp -s -work cypress "%CYPRESS_DIR%\lib\sim\presynth\vhd\ttfctn.vhd"
vhdlp -s -work cypress "%CYPRESS_DIR%\lib\sim\presynth\vhd\int_arith.vhd"
vhdlp -s -work cypress "%CYPRESS_DIR%\lib\sim\presynth\vhd\std_arth.vhd"
vhdlp -s -work cypress "%CYPRESS_DIR%\lib\sim\presynth\vhd\bit_arth.vhd"
vhdlp -s -work cypress "%CYPRESS_DIR%\lib\sim\presynth\vhd\exemplar.vhd"
