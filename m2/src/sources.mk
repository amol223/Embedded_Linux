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

ifeq ($(PLATFORM),HOST)
# Add your Source files to this variable
	SOURCES = main.c    \
	  	  memory.c  \

# Add your include paths to this variable
	INCLUDES = /home/amol/Embedded_Systems_Linux/m2/include/common
endif

ifeq ($(PLATFORM),MSP432)
# Add your Source files to this variable
	SOURCES = main.c    \
	  	  memory.c  \
		  interrupts_msp432p401r_gcc.c \
		  system_msp432p401r.c \
		  startup_msp432p401r_gcc.c \

# Add your include paths to this variable
	INCLUDES_COMMON = /home/amol/Embedded_Systems_Linux/m2/include/common	
	INCLUDES_CMSIS = /home/amol/Embedded_Systems_Linux/m2/include/CMSIS
	INCLUDES_MSP432 = /home/amol/Embedded_Systems_Linux/m2/include/msp432
	INCLUDES = $(INCLUDES_COMMON) -I$(INCLUDES_CMSIS) -I$(INCLUDES_MSP432)
endif

