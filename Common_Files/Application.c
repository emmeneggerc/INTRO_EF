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
#if PL_CONFIG_HAS_SHELL
  #include "CLS1.h"
#endif


#if PL_CONFIG_HAS_KEYS
void APP_KeyEvntHandler(EVNT_Handle event) {

  switch(event) {

#if PL_CONFIG_NOF_KEYS >= 1
  case EVNT_SW1_PRESSED:
  #if !PL_CONFIG_EVENTS_AUTO_CLEAR
    EVNT_ClearEvent(EVNT_SW1_PRESSED);
  #endif
  #if PL_CONFIG_HAS_SHELL
    CLS1_SendStr("SW1 pressed\r\n", CLS1_GetStdio()->stdOut);
  #endif
    break;
#endif

#if PL_CONFIG_NOF_KEYS >= 2
    case EVNT_SW2_PRESSED:
    #if !PL_CONFIG_EVENTS_AUTO_CLEAR
      EVNT_ClearEvent(EVNT_SW2_PRESSED);
    #endif
#if PL_CONFIG_HAS_SHELL
    CLS1_SendStr("SW2 pressed\r\n",CLS1_GetStdio()->stdOut);
  #endif
      break;
#endif

#if PL_CONFIG_NOF_KEYS >= 3
 case EVNT_SW3_PRESSED:
 #if !PL_CONFIG_EVENTS_AUTO_CLEAR
    EVNT_ClearEvent(EVNT_SW3_PRESSED);
  #endif
#if PL_CONFIG_HAS_SHELL
    CLS1_SendStr("SW3 pressed\r\n", CLS1_GetStdio()->stdOut);
  #endif
    break;
#endif

#if PL_CONFIG_NOF_KEYS >= 4
   case EVNT_SW4_PRESSED:
   #if !PL_CONFIG_EVENTS_AUTO_CLEAR
     EVNT_ClearEvent(EVNT_SW4_PRESSED);
   #endif
#if PL_CONFIG_HAS_SHELL
    CLS1_SendStr("SW4 pressed\r\n", CLS1_GetStdio()->stdOut);
  #endif
     break;
#endif

#if PL_CONFIG_NOF_KEYS >= 5
  case EVNT_SW5_PRESSED:
  #if !PL_CONFIG_EVENTS_AUTO_CLEAR
    EVNT_ClearEvent(EVNT_SW5_PRESSED);
  #endif
#if PL_CONFIG_HAS_SHELL
    CLS1_SendStr("SW5 pressed\r\n", CLS1_GetStdio()->stdOut);
  #endif
    break;
#endif

#if PL_CONFIG_NOF_KEYS >= 6
   case EVNT_SW6_PRESSED:
   #if !PL_CONFIG_EVENTS_AUTO_CLEAR
     EVNT_ClearEvent(EVNT_SW6_PRESSED);
   #endif
#if PL_CONFIG_HAS_SHELL
    CLS1_SendStr("SW6 pressed\r\n", CLS1_GetStdio()->stdOut);
  #endif
     break;
#endif

#if PL_CONFIG_NOF_KEYS >= 7
  case EVNT_SW7_PRESSED:
  #if !PL_CONFIG_EVENTS_AUTO_CLEAR
    EVNT_ClearEvent(EVNT_SW7_PRESSED);
  #endif
#if PL_CONFIG_HAS_SHELL

    CLS1_SendStr("SW7 pressed\r\n", CLS1_GetStdio()->stdOut);
  #endif

   break;
#endif

  default:
	  break;
  }

 }
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
#if PL_CONFIG_HAS_KEYS
		APP_KeyEvntHandler(event);
#endif

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


