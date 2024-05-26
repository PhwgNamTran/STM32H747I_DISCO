TARGET = STM32H747XI_GPIO

# Define the linker script location and chip architecture.
LD_SCRIPT = Linker_STM32H747_CM7.ld
MCU_SPEC  = cortex-m7

# Define the source, header and startup file.
C_SOURCES   = $(shell find . -name "*.c")
ASM_SOURCES = $(shell find . -name "*.S")
HEADERS		= $(shell find . -name "*.h")

#Define the output folder.
BUILD_DIR   = Build

# ARM Toolchain definitions
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OC = arm-none-eabi-objcopy
OD = arm-none-eabi-objdump
OS = arm-none-eabi-size
DB = arm-none-eabi-gdb

# Assembly directives.
ASFLAGS += -c
ASFLAGS += -O0
ASFLAGS += -mcpu=$(MCU_SPEC)
ASFLAGS += -mthumb
ASFLAGS += -Wall
# (Set error messages to appear on a single line.)
ASFLAGS += -fmessage-length=0

# C compilation directives
CFLAGS += -mcpu=$(MCU_SPEC)
CFLAGS += -mthumb
CFLAGS += -Wall
CFLAGS += -g
# (Set error messages to appear on a single line.)
CFLAGS += -fmessage-length=0
# (Set system to ignore semihosted junk)
CFLAGS += --specs=nosys.specs

# Linker directives.
LSCRIPT = ./$(LD_SCRIPT)
LFLAGS += -mcpu=$(MCU_SPEC)
LFLAGS += -mthumb
LFLAGS += -Wall
LFLAGS += --specs=nosys.specs
LFLAGS += -nostdlib
LFLAGS += -lgcc
LFLAGS += -T$(LSCRIPT)

INCLUDES = $(sort $(foreach dir,$(dir $(HEADERS)),-I$(dir)))

OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.S=.o)))
vpath %.S $(sort $(dir $(ASM_SOURCES)))

OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))

$(BUILD_DIR)/%.o: %.S | $(BUILD_DIR)
	$(CC) -x assembler-with-cpp $(ASFLAGS) $< -o $@

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) | $(BUILD_DIR)
	$(CC) $^ $(LFLAGS) -o $@

$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(OC) -S -O binary $< $@
	$(OS) $<

$(BUILD_DIR):
	mkdir $@

.PHONY: all
all: $(BUILD_DIR)/$(TARGET).bin

.PHONY: clean
clean:
	-rm -fr $(BUILD_DIR)

.PHONY: openocd
openocd:
	openocd -f stm32h747i-disco.cfg

.PHONY: gdb
gdb: $(BUILD_DIR)/$(TARGET).elf
	$(DB) --eval-command="target extended-remote: 3333" $<