reset halt
sleep 10
flash probe 0
stm32f1x mass_erase 0
sleep 10
flash write_bank 0 main.bin 0
sleep 10
reset run
sleep 10
shutdown
