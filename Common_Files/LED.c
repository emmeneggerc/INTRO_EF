/*
 * LED.c
 *
 *  Created on: 25.09.2015
 *      Author: tastyger
 */


#include "Platform.h"
#if PL_CONFIG_HAS_LED
#include "LED.h"

void LED_Init(void) {
#if PL_CONFIG_NOF_LED>=1
  LED1_Off();
#endif
#if PL_CONFIG_NOF_LED>=2
  LED2_Off();
#endif
#if PL_CONFIG_NOF_LED>=3
  LED3_Off();
#endif
#if PL_CONFIG_NOF_LED>=4
  #error "only 3 LEDs supported"
#endif
}

void LED_Deinit(void) {
#if PL_CONFIG_NOF_LED>=1
  LED1_Off();
#endif
#if PL_CONFIG_NOF_LED>=2
  LED2_Off();
#endif
#if PL_CONFIG_NOF_LED>=3
  LED3_Off();
#endif
#if PL_CONFIG_NOF_LED>=4
  #error "only 3 LEDs supported"
#endif
}
#endif /* PL_CONFIG_HAS_LED */
