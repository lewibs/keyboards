Follow these instructions using this qmk to compile.
Do i need to use this qmk? can i use the other one?

https://github.com/lewibs/vial-qmk/blob/vial/keyboards/explorerkb/blank/readme.md

STEPS:
Using the right plug
Using vial-qmk
```
source ~/qmk-vial-venv/bin/activate
qmk flash -c -kb explorerkb/blankrgb/mcu/rp2040 -km default
update file - /keyboards/explorerkb/blankrgb/keymaps/default/keymap.c
```
