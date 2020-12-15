/********************************************************************************************
* @file NVIC_program.c
* @brief This files contains the NVIC driver functions definitions. 
* @author: Mohammed Abdelalim
* @version:
* @date: 15-12-2020
*********************************************************************************************/

#include "../../04-Lib/STD_TYPES.h"
#include "../../04-Lib/BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void NVIC_voidInit (void){
    // Disable all NVIC interrupts
    NVIC_ICER0 = NVIC_DISABLE_ALL_INTERRUPTS;
    NVIC_ICER1 = NVIC_DISABLE_ALL_INTERRUPTS;

    // We need a register in another peripheral that we haven't implemented it yet
    // so we define this register and its needed macros right here.
    #define SCB_AIRCR           *((volatile u32 *) (0xE000ED00+0x0C))
    #define SCB_AIRCR_VECTKEY    (0x5FA<<16)


    // Assign the required number of priority groups and subgroups
    #if NVIC_PRIORITY_GROUPS == NVIC_SIXTEEN_PRIORITY_GROUPS
    // write the VECTKEY to allow write access to the register
    // then clear the PRIGROUP bits[8:10] that correspond to the priority group
    // then bitmask the PRIGROUP bits[8:10] with the required value
    SCB_AIRCR = SCB_AIRCR_VECTKEY & (~(0b111<<8)) |  NVIC_SIXTEEN_PRIORITY_GROUPS;
    #elif NVIC_PRIORITY_GROUPS == NVIC_EIGHT_PRIORITY_GROUPS
    // write the VECTKEY to allow write access to the register
    // then clear the PRIGROUP bits[8:10] that correspond to the priority group
    // then bitmask the PRIGROUP bits[8:10] with the required value
    SCB_AIRCR = SCB_AIRCR_VECTKEY & (~(0b111<<8)) |  NVIC_EIGHT_PRIORITY_GROUPS;
    #elif NVIC_PRIORITY_GROUPS == NVIC_FOUR_PRIORITY_GROUPS
    // write the VECTKEY to allow write access to the register
    // then clear the PRIGROUP bits[8:10] that correspond to the priority group
    // then bitmask the PRIGROUP bits[8:10] with the required value
    SCB_AIRCR = SCB_AIRCR_VECTKEY & (~(0b111<<8)) |  NVIC_FOUR_PRIORITY_GROUPS;
    #elif NVIC_PRIORITY_GROUPS == NVIC_TWO_PRIORITY_GROUPS
    // write the VECTKEY to allow write access to the register
    // then clear the PRIGROUP bits[8:10] that correspond to the priority group
    // then bitmask the PRIGROUP bits[8:10] with the required value
    SCB_AIRCR = SCB_AIRCR_VECTKEY & (~(0b111<<8)) |  NVIC_TWO_PRIORITY_GROUPS;
    #elif NVIC_PRIORITY_GROUPS == NVIC_NO_PRIORITY_GROUPS
    // write the VECTKEY to allow write access to the register
    // then clear the PRIGROUP bits[8:10] that correspond to the priority group
    // then bitmask the PRIGROUP bits[8:10] with the required value
    SCB_AIRCR = SCB_AIRCR_VECTKEY & (~(0b111<<8)) |  NVIC_NO_PRIORITY_GROUPS;
    #endif
}

u8 NVIC_u8EnableInterrupt (u8 copy_u8InterruptNumber){
    u8 errorStatus = 0;
    if (copy_u8InterruptNumber < 32){
        NVIC_ISER0 |=   (1<<copy_u8InterruptNumber);
        errorSt
    }
    else if (copy_u8InterruptNumber < 60){
        copy_u8InterruptNumber = copy_u8InterruptNumber - 32;
        NVIC_ISER1 |=   (1<<copy_u8InterruptNumber);
    }
    else {
        errorStatus = 1;
        return errorStatus;
    }
    return errorStatus;
}

