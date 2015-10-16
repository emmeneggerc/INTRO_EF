/*
 * Keys.h
 *
 *  Created on: 15.10.2015
 *      Author:  Mario Fischer & Cornel Emmenegger
 */

#ifndef SOURCES_COMMON_FILES_KEYS_H_
#define SOURCES_COMMON_FILES_KEYS_H_
#include "Platform.h"

#if PL_CONFIG_HAS_KEYS

typedef enum{	/* KEY_Buttons define*/
#if PL_CONFIG_NOF_KEYS >= 1
  KEY_BUTTON1,
#endif
#if PL_CONFIG_NOF_KEYS >= 2
  KEY_BUTTON2,
#endif
#if PL_CONFIG_NOF_KEYS >= 3
  KEY_BUTTON3,
#endif
#if PL_CONFIG_NOF_KEYS >= 4
  KEY_BUTTON4,
#endif
#if PL_CONFIG_NOF_KEYS >= 5
  KEY_BUTTON5,
#endif
#if PL_CONFIG_NOF_KEYS >= 6
  KEY_BUTTON6,
#endif
#if PL_CONFIG_NOF_KEYS >= 7
  KEY_BUTTON7,
#endif
 KEY_BTN_LAST /*!< must be last */

} KEY_Buttons ;



#if PL_CONFIG_NOF_KEYS>=1
  #include "SW1.h"
  #define KEY1_Get()  (!(SW1_GetVal())) /*Macro to get the value of the button 1*/
#else
  #define KEY1_Get()  FALSE  /*return 'not pressed', if the button doesn't exist*/
#endif

#if PL_CONFIG_NOF_KEYS>=2
  #include "SW2.h"
  #define KEY2_Get()  (!(SW2_GetVal())) /*Macro to get the value of the button 2*/
#else
  #define KEY2_Get()  FALSE
#endif

#if PL_CONFIG_NOF_KEYS>=3
  #include "SW3.h"
  #define KEY3_Get()  (!(SW3_GetVal())) /*Macro to get the value of the button 3*/
#else
  #define KEY3_Get()  FALSE  /*return 'not pressed', if the button doesn't exist*/
#endif

#if PL_CONFIG_NOF_KEYS>=4
  #include "SW4.h"
  #define KEY4_Get()  (!(SW4_GetVal())) /*Macro to get the value of the button 4 */
#else
  #define KEY4_Get()  FALSE  /*return 'not pressed', if the button doesn't exist*/
#endif

#if PL_CONFIG_NOF_KEYS>=5
  #include "SW5.h"
  #define KEY5_Get()  (!(SW5_GetVal())) /*Macro to get the value of the button 5*/
#else
  #define KEY5_Get()  FALSE  /*return 'not pressed', if the button doesn't exist*/
#endif

#if PL_CONFIG_NOF_KEYS>=6
  #include "SW6.h"
  #define KEY6_Get()  (!(SW6_GetVal())) /*Macro to get the value of the button 6*/
#else
  #define KEY6_Get()  FALSE  /*return 'not pressed', if the button doesn't exist*/
#endif

#if PL_CONFIG_NOF_KEYS>=7
  #include "SW7.h"
  #define KEY7_Get()  (!(SW7_GetVal())) /*Macro to get the value of the button 7*/
#else
  #define KEY7_Get()  FALSE  /*return 'not pressed', if the button doesn't exist*/
#endif


/*
 * \brief Checks the key status and generates the events.
 */
void KEY_Scan(void);

/*! \brief Get access to key hardware. Use KEY_Close() afterwards. */
void KEY_Open(void);

/*! \brief Finish access to key hardware. Called after KEY_Open(). */
void KEY_Close(void);

/*! \brief Key driver initialization */
void KEY_Init(void);

/*! \brief Key driver de-initialization */
void KEY_Deinit(void);


#endif  /*PL_CONFIG_HAS_KEYS*/

#endif /* SOURCES_COMMON_FILES_KEYS_H_ */
