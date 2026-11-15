#
#	Copyright Cypress Semiconductor, 2001
#

opendesign $VLIB\primitive\primitive
setlibrarymode -rw primitive
clearlibrary primitive
vcom primitive.vhd
setlibrarymode -ro primitive
