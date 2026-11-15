#
#	Copyright Cypress Semiconductor, 2001
#

opendesign $VLIB\cypress\cypress
setlibrarymode -rw cypress
addfile N:\synth\lib\common\cy_15g04serdes.vhd
acom cy_15g04serdes.vhd
removefile cy_15g04serdes.vhd
setlibrarymode -ro cypress

opendesign $VLIB\primitive\primitive
setlibrarymode -rw primitive
addfile N:\synth\lib\common\c15g04serdes.vhd
acom c15g04serdes.vhd
removefile c15g04serdes.vhd
setlibrarymode -ro primitive

opendesign $VLIB\cypress_verilog\cypress_verilog
setlibrarymode -rw cypress_verilog
addfile N:\synth\lib\common\cy_15g04serdes.v
addfile N:\synth\lib\common\cy_9294.v
vlcomp cy_15g04serdes.v
removefile cy_15g04serdes.v
removefile cy_9294.v
setlibrarymode -ro cypress_verilog

opendesign $VLIB\ovi_cypress\ovi_cypress
setlibrarymode -rw ovi_cypress
addfile N:\synth\lib\common\c15g04serdes.v
addfile N:\synth\lib\common\cy_9294.v
vlcomp c15g04serdes.v
removefile c15g04serdes.v
removefile cy_9294.v
setlibrarymode -ro ovi_cypress

