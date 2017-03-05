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
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MPPT_FVP.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MPPT_FVP.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=display.c ADC1Control.c addressableBits.c C:/microchip_solutions_v2013-02-15/Microchip/Include/BatteryDisplayer.c CNControl.c consoleLike.c discreteSetting.c errorControl.c flashWriting.c vincent.c Droid_Sans.c _04B_03B__8.c _8pixFont.c C:/microchip_solutions_v2013-02-15/Microchip/Include/callbacks.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Button.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/GOL.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/GOLFontDefault.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/GOLSchemeDefault.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Palette.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Picture.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Primitive.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/ProgressBar.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/StaticText.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Template.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/TextEntry.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Window.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Drivers/ST7565R.c MPPTLogo.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/bin/grc/tosaSoftwareLogo_1bpp.c menuEntry.c menuLayoutManager.c MyGraph.c myGraphicUtils.c OC1Control.c OCControl.c batterySettingsScreen.c mainSettingsScreen.c pwmSettingScreen.c stabilityTestSettings.c main.c ControlLoop.c controls.c globalPinout.c globalSettings.c globalState.c battery.c battery_graphic.c network.c inverter.c console.c pwms.c pwms_graphic.c fan.c pwmsTimeControl_graphic.c pwmStabilityTest.c pwmStabilityTest_graphic.c quantities.c settingsSaving.c basicTypes.c geometry.c SPIControl.c SPIDisplay.c splashScreen.c ClockControl.c GeneralTimers.c TimeCounter.c timeMeasurement.c timer1.c timer2.c timer3.c timer4.c timer45.c timers.c oscFail.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/display.o ${OBJECTDIR}/ADC1Control.o ${OBJECTDIR}/addressableBits.o ${OBJECTDIR}/_ext/2092063406/BatteryDisplayer.o ${OBJECTDIR}/CNControl.o ${OBJECTDIR}/consoleLike.o ${OBJECTDIR}/discreteSetting.o ${OBJECTDIR}/errorControl.o ${OBJECTDIR}/flashWriting.o ${OBJECTDIR}/vincent.o ${OBJECTDIR}/Droid_Sans.o ${OBJECTDIR}/_04B_03B__8.o ${OBJECTDIR}/_8pixFont.o ${OBJECTDIR}/_ext/2092063406/callbacks.o ${OBJECTDIR}/_ext/419008735/Button.o ${OBJECTDIR}/_ext/419008735/GOL.o ${OBJECTDIR}/_ext/419008735/GOLFontDefault.o ${OBJECTDIR}/_ext/419008735/GOLSchemeDefault.o ${OBJECTDIR}/_ext/419008735/Palette.o ${OBJECTDIR}/_ext/419008735/Picture.o ${OBJECTDIR}/_ext/419008735/Primitive.o ${OBJECTDIR}/_ext/419008735/ProgressBar.o ${OBJECTDIR}/_ext/419008735/StaticText.o ${OBJECTDIR}/_ext/419008735/Template.o ${OBJECTDIR}/_ext/419008735/TextEntry.o ${OBJECTDIR}/_ext/419008735/Window.o ${OBJECTDIR}/_ext/838860861/ST7565R.o ${OBJECTDIR}/MPPTLogo.o ${OBJECTDIR}/_ext/1439009506/tosaSoftwareLogo_1bpp.o ${OBJECTDIR}/menuEntry.o ${OBJECTDIR}/menuLayoutManager.o ${OBJECTDIR}/MyGraph.o ${OBJECTDIR}/myGraphicUtils.o ${OBJECTDIR}/OC1Control.o ${OBJECTDIR}/OCControl.o ${OBJECTDIR}/batterySettingsScreen.o ${OBJECTDIR}/mainSettingsScreen.o ${OBJECTDIR}/pwmSettingScreen.o ${OBJECTDIR}/stabilityTestSettings.o ${OBJECTDIR}/main.o ${OBJECTDIR}/ControlLoop.o ${OBJECTDIR}/controls.o ${OBJECTDIR}/globalPinout.o ${OBJECTDIR}/globalSettings.o ${OBJECTDIR}/globalState.o ${OBJECTDIR}/battery.o ${OBJECTDIR}/battery_graphic.o ${OBJECTDIR}/network.o ${OBJECTDIR}/inverter.o ${OBJECTDIR}/console.o ${OBJECTDIR}/pwms.o ${OBJECTDIR}/pwms_graphic.o ${OBJECTDIR}/fan.o ${OBJECTDIR}/pwmsTimeControl_graphic.o ${OBJECTDIR}/pwmStabilityTest.o ${OBJECTDIR}/pwmStabilityTest_graphic.o ${OBJECTDIR}/quantities.o ${OBJECTDIR}/settingsSaving.o ${OBJECTDIR}/basicTypes.o ${OBJECTDIR}/geometry.o ${OBJECTDIR}/SPIControl.o ${OBJECTDIR}/SPIDisplay.o ${OBJECTDIR}/splashScreen.o ${OBJECTDIR}/ClockControl.o ${OBJECTDIR}/GeneralTimers.o ${OBJECTDIR}/TimeCounter.o ${OBJECTDIR}/timeMeasurement.o ${OBJECTDIR}/timer1.o ${OBJECTDIR}/timer2.o ${OBJECTDIR}/timer3.o ${OBJECTDIR}/timer4.o ${OBJECTDIR}/timer45.o ${OBJECTDIR}/timers.o ${OBJECTDIR}/oscFail.o
POSSIBLE_DEPFILES=${OBJECTDIR}/display.o.d ${OBJECTDIR}/ADC1Control.o.d ${OBJECTDIR}/addressableBits.o.d ${OBJECTDIR}/_ext/2092063406/BatteryDisplayer.o.d ${OBJECTDIR}/CNControl.o.d ${OBJECTDIR}/consoleLike.o.d ${OBJECTDIR}/discreteSetting.o.d ${OBJECTDIR}/errorControl.o.d ${OBJECTDIR}/flashWriting.o.d ${OBJECTDIR}/vincent.o.d ${OBJECTDIR}/Droid_Sans.o.d ${OBJECTDIR}/_04B_03B__8.o.d ${OBJECTDIR}/_8pixFont.o.d ${OBJECTDIR}/_ext/2092063406/callbacks.o.d ${OBJECTDIR}/_ext/419008735/Button.o.d ${OBJECTDIR}/_ext/419008735/GOL.o.d ${OBJECTDIR}/_ext/419008735/GOLFontDefault.o.d ${OBJECTDIR}/_ext/419008735/GOLSchemeDefault.o.d ${OBJECTDIR}/_ext/419008735/Palette.o.d ${OBJECTDIR}/_ext/419008735/Picture.o.d ${OBJECTDIR}/_ext/419008735/Primitive.o.d ${OBJECTDIR}/_ext/419008735/ProgressBar.o.d ${OBJECTDIR}/_ext/419008735/StaticText.o.d ${OBJECTDIR}/_ext/419008735/Template.o.d ${OBJECTDIR}/_ext/419008735/TextEntry.o.d ${OBJECTDIR}/_ext/419008735/Window.o.d ${OBJECTDIR}/_ext/838860861/ST7565R.o.d ${OBJECTDIR}/MPPTLogo.o.d ${OBJECTDIR}/_ext/1439009506/tosaSoftwareLogo_1bpp.o.d ${OBJECTDIR}/menuEntry.o.d ${OBJECTDIR}/menuLayoutManager.o.d ${OBJECTDIR}/MyGraph.o.d ${OBJECTDIR}/myGraphicUtils.o.d ${OBJECTDIR}/OC1Control.o.d ${OBJECTDIR}/OCControl.o.d ${OBJECTDIR}/batterySettingsScreen.o.d ${OBJECTDIR}/mainSettingsScreen.o.d ${OBJECTDIR}/pwmSettingScreen.o.d ${OBJECTDIR}/stabilityTestSettings.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/ControlLoop.o.d ${OBJECTDIR}/controls.o.d ${OBJECTDIR}/globalPinout.o.d ${OBJECTDIR}/globalSettings.o.d ${OBJECTDIR}/globalState.o.d ${OBJECTDIR}/battery.o.d ${OBJECTDIR}/battery_graphic.o.d ${OBJECTDIR}/network.o.d ${OBJECTDIR}/inverter.o.d ${OBJECTDIR}/console.o.d ${OBJECTDIR}/pwms.o.d ${OBJECTDIR}/pwms_graphic.o.d ${OBJECTDIR}/fan.o.d ${OBJECTDIR}/pwmsTimeControl_graphic.o.d ${OBJECTDIR}/pwmStabilityTest.o.d ${OBJECTDIR}/pwmStabilityTest_graphic.o.d ${OBJECTDIR}/quantities.o.d ${OBJECTDIR}/settingsSaving.o.d ${OBJECTDIR}/basicTypes.o.d ${OBJECTDIR}/geometry.o.d ${OBJECTDIR}/SPIControl.o.d ${OBJECTDIR}/SPIDisplay.o.d ${OBJECTDIR}/splashScreen.o.d ${OBJECTDIR}/ClockControl.o.d ${OBJECTDIR}/GeneralTimers.o.d ${OBJECTDIR}/TimeCounter.o.d ${OBJECTDIR}/timeMeasurement.o.d ${OBJECTDIR}/timer1.o.d ${OBJECTDIR}/timer2.o.d ${OBJECTDIR}/timer3.o.d ${OBJECTDIR}/timer4.o.d ${OBJECTDIR}/timer45.o.d ${OBJECTDIR}/timers.o.d ${OBJECTDIR}/oscFail.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/display.o ${OBJECTDIR}/ADC1Control.o ${OBJECTDIR}/addressableBits.o ${OBJECTDIR}/_ext/2092063406/BatteryDisplayer.o ${OBJECTDIR}/CNControl.o ${OBJECTDIR}/consoleLike.o ${OBJECTDIR}/discreteSetting.o ${OBJECTDIR}/errorControl.o ${OBJECTDIR}/flashWriting.o ${OBJECTDIR}/vincent.o ${OBJECTDIR}/Droid_Sans.o ${OBJECTDIR}/_04B_03B__8.o ${OBJECTDIR}/_8pixFont.o ${OBJECTDIR}/_ext/2092063406/callbacks.o ${OBJECTDIR}/_ext/419008735/Button.o ${OBJECTDIR}/_ext/419008735/GOL.o ${OBJECTDIR}/_ext/419008735/GOLFontDefault.o ${OBJECTDIR}/_ext/419008735/GOLSchemeDefault.o ${OBJECTDIR}/_ext/419008735/Palette.o ${OBJECTDIR}/_ext/419008735/Picture.o ${OBJECTDIR}/_ext/419008735/Primitive.o ${OBJECTDIR}/_ext/419008735/ProgressBar.o ${OBJECTDIR}/_ext/419008735/StaticText.o ${OBJECTDIR}/_ext/419008735/Template.o ${OBJECTDIR}/_ext/419008735/TextEntry.o ${OBJECTDIR}/_ext/419008735/Window.o ${OBJECTDIR}/_ext/838860861/ST7565R.o ${OBJECTDIR}/MPPTLogo.o ${OBJECTDIR}/_ext/1439009506/tosaSoftwareLogo_1bpp.o ${OBJECTDIR}/menuEntry.o ${OBJECTDIR}/menuLayoutManager.o ${OBJECTDIR}/MyGraph.o ${OBJECTDIR}/myGraphicUtils.o ${OBJECTDIR}/OC1Control.o ${OBJECTDIR}/OCControl.o ${OBJECTDIR}/batterySettingsScreen.o ${OBJECTDIR}/mainSettingsScreen.o ${OBJECTDIR}/pwmSettingScreen.o ${OBJECTDIR}/stabilityTestSettings.o ${OBJECTDIR}/main.o ${OBJECTDIR}/ControlLoop.o ${OBJECTDIR}/controls.o ${OBJECTDIR}/globalPinout.o ${OBJECTDIR}/globalSettings.o ${OBJECTDIR}/globalState.o ${OBJECTDIR}/battery.o ${OBJECTDIR}/battery_graphic.o ${OBJECTDIR}/network.o ${OBJECTDIR}/inverter.o ${OBJECTDIR}/console.o ${OBJECTDIR}/pwms.o ${OBJECTDIR}/pwms_graphic.o ${OBJECTDIR}/fan.o ${OBJECTDIR}/pwmsTimeControl_graphic.o ${OBJECTDIR}/pwmStabilityTest.o ${OBJECTDIR}/pwmStabilityTest_graphic.o ${OBJECTDIR}/quantities.o ${OBJECTDIR}/settingsSaving.o ${OBJECTDIR}/basicTypes.o ${OBJECTDIR}/geometry.o ${OBJECTDIR}/SPIControl.o ${OBJECTDIR}/SPIDisplay.o ${OBJECTDIR}/splashScreen.o ${OBJECTDIR}/ClockControl.o ${OBJECTDIR}/GeneralTimers.o ${OBJECTDIR}/TimeCounter.o ${OBJECTDIR}/timeMeasurement.o ${OBJECTDIR}/timer1.o ${OBJECTDIR}/timer2.o ${OBJECTDIR}/timer3.o ${OBJECTDIR}/timer4.o ${OBJECTDIR}/timer45.o ${OBJECTDIR}/timers.o ${OBJECTDIR}/oscFail.o

