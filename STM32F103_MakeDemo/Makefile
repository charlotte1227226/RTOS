# Toolchain
CC        = arm-none-eabi-gcc
OBJCOPY   = arm-none-eabi-objcopy

# MCU 設定
CPU       = cortex-m3
FPU       =
FLOAT-ABI = soft

# 啟動與 linker
STARTUP_SRC   = startup_stm32f10x.s
LINKER_SCRIPT = stm32f103xb_flash.ld

# include 路徑
INCLUDES = \
  -I. \
  -I../../FreeRTOS/Source/include \
  -I../../FreeRTOS/Source/portable/GCC/ARM_CM3 \
  -I./stm32_driver/inc

# 編譯旗標
CFLAGS = -mcpu=$(CPU) -mthumb \
         -std=gnu11 -Wall -g \
         $(INCLUDES)

LDFLAGS = -T$(LINKER_SCRIPT) \
          -Wl,--gc-sections

# Source files
SRCS = \
  main.c \
  syscalls.c \
  ../../FreeRTOS/Source/tasks.c \
  ../../FreeRTOS/Source/queue.c \
  ../../FreeRTOS/Source/list.c \
  ../../FreeRTOS/Source/heap_2.c \
  ../../FreeRTOS/Source/portable/GCC/ARM_CM3/port.c \
  ../../FreeRTOS/Source/portable/GCC/ARM_CM3/portmacro.h

OBJS = $(SRCS:.c=.o)

# Default target
all: main.bin

# Link
main.elf: $(OBJS) $(STARTUP_SRC:.s=.o)
	$(CC) $(CFLAGS) $(OBJS) $(STARTUP_SRC:.s=.o) $(LDFLAGS) -o $@
	$(OBJCOPY) -O binary $@ main.bin

# Compile C
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Assemble startup
startup_stm32f10x.o: startup_stm32f10x.s
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o main.elf main.bin

.PHONY: all clean
