/*
 * Application.c

 *
 *  Created on: 30.09.2015
 *      Author: Cornel & Mario
 */

#include "Platform.h"
#include "Application.h"
#include "WAIT1.h"
#include "Keys.h"

#if PL_CONFIG_HAS_LED
#include "LED.h"
#endif

#if PL_CONFIG_HAS_SHELL
#include "CLS1.h"
#endif

#if PL_CONFIG_HAS_BUZZER
#include "Buzzer.h"
#endif

#if PL_CONFIG_HAS_TETRIS
#include "Tetris.h"
#endif

#if PL_CONFIG_HAS_RTOS
#include "RTOS.h"
#endif

#if PL_CONFIG_HAS_REMOTE
#include "RApp.h"
#include "RNet_App.h"
#endif
#if PL_CONFIG_HAS_KEYS
void APP_KeyEvntHandler(EVNT_Handle event) {
#if PL_CONFIG_HAS_REMOTE
	uint8_t	data;
#endif
	switch (event) {

#if PL_CONFIG_NOF_KEYS >= 1
	case EVNT_SW1_PRESSED:
#if !PL_CONFIG_EVENTS_AUTO_CLEAR
		EVNT_ClearEvent(EVNT_SW1_PRESSED);
#endif
#if PL_CONFIG_HAS_SHELL
		CLS1_SendStr("SW1 pressed\r\n", CLS1_GetStdio()->stdOut);

#endif
#if PL_CONFIG_HAS_BUZZER
		BUZ_Beep(500, 500);

#endif
#if PL_CONFIG_HAS_REMOTE
		data = 'A';
		(void)RAPP_SendPayloadDataBlock(&data, sizeof(data), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_REQ_ACK);
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
#if PL_CONFIG_HAS_REMOTE
		data = 'B';
		(void)RAPP_SendPayloadDataBlock(&data, sizeof(data), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_REQ_ACK);
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
#if PL_CONFIG_HAS_REMOTE
		data = 'C';
		(void)RAPP_SendPayloadDataBlock(&data, sizeof(data), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_REQ_ACK);
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
#if PL_CONFIG_HAS_REMOTE
		data = 'D';
		(void)RAPP_SendPayloadDataBlock(&data, sizeof(data), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_REQ_ACK);
#endif
		break;
#endif

#if PL_CONFIG_NOF_KEYS >= 5
		case EVNT_SW5_PRESSED:
#if !PL_CONFIG_EVENTS_AUTO_CLEAR
		EVNT_ClearEvent(EVNT_SW5_PRESSED);
#endif
#if PL_CONFIG_HAS_SHELL
#if PL_CONFIG_HAS_TETRIS
		CLS1_SendStr("launching Tetris...\r\n", CLS1_GetStdio()->stdOut);
		TETRIS_Start();
#endif
#else
		CLS1_SendStr("SW5 pressed\r\n", CLS1_GetStdio()->stdOut);
#endif
#if PL_CONFIG_HAS_REMOTE
		data = 'E';
		(void)RAPP_SendPayloadDataBlock(&data, sizeof(data), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_REQ_ACK);
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
#if PL_CONFIG_HAS_REMOTE
		data = 'F';
		(void)RAPP_SendPayloadDataBlock(&data, sizeof(data), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_REQ_ACK);
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
#if PL_CONFIG_HAS_REMOTE
		data = 'G';
		(void)RAPP_SendPayloadDataBlock(&data, sizeof(data), RAPP_MSG_TYPE_JOYSTICK_BTN, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_REQ_ACK);
#endif
		break;
#endif

	default:
		break;
	}

}
#endif

void APP_HandleEvent(EVNT_Handle event) {
	switch (event) {
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

void App(void){
	EVNT_HandleEvent(APP_HandleEvent);
			KEY_Scan();
	#if PL_CONFIG_HAS_TETRIS
			TETRIS_Run();
	#endif
}

void APP_Run(void) {
	PL_Init();
#if PL_CONFIG_HAS_RTOS
	EVNT_SetEvent(EVNT_STARTUP);
	RTOS_Run();
#else
	for(,,){
		App();
	}
	PL_Deinit();

#endif
}

