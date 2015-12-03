/*
 * Platform.c
 *
 *  Created on: 25.09.2015
 *      Author: tastyger
 */

#include "Platform.h"
#if PL_CONFIG_HAS_LED
#include "LED.h"
#endif
#if PL_CONFIG_HAS_EVENTS
#include "Event.h"
#endif
#if PL_CONFIG_HAS_TIMER
#include "Timer.h"
#endif
#if PL_CONFIG_HAS_TRIGGER
#include "Trigger.h"
#endif
#if PL_CONFIG_HAS_TETRIS
#include "Tetris.h"
#endif
#if PL_CONFIG_HAS_BUZZER
#include "Buzzer.h"
#endif
#if PL_CONFIG_HAS_RTOS
#include "RTOS.h"
#endif
#if PL_CONFIG_HAS_SHELL
#include "Shell.h"
#endif
#if PL_CONFIG_HAS_SHELL_QUEUE
#include "ShellQueue.h"
#endif
#if PL_CONFIG_HAS_MOTOR
#include "Motor.h"
#endif
#if PL_CONFIG_HAS_MOTOR_TACHO
#include "Tacho.h"
#endif
#if PL_CONFIG_HAS_QUAD_CALIBRATION
#include "QuadCalib.h"
#endif
#if PL_CONFIG_HAS_MCP4728
#include "MCP4728.h"
#endif
#if PL_CONFIG_HAS_LINE_SENSOR
#include "Reflectance.h"
#endif
#if PL_CONFIG_HAS_CONFIG_NVM
#include "NVM_Config.h"
#endif
#if PL_CONFIG_HAS_MOTOR_QUAD
#include "NVM_Config.h"
#endif
#if PL_CONFIG_HAS_ULTRASONIC
  #include "Ultrasonic.h"
#endif
#if PL_CONFIG_HAS_PID
  #include "PID.h"
#endif
#if PL_CONFIG_HAS_DRIVE
  #include "Drive.h"
#endif
#if PL_CONFIG_HAS_TURN
#include "Turn.h"
#endif
#if PL_CONFIG_HAS_LINE_FOLLOW
#include "LineFollow.h"
#endif
#if PL_CONFIG_HAS_RADIO
#include "RNet_App.h"
#endif

void PL_Init(void) {
#if PL_CONFIG_HAS_LED
	LED_Init();
#endif
#if PL_CONFIG_HAS_EVENTS
	EVNT_Init();
#endif
#if PL_CONFIG_HAS_TIMER
	TMR_Init();
#endif
#if PL_CONFIG_HAS_TRIGGER
	TRG_Init();
#endif
#if PL_CONFIG_HAS_BUZZER
	BUZ_Init();
#endif
#if PL_CONFIG_HAS_RTOS
	RTOS_Init();
#endif
#if PL_CONFIG_HAS_SHELL
	SHELL_Init();
#endif
#if PL_CONFIG_HAS_SHELL_QUEUE
 SQUEUE_Init();
#endif
#if PL_CONFIG_HAS_MOTOR
	MOT_Init();
#endif
#if PL_CONFIG_HAS_LINE_SENSOR
	REF_Init();
#endif
#if PL_CONFIG_HAS_MOTOR_TACHO
	TACHO_Init();
#endif
#if PL_CONFIG_HAS_MCP4728
	MCP4728_Init();
#endif
#if PL_CONFIG_HAS_ULTRASONIC
  US_Init();
#endif
#if PL_CONFIG_HAS_PID
  PID_Init();
#endif
#if PL_CONFIG_HAS_DRIVE
  DRV_Init();
#endif
#if PL_CONFIG_HAS_TURN
  TURN_Init();
#endif
#if PL_CONFIG_HAS_LINE_FOLLOW
  LF_Init();
#endif
#if PL_CONFIG_HAS_RADIO
  RNETA_Init();
#endif
}

void PL_Deinit(void) {
#if PL_CONFIG_HAS_LED
	LED_Deinit();
#endif
#if PL_CONFIG_HAS_EVENTS
	EVNT_Deinit();
#endif
#if PL_CONFIG_HAS_TIMER
	TMR_Deinit();
#endif
#if PL_CONFIG_HAS_TRIGGER
	TRG_Deinit();
#endif
#if PL_CONFIG_HAS_BUZZER
	BUZ_Deinit();
#endif
#if PL_CONFIG_HAS_SHELL_QUEUE
 SQUEUE_Deinit();
#endif
#if PL_CONFIG_HAS_MOTOR
	MOT_Deinit();
#endif
#if PL_CONFIG_HAS_MOTOR_TACHO
	TACHO_Deinit();
#endif
#if PL_CONFIG_HAS_MCP4728
	MCP4728_Deinit();
#endif
#if PL_CONFIG_HAS_LINE_SENSOR
	REF_Deinit();
#endif
#if PL_CONFIG_HAS_CONFIG_NVM
	NVMC_Deinit();
#endif
#if PL_CONFIG_HAS_ULTRASONIC
  US_Deinit();
#endif
#if PL_CONFIG_HAS_DRIVE
  DRV_Deinit();
#endif
#if PL_CONFIG_HAS_PID
  PID_Deinit();
#endif
#if PL_CONFIG_HAS_TURN
  TURN_Deinit();
#endif
#if PL_CONFIG_HAS_LINE_FOLLOW
  LF_Deinit();
#endif
}
