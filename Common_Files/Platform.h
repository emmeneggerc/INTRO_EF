/*
 * Platform.h
 *
 *  Created on: 25.09.2015
 *      Author: tefische
 */

#ifndef SOURCES_COMMON_FILES_PLATFORM_H_
#define SOURCES_COMMON_FILES_PLATFORM_H_

#include "PE_Types.h" /* common Processor Expert types: bool, NULL, ... */

/* configuration macros */
#define PL_CONFIG_HAS_TIMER   		(1 && !defined(PL_CONFIG_DISABLE_HAS_TIMER))
#define PL_CONFIG_HAS_LED   		(1 && !defined(PL_CONFIG_DISABLE_HAS_LED))
#define PL_CONFIG_HAS_EVENTS        (1 && !defined(PL_CONFIG_DISABLE_HAS_EVENTS))
#define PL_CONFIG_EVENTS_AUTO_CLEAR (0 && PL_CONFIG_HAS_EVENTS)
#define PL_CONFIG_HAS_KEYS  		(1 && !defined(PL_CONFIG_DISABLE_HAS_KEYS))
#define PL_CONFIG_HAS_KBI           (1 && !defined(PL_CONFIG_DISABLE_HAS_KBI) && PL_CONFIG_HAS_KEYS)
#define PL_CONFIG_HAS_JOYSTICK 		(1 && !defined(PL_CONFIG_DISABLE_HAS_JOYSTICK))
#define PL_CONFIG_HAS_SHELL         (1)
#define PL_CONFIG_HAS_USB_CDC		(1)
#define PL_CONFIG_HAS_TRIGGER		(1)
#define PL_CONFIG_HAS_DEBOUNCE		(1)
#define PL_CONFIG_HAS_RTOS			(1)

#define PL_CONFIG_HAS_SHELL_QUEUE   (1 && PL_CONFIG_HAS_SHELL)
#define PL_SQUEUE_SINGLE_CHAR		(0 && PL_CONFIG_HAS_SHELL)
#define PL_CONFIG_HAS_CONFIG_NVM 	(1)

#define PL_CONFIG_HAS_RADIO (1)

#if defined(PL_BOARD_IS_FRDM)
#define PL_CONFIG_NOF_LED (2)
#define PL_CONFIG_NOF_KEYS (7)
#define PL_CONFIG_HAS_TETRIS (1)

#elif defined(PL_BOARD_IS_ROBO)
#define PL_CONFIG_HAS_BLUETOOTH		(1)
#define PL_CONFIG_NOF_LED (2)
#define PL_CONFIG_NOF_KEYS (1)
#define PL_CONFIG_DISABLE_HAS_JOYSTICK (1)
#define PL_CONFIG_HAS_BUZZER (1)
#define PL_CONFIG_HAS_LINE_SENSOR (1)
#define PL_CONFIG_HAS_MOTOR			(1)
#define PL_CONFIG_HAS_MOTOR_TACHO	(1)
#define PL_CONFIG_HAS_QUAD_CALIBRATION (1)
#define PL_CONFIG_HAS_MOTOR_QUAD (1)
#define PL_CONFIG_HAS_MCP4728 (1)
#define PL_CONFIG_HAS_QUADRATURE (1)
#define PL_CONFIG_HAS_ULTRASONIC (1)
#define PL_CONFIG_HAS_PID               (1 && PL_CONFIG_HAS_MOTOR_TACHO)
#define PL_CONFIG_HAS_DRIVE             (1 && PL_CONFIG_HAS_PID)
#define PL_CONFIG_HAS_TURN		(1)
#define PL_CONFIG_HAS_LINE_FOLLOW		(1)

#else
#error "make sure you have platform defined in compiler settings!"
#endif

void PL_Init(void);
void PL_Deinit(void);

#endif /* SOURCES_INTRO_COMMON_MASTER_PLATFORM_H_ */
