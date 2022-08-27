/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  Port Driver
 *
 *      \details  The Driver Configures GPIO Pins 
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port.h"
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
* \Syntax          : void Port_Init(PortConfigType* PortConfigPtr)                                      
* \Description     : initialize GPIO pins by parsing the Configuration 
*                    into () registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

/* 
- Considerations:

2. Direction (In/Out): 
    (User's responsibility - configure this value anyway)
    -DIO: ?
    -Analog: 0 (set as Input)
    -ALTXX: X

4. Output Current (2/4/8)mA 
    (User's responsibility - configure this value anyway)
    -DIO: ?/X 
    -Analog: X
    -ALTXX: ?/X

5. Internal Attach (Off/PullUp/PullDown/Opendrain) 
    (User's responsibility - configure this value anyway)
    -OFF (User's responsibility - configure this value anyway)
    Analog: OFF
    DIO: Possible
    ALTXX: Possible
    
    -PullUp/PullDown (User's responsibility - configure this value anyway)
    Analog: 0 
    DIO: I/O:? / O:X (certain case)
    ALTXX: ?/X
    *0: PullUp/PullDown disabled
    
    -Opendrain (User's responsibility - configure this value anyway)
    Analog:  0 
    DIO: I:0 / O:?
    ALTXX:   0 (Mostly) / I2C: (?)
    *0: Not configured as open drain.

Note:
    X=Ignored (don’t care bit)
    ?=Can be either 0 or 1, depending on the configuration
*/
void Port_Init(Port_ConfigType* PortConfigPtr)
{
    /* PORT_CONFIG_CHANNEL (NameMacro in Port_Cfg.h)    */
    /* PORT_BASE_ADDRESS (NameMacro in Mcu_Hw.h)        */

    uint8 portId, pinIdx, i;
    volatile uint32* curPortBaseAddress = NULL_PTR;
    /* Loop over all pins to be configured */
    for (i=0; i<CONFIG_PORT_CHANNELS; i++)
    {
        /* current port Id */
        portId = PortConfigPtr[i].Port_Pin/PORT_PINS;
        /* Pin index (from 0 to 7) */
        pinIdx = PortConfigPtr[i].Port_Pin%PORT_PINS;
        /* Base address of corresponding port */
        switch(portId)
        {
            case PORTA: curPortBaseAddress = GPIO_PORTA_BASE_ADDRESS; break;
            case PORTB: curPortBaseAddress = GPIO_PORTB_BASE_ADDRESS; break;
            case PORTC: curPortBaseAddress = GPIO_PORTC_BASE_ADDRESS; break;
            case PORTD: curPortBaseAddress = GPIO_PORTD_BASE_ADDRESS; break;
            case PORTE: curPortBaseAddress = GPIO_PORTE_BASE_ADDRESS; break;
            case PORTF: curPortBaseAddress = GPIO_PORTF_BASE_ADDRESS; break;
        }
        /* 1. Enable clock to specified port via RCGCGPIO register */
        RCGCGPIO |= (1 << portId);
				
				/* TODO */
        /*  I. Handle special pins (JTAG/ ...) */
        /* II. Either Ignore or Lock/Commit */

        /* 2. Set Direction (In/Out). */
        if(PortConfigPtr[i].Port_PinDirection == Port_Pin_Out)
        {
            /* Cast to (uint8*) to avoid adding an offset x 4, then cast back to (uint32*) */
            SET_BIT(*(volatile uint32*)((volatile uint8*) curPortBaseAddress+GPIODIR_OFFSET), pinIdx);
            /* Initial Value of current pin */
            if(PortConfigPtr[i].Port_PinLevelValue == STD_HIGH )
            {
                SET_BIT_PER_BB(*(volatile uint32*)((volatile uint8*) curPortBaseAddress+GPIODATA_OFFSET+BITMASK_ALL_BITS_OFFSET), pinIdx);
            }
            else if(PortConfigPtr[i].Port_PinLevelValue == STD_LOW )
            {
                CLEAR_BIT_PER_BB(*(volatile uint32*)((volatile uint8*) curPortBaseAddress+GPIODATA_OFFSET+BITMASK_ALL_BITS_OFFSET), pinIdx);
            }
            /* GPIODATA w/ BitBanding Macro and Address 0x3FC */
        }
        else if(PortConfigPtr[i].Port_PinDirection == Port_Pin_In)
        {
            /* Cast to (uint8*) to avoid adding an offset x 4, then cast back to (uint32*) */
            CLEAR_BIT(*(volatile uint32*)((volatile uint8*) curPortBaseAddress+GPIODIR_OFFSET), pinIdx);
        }
        else
        {
            /* nothing... */
        }

        /* 4. Set Output Current (2/4/8)mA */
        /* By default, all GPIO pins have 2-mA drive */
        switch(PortConfigPtr[i].Port_PinOutputCurrent)
        {
            /* TODO: done */
            /* Leave unchanged? */
            /* GPIODR2R */
            case Port_PinOutputCurrent_DR2:
                SET_BIT(*(volatile uint32*)((volatile uint8*) curPortBaseAddress+GPIODR2R_OFFSET), pinIdx);
                break;
            /* GPIODR4R */
            case Port_PinOutputCurrent_DR4: 
                SET_BIT(*(volatile uint32*)((volatile uint8*) curPortBaseAddress+GPIODR4R_OFFSET), pinIdx);
                break;
            /* GPIODR8R */
            case Port_PinOutputCurrent_DR8: 
                SET_BIT(*(volatile uint32*)((volatile uint8*) curPortBaseAddress+GPIODR8R_OFFSET), pinIdx);
                break;
            default: 
                SET_BIT(*(volatile uint32*)((volatile uint8*) curPortBaseAddress+GPIODR2R_OFFSET), pinIdx);
                break;
        }
        
        /* 5. Set Internal Attach (Off, PullUp, PullDown, OpenDrain)   */
        /* cannot choose OpenDrain and (PullUp or PullDown) at the same time */
        switch(PortConfigPtr[i].Port_PinInternalAttach)
        {
            /* TODO: Done */
            /* GPIOPUR */
            case Port_PinInternalAttach_PullUp: 
                SET_BIT(*(volatile uint32*)((volatile uint8*) curPortBaseAddress+GPIOPUR_OFFSET), pinIdx);
                break;
            /* GPIOPDR */
            case Port_PinInternalAttach_PullDown: 
                SET_BIT(*(volatile uint32*)((volatile uint8*) curPortBaseAddress+GPIOPDR_OFFSET), pinIdx);
                break;
            /* GPIOODR */
            case Port_PinInternalAttach_OpenDrain: 
                SET_BIT(*(volatile uint32*)((volatile uint8*) curPortBaseAddress+GPIOODR_OFFSET), pinIdx);
                break;
            /* Disable PullUp/PullDown/OpenDrain */
            case Port_PinInternalAttach_Off: 
                CLEAR_BIT(*(volatile uint32*)((volatile uint8*) curPortBaseAddress+GPIOPUR_OFFSET), pinIdx);
                CLEAR_BIT(*(volatile uint32*)((volatile uint8*) curPortBaseAddress+GPIOPDR_OFFSET), pinIdx);
                CLEAR_BIT(*(volatile uint32*)((volatile uint8*) curPortBaseAddress+GPIOODR_OFFSET), pinIdx);
                break;
            default: 
                break;
        }
        
        /* TODO */
        /* 3. Set Mode (DIO/Alternate function/EXTINT)                 */
        /* Alternate Function 00: Analog Pin */
        if(PORT_PINMODE_ALT00 == PortConfigPtr[i].Port_PinMode)
        {
            /* 3(A). Enable Alternate Function in GPIOAFSEL   */
            /* GPIOAFSEL */
            SET_BIT(*(volatile uint32*)((volatile uint8*) curPortBaseAddress+GPIOAFSEL_OFFSET), pinIdx);

            /* 3(B). Set PMCn bits in GPIOPCTL (Port Control) */
            /* GPIOPCTL */
            /* The reset value for this register is 0x00000000 */
            *(volatile uint32*)((volatile uint8*) curPortBaseAddress+GPIOPCTL_OFFSET) |= PortConfigPtr[i].Port_PinMode << GPIOPCTL_PMC_BITS*pinIdx;

         
            /* 6. Enable GPIO pin as (Analog).                */ 
            /* GPIOAMSEL */  
            SET_BIT(*(volatile uint32*)((volatile uint8*) curPortBaseAddress+GPIOAMSEL_OFFSET), pinIdx);
        }

        /* TODO */
        /* Digital Pin with Alternate Function */
        else if(PORT_PINMODE_ALT01 <= PortConfigPtr[i].Port_PinMode &&
                PORT_PINMODE_ALT15 >= PortConfigPtr[i].Port_PinMode)
        {
            /* 3(A). Enable Alternate Function in GPIOAFSEL   */
            /* GPIOAFSEL */
            SET_BIT(*(volatile uint32*)((volatile uint8*) curPortBaseAddress+GPIOAFSEL_OFFSET), pinIdx);

            /* 3(B). Set PMCn bits in GPIOPCTL (Port Control) */
            /* GPIOPCTL */
            /* The reset value for this register is 0x00000000 */
            *(volatile uint32*)((volatile uint8*) curPortBaseAddress+GPIOPCTL_OFFSET) |= PortConfigPtr[i].Port_PinMode << GPIOPCTL_PMC_BITS*pinIdx;

            /* 6. Enable GPIO pin as (Digital).                            */   
            /* GPIODEN */
            SET_BIT(*(volatile uint32*)((volatile uint8*) curPortBaseAddress+GPIODEN_OFFSET), pinIdx);
        }
        /* TODO */
        /* DIO Pin without Alternate function */
        else if (PortConfigPtr[i].Port_PinMode == PORT_PINMODE_DIO)
        {
            /* 3(A). Disable Alternate Function in GPIOAFSEL       */
            /* GPIOAFSEL */
            CLEAR_BIT(*(volatile uint32*)((volatile uint8*) curPortBaseAddress+GPIOAFSEL_OFFSET), pinIdx);

            /* 3(B). Clear PMCn bits in GPIOPCTL (Port Control)?   */
            /* GPIOPCTL */
            /* The reset value for this register is 0x00000000 */

            /* 6. Enable GPIO pin as (Digital).                    */   
            /* GPIODEN */
            SET_BIT(*(volatile uint32*)((volatile uint8*) curPortBaseAddress+GPIODEN_OFFSET), pinIdx);
        }
        /* TODO */
        /* DIO Pin (External Interrupt) without Alternate function */
        else if (PortConfigPtr[i].Port_PinMode == PORT_PINMODE_EXTINT)
        {
            /* 3(A). Disable Alternate Function in GPIOAFSEL       */
            /* GPIOAFSEL */
            CLEAR_BIT(*(volatile uint32*)((volatile uint8*) curPortBaseAddress+GPIOAFSEL_OFFSET), pinIdx);

            /* 3(B). Clear PMCn bits in GPIOPCTL (Port Control)?   */
            /* GPIOPCTL */
            /* The reset value for this register is 0x00000000 */

            /* 6. Enable GPIO pin as (Digital).                    */
            /* GPIODEN */
            SET_BIT(*(volatile uint32*)((volatile uint8*) curPortBaseAddress+GPIODEN_OFFSET), pinIdx);

            /* 7. Interrupt                                        */
            /* GPIOIM */
            SET_BIT(*(volatile uint32*)((volatile uint8*) curPortBaseAddress+GPIOIM_OFFSET), pinIdx);
        }

        /* TODO */
        /*  I. Set Pin Level Value (according to user config.              */
        /* II. Lock/Commit of NMI and JTAG/SWD pins (When to do that?      */

        /* Incorrect Mode */
        else
        {
            /* nothing... */
        }

    } /* end of for loop */
}



/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
