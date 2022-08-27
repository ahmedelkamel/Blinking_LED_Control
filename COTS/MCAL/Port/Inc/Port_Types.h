/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* API Types */
/********************************************************
 * [I] API_Types (enum/typedef-Macro)
 *    1. Port_PinType (pin)         : A0/A1/A2/...etc. 
 *    2. Port_PinDirectionType      : Input/Output
 *    3. Port_PinModeType           : DIO/UART/ADC/External_Interrupt/Alternate_function (???)
 *    4. Port_PinInternalAttachType : Pullup/Pulldown/OpenDrain
 *    5. Port_PinOutputCurrentType  : (2/4/8)mA (DIO - Output Direction) 
 *    6. Port_ConfigType            : struct (Pin Config.) 
 *    7. Port_PinLevelValueType     : STD_LOW/STD_HIGH
 ********************************************************/

/* MACRO uint8/16/32 */
/* [1] Pin Type (43 pins) */
typedef uint8 Port_PinType;
/* Port A Pins */
#define PORT_PIN_A0              ((Port_PinType) 0)
#define PORT_PIN_A1              ((Port_PinType) 1)
#define PORT_PIN_A2              ((Port_PinType) 2)
#define PORT_PIN_A3              ((Port_PinType) 3)
#define PORT_PIN_A4              ((Port_PinType) 4)
#define PORT_PIN_A5              ((Port_PinType) 5)
#define PORT_PIN_A6              ((Port_PinType) 6)
#define PORT_PIN_A7              ((Port_PinType) 7)
/* Port B Pins */
#define PORT_PIN_B0              ((Port_PinType) 8)
#define PORT_PIN_B1              ((Port_PinType) 9)
#define PORT_PIN_B2              ((Port_PinType)10)
#define PORT_PIN_B3              ((Port_PinType)11)
#define PORT_PIN_B4              ((Port_PinType)12)
#define PORT_PIN_B5              ((Port_PinType)13)
#define PORT_PIN_B6              ((Port_PinType)14)
#define PORT_PIN_B7              ((Port_PinType)15)
/* Port C Pins */
#define PORT_PIN_C0              ((Port_PinType)16)
#define PORT_PIN_C1              ((Port_PinType)17)
#define PORT_PIN_C2              ((Port_PinType)18)
#define PORT_PIN_C3              ((Port_PinType)19)
#define PORT_PIN_C4              ((Port_PinType)20)
#define PORT_PIN_C5              ((Port_PinType)21)
#define PORT_PIN_C6              ((Port_PinType)22
#define PORT_PIN_C7              ((Port_PinType)23)
/* Port D Pins */
#define PORT_PIN_D0              ((Port_PinType)24)
#define PORT_PIN_D1              ((Port_PinType)25)
#define PORT_PIN_D2              ((Port_PinType)26)
#define PORT_PIN_D3              ((Port_PinType)27)
#define PORT_PIN_D4              ((Port_PinType)28)
#define PORT_PIN_D5              ((Port_PinType)29)
#define PORT_PIN_D6              ((Port_PinType)30)
#define PORT_PIN_D7              ((Port_PinType)31)
/* Port E Pins */
#define PORT_PIN_E0              ((Port_PinType)32)
#define PORT_PIN_E1              ((Port_PinType)33)
#define PORT_PIN_E2              ((Port_PinType)34)
#define PORT_PIN_E3              ((Port_PinType)35)
#define PORT_PIN_E4              ((Port_PinType)36)
#define PORT_PIN_E5              ((Port_PinType)37)
/* Port E: Pins 6, and 7 are not implemented */
#define PORT_PIN_E6              ((Port_PinType)38)
#define PORT_PIN_E7              ((Port_PinType)39)
/* Port F Pins */
#define PORT_PIN_F0              ((Port_PinType)40)
#define PORT_PIN_F1              ((Port_PinType)41)
#define PORT_PIN_F2              ((Port_PinType)42)
#define PORT_PIN_F3              ((Port_PinType)43)
#define PORT_PIN_F4              ((Port_PinType)44)
/* Port F: Pins 5, 6, and 7 are not implemented */
#define PORT_PIN_F5              ((Port_PinType)45)
#define PORT_PIN_F6              ((Port_PinType)46)
#define PORT_PIN_F7              ((Port_PinType)47)

