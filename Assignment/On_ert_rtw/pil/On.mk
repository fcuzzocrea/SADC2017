###########################################################################
## Makefile generated for Simulink model 'On'. 
## 
## Makefile     : On.mk
## Generated on : Wed Nov 28 13:44:11 2018
## MATLAB Coder version: 4.1 (R2018b)
## 
## Build Info:
## 
## Final product: ./On.elf
## Product type : executable
## Build type   : Top-Level Standalone Executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPUTER                Computer type. See the MATLAB "computer" command.

PRODUCT_NAME              = On
MAKEFILE                  = On.mk
COMPUTER                  = GLNXA64
MATLAB_ROOT               = /opt/mathworks/MATLAB/R2018b
MATLAB_BIN                = /opt/mathworks/MATLAB/R2018b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/glnxa64
MASTER_ANCHOR_DIR         = 
START_DIR                 = /home/fcuzzocrea/Documenti/Progetti/SADC2017/Assignment
ARCH                      = glnxa64
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = None
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ../..
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Arduino ARM v1.8.1 | gmake (64-bit Linux)
# Supported Version(s):    
# ToolchainInfo Version:   R2018b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# ARDUINO_ROOT
# ARDUINO_PACKAGES_TOOLS_ROOT
# ARDUINO_PORT
# ARDUINO_MCU
# ARDUINO_BAUD
# ARDUINO_PROTOCOL
# ARDUINO_F_CPU

#-----------
# MACROS
#-----------

PRODUCT_HEX                 = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).hex
PRODUCT_BIN                 = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).bin
ARDUINO_TOOLS               = $(ARDUINO_PACKAGES_TOOLS_ROOT)/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -Wl,--end-group -lm -gcc

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: Arduino ARM Assembler
AS_PATH = $(ARDUINO_TOOLS)
AS = $(AS_PATH)/arm-none-eabi-gcc

# C Compiler: Arduino ARM C Compiler
CC_PATH = $(ARDUINO_TOOLS)
CC = $(CC_PATH)/arm-none-eabi-gcc

# Linker: Arduino ARM Linker
LD_PATH = $(ARDUINO_TOOLS)
LD = $(LD_PATH)/arm-none-eabi-gcc

# C++ Compiler: Arduino ARM C++ Compiler
CPP_PATH = $(ARDUINO_TOOLS)
CPP = $(CPP_PATH)/arm-none-eabi-g++

# C++ Linker: Arduino ARM C++ Linker
CPP_LD_PATH = $(ARDUINO_TOOLS)
CPP_LD = $(CPP_LD_PATH)/arm-none-eabi-gcc

# Archiver: Arduino ARM Archiver
AR_PATH = $(ARDUINO_TOOLS)
AR = $(AR_PATH)/arm-none-eabi-ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = $(MEX_PATH)/mex

# Binary Converter: Binary Converter
OBJCOPY_PATH = $(ARDUINO_PACKAGES_TOOLS_ROOT)/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin
OBJCOPY = $(OBJCOPY_PATH)/arm-none-eabi-objcopy

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/glnxa64
MAKE = $(MAKE_PATH)/gmake


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = -o
CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @rm -f
ECHO                = @echo
MV                  = @mv
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
ASFLAGS              = -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -Wall \
                       -x assembler-with-cpp \
                       $(ASFLAGS_ADDITIONAL) \
                       $(DEFINES) \
                       $(INCLUDES) \
                       -c
OBJCOPYFLAGS_BIN     = -O binary $(PRODUCT) $(PRODUCT_BIN)
CFLAGS               = -std=gnu11 \
                       -Os \
                       -c \
                       -g \
                       -w \
                       -ffunction-sections \
                       -fdata-sections  \
                       -nostdlib  \
                       --param max-inline-insns-single=500  \
                       -Dprintf=iprintf  \
                       -DARDUINO=10801  \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@" 
CPPFLAGS             = -std=gnu++11 -fno-threadsafe-statics -fno-rtti -fno-exceptions  \
                       -Os \
                       -c \
                       -g \
                       -w \
                       -ffunction-sections \
                       -fdata-sections  \
                       -nostdlib  \
                       --param max-inline-insns-single=500  \
                       -Dprintf=iprintf  \
                       -DARDUINO=10801  \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@" 
CPP_LDFLAGS          =  -Os -Wl,-Map="$(PRODUCT_NAME).map" -Wl,--gc-sections
CPP_SHAREDLIB_LDFLAGS  =
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =  -Os -Wl,-Map="$(PRODUCT_NAME).map" -Wl,--gc-sections
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    =

#--------------------
# File extensions
#--------------------

