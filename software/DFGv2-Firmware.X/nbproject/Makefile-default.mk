#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/DFGv2-Firmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/DFGv2-Firmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=src/main.c src/init_mcu.c src/twi_driver.c src/avr_controllers/spi_controller.c src/lcd-driver/lcd-driver.c src/lcd-driver/graphics.c src/touch-panel-driver/touch-panel-driver.c src/user-interface/ui_button.c src/user-interface/ui_main_menu.c src/user-interface/ui_helper.c src/user-interface/ui_options_menu.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/init_mcu.o ${OBJECTDIR}/src/twi_driver.o ${OBJECTDIR}/src/avr_controllers/spi_controller.o ${OBJECTDIR}/src/lcd-driver/lcd-driver.o ${OBJECTDIR}/src/lcd-driver/graphics.o ${OBJECTDIR}/src/touch-panel-driver/touch-panel-driver.o ${OBJECTDIR}/src/user-interface/ui_button.o ${OBJECTDIR}/src/user-interface/ui_main_menu.o ${OBJECTDIR}/src/user-interface/ui_helper.o ${OBJECTDIR}/src/user-interface/ui_options_menu.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/main.o.d ${OBJECTDIR}/src/init_mcu.o.d ${OBJECTDIR}/src/twi_driver.o.d ${OBJECTDIR}/src/avr_controllers/spi_controller.o.d ${OBJECTDIR}/src/lcd-driver/lcd-driver.o.d ${OBJECTDIR}/src/lcd-driver/graphics.o.d ${OBJECTDIR}/src/touch-panel-driver/touch-panel-driver.o.d ${OBJECTDIR}/src/user-interface/ui_button.o.d ${OBJECTDIR}/src/user-interface/ui_main_menu.o.d ${OBJECTDIR}/src/user-interface/ui_helper.o.d ${OBJECTDIR}/src/user-interface/ui_options_menu.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/init_mcu.o ${OBJECTDIR}/src/twi_driver.o ${OBJECTDIR}/src/avr_controllers/spi_controller.o ${OBJECTDIR}/src/lcd-driver/lcd-driver.o ${OBJECTDIR}/src/lcd-driver/graphics.o ${OBJECTDIR}/src/touch-panel-driver/touch-panel-driver.o ${OBJECTDIR}/src/user-interface/ui_button.o ${OBJECTDIR}/src/user-interface/ui_main_menu.o ${OBJECTDIR}/src/user-interface/ui_helper.o ${OBJECTDIR}/src/user-interface/ui_options_menu.o

# Source Files
SOURCEFILES=src/main.c src/init_mcu.c src/twi_driver.c src/avr_controllers/spi_controller.c src/lcd-driver/lcd-driver.c src/lcd-driver/graphics.c src/touch-panel-driver/touch-panel-driver.c src/user-interface/ui_button.c src/user-interface/ui_main_menu.c src/user-interface/ui_helper.c src/user-interface/ui_options_menu.c