/* Available Ports */
#define PORTA                    (0u)
#define PORTB                    (1u)
#define PORTC                    (2u)
#define PORTD                    (3u)
#define PORTE                    (4u)
#define PORTF                    (5u)


/* [2] Pin Direction Type */
/* In/Out values?*/
typedef enum
{
   Port_Pin_In = 0, 
   Port_Pin_Out = 1
} Port_PinDirectionType;

/* Port_SetPinMode(); */
/* [3] Pin Mode Type */
typedef uint8 Port_PinModeType;
/* Assign value to PMCx (from ALT0 to ALT15) */
/* Enable Analog (USB/Analog)                */
#define PORT_PINMODE_ALT00       ((Port_PinModeType)00)
/* Enable Digital (from ALT01 to ALT15       */
#define PORT_PINMODE_ALT01       ((Port_PinModeType)01)
#define PORT_PINMODE_ALT02       ((Port_PinModeType)02)
#define PORT_PINMODE_ALT03       ((Port_PinModeType)03)
#define PORT_PINMODE_ALT04       ((Port_PinModeType)04)
#define PORT_PINMODE_ALT05       ((Port_PinModeType)05)
#define PORT_PINMODE_ALT06       ((Port_PinModeType)06)
#define PORT_PINMODE_ALT07       ((Port_PinModeType)07)
#define PORT_PINMODE_ALT08       ((Port_PinModeType)08)
#define PORT_PINMODE_ALT09       ((Port_PinModeType)09)
#define PORT_PINMODE_ALT10       ((Port_PinModeType)10)
#define PORT_PINMODE_ALT11       ((Port_PinModeType)11)
#define PORT_PINMODE_ALT12       ((Port_PinModeType)12)
#define PORT_PINMODE_ALT13       ((Port_PinModeType)13)
#define PORT_PINMODE_ALT14       ((Port_PinModeType)14)
#define PORT_PINMODE_ALT15       ((Port_PinModeType)15)
/* Disable Alternate function            */
/* Do not assign value to PMCx           */
/* Digital Input/Output PIN              */
#define PORT_PINMODE_DIO         ((Port_PinModeType)16)
/* External Interrupt (Direction: Input) */
#define PORT_PINMODE_EXTINT      ((Port_PinModeType)17)



/* MACRO/enum? */
/* [4] Pin Internal Attach Type */
typedef enum
{
   Port_PinInternalAttach_Off,
   Port_PinInternalAttach_PullUp,
   Port_PinInternalAttach_PullDown,
   Port_PinInternalAttach_OpenDrain
} Port_PinInternalAttachType;

/* MACRO/enum? */
/* [5] Pin Output Current Type (Drive Current)*/
typedef enum
{
   Port_PinOutputCurrent_DR2,
   Port_PinOutputCurrent_DR4,
   Port_PinOutputCurrent_DR8
} Port_PinOutputCurrentType;

/* Pin Level Value*/
/* STD_HIGH / STD_LOW */
typedef uint8 Port_PinLevelValueType;

/* [6] Config Type (single pin) */
typedef struct
{
   Port_PinType Port_Pin;
   Port_PinModeType Port_PinMode;
   Port_PinLevelValueType Port_PinLevelValue; 
   Port_PinDirectionType Port_PinDirection;
   Port_PinInternalAttachType Port_PinInternalAttach;
   Port_PinOutputCurrentType Port_PinOutputCurrent;
} Port_ConfigType;

/**/

/* typedef */
 
#endif  /* PORT_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: Port_Types.h
 *********************************************************************************************************************/
