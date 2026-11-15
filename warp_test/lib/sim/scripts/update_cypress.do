#
#	Copyright Cypress Semiconductor, 2001
#

opendesign $VLIB\cypress\cypress
setlibrarymode -rw cypress
clearlibrary cypress
runexe -wait N:\synth\lib\sim\scripts\cyp.bat
vcom cypress.vhd
vcom rtlpkg.vhd
vcom lpmpkg.vhd
vcom sim.vhd
vcom ttfctn.vhd
vcom int_arith.vhd
vcom std_arth.vhd
vcom bit_arth.vhd
vcom exemplar.vhd
vcom cygates.vhd
setlibrarymode -ro cypress
