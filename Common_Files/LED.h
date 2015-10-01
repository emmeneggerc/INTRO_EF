/*
 * LED.h
 *
 *  Created on: 30.09.2015
 *      Author: Cornel
 */

#ifndef SOURCES_COMMON_FILES_LED_H_
#define SOURCES_COMMON_FILES_LED_H_


#include "Platform.h"

#if PL_CONFIG_NOF_LED>=1
  #include "LED1.h"
#endif
#if PL_CONFIG_NOF_LED>=2
  #include "LED2.h"
#endif
#if PL_CONFIG_NOF_LED>=3
  #include "LED3.h"
#endif

void LED_Init(void);
void LED_Deinit(void);



#endif /* SOURCES_COMMON_FILES_LED_H_ */

/* Hallo Cornel */
/* Mech darf mer loesche */
