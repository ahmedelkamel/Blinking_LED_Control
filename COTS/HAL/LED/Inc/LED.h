/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  LED.h
 *       Module:  LED
 *
 *  Description:  header file for LED Module    
 *  
 *********************************************************************************************************************/
#ifndef LED_H
#define LED_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "LED_Types.h"
#include "LED_Cfg.h"
#include "IntCtrl.h"
#include "Port.h"
#include "Dio.h"
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/* LED Config. */
extern const LED_ConfigType LED_Config[LED_CONFIG_DEVS];

    
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
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
void LED_Init(LED_ConfigType* LED_Config);

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
void LED_WriteStatus(LED_IDType LED_ID, LED_StatusType LED_Status);

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
LED_StatusType LED_ReadStatus(LED_IDType LED_ID);
 

#endif  /* LED_H */

/**********************************************************************************************************************
 *  END OF FILE: LED.h
 *********************************************************************************************************************/
