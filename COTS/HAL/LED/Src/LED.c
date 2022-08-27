/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  LED.c
 *        \brief  LED Driver
 *
 *      \details  The Driver Configures GPIO Pins 
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "LED.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	


/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/


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
* \Syntax          : void LED_Init(LED_ConfigType* LED_Config)                                      
* \Description     : Initialize LED Module.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void LED_Init(LED_ConfigType* LED_Config)
{
    LED_IDType i;
    /* Init. Interrupt Driver */
    IntCrtl_Init();
    /* Init. Port Driver */
    Port_Init(Port_Config);
    /* Loop over LED Devices */
    for (i=0; i<LED_CONFIG_DEVS; i++)
    {
        Dio_WriteChannel(LED_Config[i].LED_DioChannel, LED_Config[i].LED_Status);
    }
}

/******************************************************************************
* \Syntax          : void LED_WriteStatus(LED_IDType LED_ID, LED_StatusType LED_Status)                            
* \Description     : Write LED_Status to LED device specified by LED_ID.                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void LED_WriteStatus(LED_IDType LED_ID, LED_StatusType LED_Status)
{
    /* Get Dio Channel from specified LED ID */
    Dio_ChannelType LED_DioChannelID = LED_Config[LED_ID].LED_DioChannel;   
    /* Modify LED Status */
    Dio_WriteChannel(LED_DioChannelID, LED_Status);
}

/******************************************************************************
* \Syntax          : LED_StatusType LED_ReadStatus(LED_IDType LED_ID)                                    
* \Description     : Return LED_Status of LED specifiedby LED_ID. 
*                                                  
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
LED_StatusType LED_ReadStatus(LED_IDType LED_ID)
{
    /* Get Dio Channel from specified LED ID */
    Dio_ChannelType LED_DioChannelID = LED_Config[LED_ID].LED_DioChannel;   
    /* Read Status */
    return Dio_ReadChannel(LED_DioChannelID);
}

/**********************************************************************************************************************
 *  END OF FILE: LED.c
 *********************************************************************************************************************/
