## -*- Makefile -*-
##
## User: pesho
## Time: Jan 25, 2020 5:26:23 PM
## Makefile created by Oracle Solaris Studio.
##
## This file is generated automatically.
##

# HEX_FILEPATH.. Relative to project root path to the .HEX file which
#		 is flashed to the MCU
# DEVICE........ The AVR device this project compiles for
# PROGRAMMER.... Options to avrdude to define the programming hardware
# FUSES......... Parameters for avrdude to flash the fuses appropriately

HEX_FILEPATH	:= dist/default/production/DFGv2-Firmware.X.production.hex
DEVICE		:= m328p
PROGRAMMER	:= -c usbasp -P /dev/tty.usb* -b 19200
FUSES		:= -U lfuse:w:0xff:m -U hfuse:w:0x99:m -U efuse:w:0xff:m

# AVRDUDE ...... avrdude command to program the MCU
AVRDUDE		:= avrdude $(PROGRAMMER) -p $(DEVICE)

all: flash

## Target: flash
# Flash the built .HEX file to the microcontroller's flash program memory.
flash: $(HEX_FILEPATH)
	$(AVRDUDE) -U flash:w:$(HEX_FILEPATH):i

## Target: fuse
# Set the fuse bytes of the specified AVR MCU.
# WARNING: ALWAYS double-check fuse byte values before attempting to set the
#	   fuse memory bytes of a real AVR MCU. Mistakes may lead to incorrect
#	   program/microcontroller behavior, as well as "bricking" the programmed
#	   device (i.e. to become unresponsive and unmodifiable).
fuse: 
	$(AVRDUDE) $(FUSES)

#### Clean target deletes all generated files ####
clean:

# Enable dependency checking
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-amd64-Linux

