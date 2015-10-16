/*
 * Keys.c
 *
 *  Created on: 15.10.2015
 *      Author: Mario Fischer & Cornel Emmenegger
 */

#include "Platform.h"
#if PL_CONFIG_HAS_KEYS
  #include "Keys.h"
#if PL_CONFIG_HAS_EVENTS
  #include "Event.h"
#endif

void KEY_Scan(void) {
  /* scan all the keys
   * only necessary for key 5&6, the other events will be generated
   * by button interrupts.
   */
#if PL_CONFIG_NOF_KEYS >= 1
  if (KEY1_Get()) {
    EVNT_SetEvent(EVNT_SW1_PRESSED);
  }
#endif

#if PL_CONFIG_NOF_KEYS >= 2
  if (KEY2_Get()) {
    EVNT_SetEvent(EVNT_SW2_PRESSED);
  }
#endif

#if PL_CONFIG_NOF_KEYS >= 3
  if (KEY3_Get()) {
    EVNT_SetEvent(EVNT_SW3_PRESSED);
  }
#endif

#if PL_CONFIG_NOF_KEYS >= 4
  if (KEY4_Get()) {
    EVNT_SetEvent(EVNT_SW4_PRESSED);
  }
#endif

#if PL_CONFIG_NOF_KEYS >= 5
  if (KEY5_Get()) {
    EVNT_SetEvent(EVNT_SW5_PRESSED);
  }
#endif

#if PL_CONFIG_NOF_KEYS >= 6
  if (KEY6_Get()) {
    EVNT_SetEvent(EVNT_SW6_PRESSED);
  }
#endif

#if PL_CONFIG_NOF_KEYS >= 7
  if (KEY7_Get()) {
    EVNT_SetEvent(EVNT_SW7_PRESSED);
  }
#endif

}

/* Key driver initialization */
void KEY_Init(void) {
  /* nothing needed for now */
}

/* Key driver deinitialization */
void KEY_Deinit(void) {
  /* nothing needed for now */
}
#endif /* PL_HAS_KEYS */


