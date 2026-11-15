#
#	Copyright Cypress Semiconductor, 2001
#

opendesign $VLIB\cypress_verilog\cypress_verilog
setlibrarymode -rw cypress_verilog
clearlibrary cypress_verilog
runexe -wait N:\synth\lib\sim\scripts\cypvlg.bat
vlcomp rtl.v
vlcomp lpm.v
vlcomp cygates.v
setlibrarymode -ro cypress_verilog
