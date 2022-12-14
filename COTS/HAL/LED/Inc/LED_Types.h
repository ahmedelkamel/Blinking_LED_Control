/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  LED_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef LED_TYPES_H
#define LED_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio.h"
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
  /*
  * LED_StatusType:
  * values defined in "Std_Types.h"
  * STD_LOW
  * STD_HIGH
  */
  typedef uint8 LED_StatusType;

  /* Index specifies LED_ID in LED_Config[] */
  typedef uint8 LED_IDType;
   
  typedef struct{
    /* Associated Dio Channel */
    Dio_ChannelType LED_DioChannel;
    LED_StatusType LED_Status;
  }LED_ConfigType;


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
   

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


 
#endif  /* LED_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: LED_Types.h
 *********************************************************************************************************************/
