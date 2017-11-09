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
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

TARGET = c1m2
CPPFLAGS = -Wall -Werror -g -O0 -std=c99 -D$(PLATFORM)

# Platform Overrides

ifeq ($(PLATFORM), MSP432)

# Architectures Specific Flags
	LINKER_FILE = ../msp432p401r.lds 
	CPU = cortex-m4
	ARCH = thumb
	SPECS = nosys.specs
	ARMARCH = armv7e-m
	FPU = fpv4-sp-d16
	FLOAT-ABI = hard

# Compiler Flags and Defines
	CC = arm-none-eabi-gcc 
	LD = arm-none-eabi-ld 
	LDFLAGS = -Wl, -Map=$(TARGET).map -T $(LINKER_FILE)
	CFLAGS = -mcpu=$(CPU) -m$(ARCH) -march=$(ARMARCH) -mfpu=$(FPU) -mfloat-abi=$(FLOAT-ABI) --specs=$(SPECS)
	
endif 

ifeq ($(PLATFORM),HOST)

# Architecture Specific Flags
	ARCH:= $(shell arch)

# Compiler Flags and Defines
	CC = gcc
	LD = ld
	LDFLAGS = -Wl, -Map=$(TARGET).map
	CFLAGS =   
endif

OBJS = $(SRCS: .c = .o)

%.o : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

%.i : %.c
	$(CC) $(CPPFLAGS) -I$(INCLUDES) -E $< -o $@

#%.asm : %.o

.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(OBJS) -c -o $@

.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map 
