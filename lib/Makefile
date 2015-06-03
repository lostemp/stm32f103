###########################################

DEVICE_TYPE = STM32F10X_HD
USE_STDPERIPH_DRIVER = -DUSE_STDPERIPH_DRIVER

# Set the external clock frequency
HSE_VALUE = 8000000L

TARGET_ARCH = -mcpu=cortex-m3 -mthumb -mlittle-endian -gdwarf-2 -mno-thumb-interwork
TARGET_OPTS = -O2 -finline -finline-functions-called-once 
WARNINGS = -Wall -W -Wshadow -Wwrite-strings -Winline
INCLUDE_DIRS = -Iinc -Iinc/core -Iinc/peripherals
F_NO_STRICT_ALIASING = -fno-strict-aliasing

#[OPTIONAL] Uncomment to use the firmware library
DEFINES = -D$(DEVICE_TYPE) $(USE_STDPERIPH_DRIVER) -DHSE_VALUE=$(HSE_VALUE)

COMPILE_OPTS = $(TARGET_ARCH) $(WARNINGS) $(TARGET_OPTS) $(INCLUDE_DIRS) $(DEFINES) $(F_NO_STRICT_ALIASING)

CC=arm-none-eabi-gcc
CFLAGS = $(COMPILE_OPTS)

AR=arm-none-eabi-ar
###ARFLAGS = -mcpu=cortex-m3
###ARFLAGS = ar -mcpu=cortex-m3

LIB_OUT = libstm32fw.a

LIB_OBJS = $(sort \
	   $(patsubst %.c,%.o,$(wildcard src/*.c)) \
	   $(patsubst %.c,%.o,$(wildcard src/peripherals/*.c)) \
	   $(patsubst %.c,%.o,$(wildcard inc/core/*.c)) \
	   $(patsubst %.s,%.o,$(wildcard src/*.s)))

.PHONY: all
all: $(LIB_OUT)

$(LIB_OUT): $(LIB_OBJS)
	$(AR) $(ARFLAGS) $@ $(LIB_OBJS)

$(LIB_OBJS): $(wildcard *.h) $(wildcard inc/*.h) \
	$(wildcard inc/core/*.h) $(wildcard inc/peripherals/*.h)

.PHONY: clean
clean:
	rm -f $(LIB_OBJS) $(LIB_OUT)
