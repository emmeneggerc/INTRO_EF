/*
 * Application.c
 *
 *  Created on: 30.09.2015
 *      Author: Cornel
 */

#include "Platform.h"
#include "Application.h"
#include "WAIT1.h"
#if PL_CONFIG_HAS_LED
  #include "LED.h"
#endif

void APP_Run(void) {
  PL_Init();
  for(;;) {
#if PL_CONFIG_HAS_LED
#if PL_CONFIG_NOF_LED>=1
    LED1_Neg();
#endif
    WAIT1_Waitms(100);
#if PL_CONFIG_NOF_LED>=2
    LED2_Neg();
#endif
    WAIT1_Waitms(100);
#if PL_CONFIG_NOF_LED>=3
    LED3_Neg();
#endif
    WAIT1_Waitms(100);
#endif
  }
  PL_Deinit();
}
