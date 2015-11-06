/**
 * \file
 * \brief Real Time Operating System (RTOS) main program.
 * \author Erich Styger, erich.styger@hslu.ch
 */

#include "Platform.h"
#if PL_CONFIG_HAS_RTOS
#include "RTOS.h"
#include "FRTOS1.h"
#include "LED.h"
#include "Event.h"
#include "Keys.h"
#include "Application.h"

#define TEST_RTOS_TASKS  (1)

static volatile bool SW1Pressed = FALSE;

void RTOS_ButtonSW1Press(void) {
	SW1Pressed = TRUE;
}

#if TEST_RTOS_TASKS
static void Task1(void* param) {
for(;;) {
	FRTOS1_vTaskDelay(500);
#if PL_CONFIG_NOF_LED>=1
	LED1_Neg();
#endif

}
}

static void Task2(void* param) {
for(;;) {
FRTOS1_vTaskDelay(500);
#if PL_CONFIG_NOF_LED>=2
LED2_Neg();
#endif
}
}
#endif

static void AppTask(void* param) {
for (;;) {
EVNT_HandleEvent(APP_HandleEvent);
#if PL_CONFIG_HAS_KEYS && PL_CONFIG_NOF_KEYS >=0
KEY_Scan();
#endif
}
PL_Deinit();
}

void RTOS_Run(void) {
FRTOS1_vTaskStartScheduler(); /* does usually not return! */
}

void RTOS_Init(void) {
/*! \todo Add tasks here */

if (FRTOS1_xTaskCreate(AppTask, (signed portCHAR *)"App",
	configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL) != pdPASS) {
for (;;) { /*error*/
}
}
#if TEST_RTOS_TASKS
if (FRTOS1_xTaskCreate(Task1, (signed portCHAR *)"T2", configMINIMAL_STACK_SIZE,
	NULL, tskIDLE_PRIORITY, NULL) != pdPASS) {
for (;;) {
	/*error*/
}
}

if (FRTOS1_xTaskCreate(Task2, (signed portCHAR *)"T3", configMINIMAL_STACK_SIZE,
	NULL, tskIDLE_PRIORITY, NULL) != pdPASS) {
for (;;) {
	/*error*/
}
}

#endif

}

void RTOS_Deinit(void) {
/* nothing needed */
}

#endif /* PL_HAS_RTOS */