# Source Files
SOURCEFILES=display.c ADC1Control.c addressableBits.c C:/microchip_solutions_v2013-02-15/Microchip/Include/BatteryDisplayer.c CNControl.c consoleLike.c discreteSetting.c errorControl.c flashWriting.c vincent.c Droid_Sans.c _04B_03B__8.c _8pixFont.c C:/microchip_solutions_v2013-02-15/Microchip/Include/callbacks.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Button.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/GOL.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/GOLFontDefault.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/GOLSchemeDefault.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Palette.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Picture.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Primitive.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/ProgressBar.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/StaticText.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Template.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/TextEntry.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Window.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Drivers/ST7565R.c MPPTLogo.c C:/microchip_solutions_v2013-02-15/Microchip/Graphics/bin/grc/tosaSoftwareLogo_1bpp.c menuEntry.c menuLayoutManager.c MyGraph.c myGraphicUtils.c OC1Control.c OCControl.c batterySettingsScreen.c mainSettingsScreen.c pwmSettingScreen.c stabilityTestSettings.c main.c ControlLoop.c controls.c globalPinout.c globalSettings.c globalState.c battery.c battery_graphic.c network.c inverter.c console.c pwms.c pwms_graphic.c fan.c pwmsTimeControl_graphic.c pwmStabilityTest.c pwmStabilityTest_graphic.c quantities.c settingsSaving.c basicTypes.c geometry.c SPIControl.c SPIDisplay.c splashScreen.c ClockControl.c GeneralTimers.c TimeCounter.c timeMeasurement.c timer1.c timer2.c timer3.c timer4.c timer45.c timers.c oscFail.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/MPPT_FVP.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ128MC804
MP_LINKER_FILE_OPTION=,--script=p33FJ128MC804.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/display.o: display.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/display.o.d 
	@${RM} ${OBJECTDIR}/display.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  display.c  -o ${OBJECTDIR}/display.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/display.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/display.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ADC1Control.o: ADC1Control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ADC1Control.o.d 
	@${RM} ${OBJECTDIR}/ADC1Control.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ADC1Control.c  -o ${OBJECTDIR}/ADC1Control.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ADC1Control.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/ADC1Control.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/addressableBits.o: addressableBits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/addressableBits.o.d 
	@${RM} ${OBJECTDIR}/addressableBits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  addressableBits.c  -o ${OBJECTDIR}/addressableBits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/addressableBits.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/addressableBits.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2092063406/BatteryDisplayer.o: C:/microchip_solutions_v2013-02-15/Microchip/Include/BatteryDisplayer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2092063406 
	@${RM} ${OBJECTDIR}/_ext/2092063406/BatteryDisplayer.o.d 
	@${RM} ${OBJECTDIR}/_ext/2092063406/BatteryDisplayer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Include/BatteryDisplayer.c  -o ${OBJECTDIR}/_ext/2092063406/BatteryDisplayer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2092063406/BatteryDisplayer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/2092063406/BatteryDisplayer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/CNControl.o: CNControl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/CNControl.o.d 
	@${RM} ${OBJECTDIR}/CNControl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CNControl.c  -o ${OBJECTDIR}/CNControl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CNControl.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/CNControl.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/consoleLike.o: consoleLike.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/consoleLike.o.d 
	@${RM} ${OBJECTDIR}/consoleLike.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  consoleLike.c  -o ${OBJECTDIR}/consoleLike.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/consoleLike.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/consoleLike.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/discreteSetting.o: discreteSetting.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/discreteSetting.o.d 
	@${RM} ${OBJECTDIR}/discreteSetting.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  discreteSetting.c  -o ${OBJECTDIR}/discreteSetting.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/discreteSetting.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/discreteSetting.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/errorControl.o: errorControl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/errorControl.o.d 
	@${RM} ${OBJECTDIR}/errorControl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  errorControl.c  -o ${OBJECTDIR}/errorControl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/errorControl.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/errorControl.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/flashWriting.o: flashWriting.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/flashWriting.o.d 
	@${RM} ${OBJECTDIR}/flashWriting.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  flashWriting.c  -o ${OBJECTDIR}/flashWriting.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/flashWriting.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/flashWriting.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/vincent.o: vincent.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/vincent.o.d 
	@${RM} ${OBJECTDIR}/vincent.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  vincent.c  -o ${OBJECTDIR}/vincent.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/vincent.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/vincent.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Droid_Sans.o: Droid_Sans.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Droid_Sans.o.d 
	@${RM} ${OBJECTDIR}/Droid_Sans.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Droid_Sans.c  -o ${OBJECTDIR}/Droid_Sans.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Droid_Sans.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/Droid_Sans.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_04B_03B__8.o: _04B_03B__8.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/_04B_03B__8.o.d 
	@${RM} ${OBJECTDIR}/_04B_03B__8.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _04B_03B__8.c  -o ${OBJECTDIR}/_04B_03B__8.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_04B_03B__8.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_04B_03B__8.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_8pixFont.o: _8pixFont.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/_8pixFont.o.d 
	@${RM} ${OBJECTDIR}/_8pixFont.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _8pixFont.c  -o ${OBJECTDIR}/_8pixFont.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_8pixFont.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_8pixFont.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2092063406/callbacks.o: C:/microchip_solutions_v2013-02-15/Microchip/Include/callbacks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2092063406 
	@${RM} ${OBJECTDIR}/_ext/2092063406/callbacks.o.d 
	@${RM} ${OBJECTDIR}/_ext/2092063406/callbacks.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Include/callbacks.c  -o ${OBJECTDIR}/_ext/2092063406/callbacks.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2092063406/callbacks.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/2092063406/callbacks.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/419008735/Button.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/419008735 
	@${RM} ${OBJECTDIR}/_ext/419008735/Button.o.d 
	@${RM} ${OBJECTDIR}/_ext/419008735/Button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Button.c  -o ${OBJECTDIR}/_ext/419008735/Button.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/419008735/Button.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/419008735/Button.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/419008735/GOL.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/GOL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/419008735 
	@${RM} ${OBJECTDIR}/_ext/419008735/GOL.o.d 
	@${RM} ${OBJECTDIR}/_ext/419008735/GOL.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/GOL.c  -o ${OBJECTDIR}/_ext/419008735/GOL.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/419008735/GOL.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/419008735/GOL.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/419008735/GOLFontDefault.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/GOLFontDefault.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/419008735 
	@${RM} ${OBJECTDIR}/_ext/419008735/GOLFontDefault.o.d 
	@${RM} ${OBJECTDIR}/_ext/419008735/GOLFontDefault.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/GOLFontDefault.c  -o ${OBJECTDIR}/_ext/419008735/GOLFontDefault.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/419008735/GOLFontDefault.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/419008735/GOLFontDefault.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/419008735/GOLSchemeDefault.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/GOLSchemeDefault.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/419008735 
	@${RM} ${OBJECTDIR}/_ext/419008735/GOLSchemeDefault.o.d 
	@${RM} ${OBJECTDIR}/_ext/419008735/GOLSchemeDefault.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/GOLSchemeDefault.c  -o ${OBJECTDIR}/_ext/419008735/GOLSchemeDefault.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/419008735/GOLSchemeDefault.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/419008735/GOLSchemeDefault.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/419008735/Palette.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Palette.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/419008735 
	@${RM} ${OBJECTDIR}/_ext/419008735/Palette.o.d 
	@${RM} ${OBJECTDIR}/_ext/419008735/Palette.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Palette.c  -o ${OBJECTDIR}/_ext/419008735/Palette.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/419008735/Palette.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/419008735/Palette.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/419008735/Picture.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Picture.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/419008735 
	@${RM} ${OBJECTDIR}/_ext/419008735/Picture.o.d 
	@${RM} ${OBJECTDIR}/_ext/419008735/Picture.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Picture.c  -o ${OBJECTDIR}/_ext/419008735/Picture.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/419008735/Picture.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/419008735/Picture.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/419008735/Primitive.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Primitive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/419008735 
	@${RM} ${OBJECTDIR}/_ext/419008735/Primitive.o.d 
	@${RM} ${OBJECTDIR}/_ext/419008735/Primitive.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Primitive.c  -o ${OBJECTDIR}/_ext/419008735/Primitive.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/419008735/Primitive.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/419008735/Primitive.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/419008735/ProgressBar.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/ProgressBar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/419008735 
	@${RM} ${OBJECTDIR}/_ext/419008735/ProgressBar.o.d 
	@${RM} ${OBJECTDIR}/_ext/419008735/ProgressBar.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/ProgressBar.c  -o ${OBJECTDIR}/_ext/419008735/ProgressBar.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/419008735/ProgressBar.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/419008735/ProgressBar.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/419008735/StaticText.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/StaticText.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/419008735 
	@${RM} ${OBJECTDIR}/_ext/419008735/StaticText.o.d 
	@${RM} ${OBJECTDIR}/_ext/419008735/StaticText.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/StaticText.c  -o ${OBJECTDIR}/_ext/419008735/StaticText.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/419008735/StaticText.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/419008735/StaticText.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/419008735/Template.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Template.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/419008735 
	@${RM} ${OBJECTDIR}/_ext/419008735/Template.o.d 
	@${RM} ${OBJECTDIR}/_ext/419008735/Template.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Template.c  -o ${OBJECTDIR}/_ext/419008735/Template.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/419008735/Template.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/419008735/Template.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/419008735/TextEntry.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/TextEntry.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/419008735 
	@${RM} ${OBJECTDIR}/_ext/419008735/TextEntry.o.d 
	@${RM} ${OBJECTDIR}/_ext/419008735/TextEntry.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/TextEntry.c  -o ${OBJECTDIR}/_ext/419008735/TextEntry.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/419008735/TextEntry.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/419008735/TextEntry.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/419008735/Window.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/419008735 
	@${RM} ${OBJECTDIR}/_ext/419008735/Window.o.d 
	@${RM} ${OBJECTDIR}/_ext/419008735/Window.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Window.c  -o ${OBJECTDIR}/_ext/419008735/Window.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/419008735/Window.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/419008735/Window.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/838860861/ST7565R.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Drivers/ST7565R.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/838860861 
	@${RM} ${OBJECTDIR}/_ext/838860861/ST7565R.o.d 
	@${RM} ${OBJECTDIR}/_ext/838860861/ST7565R.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Drivers/ST7565R.c  -o ${OBJECTDIR}/_ext/838860861/ST7565R.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/838860861/ST7565R.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/838860861/ST7565R.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/MPPTLogo.o: MPPTLogo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/MPPTLogo.o.d 
	@${RM} ${OBJECTDIR}/MPPTLogo.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MPPTLogo.c  -o ${OBJECTDIR}/MPPTLogo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/MPPTLogo.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/MPPTLogo.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1439009506/tosaSoftwareLogo_1bpp.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/bin/grc/tosaSoftwareLogo_1bpp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1439009506 
	@${RM} ${OBJECTDIR}/_ext/1439009506/tosaSoftwareLogo_1bpp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1439009506/tosaSoftwareLogo_1bpp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/bin/grc/tosaSoftwareLogo_1bpp.c  -o ${OBJECTDIR}/_ext/1439009506/tosaSoftwareLogo_1bpp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1439009506/tosaSoftwareLogo_1bpp.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1439009506/tosaSoftwareLogo_1bpp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/menuEntry.o: menuEntry.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/menuEntry.o.d 
	@${RM} ${OBJECTDIR}/menuEntry.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  menuEntry.c  -o ${OBJECTDIR}/menuEntry.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/menuEntry.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/menuEntry.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/menuLayoutManager.o: menuLayoutManager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/menuLayoutManager.o.d 
	@${RM} ${OBJECTDIR}/menuLayoutManager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  menuLayoutManager.c  -o ${OBJECTDIR}/menuLayoutManager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/menuLayoutManager.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/menuLayoutManager.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/MyGraph.o: MyGraph.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/MyGraph.o.d 
	@${RM} ${OBJECTDIR}/MyGraph.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MyGraph.c  -o ${OBJECTDIR}/MyGraph.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/MyGraph.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/MyGraph.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/myGraphicUtils.o: myGraphicUtils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/myGraphicUtils.o.d 
	@${RM} ${OBJECTDIR}/myGraphicUtils.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  myGraphicUtils.c  -o ${OBJECTDIR}/myGraphicUtils.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/myGraphicUtils.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/myGraphicUtils.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/OC1Control.o: OC1Control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/OC1Control.o.d 
	@${RM} ${OBJECTDIR}/OC1Control.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OC1Control.c  -o ${OBJECTDIR}/OC1Control.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/OC1Control.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/OC1Control.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/OCControl.o: OCControl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/OCControl.o.d 
	@${RM} ${OBJECTDIR}/OCControl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OCControl.c  -o ${OBJECTDIR}/OCControl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/OCControl.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/OCControl.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/batterySettingsScreen.o: batterySettingsScreen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/batterySettingsScreen.o.d 
	@${RM} ${OBJECTDIR}/batterySettingsScreen.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  batterySettingsScreen.c  -o ${OBJECTDIR}/batterySettingsScreen.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/batterySettingsScreen.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/batterySettingsScreen.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/mainSettingsScreen.o: mainSettingsScreen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/mainSettingsScreen.o.d 
	@${RM} ${OBJECTDIR}/mainSettingsScreen.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mainSettingsScreen.c  -o ${OBJECTDIR}/mainSettingsScreen.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/mainSettingsScreen.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/mainSettingsScreen.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/pwmSettingScreen.o: pwmSettingScreen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/pwmSettingScreen.o.d 
	@${RM} ${OBJECTDIR}/pwmSettingScreen.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pwmSettingScreen.c  -o ${OBJECTDIR}/pwmSettingScreen.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/pwmSettingScreen.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/pwmSettingScreen.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/stabilityTestSettings.o: stabilityTestSettings.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/stabilityTestSettings.o.d 
	@${RM} ${OBJECTDIR}/stabilityTestSettings.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  stabilityTestSettings.c  -o ${OBJECTDIR}/stabilityTestSettings.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/stabilityTestSettings.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/stabilityTestSettings.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ControlLoop.o: ControlLoop.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ControlLoop.o.d 
	@${RM} ${OBJECTDIR}/ControlLoop.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ControlLoop.c  -o ${OBJECTDIR}/ControlLoop.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ControlLoop.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/ControlLoop.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/controls.o: controls.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/controls.o.d 
	@${RM} ${OBJECTDIR}/controls.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  controls.c  -o ${OBJECTDIR}/controls.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/controls.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/controls.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/globalPinout.o: globalPinout.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/globalPinout.o.d 
	@${RM} ${OBJECTDIR}/globalPinout.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  globalPinout.c  -o ${OBJECTDIR}/globalPinout.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/globalPinout.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/globalPinout.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/globalSettings.o: globalSettings.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/globalSettings.o.d 
	@${RM} ${OBJECTDIR}/globalSettings.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  globalSettings.c  -o ${OBJECTDIR}/globalSettings.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/globalSettings.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/globalSettings.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/globalState.o: globalState.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/globalState.o.d 
	@${RM} ${OBJECTDIR}/globalState.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  globalState.c  -o ${OBJECTDIR}/globalState.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/globalState.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/globalState.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/battery.o: battery.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/battery.o.d 
	@${RM} ${OBJECTDIR}/battery.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  battery.c  -o ${OBJECTDIR}/battery.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/battery.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/battery.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/battery_graphic.o: battery_graphic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/battery_graphic.o.d 
	@${RM} ${OBJECTDIR}/battery_graphic.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  battery_graphic.c  -o ${OBJECTDIR}/battery_graphic.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/battery_graphic.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/battery_graphic.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/network.o: network.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/network.o.d 
	@${RM} ${OBJECTDIR}/network.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  network.c  -o ${OBJECTDIR}/network.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/network.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/network.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/inverter.o: inverter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/inverter.o.d 
	@${RM} ${OBJECTDIR}/inverter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  inverter.c  -o ${OBJECTDIR}/inverter.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/inverter.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/inverter.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/console.o: console.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/console.o.d 
	@${RM} ${OBJECTDIR}/console.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  console.c  -o ${OBJECTDIR}/console.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/console.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/console.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/pwms.o: pwms.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/pwms.o.d 
	@${RM} ${OBJECTDIR}/pwms.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pwms.c  -o ${OBJECTDIR}/pwms.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/pwms.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/pwms.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/pwms_graphic.o: pwms_graphic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/pwms_graphic.o.d 
	@${RM} ${OBJECTDIR}/pwms_graphic.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pwms_graphic.c  -o ${OBJECTDIR}/pwms_graphic.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/pwms_graphic.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/pwms_graphic.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/fan.o: fan.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/fan.o.d 
	@${RM} ${OBJECTDIR}/fan.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  fan.c  -o ${OBJECTDIR}/fan.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/fan.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/fan.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/pwmsTimeControl_graphic.o: pwmsTimeControl_graphic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/pwmsTimeControl_graphic.o.d 
	@${RM} ${OBJECTDIR}/pwmsTimeControl_graphic.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pwmsTimeControl_graphic.c  -o ${OBJECTDIR}/pwmsTimeControl_graphic.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/pwmsTimeControl_graphic.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/pwmsTimeControl_graphic.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/pwmStabilityTest.o: pwmStabilityTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/pwmStabilityTest.o.d 
	@${RM} ${OBJECTDIR}/pwmStabilityTest.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pwmStabilityTest.c  -o ${OBJECTDIR}/pwmStabilityTest.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/pwmStabilityTest.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/pwmStabilityTest.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/pwmStabilityTest_graphic.o: pwmStabilityTest_graphic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/pwmStabilityTest_graphic.o.d 
	@${RM} ${OBJECTDIR}/pwmStabilityTest_graphic.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pwmStabilityTest_graphic.c  -o ${OBJECTDIR}/pwmStabilityTest_graphic.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/pwmStabilityTest_graphic.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/pwmStabilityTest_graphic.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/quantities.o: quantities.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/quantities.o.d 
	@${RM} ${OBJECTDIR}/quantities.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  quantities.c  -o ${OBJECTDIR}/quantities.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/quantities.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/quantities.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/settingsSaving.o: settingsSaving.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/settingsSaving.o.d 
	@${RM} ${OBJECTDIR}/settingsSaving.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  settingsSaving.c  -o ${OBJECTDIR}/settingsSaving.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/settingsSaving.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/settingsSaving.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/basicTypes.o: basicTypes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/basicTypes.o.d 
	@${RM} ${OBJECTDIR}/basicTypes.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  basicTypes.c  -o ${OBJECTDIR}/basicTypes.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/basicTypes.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/basicTypes.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/geometry.o: geometry.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/geometry.o.d 
	@${RM} ${OBJECTDIR}/geometry.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  geometry.c  -o ${OBJECTDIR}/geometry.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/geometry.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/geometry.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SPIControl.o: SPIControl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/SPIControl.o.d 
	@${RM} ${OBJECTDIR}/SPIControl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SPIControl.c  -o ${OBJECTDIR}/SPIControl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SPIControl.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/SPIControl.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SPIDisplay.o: SPIDisplay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/SPIDisplay.o.d 
	@${RM} ${OBJECTDIR}/SPIDisplay.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SPIDisplay.c  -o ${OBJECTDIR}/SPIDisplay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SPIDisplay.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/SPIDisplay.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/splashScreen.o: splashScreen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/splashScreen.o.d 
	@${RM} ${OBJECTDIR}/splashScreen.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  splashScreen.c  -o ${OBJECTDIR}/splashScreen.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/splashScreen.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/splashScreen.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ClockControl.o: ClockControl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ClockControl.o.d 
	@${RM} ${OBJECTDIR}/ClockControl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ClockControl.c  -o ${OBJECTDIR}/ClockControl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ClockControl.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/ClockControl.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/GeneralTimers.o: GeneralTimers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/GeneralTimers.o.d 
	@${RM} ${OBJECTDIR}/GeneralTimers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  GeneralTimers.c  -o ${OBJECTDIR}/GeneralTimers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/GeneralTimers.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/GeneralTimers.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/TimeCounter.o: TimeCounter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/TimeCounter.o.d 
	@${RM} ${OBJECTDIR}/TimeCounter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TimeCounter.c  -o ${OBJECTDIR}/TimeCounter.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TimeCounter.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/TimeCounter.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/timeMeasurement.o: timeMeasurement.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/timeMeasurement.o.d 
	@${RM} ${OBJECTDIR}/timeMeasurement.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timeMeasurement.c  -o ${OBJECTDIR}/timeMeasurement.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timeMeasurement.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/timeMeasurement.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/timer1.o: timer1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/timer1.o.d 
	@${RM} ${OBJECTDIR}/timer1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer1.c  -o ${OBJECTDIR}/timer1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timer1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/timer1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/timer2.o: timer2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/timer2.o.d 
	@${RM} ${OBJECTDIR}/timer2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer2.c  -o ${OBJECTDIR}/timer2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timer2.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/timer2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/timer3.o: timer3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/timer3.o.d 
	@${RM} ${OBJECTDIR}/timer3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer3.c  -o ${OBJECTDIR}/timer3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timer3.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/timer3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/timer4.o: timer4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/timer4.o.d 
	@${RM} ${OBJECTDIR}/timer4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer4.c  -o ${OBJECTDIR}/timer4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timer4.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/timer4.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/timer45.o: timer45.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/timer45.o.d 
	@${RM} ${OBJECTDIR}/timer45.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer45.c  -o ${OBJECTDIR}/timer45.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timer45.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/timer45.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/timers.o: timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/timers.o.d 
	@${RM} ${OBJECTDIR}/timers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timers.c  -o ${OBJECTDIR}/timers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timers.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/timers.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/oscFail.o: oscFail.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/oscFail.o.d 
	@${RM} ${OBJECTDIR}/oscFail.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  oscFail.c  -o ${OBJECTDIR}/oscFail.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/oscFail.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/oscFail.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/display.o: display.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/display.o.d 
	@${RM} ${OBJECTDIR}/display.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  display.c  -o ${OBJECTDIR}/display.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/display.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/display.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ADC1Control.o: ADC1Control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ADC1Control.o.d 
	@${RM} ${OBJECTDIR}/ADC1Control.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ADC1Control.c  -o ${OBJECTDIR}/ADC1Control.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ADC1Control.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/ADC1Control.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/addressableBits.o: addressableBits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/addressableBits.o.d 
	@${RM} ${OBJECTDIR}/addressableBits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  addressableBits.c  -o ${OBJECTDIR}/addressableBits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/addressableBits.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/addressableBits.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2092063406/BatteryDisplayer.o: C:/microchip_solutions_v2013-02-15/Microchip/Include/BatteryDisplayer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2092063406 
	@${RM} ${OBJECTDIR}/_ext/2092063406/BatteryDisplayer.o.d 
	@${RM} ${OBJECTDIR}/_ext/2092063406/BatteryDisplayer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Include/BatteryDisplayer.c  -o ${OBJECTDIR}/_ext/2092063406/BatteryDisplayer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2092063406/BatteryDisplayer.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/2092063406/BatteryDisplayer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/CNControl.o: CNControl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/CNControl.o.d 
	@${RM} ${OBJECTDIR}/CNControl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CNControl.c  -o ${OBJECTDIR}/CNControl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CNControl.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/CNControl.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/consoleLike.o: consoleLike.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/consoleLike.o.d 
	@${RM} ${OBJECTDIR}/consoleLike.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  consoleLike.c  -o ${OBJECTDIR}/consoleLike.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/consoleLike.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/consoleLike.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/discreteSetting.o: discreteSetting.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/discreteSetting.o.d 
	@${RM} ${OBJECTDIR}/discreteSetting.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  discreteSetting.c  -o ${OBJECTDIR}/discreteSetting.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/discreteSetting.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/discreteSetting.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/errorControl.o: errorControl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/errorControl.o.d 
	@${RM} ${OBJECTDIR}/errorControl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  errorControl.c  -o ${OBJECTDIR}/errorControl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/errorControl.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/errorControl.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/flashWriting.o: flashWriting.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/flashWriting.o.d 
	@${RM} ${OBJECTDIR}/flashWriting.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  flashWriting.c  -o ${OBJECTDIR}/flashWriting.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/flashWriting.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/flashWriting.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/vincent.o: vincent.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/vincent.o.d 
	@${RM} ${OBJECTDIR}/vincent.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  vincent.c  -o ${OBJECTDIR}/vincent.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/vincent.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/vincent.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Droid_Sans.o: Droid_Sans.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Droid_Sans.o.d 
	@${RM} ${OBJECTDIR}/Droid_Sans.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Droid_Sans.c  -o ${OBJECTDIR}/Droid_Sans.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Droid_Sans.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/Droid_Sans.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_04B_03B__8.o: _04B_03B__8.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/_04B_03B__8.o.d 
	@${RM} ${OBJECTDIR}/_04B_03B__8.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _04B_03B__8.c  -o ${OBJECTDIR}/_04B_03B__8.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_04B_03B__8.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_04B_03B__8.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_8pixFont.o: _8pixFont.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/_8pixFont.o.d 
	@${RM} ${OBJECTDIR}/_8pixFont.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _8pixFont.c  -o ${OBJECTDIR}/_8pixFont.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_8pixFont.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_8pixFont.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2092063406/callbacks.o: C:/microchip_solutions_v2013-02-15/Microchip/Include/callbacks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2092063406 
	@${RM} ${OBJECTDIR}/_ext/2092063406/callbacks.o.d 
	@${RM} ${OBJECTDIR}/_ext/2092063406/callbacks.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Include/callbacks.c  -o ${OBJECTDIR}/_ext/2092063406/callbacks.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2092063406/callbacks.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/2092063406/callbacks.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/419008735/Button.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/419008735 
	@${RM} ${OBJECTDIR}/_ext/419008735/Button.o.d 
	@${RM} ${OBJECTDIR}/_ext/419008735/Button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Button.c  -o ${OBJECTDIR}/_ext/419008735/Button.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/419008735/Button.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/419008735/Button.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/419008735/GOL.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/GOL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/419008735 
	@${RM} ${OBJECTDIR}/_ext/419008735/GOL.o.d 
	@${RM} ${OBJECTDIR}/_ext/419008735/GOL.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/GOL.c  -o ${OBJECTDIR}/_ext/419008735/GOL.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/419008735/GOL.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/419008735/GOL.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/419008735/GOLFontDefault.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/GOLFontDefault.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/419008735 
	@${RM} ${OBJECTDIR}/_ext/419008735/GOLFontDefault.o.d 
	@${RM} ${OBJECTDIR}/_ext/419008735/GOLFontDefault.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/GOLFontDefault.c  -o ${OBJECTDIR}/_ext/419008735/GOLFontDefault.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/419008735/GOLFontDefault.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/419008735/GOLFontDefault.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/419008735/GOLSchemeDefault.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/GOLSchemeDefault.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/419008735 
	@${RM} ${OBJECTDIR}/_ext/419008735/GOLSchemeDefault.o.d 
	@${RM} ${OBJECTDIR}/_ext/419008735/GOLSchemeDefault.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/GOLSchemeDefault.c  -o ${OBJECTDIR}/_ext/419008735/GOLSchemeDefault.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/419008735/GOLSchemeDefault.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/419008735/GOLSchemeDefault.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/419008735/Palette.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Palette.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/419008735 
	@${RM} ${OBJECTDIR}/_ext/419008735/Palette.o.d 
	@${RM} ${OBJECTDIR}/_ext/419008735/Palette.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Palette.c  -o ${OBJECTDIR}/_ext/419008735/Palette.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/419008735/Palette.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/419008735/Palette.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/419008735/Picture.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Picture.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/419008735 
	@${RM} ${OBJECTDIR}/_ext/419008735/Picture.o.d 
	@${RM} ${OBJECTDIR}/_ext/419008735/Picture.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Picture.c  -o ${OBJECTDIR}/_ext/419008735/Picture.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/419008735/Picture.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/419008735/Picture.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/419008735/Primitive.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Primitive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/419008735 
	@${RM} ${OBJECTDIR}/_ext/419008735/Primitive.o.d 
	@${RM} ${OBJECTDIR}/_ext/419008735/Primitive.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Primitive.c  -o ${OBJECTDIR}/_ext/419008735/Primitive.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/419008735/Primitive.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/419008735/Primitive.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/419008735/ProgressBar.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/ProgressBar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/419008735 
	@${RM} ${OBJECTDIR}/_ext/419008735/ProgressBar.o.d 
	@${RM} ${OBJECTDIR}/_ext/419008735/ProgressBar.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/ProgressBar.c  -o ${OBJECTDIR}/_ext/419008735/ProgressBar.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/419008735/ProgressBar.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/419008735/ProgressBar.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/419008735/StaticText.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/StaticText.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/419008735 
	@${RM} ${OBJECTDIR}/_ext/419008735/StaticText.o.d 
	@${RM} ${OBJECTDIR}/_ext/419008735/StaticText.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/StaticText.c  -o ${OBJECTDIR}/_ext/419008735/StaticText.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/419008735/StaticText.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/419008735/StaticText.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/419008735/Template.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Template.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/419008735 
	@${RM} ${OBJECTDIR}/_ext/419008735/Template.o.d 
	@${RM} ${OBJECTDIR}/_ext/419008735/Template.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Template.c  -o ${OBJECTDIR}/_ext/419008735/Template.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/419008735/Template.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/419008735/Template.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/419008735/TextEntry.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/TextEntry.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/419008735 
	@${RM} ${OBJECTDIR}/_ext/419008735/TextEntry.o.d 
	@${RM} ${OBJECTDIR}/_ext/419008735/TextEntry.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/TextEntry.c  -o ${OBJECTDIR}/_ext/419008735/TextEntry.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/419008735/TextEntry.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/419008735/TextEntry.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/419008735/Window.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/419008735 
	@${RM} ${OBJECTDIR}/_ext/419008735/Window.o.d 
	@${RM} ${OBJECTDIR}/_ext/419008735/Window.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Window.c  -o ${OBJECTDIR}/_ext/419008735/Window.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/419008735/Window.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/419008735/Window.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/838860861/ST7565R.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Drivers/ST7565R.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/838860861 
	@${RM} ${OBJECTDIR}/_ext/838860861/ST7565R.o.d 
	@${RM} ${OBJECTDIR}/_ext/838860861/ST7565R.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/Drivers/ST7565R.c  -o ${OBJECTDIR}/_ext/838860861/ST7565R.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/838860861/ST7565R.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/838860861/ST7565R.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/MPPTLogo.o: MPPTLogo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/MPPTLogo.o.d 
	@${RM} ${OBJECTDIR}/MPPTLogo.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MPPTLogo.c  -o ${OBJECTDIR}/MPPTLogo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/MPPTLogo.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/MPPTLogo.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1439009506/tosaSoftwareLogo_1bpp.o: C:/microchip_solutions_v2013-02-15/Microchip/Graphics/bin/grc/tosaSoftwareLogo_1bpp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1439009506 
	@${RM} ${OBJECTDIR}/_ext/1439009506/tosaSoftwareLogo_1bpp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1439009506/tosaSoftwareLogo_1bpp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/microchip_solutions_v2013-02-15/Microchip/Graphics/bin/grc/tosaSoftwareLogo_1bpp.c  -o ${OBJECTDIR}/_ext/1439009506/tosaSoftwareLogo_1bpp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1439009506/tosaSoftwareLogo_1bpp.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1439009506/tosaSoftwareLogo_1bpp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/menuEntry.o: menuEntry.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/menuEntry.o.d 
	@${RM} ${OBJECTDIR}/menuEntry.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  menuEntry.c  -o ${OBJECTDIR}/menuEntry.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/menuEntry.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/menuEntry.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/menuLayoutManager.o: menuLayoutManager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/menuLayoutManager.o.d 
	@${RM} ${OBJECTDIR}/menuLayoutManager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  menuLayoutManager.c  -o ${OBJECTDIR}/menuLayoutManager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/menuLayoutManager.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/menuLayoutManager.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/MyGraph.o: MyGraph.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/MyGraph.o.d 
	@${RM} ${OBJECTDIR}/MyGraph.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MyGraph.c  -o ${OBJECTDIR}/MyGraph.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/MyGraph.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/MyGraph.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/myGraphicUtils.o: myGraphicUtils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/myGraphicUtils.o.d 
	@${RM} ${OBJECTDIR}/myGraphicUtils.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  myGraphicUtils.c  -o ${OBJECTDIR}/myGraphicUtils.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/myGraphicUtils.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/myGraphicUtils.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/OC1Control.o: OC1Control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/OC1Control.o.d 
	@${RM} ${OBJECTDIR}/OC1Control.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OC1Control.c  -o ${OBJECTDIR}/OC1Control.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/OC1Control.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/OC1Control.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/OCControl.o: OCControl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/OCControl.o.d 
	@${RM} ${OBJECTDIR}/OCControl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OCControl.c  -o ${OBJECTDIR}/OCControl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/OCControl.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/OCControl.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/batterySettingsScreen.o: batterySettingsScreen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/batterySettingsScreen.o.d 
	@${RM} ${OBJECTDIR}/batterySettingsScreen.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  batterySettingsScreen.c  -o ${OBJECTDIR}/batterySettingsScreen.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/batterySettingsScreen.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/batterySettingsScreen.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/mainSettingsScreen.o: mainSettingsScreen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/mainSettingsScreen.o.d 
	@${RM} ${OBJECTDIR}/mainSettingsScreen.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mainSettingsScreen.c  -o ${OBJECTDIR}/mainSettingsScreen.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/mainSettingsScreen.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/mainSettingsScreen.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/pwmSettingScreen.o: pwmSettingScreen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/pwmSettingScreen.o.d 
	@${RM} ${OBJECTDIR}/pwmSettingScreen.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pwmSettingScreen.c  -o ${OBJECTDIR}/pwmSettingScreen.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/pwmSettingScreen.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/pwmSettingScreen.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/stabilityTestSettings.o: stabilityTestSettings.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/stabilityTestSettings.o.d 
	@${RM} ${OBJECTDIR}/stabilityTestSettings.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  stabilityTestSettings.c  -o ${OBJECTDIR}/stabilityTestSettings.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/stabilityTestSettings.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/stabilityTestSettings.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ControlLoop.o: ControlLoop.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ControlLoop.o.d 
	@${RM} ${OBJECTDIR}/ControlLoop.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ControlLoop.c  -o ${OBJECTDIR}/ControlLoop.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ControlLoop.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/ControlLoop.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/controls.o: controls.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/controls.o.d 
	@${RM} ${OBJECTDIR}/controls.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  controls.c  -o ${OBJECTDIR}/controls.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/controls.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/controls.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/globalPinout.o: globalPinout.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/globalPinout.o.d 
	@${RM} ${OBJECTDIR}/globalPinout.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  globalPinout.c  -o ${OBJECTDIR}/globalPinout.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/globalPinout.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/globalPinout.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/globalSettings.o: globalSettings.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/globalSettings.o.d 
	@${RM} ${OBJECTDIR}/globalSettings.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  globalSettings.c  -o ${OBJECTDIR}/globalSettings.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/globalSettings.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/globalSettings.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/globalState.o: globalState.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/globalState.o.d 
	@${RM} ${OBJECTDIR}/globalState.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  globalState.c  -o ${OBJECTDIR}/globalState.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/globalState.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/globalState.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/battery.o: battery.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/battery.o.d 
	@${RM} ${OBJECTDIR}/battery.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  battery.c  -o ${OBJECTDIR}/battery.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/battery.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/battery.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/battery_graphic.o: battery_graphic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/battery_graphic.o.d 
	@${RM} ${OBJECTDIR}/battery_graphic.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  battery_graphic.c  -o ${OBJECTDIR}/battery_graphic.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/battery_graphic.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/battery_graphic.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/network.o: network.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/network.o.d 
	@${RM} ${OBJECTDIR}/network.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  network.c  -o ${OBJECTDIR}/network.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/network.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/network.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/inverter.o: inverter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/inverter.o.d 
	@${RM} ${OBJECTDIR}/inverter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  inverter.c  -o ${OBJECTDIR}/inverter.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/inverter.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/inverter.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/console.o: console.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/console.o.d 
	@${RM} ${OBJECTDIR}/console.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  console.c  -o ${OBJECTDIR}/console.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/console.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/console.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/pwms.o: pwms.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/pwms.o.d 
	@${RM} ${OBJECTDIR}/pwms.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pwms.c  -o ${OBJECTDIR}/pwms.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/pwms.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/pwms.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/pwms_graphic.o: pwms_graphic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/pwms_graphic.o.d 
	@${RM} ${OBJECTDIR}/pwms_graphic.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pwms_graphic.c  -o ${OBJECTDIR}/pwms_graphic.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/pwms_graphic.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/pwms_graphic.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/fan.o: fan.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/fan.o.d 
	@${RM} ${OBJECTDIR}/fan.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  fan.c  -o ${OBJECTDIR}/fan.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/fan.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/fan.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/pwmsTimeControl_graphic.o: pwmsTimeControl_graphic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/pwmsTimeControl_graphic.o.d 
	@${RM} ${OBJECTDIR}/pwmsTimeControl_graphic.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pwmsTimeControl_graphic.c  -o ${OBJECTDIR}/pwmsTimeControl_graphic.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/pwmsTimeControl_graphic.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/pwmsTimeControl_graphic.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/pwmStabilityTest.o: pwmStabilityTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/pwmStabilityTest.o.d 
	@${RM} ${OBJECTDIR}/pwmStabilityTest.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pwmStabilityTest.c  -o ${OBJECTDIR}/pwmStabilityTest.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/pwmStabilityTest.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/pwmStabilityTest.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/pwmStabilityTest_graphic.o: pwmStabilityTest_graphic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/pwmStabilityTest_graphic.o.d 
	@${RM} ${OBJECTDIR}/pwmStabilityTest_graphic.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pwmStabilityTest_graphic.c  -o ${OBJECTDIR}/pwmStabilityTest_graphic.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/pwmStabilityTest_graphic.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/pwmStabilityTest_graphic.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/quantities.o: quantities.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/quantities.o.d 
	@${RM} ${OBJECTDIR}/quantities.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  quantities.c  -o ${OBJECTDIR}/quantities.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/quantities.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/quantities.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/settingsSaving.o: settingsSaving.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/settingsSaving.o.d 
	@${RM} ${OBJECTDIR}/settingsSaving.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  settingsSaving.c  -o ${OBJECTDIR}/settingsSaving.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/settingsSaving.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/settingsSaving.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/basicTypes.o: basicTypes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/basicTypes.o.d 
	@${RM} ${OBJECTDIR}/basicTypes.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  basicTypes.c  -o ${OBJECTDIR}/basicTypes.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/basicTypes.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/basicTypes.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/geometry.o: geometry.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/geometry.o.d 
	@${RM} ${OBJECTDIR}/geometry.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  geometry.c  -o ${OBJECTDIR}/geometry.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/geometry.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/geometry.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SPIControl.o: SPIControl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/SPIControl.o.d 
	@${RM} ${OBJECTDIR}/SPIControl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SPIControl.c  -o ${OBJECTDIR}/SPIControl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SPIControl.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/SPIControl.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SPIDisplay.o: SPIDisplay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/SPIDisplay.o.d 
	@${RM} ${OBJECTDIR}/SPIDisplay.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SPIDisplay.c  -o ${OBJECTDIR}/SPIDisplay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SPIDisplay.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/SPIDisplay.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/splashScreen.o: splashScreen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/splashScreen.o.d 
	@${RM} ${OBJECTDIR}/splashScreen.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  splashScreen.c  -o ${OBJECTDIR}/splashScreen.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/splashScreen.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/splashScreen.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ClockControl.o: ClockControl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ClockControl.o.d 
	@${RM} ${OBJECTDIR}/ClockControl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ClockControl.c  -o ${OBJECTDIR}/ClockControl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ClockControl.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/ClockControl.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/GeneralTimers.o: GeneralTimers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/GeneralTimers.o.d 
	@${RM} ${OBJECTDIR}/GeneralTimers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  GeneralTimers.c  -o ${OBJECTDIR}/GeneralTimers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/GeneralTimers.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/GeneralTimers.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/TimeCounter.o: TimeCounter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/TimeCounter.o.d 
	@${RM} ${OBJECTDIR}/TimeCounter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TimeCounter.c  -o ${OBJECTDIR}/TimeCounter.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TimeCounter.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/TimeCounter.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/timeMeasurement.o: timeMeasurement.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/timeMeasurement.o.d 
	@${RM} ${OBJECTDIR}/timeMeasurement.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timeMeasurement.c  -o ${OBJECTDIR}/timeMeasurement.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timeMeasurement.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/timeMeasurement.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/timer1.o: timer1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/timer1.o.d 
	@${RM} ${OBJECTDIR}/timer1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer1.c  -o ${OBJECTDIR}/timer1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timer1.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/timer1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/timer2.o: timer2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/timer2.o.d 
	@${RM} ${OBJECTDIR}/timer2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer2.c  -o ${OBJECTDIR}/timer2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timer2.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/timer2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/timer3.o: timer3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/timer3.o.d 
	@${RM} ${OBJECTDIR}/timer3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer3.c  -o ${OBJECTDIR}/timer3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timer3.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/timer3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/timer4.o: timer4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/timer4.o.d 
	@${RM} ${OBJECTDIR}/timer4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer4.c  -o ${OBJECTDIR}/timer4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timer4.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/timer4.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/timer45.o: timer45.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/timer45.o.d 
	@${RM} ${OBJECTDIR}/timer45.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer45.c  -o ${OBJECTDIR}/timer45.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timer45.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/timer45.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/timers.o: timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/timers.o.d 
	@${RM} ${OBJECTDIR}/timers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timers.c  -o ${OBJECTDIR}/timers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timers.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/timers.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/oscFail.o: oscFail.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/oscFail.o.d 
	@${RM} ${OBJECTDIR}/oscFail.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  oscFail.c  -o ${OBJECTDIR}/oscFail.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/oscFail.o.d"        -g -omf=elf -mlarge-code -O0 -I"C:/microchip_solutions_v2013-02-15/Microchip/Include" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/oscFail.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/MPPT_FVP.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/MPPT_FVP.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf  -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--heap=8192,--stack=1024,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=64,--no-force-link,--smart-io,--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/MPPT_FVP.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/MPPT_FVP.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -Wl,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--heap=8192,--stack=1024,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=64,--no-force-link,--smart-io,--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/MPPT_FVP.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
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

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
