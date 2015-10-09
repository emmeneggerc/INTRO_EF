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
<<<<<<< HEAD
#define PL_CONFIG_HAS_LED   (1 && !defined(PL_CONFIG_DISABLE_HAS_LED))
#define PL_CONFIG_HAS_TIMER   (1 && !defined(PL_CONFIG_DISABLE_HAS_TIMER))
=======
#define PL_CONFIG_HAS_LED   		(1 && !defined(PL_CONFIG_DISABLE_HAS_LED))
#define PL_CONFIG_HAS_EVENTS        (1 && !defined(PL_CONFIG_DISABLE_HAS_EVENTS))
>>>>>>> fa9a812a44db8be0ea2972b5f763d0c3add277dc

#if 0 /* another way, if configured for compiler define */
#if defined(PL_BOARD_IS_FRDM)
  #define PL_CONFIG_NOF_LEDS (3)
#elif defined(PL_BOARD_IS_ROBO)
  #define PL_CONFIG_NOF_LEDS (2)
#else
  #error "make sure you have platform defined in compiler settings!"
#endif
#endif


void PL_Init(void);
void PL_Deinit(void);


#endif /* SOURCES_INTRO_COMMON_MASTER_PLATFORM_H_ */