/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port_Lcfg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
/* Port_ChannelType, */
const Port_ConfigType Port_Config[CONFIG_PORT_CHANNELS] = {
    {PORT_PIN_B0, PORT_PINMODE_DIO, STD_LOW, Port_Pin_Out, Port_PinInternalAttach_PullUp, Port_PinOutputCurrent_DR4},
    {PORT_PIN_B1, PORT_PINMODE_DIO, STD_LOW, Port_Pin_Out, Port_PinInternalAttach_PullDown, Port_PinOutputCurrent_DR8},
    {PORT_PIN_B2, PORT_PINMODE_DIO, STD_LOW, Port_Pin_Out, Port_PinInternalAttach_Off, Port_PinOutputCurrent_DR2},
    {PORT_PIN_B3, PORT_PINMODE_DIO, STD_LOW, Port_Pin_Out, Port_PinInternalAttach_Off, Port_PinOutputCurrent_DR2},
    {PORT_PIN_B4, PORT_PINMODE_DIO, STD_HIGH, Port_Pin_In, Port_PinInternalAttach_Off, Port_PinOutputCurrent_DR2},
    {PORT_PIN_B5, PORT_PINMODE_DIO, STD_HIGH, Port_Pin_In, Port_PinInternalAttach_Off, Port_PinOutputCurrent_DR2},
    {PORT_PIN_B6, PORT_PINMODE_DIO, STD_HIGH, Port_Pin_In, Port_PinInternalAttach_Off, Port_PinOutputCurrent_DR2},
    {PORT_PIN_B7, PORT_PINMODE_DIO, STD_HIGH, Port_Pin_In, Port_PinInternalAttach_Off, Port_PinOutputCurrent_DR2},
};


/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  END OF FILE: Port_Lcfg.c
 *********************************************************************************************************************/
