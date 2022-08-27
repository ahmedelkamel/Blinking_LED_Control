/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief  Digital Input Output Driver
 *
 *      \details  The Driver Allows Read/Write operations on DIO pins
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio.h"
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
* \Syntax          :                                 
* \Description     : 
*                                                        
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

/* Reentrant */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	  /* Port ID */
    Dio_PortType PortId = ChannelId/PORT_PINS;
    volatile uint8* portBaseAddress = NULL_PTR;
    /* pin index (from 0 to 7) */
    uint8 pinIdx = ChannelId%PORT_PINS;
    Dio_LevelType ChannelLevel = 0;

    switch(PortId)
    {
        case DIO_PORTA: portBaseAddress = GPIO_PORTA_BASE_ADDRESS; break;
        case DIO_PORTB: portBaseAddress = GPIO_PORTB_BASE_ADDRESS; break;
        case DIO_PORTC: portBaseAddress = GPIO_PORTC_BASE_ADDRESS; break;
        case DIO_PORTD: portBaseAddress = GPIO_PORTD_BASE_ADDRESS; break;
        case DIO_PORTE: portBaseAddress = GPIO_PORTE_BASE_ADDRESS; break;
        case DIO_PORTF: portBaseAddress = GPIO_PORTF_BASE_ADDRESS; break;
        default: /* Invalid Port */
            return ChannelLevel;
    }
    /* Reenetrant: No Writes performed !! Only Read/Modify */
    /* Bit Masking through address lines (Allows to modify All GPIODATA Bits) */
    /* Read a single byte / Use bit masking to find value of the specified bit */
    ChannelLevel = (*((volatile uint8*) portBaseAddress+GPIODATA_OFFSET+BITMASK_ALL_BITS_OFFSET)) & (1<<pinIdx);
    if (ChannelLevel)
        return STD_HIGH;
    else
        return STD_LOW;
}

/* Reentrant */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    /* Port ID */
    Dio_PortType PortId = ChannelId/PORT_PINS;
    /* Pin index (from 0 to 7) */
    uint8 pinIdx = ChannelId%PORT_PINS;
    /* Base Address of Port */
    volatile uint32* portBaseAddress = NULL_PTR;
    switch(PortId)
    {
        case DIO_PORTA: portBaseAddress = GPIO_PORTA_BASE_ADDRESS; break;
        case DIO_PORTB: portBaseAddress = GPIO_PORTB_BASE_ADDRESS; break;
        case DIO_PORTC: portBaseAddress = GPIO_PORTC_BASE_ADDRESS; break;
        case DIO_PORTD: portBaseAddress = GPIO_PORTD_BASE_ADDRESS; break;
        case DIO_PORTE: portBaseAddress = GPIO_PORTE_BASE_ADDRESS; break;
        case DIO_PORTF: portBaseAddress = GPIO_PORTF_BASE_ADDRESS; break;
        default: /* Invalid Port */
            return;
    }
    /* Set/Clear via Bit Banding and Bit Masking through address lines (Allows to modify All GPIODATA Bits) */
    if(Level == STD_HIGH)
			SET_BIT_PER_BB(*(volatile uint32*)((volatile uint8*) portBaseAddress+GPIODATA_OFFSET+BITMASK_ALL_BITS_OFFSET), pinIdx);
		else
			CLEAR_BIT_PER_BB(*(volatile uint32*)((volatile uint8*) portBaseAddress+GPIODATA_OFFSET+BITMASK_ALL_BITS_OFFSET), pinIdx);
}

