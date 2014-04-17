###########################################

DEVICE_TYPE = STM32F10X_HD
STARTUP_FILE = stm32f10x_hd
USE_STDPERIPH_DRIVER = -DUSE_STDPERIPH_DRIVER

# Set the external clock frequency
HSE_VALUE = 8000000L

# Enable debug compilation
#DEBUG = 1

STDOUT_USART = 1
STDERR_USART = 1
STDIN_USART = 1

# [OPTIONAL] Uncomment to use the firmware library
FWLIB = lib/libstm32fw.a
FATLIB = FatFS/libFatFs.a

#export DEBUG


TARGET_ARCH = -mcpu=cortex-m3 -mthumb -mlittle-endian
TARGET_OPTS = -O2 -finline -finline-functions-called-once 

INCLUDE_DIRS = -Iinc -Ilib/inc -Ilib/inc/core -Ilib/inc/peripherals -IFatFS/src
LIBRARY_DIRS = -Llib

#F_NO_STRICT_ALIASING = -fno-strict-aliasing

#[OPTIONAL] Uncomment to use the firmware library
DEFINES = -D$(DEVICE_TYPE) -DSTDERR_USART=$(STDERR_USART) -DSTDIN_USART=$(STDIN_USART) -DSTDOUT_USART=$(STDOUT_USART) -DHSE_VALUE=$(HSE_VALUE) $(USE_STDPERIPH_DRIVER)

export DEFINES

COMPILE_OPTS = $(TARGET_ARCH) $(WARNINGS) $(TARGET_OPTS) $(INCLUDE_DIRS) $(DEFINES)
WARNINGS = -Wall -W -Wshadow -Wcast-qual -Wwrite-strings -Winline

ifdef DEBUG
TARGET_OPTS = -O0 -g3
DEBUG_MACRO = -DDEBUG
else
TARGET_OPTS = -O2 $(F_INLINE) $(F_INLINE_ONCE) $(F_UNROLL_LOOPS)
F_INLINE = -finline
F_INLINE_ONCE = -finline-functions-called-once
#F_UNROLL_LOOPS = -funroll-loops
endif

CC=arm-none-eabi-gcc
CFLAGS = -std=gnu99 $(COMPILE_OPTS)

AS = $(CC) -x assembler-with-cpp -c $(TARGET_ARCH)
ASFLAGS = $(COMPILE_OPTS)

LD = $(CC)
LDFLAGS = -Wl,--gc-sections,-Map=$(MAIN_MAP),-cref -T stm32.ld $(INCLUDE_DIRS)\
	   $(LIBRARY_DIRS) $(LIBM)

AR = arm-none-eabi-ar
ARFLAGS = cr

OBJCOPY = arm-none-eabi-objcopy
OBJCOPYFLAGS = -O binary

STARTUP_OBJ = lib/startup_$(STARTUP_FILE).o


MAIN_OUT = main.elf
MAIN_MAP = $(MAIN_OUT:%.elf=%.map)
MAIN_BIN = $(MAIN_OUT:%.elf=%.bin)

MAIN_OBJS = $(sort \
 $(patsubst %.cpp,%.o,$(wildcard src/*.cpp)) \
 $(patsubst %.cc,%.o,$(wildcard src/*.cc)) \
 $(patsubst %.c,%.o,$(wildcard src/*.c)) \
 $(patsubst %.s,%.o,$(wildcard src/*.s)) \
 $(STARTUP_OBJ))

# all
.PHONY: all
all: $(MAIN_BIN)


# main
$(MAIN_OUT): $(MAIN_OBJS) $(FWLIB) $(FATLIB) $(USBLIB)
	$(LD) $(LDFLAGS) $(TARGET_ARCH) $^ -o $@

$(MAIN_OBJS): $(wildcard *.h) $(wildcard inc/*.h)\
	$(wildcard lib/inc/*.h)\
	$(wildcard lib/inc/core/*.h)\
	$(wildcard lib/inc/peripherals/*.h)\
	$(wildcard lib/STM32_USB-FS-Device_Driver/inc/*.h)

$(MAIN_BIN): $(MAIN_OUT)
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@

# fwlib
.PHONY: fwlib
fwlib: $(FWLIB)

$(FWLIB): $(wildcard lib/inc/*.h) $(wildcard lib/core/*.h) \
	  $(wildcard lib/inc/peripherals/*.h)
	@cd lib && $(MAKE)
      
#fatlib
.PHONY: fatlib
fatlib: $(FATLIB)

$(FATLIB): $(wildcard inc/*.h) $(wildcard lib/inc/*.h) $(wildcard lib/core/*.h) \
	  $(wildcard lib/inc/peripherals/*.h)
	@cd FatFS && $(MAKE)

# flash-bin
.PHONY: flash-bin
flash-bin: all
	@openocd -f jlink.cfg -f stm32f1x.cfg -c "init" -c "script stm32_flash.tcl"

#clean
.PHONY: clean
clean:
	-rm -f $(MAIN_OBJS) $(MAIN_OUT) $(MAIN_MAP) $(MAIN_BIN)
#	-rm -rf cscope.* tags
	@cd lib && $(MAKE) clean
	@cd FatFS && $(MAKE) clean
