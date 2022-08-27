/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Systick.c
 *        \brief  Systick Driver
 *
 *      \details  The Driver Configures GPIO Pins 
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Systick.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
VoidFncVoid_t Systick_Callback = NULL_PTR;

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void Systick_Init(void)                                      
* \Description     : Initialize Systick timer by parsing the Configuration 
*                    into STCTRL/STRELOAD registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Systick_Init(void)
{
    /* 
     * STRCURRENT Systick current value:
     * 1. Register Map (Pg. 141):
     *      Reset:
     *      CURRENT = 0x00.0000
     *
     * 2. Functional Description (Pg. 123):
     * The SysTick counter reload and current value are undefined at reset.
     *
     */

    /* 1. Initialize Reload Register */
    STRELOAD = Systick_Config.ReloadValue;    

    /* 2. Clear the STCURRENT register by writing to it with any value */
    STCURRENT = SYSTICK_RELOADVALUE_MAX;

    /* 3. (A) Configure Clock Source */
    STCTRL.B.CLK_SRC = Systick_Config.CSR;

    /* 3. (B) Enable/Disable Systick Interrupt */
    STCTRL.B.INTEN = Systick_Config.IntStatus;

    /* 3. (C) Enable/Disable Systick Timer */
    STCTRL.B.ENABLE = Systick_Config.TimerStatus;
}

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
void Systick_Start(Systick_ValueType reloadValue)
{
    /* 1. Initialize Reload Register */
    STRELOAD = reloadValue;    

    /* 2. Clear the STCURRENT register by writing to it with any value */
    STCURRENT = SYSTICK_RELOADVALUE_MAX;

    /* 3. Enable Systick Timer */
    STCTRL.B.ENABLE = SYSTICK_TIMER_ENABLE;
}

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
void Systick_Stop(void)
{
    /* 3. Disable Systick Timer */
    STCTRL.B.ENABLE = SYSTICK_TIMER_DISABLE;
}

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
void Systick_SetCallbackFunction(VoidFncVoid_t Callback)
{
    /* Register callback function */
    if(Callback!=NULL_PTR)
       Systick_Callback = Callback;
}

/******************************************************************************
* \Syntax          : void SysTick_Handler(void)                                      
* \Description     : SysTick Handler in Vector Table.
*                    Keep it generic, and perform any interrupt handling
*                    in the callback function.
*                                                          
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SysTick_Handler(void)
{
    if(Systick_Callback!=NULL_PTR)
        Systick_Callback();
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
