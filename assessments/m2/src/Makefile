#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile for the second assignement in the course  the Introduction to Embedded
# Systems Software and Development Environments specialization
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <File>.o : builds <File> object file
#      <File>.asm : builds <File> assembly file
#      <File>.i : builds <File> preprocessor file
#      compile-all : compiles all object files without linking
#	   build : builds and links all source files
#      clean : remove all generated files
#
# Platform Overrides:
#      CPU : ARM Cortex Architecture (cortex-m0plus, cortex-m4)
#      ARCH : ARM Architecture (arm, thumb)
#      SPECS : specs files to give to the linker (nosys.specs, nano.specs)
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
ifndef PLATFORM
PLATFORM = HOST
else
PLATFORM = $(PLATFORM)
endif

# Architectures Specific Flags
LINKER_FILE = 
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs
FLOATABI = hard
FPU = fpv4-sp-d16

# Compiler Flags and Defines
BASENAME = c1m2
TARGET = $(BASENAME).out
CFLAGS = -Wall \
	 	 -Werror \
		 -g \
		 -O0 \
		 -std=c99 \
		 -D$(PLATFORM)
LDFLAGS = -Wl,-Map=$(BASENAME).map
ifeq ($(PLATFORM),HOST)
	CC := gcc
else
	CC := arm-none-eabi-gcc
	CFLAGS += --specs=$(SPECS)
	CFLAGS +=  -mcpu=$(CPU)
	CFLAGS +=  -mthumb
	CFLAGS +=  -march=$(ARCH)
	CFLAGS +=  -mfloat-abi=$(FLOATABI)
	CFLAGS +=  -mfpu=$(FPU)
	CFLAGS +=  -T ../msp432p401r.lds
endif
ifeq ($(PLATFORM),HOST)
	LD = $(LD)
else
	LD = arm-none-eabi-ld
endif
#CPPFLAGs = 

OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)

%.i: %.c
	$(CC) -E $^ $(CFLAGS) $(INCLUDES) -o $@
%.asm: %.o
	objdump -S --disassemble $^ > $@
%.o: %.c
	$(CC) -c  $^ $(CFLAGS) $(INCLUDES) -o $@
	
.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@
	
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) $(BASENAME).map *.i *.asm
	