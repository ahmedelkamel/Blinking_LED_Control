/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef DIO_TYPES_H
#define DIO_TYPES_H

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
typedef uint8 Dio_ChannelType;
/* Available Channels (43) */
/* Port A Pins */
#define DIO_CHANNEL_A0              ((Dio_ChannelType) 0)
#define DIO_CHANNEL_A1              ((Dio_ChannelType) 1)
#define DIO_CHANNEL_A2              ((Dio_ChannelType) 2)
#define DIO_CHANNEL_A3              ((Dio_ChannelType) 3)
#define DIO_CHANNEL_A4              ((Dio_ChannelType) 4)
#define DIO_CHANNEL_A5              ((Dio_ChannelType) 5)
#define DIO_CHANNEL_A6              ((Dio_ChannelType) 6)
#define DIO_CHANNEL_A7              ((Dio_ChannelType) 7)
/* Port B Pins */
#define DIO_CHANNEL_B0              ((Dio_ChannelType) 8)
#define DIO_CHANNEL_B1              ((Dio_ChannelType) 9)
#define DIO_CHANNEL_B2              ((Dio_ChannelType)10)
#define DIO_CHANNEL_B3              ((Dio_ChannelType)11)
#define DIO_CHANNEL_B4              ((Dio_ChannelType)12)
#define DIO_CHANNEL_B5              ((Dio_ChannelType)13)
#define DIO_CHANNEL_B6              ((Dio_ChannelType)14)
#define DIO_CHANNEL_B7              ((Dio_ChannelType)15)
/* Port C Pins */
#define DIO_CHANNEL_C0              ((Dio_ChannelType)16)
#define DIO_CHANNEL_C1              ((Dio_ChannelType)17)
#define DIO_CHANNEL_C2              ((Dio_ChannelType)18)
#define DIO_CHANNEL_C3              ((Dio_ChannelType)19)
#define DIO_CHANNEL_C4              ((Dio_ChannelType)20)
#define DIO_CHANNEL_C5              ((Dio_ChannelType)21)
#define DIO_CHANNEL_C6              ((Dio_ChannelType)22
#define DIO_CHANNEL_C7              ((Dio_ChannelType)23)
/* Port D Pins */
#define DIO_CHANNEL_D0              ((Dio_ChannelType)24)
#define DIO_CHANNEL_D1              ((Dio_ChannelType)25)
#define DIO_CHANNEL_D2              ((Dio_ChannelType)26)
#define DIO_CHANNEL_D3              ((Dio_ChannelType)27)
#define DIO_CHANNEL_D4              ((Dio_ChannelType)28)
#define DIO_CHANNEL_D5              ((Dio_ChannelType)29)
#define DIO_CHANNEL_D6              ((Dio_ChannelType)30)
#define DIO_CHANNEL_D7              ((Dio_ChannelType)31)
/* Port E Pins */
#define DIO_CHANNEL_E0              ((Dio_ChannelType)32)
#define DIO_CHANNEL_E1              ((Dio_ChannelType)33)
#define DIO_CHANNEL_E2              ((Dio_ChannelType)34)
#define DIO_CHANNEL_E3              ((Dio_ChannelType)35)
#define DIO_CHANNEL_E4              ((Dio_ChannelType)36)
#define DIO_CHANNEL_E5              ((Dio_ChannelType)37)
/* Port E: Pins 6, and 7 are not implemented */
#define DIO_CHANNEL_E6              ((Dio_ChannelType)38)
#define DIO_CHANNEL_E7              ((Dio_ChannelType)39)
/* Port F Pins */
#define DIO_CHANNEL_F0              ((Dio_ChannelType)40)
#define DIO_CHANNEL_F1              ((Dio_ChannelType)41)
#define DIO_CHANNEL_F2              ((Dio_ChannelType)42)
#define DIO_CHANNEL_F3              ((Dio_ChannelType)43)
#define DIO_CHANNEL_F4              ((Dio_ChannelType)44)
/* Port F: Pins 5, 6, and 7 are not implemented */
#define DIO_CHANNEL_F5              ((Dio_ChannelType)45)
#define DIO_CHANNEL_F6              ((Dio_ChannelType)46)
#define DIO_CHANNEL_F7              ((Dio_ChannelType)47)



typedef uint8 Dio_PortType;
/* Available Ports */
#define DIO_PORTA                    ((Dio_PortType)0)
#define DIO_PORTB                    ((Dio_PortType)1)
#define DIO_PORTC                    ((Dio_PortType)2)
#define DIO_PORTD                    ((Dio_PortType)3)
#define DIO_PORTE                    ((Dio_PortType)4)
#define DIO_PORTF                    ((Dio_PortType)5)

typedef uint8 Dio_LevelType;
/*
 * Dio_LevelType:
 * values defined in "Std_Types.h"
 * STD_LOW
 * STD_HIGH
*/

typedef uint8 Dio_PortLevelType;
/*
 * Range of values: 0 to 255
*/

 
#endif  /* DIO_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: Dio_Types.h
 *********************************************************************************************************************/
