/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :4;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;

typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;


typedef struct 
{
    uint32 ENABLE   :1;
    uint32 INTEN    :1;
    uint32 CLK_SRC  :1;
    uint32          :13;
    uint32 COUNT    :1;
    uint32          :15;
}STCTRL_BF;

typedef union 
{
    uint32 R;
    STCTRL_BF B;
}STCTRL_Tag;



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* Base Address of Peripheral Registers */
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
/* Base Address of System Control Registers */
#define CORTEXM4_SC_BASE_ADDRESS               0x400FE000
#define APINT                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL                                (*((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04)))
#define NVIC_EN                                 ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
/* Note PRI is byte accessible and is treated accordingly */
#define NVIC_PRI                                ((volatile uint8*)(CORTEXM4_PERI_BASE_ADDRESS+0x400))
/* System Priority Registers */
#define SYSPRI1                                 ((volatile uint8*)(CORTEXM4_PERI_BASE_ADDRESS+0xD18))
#define SYSPRI2                                 ((volatile uint8*)(CORTEXM4_PERI_BASE_ADDRESS+0xD1C))
#define SYSPRI3                                 ((volatile uint8*)(CORTEXM4_PERI_BASE_ADDRESS+0xD20))
/* System Exception Priority Byte */
#define SYSPRI_MEM                             (*(SYSPRI1+0))
#define SYSPRI_BUS                             (*(SYSPRI1+1))    
#define SYSPRI_USAGE                           (*(SYSPRI1+2))    
#define SYSPRI_SVC                             (*(SYSPRI2+3))    
#define SYSPRI_DEBUG                           (*(SYSPRI3+0))    
#define SYSPRI_PENDSV                          (*(SYSPRI3+2))    
#define SYSPRI_TICK                            (*(SYSPRI3+3))    


/* #Bits per register */
#define REG_BITS                                ((uint8)0x20)
/* #Bytes per register */
#define REG_BYTES                               ((uint8)0x04)
/* Starting bit of PRIGROUP bitfield in APINT reg. */
#define APINT_PRIGROUP_BIT0                     ((uint8)0x08)
#define APINT_VECTKEY						    ((uint32)0x05FA0000)
/* Priority fields per PRI register */
#define NVIC_PRI_FIELDS                         ((uint8)0x04)
/* Priority bits per PRI register */
#define NVIC_PRI_BITS                           ((uint8)0x03)
/* Priority bit #0 in PRI register */
#define NVIC_PRI_BIT0                           ((uint8)0x05)
/* Priority bit #0 in PRI register */
#define SCB_PRI_BIT0                            ((uint8)0x05)
/* #Pins per port (Most and NOT all ports) */
#define PORT_PINS                               ((uint8)0x08)
/* Port Control Mux bits in GPIOPCTL register */
#define GPIOPCTL_PMC_BITS                       ((uint8)0x04)

/* GPIO Port Base Address (APB) */
#define GPIO_PORTA_BASE_ADDRESS                 ((volatile uint32*)0x40004000)
#define GPIO_PORTB_BASE_ADDRESS                 ((volatile uint32*)0x40005000)
#define GPIO_PORTC_BASE_ADDRESS                 ((volatile uint32*)0x40006000)
#define GPIO_PORTD_BASE_ADDRESS                 ((volatile uint32*)0x40007000)
#define GPIO_PORTE_BASE_ADDRESS                 ((volatile uint32*)0x40024000)
#define GPIO_PORTF_BASE_ADDRESS                 ((volatile uint32*)0x40025000)

/* GPIO Config. Reg. Offset */
#define GPIODATA_OFFSET                         (0x000) /* GPIO Data                      */
#define GPIODIR_OFFSET                          (0x400) /* GPIO Direction                 */
#define GPIOIS_OFFSET                           (0x404) /* GPIO Interrupt Sense           */
#define GPIOIBE_OFFSET                          (0x408) /* GPIO Interrupt Both Edges      */
#define GPIOIEV_OFFSET                          (0x40C) /* GPIO Interrupt Event           */
#define GPIOIM_OFFSET                           (0x410) /* GPIO Interrupt Mask            */
#define GPIOAFSEL_OFFSET                        (0x420) /* GPIO Alternate Function Select */
#define GPIODR2R_OFFSET                         (0x500) /* GPIO 2-mA Drive Select         */
#define GPIODR4R_OFFSET                         (0x504) /* GPIO 4-mA Drive Select         */
#define GPIODR8R_OFFSET                         (0x508) /* GPIO 8-mA Drive Select         */
#define GPIOODR_OFFSET                          (0x50C) /* GPIO Open Drain Select         */
#define GPIOPUR_OFFSET                          (0x510) /* GPIO Pull-Up Select            */
#define GPIOPDR_OFFSET                          (0x514) /* GPIO Pull-Down Select          */
#define GPIOSLR_OFFSET                          (0x518) /* GPIO Slew Rate Control Select  */
#define GPIODEN_OFFSET                          (0x51C) /* GPIO Digital Enable            */
#define GPIOLOCK_OFFSET                         (0x520) /* GPIO Lock                      */
#define GPIOCR_OFFSET                           (0x524) /* GPIO Commit                    */
#define GPIOAMSEL_OFFSET                        (0x528) /* GPIO Analog Mode Select        */
#define GPIOPCTL_OFFSET                         (0x52C) /* GPIO Port Control              */

/* Bit Masking Offset */
#define BITMASK_ALL_BITS_OFFSET                 ((uint32)0x3FC)

/* GPIO Run Mode Clock Gating Control (RCGCGPIO) */
#define RCGCGPIO                               *((volatile uint32*)(CORTEXM4_SC_BASE_ADDRESS+0x608))



/* Systick Registers */
/* SysTick Control and Status Register  */
#define STCTRL                                 (*((volatile STCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x010)))
/* SysTick Reload Value Register        */
#define STRELOAD                               *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x014)) 
/* SysTick Current Value Register       */
#define STCURRENT                              *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x018)) 
/* STCTRL Enable bit                    */
#define STCTRL_EN_BIT                           ((uint8)0x00)
/* STCTRL Interrupt Enable bit          */                                          
#define STCTRL_INTEN_BIT                        ((uint8)0x01)
/* STCTRL Clock Source bit              */                                          
#define STCTRL_CLK_SRC_BIT                      ((uint8)0x02)
/* STRLEAD RELOAD bitfield width        */                                          
#define STRELOAD_RELOAD_BITS                    ((uint8)24)                                            

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/

/*
 Possible Issues:
 1. Compiler places Least or Most bitfield in the beginning of struct. 
 2. Some registers should be written to as a whole. 

 Draft:
 #define INTCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
*/
