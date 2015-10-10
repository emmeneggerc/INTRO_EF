/*
 * Application.c
 *
 *  Created on: 30.09.2015
 *      Author: Cornel
 */

#include "Platform.h"
#include "Application.h"
#include "Event.h"
#include "WAIT1.h"
#if PL_CONFIG_HAS_LED
  #include "LED.h"
#endif

void APP_HandleEvent(EVNT_Handle event){
	switch (event){
	case EVNT_STARTUP:
#if PL_CONFIG_NOF_LED>= 1
		LED1_On();
#endif
		break;
	case EVENT_LED_HEARTBEAT:
#if PL_CONFIG_NOF_LED == 1
		LED1_Neg();
		#endif
		#if PL_CONFIG_NOF_LED > 1
		LED2_Neg();
#endif
		break;

	default:
		break;
	}


}

void APP_Run(void) {
  PL_Init();
  EVNT_SetEvent(EVNT_STARTUP);
  for(;;) {
	  EVNT_HandleEvent(APP_HandleEvent);
  }
  PL_Deinit();
}


