/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
#define ClearBitsOutOfRange(Val, Bits) Val&=(1<<(Bits))-1


/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
/* Group Priority bits */
static uint8 groupPriBits;
/* SubGroup Priority bits */
static uint8 subGroupPriBits;

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void IntCtrl_SetPri(IntCtrl_PriType groupPriLevel, IntCtrl_PriType subGroupPriLevel, IntCtrl_InterruptType intVectNum);
void IntCtrl_EnableInt(IntCtrl_InterruptType IntVecNum);


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void IntCtrl_SetPri(IntCtrl_PriType groupPriLevel, IntCtrl_PriType subGroupPriLevel, IntCtrl_InterruptType IntVectNum)                                   
* \Description     : Set Group/SubGroup Pri. for the specified Int. Vec. Number 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
/* SCB (for sys. exceptions): Not implemented */
void IntCtrl_SetPri(IntCtrl_PriType groupPriLevel, IntCtrl_PriType subGroupPriLevel, IntCtrl_InterruptType IntVectNum)
{
    IntCtrl_PriType priVal;
		uint8 IntNum, PRI_Idx, byteIdx;
    /* Separate the code above (calculate once and store in local/global variables). */
    /*--------------------------------------------------------------------------------*/                             
    /* Ensure group/subgroup priority values stay in range */
    ClearBitsOutOfRange(groupPriLevel, groupPriBits);
    ClearBitsOutOfRange(subGroupPriBits, subGroupPriBits);
    /* Priority value */
		priVal = (groupPriLevel<<subGroupPriBits)|subGroupPriLevel;
    /* Assign Priority to specified IRQ# */
    /* Interrupts */
    if(IntVectNum >= INTCTRL_GPIOA)
    {
        IntNum = IntVectNum - INTCTRL_GPIOA;
        /* PRI register index */
        PRI_Idx = IntNum/NVIC_PRI_FIELDS;
        /* Byte index within register */
        byteIdx = IntNum%NVIC_PRI_FIELDS; 
        NVIC_PRI[PRI_Idx*REG_BYTES+byteIdx] |= (priVal<<NVIC_PRI_BIT0);
    }
    /* System Exception */
    else
    {
        switch(IntVectNum)
        {
            case INTCTRL_MEMORYMANAGEMENT: 
                SYSPRI_MEM = (priVal<<SCB_PRI_BIT0);
                break;
            case INTCTRL_BUSFAULT: 
                SYSPRI_BUS = (priVal<<SCB_PRI_BIT0);
                break;
            case INTCTRL_USAGEFAULT: 
                SYSPRI_USAGE = (priVal<<SCB_PRI_BIT0);
                break;
            case INTCTRL_SVCALL: 
                SYSPRI_SVC = (priVal<<SCB_PRI_BIT0);
                break;
            case INTCTRL_DEBUGMONITOR: 
                SYSPRI_DEBUG = (priVal<<SCB_PRI_BIT0);
                break;
            case INTCTRL_PENDSV: 
                SYSPRI_PENDSV = (priVal<<SCB_PRI_BIT0);
                break;
            case INTCTRL_SYSTICK: 
                SYSPRI_TICK = (priVal<<SCB_PRI_BIT0);
                break;
            default: /* Invalid IntVectNum */
                break;
        }
    }
}


/******************************************************************************
* \Syntax          : void IntCtrl_EnableInt(IntCtrl_InterruptType IntVecNum)                                   
* \Description     : Enable Interrupts\Exceptions (Nvic\SCB Module) given Int. Vec. Number                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
/* SCB (for sys. exceptions): Not implemented */
void IntCtrl_EnableInt(IntCtrl_InterruptType IntVecNum)
{
    /* Interrupts */
    if(IntVecNum >= INTCTRL_GPIOA) 
    {       
    	uint8 IntNum = IntVecNum - INTCTRL_GPIOA;
    	uint8 enBit = IntNum % REG_BITS;
    	NVIC_EN[IntNum/REG_BITS] |= (1<<enBit);
    }
}




/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{
	uint8 i;
	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
	APINT = (APINT_VECTKEY|priGrouping);
  
	/* Extract first 2 bits from PRIGROUP bitfield in APINT reg. */
	subGroupPriBits = (priGrouping >> APINT_PRIGROUP_BIT0)
                             & 0x03;
	groupPriBits = NVIC_PRI_BITS-subGroupPriBits; 
	/*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/
	for (i=0; i<INTCTRL_INT_COUNT; i++)
	{
		IntCtrl_SetPri(IntCtrl_Config[i].groupPriVal, IntCtrl_Config[i].subGroupPriVal, IntCtrl_Config[i].IntVecNum);
		IntCtrl_EnableInt(IntCtrl_Config[i].IntVecNum);
	}
	/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
	/* pass array of uint8
	 # of interrupts that should be enabled in this array
	 or... any other container */
}



/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
