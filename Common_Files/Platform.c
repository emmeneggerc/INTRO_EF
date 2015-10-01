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

void PL_Init(void) {
#if PL_CONFIG_HAS_LED
  LED_Init();
#endif
}

void PL_Deinit(void) {
#if PL_CONFIG_HAS_LED
  LED_Deinit();
#endif
}
