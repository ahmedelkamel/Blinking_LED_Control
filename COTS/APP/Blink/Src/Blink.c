/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Blink.c
 *        \brief  Blink Driver
 *
 *      \details  The Driver Configures GPIO Pins 
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Blink.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	


/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
volatile static Blink_TimerFlagType Blink_TimerFlag;
volatile static Blink_StatusType Blink_Status;
volatile static Blink_TickType Blink_TimerExten;
volatile static Blink_TickType Blink_OnTicks;
volatile static Blink_TickType Blink_OffTicks;
volatile static Blink_TickType Blink_TargetTicks;
volatile static Blink_TickType Blink_ReloadValue;

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void Blink_TimerCallback(void)                                      
* \Description     : Callback function passed to Systick Driver.
*                    This function is called in Systick interrupt handler.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Blink_TimerCallback(void);


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void Blink_TimerCallback(void)                                      
* \Description     : Callback function passed to Systick Driver.
*                    This function is called in Systick interrupt handler.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Blink_TimerCallback(void)
{
    /* Raise Flag */
    Blink_TimerFlag = STD_HIGH;
}



/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void Blink_Init(void)                                      
* \Description     : initialize Blink App.                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Blink_Init(void)
{
    /* Init. LED Module */
    LED_Init(LED_Config);

    /* Systick ISR callback registeration */
    Systick_SetCallbackFunction(Blink_TimerCallback);
    /* Systick Init. */
    Systick_Init();

    /* Blink Status: LED ON or OFF */
    Blink_Status = Blink_Config.Blink_Status;
    /* Calculate On/Off Ticks */
    Blink_OnTicks = SYSTICK_MS_TO_TICKS(Blink_Config.OnTime);
    Blink_OffTicks = SYSTICK_MS_TO_TICKS(Blink_Config.OffTime);

    /* Initialize LED Status */
    LED_WriteStatus(Blink_Config.Blink_LEDID, Blink_Status);

    /* Timer ISR Flag: OFF by default */
    Blink_TimerFlag = STD_LOW;
    /* Init. Target Ticks */
    Blink_TargetTicks = Blink_Status?Blink_OnTicks:Blink_OffTicks;

		/* Extract higher bits */
		Blink_TimerExten = Blink_TargetTicks >> STRELOAD_RELOAD_BITS;
		/* Reload Remaining ticks */
		Blink_ReloadValue = Blink_TargetTicks - (Blink_TimerExten<<STRELOAD_RELOAD_BITS);
    /* Start Systick Timer */
    Systick_Start(Blink_ReloadValue);
}

/******************************************************************************
* \Syntax          : void Blink_Running(void)                                      
* \Description     : Running function.
*                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Blink_Running(void)
{
    /* Systick done counting? */
    if(Blink_TimerFlag)
    {
        Systick_Stop();
				/* Not Previously loaded w/ Max val.? */
        if(Blink_ReloadValue < SYSTICK_RELOADVALUE_MAX)
        {
					/* Reload with Max val. */
					Blink_ReloadValue = SYSTICK_RELOADVALUE_MAX;
        }
				/* Previously loaded w/ Max val.: Decrement Timer Extension */
				else
					{Blink_TimerExten--;}

        /* No remaining ticks? */
        /* Flip state */
				if(Blink_TimerExten<=0)
        {   
            /* Previous status: HIGH */
            if(Blink_Status == STD_HIGH)
            {
                Blink_Status = STD_LOW;
                Blink_TargetTicks = Blink_OffTicks;
            }
            /* Previous status: LOW */
            else
            {
                Blink_Status = STD_HIGH;
                Blink_TargetTicks = Blink_OnTicks;
            }
						/* Extract higher bits */
						Blink_TimerExten = Blink_TargetTicks >> STRELOAD_RELOAD_BITS;
						/* Reload remaining ticks */
						Blink_ReloadValue = Blink_TargetTicks - (Blink_TimerExten<<STRELOAD_RELOAD_BITS);
            /* Update LED Status accordingly */
            LED_WriteStatus(Blink_Config.Blink_LEDID, Blink_Status);
				}
				/* Lower timer flag */
				Blink_TimerFlag = STD_LOW;
        /* Start Systick Timer */
        Systick_Start(Blink_ReloadValue);
    }
}



/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
