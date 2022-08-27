/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File: Bit_Math.h
 *    Component: -
 *       Module: -
 *
 *  Description: Bit Manipulation
 *
 *********************************************************************************************************************/

#ifndef __BIT_MATH_H__
#define __BIT_MATH_H__

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"

/**********************************************************************************************************************
*  Global MACROS 
*********************************************************************************************************************/

/* Set specified bit in a register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear specified bit in a register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Toggle specified bit in a register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* Check if a specific bit is set in any register and return true if set. */
#define IS_BIT_SET(REG,BIT) ((REG & (1<<BIT)) >> BIT)

/* Set Bit using Bit Banding of SRAM registers */
#define SET_BIT_RAM_BB(REG,BIT) ((*((volatile uint32*)( 0x22000000 + (((uint32)(&REG) - 0x20000000) * 32) + ((BIT) * 4) ))) = STD_HIGH)

/* Set Bit using Bit Banding of Peripheral registers */
#define SET_BIT_PER_BB(REG,BIT) ((*((volatile uint32*)( 0x42000000 + (((uint32)(&REG) - 0x40000000) * 32) + ((BIT) * 4) ))) = STD_HIGH)

/* Clear Bit using Bit Banding of SRAM registers */
#define CLEAR_BIT_RAM_BB(REG,BIT) ((*((volatile uint32*)( 0x22000000 + (((uint32)(&REG) - 0x20000000) * 32) + ((BIT) * 4) ))) = STD_LOW)

/* Clear Bit using Bit Banding of Peripheral registers */
#define CLEAR_BIT_PER_BB(REG,BIT) ((*((volatile uint32*)( 0x42000000 + (((uint32)(&REG) - 0x40000000) * 32) + ((BIT) * 4) ))) = STD_LOW)

#endif /* __BIT_MATH_H__ */
