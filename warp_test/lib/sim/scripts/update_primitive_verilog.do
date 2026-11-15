#
#	Copyright Cypress Semiconductor, 2001
#

opendesign $VLIB\ovi_cypress\ovi_cypress
setlibrarymode -rw ovi_cypress
clearlibrary ovi_cypress
vlcomp primitive.vlg
setlibrarymode -ro ovi_cypress
