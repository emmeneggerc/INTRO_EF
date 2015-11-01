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
#define PL_CONFIG_HAS_KBI             (1 && !defined(PL_CONFIG_DISABLE_HAS_KBI) && PL_CONFIG_HAS_KEYS)
#define PL_CONFIG_HAS_JOYSTICK 		(1 && !defined(PL_CONFIG_DISABLE_HAS_JOYSTICK))

#define PL_CONFIG_HAS_SHELL         (1)
#define PL_CONFIG_HAS_TRIGGER		(1)



#if defined(PL_BOARD_IS_FRDM)
#define PL_CONFIG_NOF_LED (3)
#define PL_CONFIG_NOF_KEYS (7)


#elif defined(PL_BOARD_IS_ROBO)
#define PL_CONFIG_NOF_LED (2)
#define PL_CONFIG_NOF_KEYS (1)
#define PL_CONFIG_DISABLE_HAS_JOYSTICK (1)
#define PL_CONFIG_HAS_BUZZER (1)

#else
#error "make sure you have platform defined in compiler settings!"
#endif

void PL_Init(void);
void PL_Deinit(void);

#endif /* SOURCES_INTRO_COMMON_MASTER_PLATFORM_H_ */
