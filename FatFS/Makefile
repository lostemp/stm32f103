###########################################

DEVICE_TYPE = STM32F10X_HD
USE_STDPERIPH_DRIVER = -DUSE_STDPERIPH_DRIVER

# Set the external clock frequency
# HSE_VALUE = 8000000L

TARGET_ARCH = -mcpu=cortex-m3 -mthumb -mlittle-endian
TARGET_OPTS = -O2 -finline -finline-functions-called-once 
WARNINGS = -Wall -W -Wshadow -Wwrite-strings -Winline
INCLUDE_DIRS = -Isrc -I../inc -I../lib/inc -I../lib/inc/core -I../lib/inc/peripherals
F_NO_STRICT_ALIASING = -fno-strict-aliasing

#[OPTIONAL] Uncomment to use the firmware library
DEFINES = -D$(DEVICE_TYPE) $(USE_STDPERIPH_DRIVER) -DHSE_VALUE=$(HSE_VALUE)

COMPILE_OPTS = $(TARGET_ARCH) $(WARNINGS) $(TARGET_OPTS) $(INCLUDE_DIRS) $(DEFINES) $(F_NO_STRICT_ALIASING)

CC=arm-none-eabi-gcc
CFLAGS = $(COMPILE_OPTS)

AR=arm-none-eabi-ar
ARFLAGS = cr

LIB_OUT = libFatFs.a

LIB_OBJS = $(sort \
	   $(patsubst %.c,%.o,$(wildcard src/*.c)))

.PHONY: all
all: $(LIB_OUT)

$(LIB_OUT): $(LIB_OBJS)
	$(AR) $(ARFLAGS) $@ $(LIB_OBJS)

$(LIB_OBJS): $(wildcard *.h) $(wildcard src/*.h)

.PHONY: clean
clean:
	rm -f $(LIB_OBJS) $(LIB_OUT)
