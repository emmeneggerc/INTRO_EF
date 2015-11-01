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
#if PL_CONFIG_HAS_EVENTS
#include "Event.h"
#endif
#if PL_CONFIG_HAS_TIMER
#include "Timer.h"
#endif
#if PL_CONFIG_HAS_TRIGGER
#include "Trigger.h"
#endif

void PL_Init(void) {
#if PL_CONFIG_HAS_LED
	LED_Init();
#endif
#if PL_CONFIG_HAS_EVENTS
	EVNT_Init();
#endif
#if PL_CONFIG_HAS_TIMER
	TMR_Init();
#endif
#if PL_CONFIG_HAS_TRIGGER
	TRG_Init();
#endif


}

void PL_Deinit(void) {
#if PL_CONFIG_HAS_LED
	LED_Deinit();
#endif
#if PL_CONFIG_HAS_EVENTS
	EVNT_Deinit();
#endif
#if PL_CONFIG_HAS_TIMER
	TMR_Deinit();
#endif
#if PL_CONFIG_HAS_TRIGGER
	TRG_Deinit();
#endif

}
