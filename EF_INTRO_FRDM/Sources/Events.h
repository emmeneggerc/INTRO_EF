/* ###################################################################
**     Filename    : Events.h
**     Project     : EF_INTRO_FRDM
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-09-25, 14:04, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "WAIT1.h"
#include "SWI2.h"
#include "ExtIntLdd2.h"
#include "SWI3.h"
#include "ExtIntLdd3.h"
#include "SWI4.h"
#include "ExtIntLdd4.h"
#include "SWI5.h"
#include "BitIoLdd8.h"
#include "SWI6.h"
#include "BitIoLdd9.h"
#include "SWI7.h"
#include "ExtIntLdd5.h"
#include "CLS1.h"
#include "UTIL1.h"
#include "AS1.h"
#include "ASerialLdd2.h"
#include "LED1.h"
#include "LEDpin1.h"
#include "LED2.h"
#include "LEDpin2.h"
#include "LED3.h"
#include "LEDpin3.h"
#include "BitIoLdd1.h"
#include "BitIoLdd2.h"
#include "BitIoLdd3.h"
#include "Timer1.h"
#include "TimerIntLdd1.h"
#include "TU1.h"
#include "CS1.h"
#include "HF1.h"
#include "SWI1.h"
#include "ExtIntLdd1.h"



#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MKL25Z128LK4]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMIINT(void);


/*
** ===================================================================
**     Event       :  Timer1_OnInterrupt (module Events)
**
**     Component   :  Timer1 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Timer1_OnInterrupt(void);

void SWI3_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  SWI3_OnInterrupt (module Events)
**
**     Component   :  SWI3 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void SWI2_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  SWI2_OnInterrupt (module Events)
**
**     Component   :  SWI2 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void SWI1_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  SWI1_OnInterrupt (module Events)
**
**     Component   :  SWI1 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void SWI7_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  SWI7_OnInterrupt (module Events)
**
**     Component   :  SWI7 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void SWI4_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  SWI4_OnInterrupt (module Events)
**
**     Component   :  SWI4 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
