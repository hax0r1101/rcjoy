#Generated by VisualGDB (http://visualgdb.com)
#DO NOT EDIT THIS FILE MANUALLY UNLESS YOU ABSOLUTELY NEED TO
#USE VISUALGDB PROJECT PROPERTIES DIALOG INSTEAD

BINARYDIR := Release_P407

#Additional flags
PREPROCESSOR_MACROS := NDEBUG RELEASE HSE_VALUE=8000000 USE_USB_OTG_FS PORT407 STMF407VG
INCLUDE_DIRS :=
LIBRARY_DIRS :=
LIBRARY_NAMES :=
ADDITIONAL_LINKER_INPUTS :=
MACOS_FRAMEWORKS :=

CFLAGS := -ggdb -ffunction-sections -O3 -fno-exceptions
CXXFLAGS := -ggdb -ffunction-sections -fno-exceptions -O3
ASFLAGS :=
LDFLAGS := -Wl,-gc-sections
COMMONFLAGS :=

START_GROUP := -Wl,--start-group
END_GROUP := -Wl,--end-group

#Additional options detected from testing the toolchain
USE_DEL_TO_CLEAN := 1
CP_NOT_AVAILABLE := 1

#ADDITIONAL_MAKE_FILES := stm32.mak
GENERATE_BIN_FILE := 1

BSP_ROOT := D:\Sergey\projects\Arduino\RCJoy\STM32F407DISC_RC_JOY
TOOLCHAIN_ROOT := D:/SysGCC/arm-eabi

#Embedded toolchain
CC := C:/SysGCC/arm-eabi/bin/arm-eabi-gcc.exe
CXX := C:/SysGCC/arm-eabi/bin/arm-eabi-g++.exe
LD := $(CXX)
AR := C:/SysGCC/arm-eabi/bin/arm-eabi-ar.exe
OBJCOPY := C:/SysGCC/arm-eabi/bin/arm-eabi-objcopy.exe

#Additional flags
PREPROCESSOR_MACROS += ARM_MATH_CM4 stm32_flash_layout STM32F407VG STM32F40XX
INCLUDE_DIRS += $(BSP_ROOT)/STM32F4xxxx/CMSIS/Device/ST/STM32F4xx/Include $(BSP_ROOT)/STM32F4xxxx/CMSIS/Include $(BSP_ROOT)/STM32F4xxxx/CMSIS/RTOS $(BSP_ROOT)/STM32F4xxxx/STM32F4xx_StdPeriph_Driver/inc
LIBRARY_DIRS += 
LIBRARY_NAMES += 
ADDITIONAL_LINKER_INPUTS += 
MACOS_FRAMEWORKS += 

CFLAGS += -mcpu=cortex-m4 -mthumb
CXXFLAGS += -mcpu=cortex-m4 -mthumb
ASFLAGS += -mcpu=cortex-m4 -mthumb
LDFLAGS += -mcpu=cortex-m4 -mthumb  -T$(BSP_ROOT)/STM32F4xxxx/LinkerScripts/STM32F407xG_flash.lds
COMMONFLAGS += 