/* Reentrant */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    volatile uint8* portBaseAddress = NULL_PTR;
    Dio_PortLevelType PortLevel = 0x00;
    switch(PortId)
    {
        case DIO_PORTA: portBaseAddress = GPIO_PORTA_BASE_ADDRESS; break;
        case DIO_PORTB: portBaseAddress = GPIO_PORTB_BASE_ADDRESS; break;
        case DIO_PORTC: portBaseAddress = GPIO_PORTC_BASE_ADDRESS; break;
        case DIO_PORTD: portBaseAddress = GPIO_PORTD_BASE_ADDRESS; break;
        case DIO_PORTE: portBaseAddress = GPIO_PORTE_BASE_ADDRESS; break;
        case DIO_PORTF: portBaseAddress = GPIO_PORTF_BASE_ADDRESS; break;
        default: /* Invalid Port */
            return PortLevel;
    }
    /* Bit Masking through address lines (Allows to modify All GPIODATA Bits) */
    /* Read a single byte */
    PortLevel = *((volatile uint8*) portBaseAddress+GPIODATA_OFFSET+BITMASK_ALL_BITS_OFFSET);
    return PortLevel;
}

/* Reentrant */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    volatile uint8* portBaseAddress = NULL_PTR;
    switch(PortId)
    {
        case DIO_PORTA: portBaseAddress = GPIO_PORTA_BASE_ADDRESS; break;
        case DIO_PORTB: portBaseAddress = GPIO_PORTB_BASE_ADDRESS; break;
        case DIO_PORTC: portBaseAddress = GPIO_PORTC_BASE_ADDRESS; break;
        case DIO_PORTD: portBaseAddress = GPIO_PORTD_BASE_ADDRESS; break;
        case DIO_PORTE: portBaseAddress = GPIO_PORTE_BASE_ADDRESS; break;
        case DIO_PORTF: portBaseAddress = GPIO_PORTF_BASE_ADDRESS; break;
        default: /* Invalid Port */
            return;
    }
    /* Bit Masking through address lines (Allows to modify All GPIODATA Bits) */
    /* Write a single byte */
    *((volatile uint8*) portBaseAddress+GPIODATA_OFFSET+BITMASK_ALL_BITS_OFFSET) = Level;
}


/* Reentrant */
/* Use Synchronization primitives along with Bit Banding */
/* Currently not reentrant!! */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
    /* Port ID */
    Dio_PortType PortId = ChannelId/PORT_PINS;
    /* Pin index (from 0 to 7) */
    uint8 pinIdx = ChannelId%PORT_PINS;
    /* Base Address of Port */
    volatile uint32* portBaseAddress = NULL_PTR;
	/* Channel Level after flipping */
	volatile Dio_LevelType ChannelLevel;
    /* Port Level before flipping */
    volatile Dio_PortLevelType PortLevel;
    switch(PortId)
    {
        case DIO_PORTA: portBaseAddress = GPIO_PORTA_BASE_ADDRESS; break;
        case DIO_PORTB: portBaseAddress = GPIO_PORTB_BASE_ADDRESS; break;
        case DIO_PORTC: portBaseAddress = GPIO_PORTC_BASE_ADDRESS; break;
        case DIO_PORTD: portBaseAddress = GPIO_PORTD_BASE_ADDRESS; break;
        case DIO_PORTE: portBaseAddress = GPIO_PORTE_BASE_ADDRESS; break;
        case DIO_PORTF: portBaseAddress = GPIO_PORTF_BASE_ADDRESS; break;
        default: /* Invalid Port */
            return STD_LOW;
    }
		
    /* Bit Masking through address lines (Allows to modify All GPIODATA Bits) */
    /* Read a single byte / Use bit masking to find value of the specified bit */
    ChannelLevel = (*((volatile uint8*) portBaseAddress+GPIODATA_OFFSET+BITMASK_ALL_BITS_OFFSET)) & (1<<pinIdx);
    /* Flip Level */
    ChannelLevel = !ChannelLevel;

    /* Set/Clear via Bit Banding and Bit Masking through address lines (Allows to modify All GPIODATA Bits) */
    if(ChannelLevel == STD_HIGH)
            SET_BIT_PER_BB(*(volatile uint32*)((volatile uint8*) portBaseAddress+GPIODATA_OFFSET+BITMASK_ALL_BITS_OFFSET), pinIdx);
        else
            CLEAR_BIT_PER_BB(*(volatile uint32*)((volatile uint8*) portBaseAddress+GPIODATA_OFFSET+BITMASK_ALL_BITS_OFFSET), pinIdx);
    return ChannelLevel;
}



/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
