/**
 * \file
 * \brief Timer driver
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This module implements the driver for all our timers.
  */

#include "Platform.h"
#if PL_CONFIG_HAS_TIMER
#include "Timer.h"
#include "Event.h"
#if PL_CONFIG_HAS_TRIGGER
#include "Trigger.h"
#endif
#if PL_CONFIG_HAS_BUZZER
#include "Buzzer.h"
#endif

void TMR_OnInterrupt(void) {
#define DELAY_TIMER_MS 1000
  static int counter = 0;
  counter++;
  if(counter%(DELAY_TIMER_MS / TMR_TICK_MS)==0){
	  EVNT_SetEvent(EVENT_LED_HEARTBEAT);
  }
#if PL_CONFIG_HAS_TRIGGER
  TRG_IncTick();
#endif

}

void TMR_Init(void) {
  /* nothing needed right now */
}

void TMR_Deinit(void) {
  /* nothing needed right now */
}

#endif /*PL_HAS_TIMER*/