ASM_Type1_Ext       = .S
DEP_EXT             = .dep
OBJ_EXT             = .S.o
ASM_EXT             = .s
C_DEP               = .dep
H_EXT               = .h
OBJ_EXT             = .o
C_EXT               = .c
EXE_EXT             = .elf
SHAREDLIB_EXT       = .so
CXX_EXT             = .cxx
C_DEP               = .dep
HPP_EXT             = .hpp
OBJ_EXT             = .o
CPP_EXT             = .cpp
UNIX_TYPE1_EXT      = .cc
UNIX_TYPE2_EXT      = .C
EXE_EXT             =
SHAREDLIB_EXT       =
STATICLIB_EXT       = .a
MEX_EXT             = .mexa64
MAKE_EXT            = .mk


###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./On.elf
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(START_DIR)/On_ert_rtw -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(ARDUINO_SAM_ROOT)/hardware/sam/1.6.11/system/libsam -I$(ARDUINO_SAM_ROOT)/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include -I$(ARDUINO_SAM_ROOT)/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL -I$(ARDUINO_SAM_ROOT)/hardware/sam/1.6.11/cores/arduino -I$(ARDUINO_SAM_ROOT)/hardware/sam/1.6.11/cores/arduino/avr -I$(ARDUINO_SAM_ROOT)/hardware/sam/1.6.11/variants/arduino_due_x -I/home/fcuzzocrea/.matlab/SupportPackages/R2018B/toolbox/target/supportpackages/arduinotarget/include -I/home/fcuzzocrea/.matlab/SupportPackages/R2018B/toolbox/target/supportpackages/arduinotarget/scheduler/include -I/home/fcuzzocrea/.matlab/SupportPackages/R2018B/toolbox/target/supportpackages/arduinobase/include -I/home/fcuzzocrea/.matlab/SupportPackages/R2018B/toolbox/target/shared/externalmode_daemon/include -I$(MATLAB_ROOT)/toolbox/rtw/targets/pil/c -I$(START_DIR)/On_ert_rtw/pil -I$(MATLAB_ROOT)/extern/include/coder/connectivity/XILTgtAppSvc -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils -I$(MATLAB_ROOT)/extern/include/coder/connectivity/CoderAssumpTgtAppSvc -I$(START_DIR)/On_ert_rtw/coderassumptions -I/home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/system/libsam -I/home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include -I/home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL -I/home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino -I/home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -DMODEL=On -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DUNIX -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 -DEXIT_FAILURE=1 -DEXTMODE_DISABLEPRINTF -DEXTMODE_DISABLETESTING -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -DSTACK_SIZE=64 -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DRT -DMW_TIMERID=9 -DMW_TIMERCOUNT=656250 -DMW_SAM_CLOCKID=TC_CMR_TCCLKS_TIMER_CLOCK4 -D_RTT_BAUDRATE_SERIAL0_=9600 -D_RTT_BAUDRATE_SERIAL1_=9600 -D_RTT_BAUDRATE_SERIAL2_=9600 -D_RTT_BAUDRATE_SERIAL3_=9600 -D_RTT_ANALOG_REF_=0 -DCODER_ASSUMPTIONS_ENABLED=1 -DRTIOSTREAM_RX_BUFFER_BYTE_SIZE=128 -DRTIOSTREAM_TX_BUFFER_BYTE_SIZE=128 -DMEM_UNIT_BYTES=1 -DMemUnit_T=uint8_T -DMW_PIL_SERIAL_BAUDRATE=115200 -DMW_PIL_ARUDINOSERIAL
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0
DEFINES_IMPLIED = -DTID01EQ=0
DEFINES_OPTS = -DCODER_ASSUMPTIONS_ENABLED=1 -DRTIOSTREAM_RX_BUFFER_BYTE_SIZE=128 -DRTIOSTREAM_TX_BUFFER_BYTE_SIZE=128 -DMEM_UNIT_BYTES=1 -DMemUnit_T=uint8_T
DEFINES_SKIPFORSIL = -DEXIT_FAILURE=1 -DEXTMODE_DISABLEPRINTF -DEXTMODE_DISABLETESTING -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -DSTACK_SIZE=64 -DRT
DEFINES_STANDARD = -DMODEL=On -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DUNIX

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_IMPLIED) $(DEFINES_OPTS) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/xil_interface_lib.c $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/xil_data_stream.c $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/xil_services.c $(START_DIR)/On_ert_rtw/pil/xil_interface.c $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/xilcomms_rtiostream.c $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/xil_rtiostream.c $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/rtiostream_utils.c $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/coder_assumptions_app.c $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/coder_assumptions_data_stream.c $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/coder_assumptions_rtiostream.c /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/cortex_handlers.c /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/hooks.c /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/iar_calls_sam3.c /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/itoa.c /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/syscalls_sam3.c /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/WInterrupts.c /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/wiring.c /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/wiring_analog.c /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/wiring_digital.c /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/wiring_shift.c /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/abi.cpp /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/IPAddress.cpp /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/new.cpp /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/Print.cpp /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/Reset.cpp /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/RingBuffer.cpp /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/Stream.cpp /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/UARTClass.cpp /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/USARTClass.cpp /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/wiring_pulse.cpp /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/WMath.cpp /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/WString.cpp /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/watchdog.cpp /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/avr/dtostrf.c /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/USB/CDC.cpp /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/USB/PluggableUSB.cpp /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/USB/USBCore.cpp /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x/variant.cpp /home/fcuzzocrea/.matlab/SupportPackages/R2018B/toolbox/target/supportpackages/arduinobase/src/io_wrappers.cpp /home/fcuzzocrea/.matlab/SupportPackages/R2018B/toolbox/target/supportpackages/arduinotarget/src/MW_ArduinoHWInit.cpp /home/fcuzzocrea/.matlab/SupportPackages/R2018B/toolbox/target/supportpackages/arduinobase/src/MW_arduino_digitalio.cpp /home/fcuzzocrea/.matlab/SupportPackages/R2018B/toolbox/target/supportpackages/arduinotarget/src/rtiostream_serial.cpp /home/fcuzzocrea/.matlab/SupportPackages/R2018B/toolbox/target/supportpackages/arduinotarget/src/pil_main_arduino.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = xil_interface_lib.o xil_data_stream.o xil_services.o xil_interface.o xilcomms_rtiostream.o xil_rtiostream.o rtiostream_utils.o coder_assumptions_app.o coder_assumptions_data_stream.o coder_assumptions_rtiostream.o cortex_handlers.o hooks.o iar_calls_sam3.o itoa.o syscalls_sam3.o WInterrupts.o wiring.o wiring_analog.o wiring_digital.o wiring_shift.o abi.o IPAddress.o new.o Print.o Reset.o RingBuffer.o Stream.o UARTClass.o USARTClass.o wiring_pulse.o WMath.o WString.o watchdog.o dtostrf.o CDC.o PluggableUSB.o USBCore.o variant.o io_wrappers.o MW_ArduinoHWInit.o MW_arduino_digitalio.o rtiostream_serial.o pil_main_arduino.o

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

