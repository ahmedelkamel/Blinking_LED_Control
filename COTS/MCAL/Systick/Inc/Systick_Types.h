/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Systick_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef SYSTICK_TYPES_H
#define SYSTICK_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
   typedef uint8 Systick_TimerStatusType;

   typedef uint8 Systick_IntStatusType;

   typedef uint8 Systick_CSRType;

   typedef uint32 Systick_ValueType;

   typedef struct {
      Systick_TimerStatusType TimerStatus;
      Systick_IntStatusType IntStatus;
      Systick_CSRType CSR;
      Systick_ValueType ReloadValue;
   } Systick_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
   /* Systick Timer Status         */
   #define SYSTICK_TIMER_DISABLE               ((Systick_TimerStatusType)0)
   #define SYSTICK_TIMER_ENABLE                ((Systick_TimerStatusType)1)
   /* Systick Interrupt Status     */
   #define SYSTICK_INT_DISABLE                 ((Systick_IntStatusType)0)
   #define SYSTICK_INT_ENABLE                  ((Systick_IntStatusType)1)
   /* Systick Clock Source         */   
   #define SYSTICK_CSR_PIOSC                   ((Systick_CSRType)0)
   #define SYSTICK_CSR_SYSCLK                  ((Systick_CSRType)1)
   /* Systick Max Reload Value     */   
   #define SYSTICK_RELOADVALUE_MAX             ((Systick_ValueType)0xFFFFFF)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


 
#endif  /* SYSTICK_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: Systick_Types.h
 *********************************************************************************************************************/
