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
#if PL_CONFIG_HAS_DEBOUNCE
  #include "KeyDebounce.h"
#endif

void KEY_Scan(void) {
  /* scan all the keys
   * only necessary for key 5&6, the other events will be generated
   * by button interrupts.
   */
#if PL_CONFIG_HAS_DEBOUNCE
  KEYDBNC_Process();
#else

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
#endif
}


#if PL_CONFIG_HAS_KBI
void KEY_EnableInterrupts(void) {
#if PL_CONFIG_NOF_KEYS >= 1
  SWI1_Enable();
#endif
#if PL_CONFIG_NOF_KEYS >= 2
  SWI2_Enable();
#endif
#if PL_CONFIG_NOF_KEYS >= 3
  SWI3_Enable();
#endif
#if PL_CONFIG_NOF_KEYS >= 4
  SWI4_Enable();
#endif
#if PL_CONFIG_NOF_KEYS >= 7
  SWI7_Enable();
#endif
}
#endif /* PL_CONFIG_HAS_KBI */


#if PL_CONFIG_HAS_KBI
void KEY_DisableInterrupts(void) {
#if PL_CONFIG_NOF_KEYS >= 1
 SWI1_Disable();
#endif

#if PL_CONFIG_NOF_KEYS >= 2
  SWI2_Disable();
#endif
#if PL_CONFIG_NOF_KEYS >= 3
  SWI3_Disable();
#endif
#if PL_CONFIG_NOF_KEYS >= 4
  SWI4_Disable();
#endif
#if PL_CONFIG_NOF_KEYS >= 7
  SWI7_Disable();
#endif
}
#endif /* PL_CONFIG_HAS_KBI */


#if PL_CONFIG_HAS_KBI
void KEY_OnInterrupt(KEY_Buttons button) {
#if PL_CONFIG_HAS_DEBOUNCE
  KEYDBNC_Process();
#else
  switch(button) {
#if PL_CONFIG_NOF_KEYS >= 1
    case KEY_BTN1: EVNT_SetEvent(EVNT_SW1_PRESSED); break;
#endif
#if PL_CONFIG_NOF_KEYS >= 2
    case KEY_BTN2: EVNT_SetEvent(EVNT_SW2_PRESSED); break;
#endif
#if PL_CONFIG_NOF_KEYS >= 3
    case KEY_BTN3: EVNT_SetEvent(EVNT_SW3_PRESSED); break;
#endif
#if PL_CONFIG_NOF_KEYS >= 4
    case KEY_BTN4: EVNT_SetEvent(EVNT_SW4_PRESSED); break;
#endif
#if PL_CONFIG_NOF_KEYS >= 5
    case KEY_BTN5: EVNT_SetEvent(EVNT_SW5_PRESSED); break;
#endif
#if PL_CONFIG_NOF_KEYS >= 6
    case KEY_BTN6: EVNT_SetEvent(EVNT_SW6_PRESSED); break;
#endif
#if PL_CONFIG_NOF_KEYS >= 7
    case KEY_BTN7: EVNT_SetEvent(EVNT_SW7_PRESSED); break;
#endif
    default:
      /* unknown? */
      break;
  } /* switch */
#endif
}
#endif /* PL_CONFIG_HAS_KBI */


/* Key driver initialization */
void KEY_Init(void) {
  /* nothing needed for now */
}

/* Key driver deinitialization */
void KEY_Deinit(void) {
  /* nothing needed for now */
}
#endif /* PL_HAS_KEYS */


