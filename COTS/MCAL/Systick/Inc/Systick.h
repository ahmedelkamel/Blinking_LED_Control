/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Systick.h
 *       Module:  Systick
 *
 *  Description:  header file for Systick Module    
 *  
 *********************************************************************************************************************/
#ifndef SYSTICK_H
#define SYSTICK_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Systick_Types.h"
#include "Systick_Cfg.h"
#include "Bit_Math.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* System Clock Freq.: 12Mhz        */
#define SYS_CLK_FREQ                ((uint32)12e6)
#define SYSTICK_TICKS_PER_SEC       SYS_CLK_FREQ


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define S_TO_MS(Time)               ((uint32)Time*1000)
#define MS_TO_S(Time)               ((float32)Time/1000)
#define SYSTICK_MS_TO_TICKS(Time)   ((uint32)(MS_TO_S(Time)*SYS_CLK_FREQ))

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/* Systick Config. */
extern const Systick_ConfigType Systick_Config;

    
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
/******************************************************************************
* \Syntax          : void Systick_Init(void)                                      
* \Description     : initialize Systick Timer by parsing the Configuration 
*                    into STCTRL/STRELOAD registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Systick_Init(void);

/******************************************************************************
* \Syntax          : void Systick_Start(Systick_ValueType reloadValue)                                      
* \Description     : Reload Systick Reload Reg. by the passed reloadValue, 
*                    clears Systick Current Reg. and enables the Systick timer.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Systick_Start(Systick_ValueType reloadValue);

/******************************************************************************
* \Syntax          : void Systick_Stop(void)                                      
* \Description     : Disables/Stops Systick timer.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Systick_Stop(void);

/******************************************************************************
* \Syntax          : void Systick_SetCallback(VoidFncVoid_t Callback)                                      
* \Description     : Register callback function.
*                    This function will be called when an interrupt is active.                                    
*                    A higher abstraction layer is likely to use this.
*                                                          
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Systick_SetCallbackFunction(VoidFncVoid_t Callback);
 

#endif  /* SYSTICK_H */

/**********************************************************************************************************************
 *  END OF FILE: Systick.h
 *********************************************************************************************************************/