MODELREF_LIBS = ../On.o ../On_data.o ../rtGetInf.o ../rtGetNaN.o ../rt_nonfinite.o

LIBS = $(START_DIR)/On_ert_rtw/coderassumptions/lib/On_ca.a

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_SKIPFORSIL = -MD -mcpu=cortex-m3 -fpermissive -DF_CPU=84000000L -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON -DUSB_MANUFACTURER=\""Unknown\"" -DUSB_PRODUCT=\""Arduino Due\"" -D_RUNONTARGETHARDWARE_BUILD_ -D_ROTH_DUE_
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_SKIPFORSIL = -MD -mcpu=cortex-m3 -fpermissive -DF_CPU=84000000L -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON -DUSB_MANUFACTURER=\""Unknown\"" -DUSB_PRODUCT=\""Arduino Due\"" -D_RUNONTARGETHARDWARE_BUILD_ -D_ROTH_DUE_
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_SKIPFORSIL = -T$(ARDUINO_SAM_ROOT)/hardware/sam/1.6.11/variants/arduino_due_x/linker_scripts/gcc/flash.ld -mcpu=cortex-m3 -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group $(ARDUINO_SAM_ROOT)/hardware/sam/1.6.11/variants/arduino_due_x/libsam_sam3x8e_gcc_rel.a

CPP_LDFLAGS += $(CPP_LDFLAGS_SKIPFORSIL)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = -T$(ARDUINO_SAM_ROOT)/hardware/sam/1.6.11/variants/arduino_due_x/linker_scripts/gcc/flash.ld -mcpu=cortex-m3 -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group $(ARDUINO_SAM_ROOT)/hardware/sam/1.6.11/variants/arduino_due_x/libsam_sam3x8e_gcc_rel.a

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)

#-----------
# Linker
#-----------

LDFLAGS_SKIPFORSIL = -T$(ARDUINO_SAM_ROOT)/hardware/sam/1.6.11/variants/arduino_due_x/linker_scripts/gcc/flash.ld -mcpu=cortex-m3 -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group $(ARDUINO_SAM_ROOT)/hardware/sam/1.6.11/variants/arduino_due_x/libsam_sam3x8e_gcc_rel.a