# Pack Options 
PACK_COMPILER_OPTIONS=-I ${DFP_DIR}/include
PACK_COMMON_OPTIONS=-B ${DFP_DIR}/gcc/dev/atmega328p



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/DFGv2-Firmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega328P
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/main.o: src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000 -D_ILI9341_ -D_XPT2046_  -I "include" -Wall -MD -MP -MF "${OBJECTDIR}/src/main.o.d" -MT "${OBJECTDIR}/src/main.o.d" -MT ${OBJECTDIR}/src/main.o  -o ${OBJECTDIR}/src/main.o src/main.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/init_mcu.o: src/init_mcu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/init_mcu.o.d 
	@${RM} ${OBJECTDIR}/src/init_mcu.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000 -D_ILI9341_ -D_XPT2046_  -I "include" -Wall -MD -MP -MF "${OBJECTDIR}/src/init_mcu.o.d" -MT "${OBJECTDIR}/src/init_mcu.o.d" -MT ${OBJECTDIR}/src/init_mcu.o  -o ${OBJECTDIR}/src/init_mcu.o src/init_mcu.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/twi_driver.o: src/twi_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/twi_driver.o.d 
	@${RM} ${OBJECTDIR}/src/twi_driver.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000 -D_ILI9341_ -D_XPT2046_  -I "include" -Wall -MD -MP -MF "${OBJECTDIR}/src/twi_driver.o.d" -MT "${OBJECTDIR}/src/twi_driver.o.d" -MT ${OBJECTDIR}/src/twi_driver.o  -o ${OBJECTDIR}/src/twi_driver.o src/twi_driver.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/avr_controllers/spi_controller.o: src/avr_controllers/spi_controller.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/avr_controllers" 
	@${RM} ${OBJECTDIR}/src/avr_controllers/spi_controller.o.d 
	@${RM} ${OBJECTDIR}/src/avr_controllers/spi_controller.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000 -D_ILI9341_ -D_XPT2046_  -I "include" -Wall -MD -MP -MF "${OBJECTDIR}/src/avr_controllers/spi_controller.o.d" -MT "${OBJECTDIR}/src/avr_controllers/spi_controller.o.d" -MT ${OBJECTDIR}/src/avr_controllers/spi_controller.o  -o ${OBJECTDIR}/src/avr_controllers/spi_controller.o src/avr_controllers/spi_controller.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/lcd-driver/lcd-driver.o: src/lcd-driver/lcd-driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/lcd-driver" 
	@${RM} ${OBJECTDIR}/src/lcd-driver/lcd-driver.o.d 
	@${RM} ${OBJECTDIR}/src/lcd-driver/lcd-driver.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000 -D_ILI9341_ -D_XPT2046_  -I "include" -Wall -MD -MP -MF "${OBJECTDIR}/src/lcd-driver/lcd-driver.o.d" -MT "${OBJECTDIR}/src/lcd-driver/lcd-driver.o.d" -MT ${OBJECTDIR}/src/lcd-driver/lcd-driver.o  -o ${OBJECTDIR}/src/lcd-driver/lcd-driver.o src/lcd-driver/lcd-driver.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/lcd-driver/graphics.o: src/lcd-driver/graphics.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/lcd-driver" 
	@${RM} ${OBJECTDIR}/src/lcd-driver/graphics.o.d 
	@${RM} ${OBJECTDIR}/src/lcd-driver/graphics.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000 -D_ILI9341_ -D_XPT2046_  -I "include" -Wall -MD -MP -MF "${OBJECTDIR}/src/lcd-driver/graphics.o.d" -MT "${OBJECTDIR}/src/lcd-driver/graphics.o.d" -MT ${OBJECTDIR}/src/lcd-driver/graphics.o  -o ${OBJECTDIR}/src/lcd-driver/graphics.o src/lcd-driver/graphics.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/touch-panel-driver/touch-panel-driver.o: src/touch-panel-driver/touch-panel-driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/touch-panel-driver" 
	@${RM} ${OBJECTDIR}/src/touch-panel-driver/touch-panel-driver.o.d 
	@${RM} ${OBJECTDIR}/src/touch-panel-driver/touch-panel-driver.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000 -D_ILI9341_ -D_XPT2046_  -I "include" -Wall -MD -MP -MF "${OBJECTDIR}/src/touch-panel-driver/touch-panel-driver.o.d" -MT "${OBJECTDIR}/src/touch-panel-driver/touch-panel-driver.o.d" -MT ${OBJECTDIR}/src/touch-panel-driver/touch-panel-driver.o  -o ${OBJECTDIR}/src/touch-panel-driver/touch-panel-driver.o src/touch-panel-driver/touch-panel-driver.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/user-interface/ui_button.o: src/user-interface/ui_button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/user-interface" 
	@${RM} ${OBJECTDIR}/src/user-interface/ui_button.o.d 
	@${RM} ${OBJECTDIR}/src/user-interface/ui_button.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000 -D_ILI9341_ -D_XPT2046_  -I "include" -Wall -MD -MP -MF "${OBJECTDIR}/src/user-interface/ui_button.o.d" -MT "${OBJECTDIR}/src/user-interface/ui_button.o.d" -MT ${OBJECTDIR}/src/user-interface/ui_button.o  -o ${OBJECTDIR}/src/user-interface/ui_button.o src/user-interface/ui_button.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/user-interface/ui_main_menu.o: src/user-interface/ui_main_menu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/user-interface" 
	@${RM} ${OBJECTDIR}/src/user-interface/ui_main_menu.o.d 
	@${RM} ${OBJECTDIR}/src/user-interface/ui_main_menu.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000 -D_ILI9341_ -D_XPT2046_  -I "include" -Wall -MD -MP -MF "${OBJECTDIR}/src/user-interface/ui_main_menu.o.d" -MT "${OBJECTDIR}/src/user-interface/ui_main_menu.o.d" -MT ${OBJECTDIR}/src/user-interface/ui_main_menu.o  -o ${OBJECTDIR}/src/user-interface/ui_main_menu.o src/user-interface/ui_main_menu.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/user-interface/ui_helper.o: src/user-interface/ui_helper.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/user-interface" 
	@${RM} ${OBJECTDIR}/src/user-interface/ui_helper.o.d 
	@${RM} ${OBJECTDIR}/src/user-interface/ui_helper.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000 -D_ILI9341_ -D_XPT2046_  -I "include" -Wall -MD -MP -MF "${OBJECTDIR}/src/user-interface/ui_helper.o.d" -MT "${OBJECTDIR}/src/user-interface/ui_helper.o.d" -MT ${OBJECTDIR}/src/user-interface/ui_helper.o  -o ${OBJECTDIR}/src/user-interface/ui_helper.o src/user-interface/ui_helper.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/user-interface/ui_options_menu.o: src/user-interface/ui_options_menu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/user-interface" 
	@${RM} ${OBJECTDIR}/src/user-interface/ui_options_menu.o.d 
	@${RM} ${OBJECTDIR}/src/user-interface/ui_options_menu.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000 -D_ILI9341_ -D_XPT2046_  -I "include" -Wall -MD -MP -MF "${OBJECTDIR}/src/user-interface/ui_options_menu.o.d" -MT "${OBJECTDIR}/src/user-interface/ui_options_menu.o.d" -MT ${OBJECTDIR}/src/user-interface/ui_options_menu.o  -o ${OBJECTDIR}/src/user-interface/ui_options_menu.o src/user-interface/ui_options_menu.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/src/main.o: src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000 -D_ILI9341_ -D_XPT2046_  -I "include" -Wall -MD -MP -MF "${OBJECTDIR}/src/main.o.d" -MT "${OBJECTDIR}/src/main.o.d" -MT ${OBJECTDIR}/src/main.o  -o ${OBJECTDIR}/src/main.o src/main.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/init_mcu.o: src/init_mcu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/init_mcu.o.d 
	@${RM} ${OBJECTDIR}/src/init_mcu.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000 -D_ILI9341_ -D_XPT2046_  -I "include" -Wall -MD -MP -MF "${OBJECTDIR}/src/init_mcu.o.d" -MT "${OBJECTDIR}/src/init_mcu.o.d" -MT ${OBJECTDIR}/src/init_mcu.o  -o ${OBJECTDIR}/src/init_mcu.o src/init_mcu.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/twi_driver.o: src/twi_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/twi_driver.o.d 
	@${RM} ${OBJECTDIR}/src/twi_driver.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000 -D_ILI9341_ -D_XPT2046_  -I "include" -Wall -MD -MP -MF "${OBJECTDIR}/src/twi_driver.o.d" -MT "${OBJECTDIR}/src/twi_driver.o.d" -MT ${OBJECTDIR}/src/twi_driver.o  -o ${OBJECTDIR}/src/twi_driver.o src/twi_driver.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/avr_controllers/spi_controller.o: src/avr_controllers/spi_controller.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/avr_controllers" 
	@${RM} ${OBJECTDIR}/src/avr_controllers/spi_controller.o.d 
	@${RM} ${OBJECTDIR}/src/avr_controllers/spi_controller.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000 -D_ILI9341_ -D_XPT2046_  -I "include" -Wall -MD -MP -MF "${OBJECTDIR}/src/avr_controllers/spi_controller.o.d" -MT "${OBJECTDIR}/src/avr_controllers/spi_controller.o.d" -MT ${OBJECTDIR}/src/avr_controllers/spi_controller.o  -o ${OBJECTDIR}/src/avr_controllers/spi_controller.o src/avr_controllers/spi_controller.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/lcd-driver/lcd-driver.o: src/lcd-driver/lcd-driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/lcd-driver" 
	@${RM} ${OBJECTDIR}/src/lcd-driver/lcd-driver.o.d 
	@${RM} ${OBJECTDIR}/src/lcd-driver/lcd-driver.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000 -D_ILI9341_ -D_XPT2046_  -I "include" -Wall -MD -MP -MF "${OBJECTDIR}/src/lcd-driver/lcd-driver.o.d" -MT "${OBJECTDIR}/src/lcd-driver/lcd-driver.o.d" -MT ${OBJECTDIR}/src/lcd-driver/lcd-driver.o  -o ${OBJECTDIR}/src/lcd-driver/lcd-driver.o src/lcd-driver/lcd-driver.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/lcd-driver/graphics.o: src/lcd-driver/graphics.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/lcd-driver" 
	@${RM} ${OBJECTDIR}/src/lcd-driver/graphics.o.d 
	@${RM} ${OBJECTDIR}/src/lcd-driver/graphics.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000 -D_ILI9341_ -D_XPT2046_  -I "include" -Wall -MD -MP -MF "${OBJECTDIR}/src/lcd-driver/graphics.o.d" -MT "${OBJECTDIR}/src/lcd-driver/graphics.o.d" -MT ${OBJECTDIR}/src/lcd-driver/graphics.o  -o ${OBJECTDIR}/src/lcd-driver/graphics.o src/lcd-driver/graphics.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/touch-panel-driver/touch-panel-driver.o: src/touch-panel-driver/touch-panel-driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/touch-panel-driver" 
	@${RM} ${OBJECTDIR}/src/touch-panel-driver/touch-panel-driver.o.d 
	@${RM} ${OBJECTDIR}/src/touch-panel-driver/touch-panel-driver.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000 -D_ILI9341_ -D_XPT2046_  -I "include" -Wall -MD -MP -MF "${OBJECTDIR}/src/touch-panel-driver/touch-panel-driver.o.d" -MT "${OBJECTDIR}/src/touch-panel-driver/touch-panel-driver.o.d" -MT ${OBJECTDIR}/src/touch-panel-driver/touch-panel-driver.o  -o ${OBJECTDIR}/src/touch-panel-driver/touch-panel-driver.o src/touch-panel-driver/touch-panel-driver.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/user-interface/ui_button.o: src/user-interface/ui_button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/user-interface" 
	@${RM} ${OBJECTDIR}/src/user-interface/ui_button.o.d 
	@${RM} ${OBJECTDIR}/src/user-interface/ui_button.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000 -D_ILI9341_ -D_XPT2046_  -I "include" -Wall -MD -MP -MF "${OBJECTDIR}/src/user-interface/ui_button.o.d" -MT "${OBJECTDIR}/src/user-interface/ui_button.o.d" -MT ${OBJECTDIR}/src/user-interface/ui_button.o  -o ${OBJECTDIR}/src/user-interface/ui_button.o src/user-interface/ui_button.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/user-interface/ui_main_menu.o: src/user-interface/ui_main_menu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/user-interface" 
	@${RM} ${OBJECTDIR}/src/user-interface/ui_main_menu.o.d 
	@${RM} ${OBJECTDIR}/src/user-interface/ui_main_menu.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000 -D_ILI9341_ -D_XPT2046_  -I "include" -Wall -MD -MP -MF "${OBJECTDIR}/src/user-interface/ui_main_menu.o.d" -MT "${OBJECTDIR}/src/user-interface/ui_main_menu.o.d" -MT ${OBJECTDIR}/src/user-interface/ui_main_menu.o  -o ${OBJECTDIR}/src/user-interface/ui_main_menu.o src/user-interface/ui_main_menu.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/user-interface/ui_helper.o: src/user-interface/ui_helper.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/user-interface" 
	@${RM} ${OBJECTDIR}/src/user-interface/ui_helper.o.d 
	@${RM} ${OBJECTDIR}/src/user-interface/ui_helper.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000 -D_ILI9341_ -D_XPT2046_  -I "include" -Wall -MD -MP -MF "${OBJECTDIR}/src/user-interface/ui_helper.o.d" -MT "${OBJECTDIR}/src/user-interface/ui_helper.o.d" -MT ${OBJECTDIR}/src/user-interface/ui_helper.o  -o ${OBJECTDIR}/src/user-interface/ui_helper.o src/user-interface/ui_helper.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/user-interface/ui_options_menu.o: src/user-interface/ui_options_menu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/user-interface" 
	@${RM} ${OBJECTDIR}/src/user-interface/ui_options_menu.o.d 
	@${RM} ${OBJECTDIR}/src/user-interface/ui_options_menu.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000 -D_ILI9341_ -D_XPT2046_  -I "include" -Wall -MD -MP -MF "${OBJECTDIR}/src/user-interface/ui_options_menu.o.d" -MT "${OBJECTDIR}/src/user-interface/ui_options_menu.o.d" -MT ${OBJECTDIR}/src/user-interface/ui_options_menu.o  -o ${OBJECTDIR}/src/user-interface/ui_options_menu.o src/user-interface/ui_options_menu.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/DFGv2-Firmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega328p ${PACK_COMMON_OPTIONS}  -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2 -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="dist/${CND_CONF}/${IMAGE_TYPE}/DFGv2-Firmware.X.${IMAGE_TYPE}.map"    -o dist/${CND_CONF}/${IMAGE_TYPE}/DFGv2-Firmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1 -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	
	
	
	
	
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/DFGv2-Firmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega328p ${PACK_COMMON_OPTIONS}  -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="dist/${CND_CONF}/${IMAGE_TYPE}/DFGv2-Firmware.X.${IMAGE_TYPE}.map"    -o dist/${CND_CONF}/${IMAGE_TYPE}/DFGv2-Firmware.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION) -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}/avr-objcopy -O ihex "dist/${CND_CONF}/${IMAGE_TYPE}/DFGv2-Firmware.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/DFGv2-Firmware.X.${IMAGE_TYPE}.hex"
	
	
	
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
