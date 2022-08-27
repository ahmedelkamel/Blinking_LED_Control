/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/* Group Priority: GroupPriorityBits_SubGroupPriorityBits */
#define INTCTRL_PRIGROUP_3_0      ((uint32)0x04 << APINT_PRIGROUP_BIT0)
#define INTCTRL_PRIGROUP_2_1      ((uint32)0x05 << APINT_PRIGROUP_BIT0)
#define INTCTRL_PRIGROUP_1_2      ((uint32)0x06 << APINT_PRIGROUP_BIT0)
#define INTCTRL_PRIGROUP_0_3      ((uint32)0x07 << APINT_PRIGROUP_BIT0)



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8 IntCtrl_PriType;
typedef uint32 IntCtrl_PriGroupType;

/* Vector Number of all System Exceptions & Interrupts 
 *
 * Interrupt Number = Vector Number(x) - Vector Number(Interrupt #0)
 * Int#(x) = Vec#(x) - INTCTRL_GPIOA
 * All Vector table interrupts (Datasheet: CortexM4 Processor / Exception Model / Vector Table)
 * presentation: interrupt control interrupt type 
 */
typedef enum
{
    /* Interrupt Vector Number */
    INTCTRL_RESET               =   1,          /* Excep.: Reset */
    INTCTRL_NMI                 =   2,          /* Excep.: Non-Maskable Interrupt */
    INTCTRL_HARDFAULT           =   3,          /* Excep.: Hard Fault */
    INTCTRL_MEMORYMANAGEMENT    =   4,          /* Excep.: Memory Management */
    INTCTRL_BUSFAULT            =   5,          /* Excep.: Bus Fault */
    INTCTRL_USAGEFAULT          =   6,          /* Excep.: Usage Fault */
    INTCTRL_SVCALL              =  11,          /* Excep.: SV Call */
    INTCTRL_DEBUGMONITOR        =  12,          /* Excep.: Debug Monitor */
    INTCTRL_PENDSV              =  14,          /* Excep.: Pend SV */
    INTCTRL_SYSTICK             =  15,          /* Excep.: Sys Tick */

    INTCTRL_GPIOA               =  16,          /* GPIO Port A */
    INTCTRL_GPIOB               =  17,          /* GPIO Port B */
    INTCTRL_GPIOC               =  18,          /* GPIO Port C */
    INTCTRL_GPIOD               =  19,          /* GPIO Port D */
    INTCTRL_GPIOE               =  20,          /* GPIO Port E */
    INTCTRL_UART0               =  21,          /* UART0 */
    INTCTRL_UART1               =  22,          /* UART1 */
    INTCTRL_SSI0                =  23,          /* SSI0 */
    INTCTRL_I2C0                =  24,          /* I2C0 */
    INTCTRL_PWM0_FAULT          =  25,          /* PWM0 Fault */
    INTCTRL_PWM0_0              =  26,          /* PWM0 Generator 0 */
    INTCTRL_PWM0_1              =  27,          /* PWM0 Generator 1 */
    INTCTRL_PWM0_2              =  28,          /* PWM0 Generator 2 */
    INTCTRL_QEI0                =  29,          /* QEI0 */
    INTCTRL_ADC0SS0             =  30,          /* ADC0 Sequence 0 */
    INTCTRL_ADC0SS1             =  31,          /* ADC0 Sequence 1 */
    INTCTRL_ADC0SS2             =  32,          /* ADC0 Sequence 2 */
    INTCTRL_ADC0SS3             =  33,          /* ADC0 Sequence 3 */
    INTCTRL_WATCHDOG            =  34,          /* Watchdog Timers 0 and 1 */
    INTCTRL_TIMER0A             =  35,          /* 16/32-Bit Timer 0A */
    INTCTRL_TIMER0B             =  36,          /* 16/32-Bit Timer 0B */
    INTCTRL_TIMER1A             =  37,          /* 16/32-Bit Timer 1A */
    INTCTRL_TIMER1B             =  38,          /* 16/32-Bit Timer 1B */
    INTCTRL_TIMER2A             =  39,          /* 16/32-Bit Timer 2A */
    INTCTRL_TIMER2B             =  40,          /* 16/32-Bit Timer 2B */
    INTCTRL_COMP0               =  41,          /* Analog Comparator 0 */
    INTCTRL_COMP1               =  42,          /* Analog Comparator 1 */
    INTCTRL_SYSCTL              =  44,          /* System Control */
    INTCTRL_FLASH               =  45,          /* Flash Memory Control and EEPROM Control */
    INTCTRL_GPIOF               =  46,          /* GPIO Port F */
    INTCTRL_UART2               =  49,          /* UART2 */
    INTCTRL_SSI1                =  50,          /* SSI1 */
    INTCTRL_TIMER3A             =  51,          /* Timer 3A */
    INTCTRL_TIMER3B             =  52,          /* Timer 3B */
    INTCTRL_I2C1                =  53,          /* I2C1 */
    INTCTRL_QEI1                =  54,          /* QEI1 */
    INTCTRL_CAN0                =  55,          /* CAN0 */
    INTCTRL_CAN1                =  56,          /* CAN1 */
    INTCTRL_HIBERNATE           =  59,          /* Hibernation Module */
    INTCTRL_USB0                =  60,          /* USB */
    INTCTRL_PWM0_3              =  61,          /* PWM Generator 3 */
    INTCTRL_UDMA                =  62,          /* uDMA Software */
    INTCTRL_UDMAERR             =  63,          /* uDMA Error */
    INTCTRL_ADC1SS0             =  64,          /* ADC1 Sequence 0 */
    INTCTRL_ADC1SS1             =  65,          /* ADC1 Sequence 1 */
    INTCTRL_ADC1SS2             =  66,          /* ADC1 Sequence 2 */
    INTCTRL_ADC1SS3             =  67,          /* ADC1 Sequence 3 */
    INTCTRL_SSI2                =  73,          /* SSI2 */
    INTCTRL_SSI3                =  74,          /* SSI3 */
    INTCTRL_UART3               =  75,          /* UART3 */
    INTCTRL_UART4               =  76,          /* UART4 */
    INTCTRL_UART5               =  77,          /* UART5 */
    INTCTRL_UART6               =  78,          /* UART6 */
    INTCTRL_UART7               =  79,          /* UART7 */
    INTCTRL_I2C2                =  84,          /* I2C2 */
    INTCTRL_I2C3                =  85,          /* I2C3 */
    INTCTRL_TIMER4A             =  86,          /* 16/32-Bit Timer 4A */
    INTCTRL_TIMER4B             =  87,          /* 16/32-Bit Timer 4B */
    INTCTRL_TIMER5A             = 108,          /* 16/32-Bit Timer 5A */
    INTCTRL_TIMER5B             = 109,          /* 16/32-Bit Timer 5B */
    INTCTRL_WTIMER0A            = 110,          /* 32/64-Bit Wide Timer 0A */
    INTCTRL_WTIMER0B            = 111,          /* 32/64-Bit Wide Timer 0B */
    INTCTRL_WTIMER1A            = 112,          /* 32/64-Bit Wide Timer 1A */
    INTCTRL_WTIMER1B            = 113,          /* 32/64-Bit Wide Timer 1B */
    INTCTRL_WTIMER2A            = 114,          /* 32/64-Bit Wide Timer 2A */
    INTCTRL_WTIMER2B            = 115,          /* 32/64-Bit Wide Timer 2B */
    INTCTRL_WTIMER3A            = 116,          /* 32/64-Bit Wide Timer 3A */
    INTCTRL_WTIMER3B            = 117,          /* 32/64-Bit Wide Timer 3B */
    INTCTRL_WTIMER4A            = 118,          /* 32/64-Bit Wide Timer 4A */
    INTCTRL_WTIMER4B            = 119,          /* 32/64-Bit Wide Timer 4B */
    INTCTRL_WTIMER5A            = 120,          /* 32/64-Bit Wide Timer 5A */
    INTCTRL_WTIMER5B            = 121,          /* 32/64-Bit Wide Timer 5B */
    INTCTRL_SYSEXC              = 122,          /* System Exception (imprecise) */
    INTCTRL_PWM1_0              = 150,          /* PWM1 Generator 0 */
    INTCTRL_PWM1_1              = 151,          /* PWM1 Generator 1 */
    INTCTRL_PWM1_2              = 152,          /* PWM1 Generator 2 */
    INTCTRL_PWM1_3              = 153,          /* PWM1 Generator 3 */
    INTCTRL_PWM1_FAULT          = 154           /* PWM1 Fault */
}IntCtrl_InterruptType;

/* Config: Single Interrupt */
typedef struct {
    IntCtrl_PriType groupPriVal;
    IntCtrl_PriType subGroupPriVal;
    IntCtrl_InterruptType IntVecNum;
} IntCtrl_ConfigType;


 
#endif  /* INTCTRL_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