LDFLAGS += $(LDFLAGS_SKIPFORSIL)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_SKIPFORSIL = -T$(ARDUINO_SAM_ROOT)/hardware/sam/1.6.11/variants/arduino_due_x/linker_scripts/gcc/flash.ld -mcpu=cortex-m3 -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group $(ARDUINO_SAM_ROOT)/hardware/sam/1.6.11/variants/arduino_due_x/libsam_sam3x8e_gcc_rel.a

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_SKIPFORSIL)

###########################################################################
## INLINED COMMANDS
###########################################################################


DERIVED_SRCS = $(subst .o,.dep,$(OBJS))

build:

%.dep:



-include codertarget_assembly_flags.mk
-include *.dep


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild postbuild download execute


all : build postbuild
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(MODELREF_LIBS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


postbuild : build
	@echo "### Invoking postbuild tool "Binary Converter" ..."
	$(OBJCOPY) $(OBJCOPYFLAGS_BIN)
	@echo "### Done invoking postbuild tool."


download : postbuild


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(MODELREF_LIBS) $(LIBS)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(CPP_LD) $(CPP_LDFLAGS) -o $(PRODUCT) $(OBJS) ../On.o ../On_data.o ../rtGetInf.o ../rtGetNaN.o ../rt_nonfinite.o $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o $@ $<


%.S.o : %.s
	$(AS) $(ASFLAGS) -o $@ $<


%.S.o : %.S
	$(AS) $(ASFLAGS) -o $@ $<


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : %.cc
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : %.C
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : %.cxx
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.S.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.S.o : $(RELATIVE_PATH_TO_ANCHOR)/%.S
	$(AS) $(ASFLAGS) -o $@ $<


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cc
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.C
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cxx
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.S.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.S.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.S
	$(AS) $(ASFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.cc
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.C
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.cxx
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.S.o : $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.S.o : $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/%.S
	$(AS) $(ASFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/%.cc
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/%.C
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/%.cxx
	$(CPP) $(CPPFLAGS) -o $@ $<


xil_interface.o : $(START_DIR)/On_ert_rtw/pil/xil_interface.c
	$(CC) $(CFLAGS) -o $@ $<


cortex_handlers.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/cortex_handlers.c
	$(CC) $(CFLAGS) -o $@ $<


hooks.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/hooks.c
	$(CC) $(CFLAGS) -o $@ $<


iar_calls_sam3.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/iar_calls_sam3.c
	$(CC) $(CFLAGS) -o $@ $<


itoa.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/itoa.c
	$(CC) $(CFLAGS) -o $@ $<


syscalls_sam3.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/syscalls_sam3.c
	$(CC) $(CFLAGS) -o $@ $<


WInterrupts.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/WInterrupts.c
	$(CC) $(CFLAGS) -o $@ $<


wiring.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/wiring.c
	$(CC) $(CFLAGS) -o $@ $<


wiring_analog.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/wiring_analog.c
	$(CC) $(CFLAGS) -o $@ $<


wiring_digital.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/wiring_digital.c
	$(CC) $(CFLAGS) -o $@ $<


wiring_shift.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/wiring_shift.c
	$(CC) $(CFLAGS) -o $@ $<


abi.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/abi.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


IPAddress.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/IPAddress.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


new.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/new.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


Print.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/Print.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


Reset.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/Reset.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


RingBuffer.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/RingBuffer.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


Stream.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/Stream.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


UARTClass.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/UARTClass.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


USARTClass.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/USARTClass.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


wiring_pulse.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/wiring_pulse.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


WMath.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/WMath.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


WString.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/WString.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


watchdog.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/watchdog.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


dtostrf.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/avr/dtostrf.c
	$(CC) $(CFLAGS) -o $@ $<


CDC.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/USB/CDC.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


PluggableUSB.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/USB/PluggableUSB.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


USBCore.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/cores/arduino/USB/USBCore.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


variant.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/3P.instrset/arduinoide.instrset/idepkgs/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x/variant.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


io_wrappers.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/toolbox/target/supportpackages/arduinobase/src/io_wrappers.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


MW_ArduinoHWInit.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/toolbox/target/supportpackages/arduinotarget/src/MW_ArduinoHWInit.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


MW_arduino_digitalio.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/toolbox/target/supportpackages/arduinobase/src/MW_arduino_digitalio.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


rtiostream_serial.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/toolbox/target/supportpackages/arduinotarget/src/rtiostream_serial.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


pil_main_arduino.o : /home/fcuzzocrea/.matlab/SupportPackages/R2018B/toolbox/target/supportpackages/arduinotarget/src/pil_main_arduino.c
	$(CC) $(CFLAGS) -o $@ $<


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### ASFLAGS = $(ASFLAGS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### OBJCOPYFLAGS_BIN = $(OBJCOPYFLAGS_BIN)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(RM) *.dep
	$(ECHO) "### Deleted all derived files."


