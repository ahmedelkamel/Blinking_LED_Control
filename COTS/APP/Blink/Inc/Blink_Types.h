/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Blink_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef BLINK_TYPES_H
#define BLINK_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "LED.h"
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
   typedef uint8 Blink_StatusType;
   typedef uint8 Blink_TimerFlagType;
   typedef uint32 Blink_TickType;
   /* Time in miliseconds */
   typedef uint32 Blink_TimeType;
   
   typedef struct {
      LED_IDType Blink_LEDID;
      Blink_StatusType Blink_Status;
      Blink_TimeType OnTime;
      Blink_TimeType OffTime;
   } Blink_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
   

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


 
#endif  /* BLINK_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: Blink_Types.h
 *********************************************************************************************************************/