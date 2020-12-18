/********************************************************************************************
* @file NVIC_program.c
* @brief This files contains the NVIC driver functions definitions. 
* @author: Mohammed Abdelalim
* @version:
* @date: 15-12-2020
*********************************************************************************************/

#include "../../04-LIB/STD_TYPES.h"
#include "../../04-LIB/BIT_MATH.h"

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
    SCB_AIRCR = (SCB_AIRCR_VECTKEY & (~(0b111<<8))) |  NVIC_SIXTEEN_PRIORITY_GROUPS;
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
        //the following commented statement is converted to 3 assembly instructions:
        // 1)shifting 2)oring 3)storing
        //NVIC_ISER0 |= (1<<copy_u8InterruptNumber);

        //the following statement is converted to only 2 ass. instructions:
        // 1)shifting 2)storing .. so it more optimizes our code
        // note that the programming manual specifies that writing '0' to this
        // register has no effect .. that's why we can write the following 
        // statements without logical error. 
        NVIC_ISER0 = (1<<copy_u8InterruptNumber); 
        errorStatus = 0;
    }
    else if (copy_u8InterruptNumber < 60){
        // just trivial data processing to simply deal with ISER1
        copy_u8InterruptNumber = copy_u8InterruptNumber - 32;
        NVIC_ISER1 = (1<<copy_u8InterruptNumber);
        errorStatus = 0;
    }
    else {
        errorStatus = 1;
    }
    return errorStatus;
}

u8 NVIC_u8DisableInterrupt (u8 copy_u8InterruptNumber){
    u8 errorStatus = 0;
    if (copy_u8InterruptNumber < 32){
        NVIC_ICER0 = (1<<copy_u8InterruptNumber);
        errorStatus = 0;
    }
    else if (copy_u8InterruptNumber < 60){
       // just trivial data processing to simply deal with ICER1
        copy_u8InterruptNumber = copy_u8InterruptNumber - 32;
        NVIC_ICER1 = (1<<copy_u8InterruptNumber);
        errorStatus = 0;
    }
    else {
        errorStatus = 1;
    }
    return errorStatus;
}

u8 NVIC_u8ForcePendingInterrupt (u8 copy_u8InterruptNumber){
    u8 errorStatus = 0;
    if (copy_u8InterruptNumber < 32){
        NVIC_ISPR0 = (1<<copy_u8InterruptNumber);
        errorStatus = 0;
    }
    else if (copy_u8InterruptNumber < 60){
       // just trivial data processing to simply deal with ISPR1
        copy_u8InterruptNumber = copy_u8InterruptNumber - 32;
        NVIC_ISPR1 = (1<<copy_u8InterruptNumber);
        errorStatus = 0;
    }
    else {
        errorStatus = 1;
    }
    return errorStatus;
}

u8 NVIC_u8ClearPendingInterrupt (u8 copy_u8InterruptNumber){
    u8 errorStatus = 0;
    if (copy_u8InterruptNumber < 32){
        NVIC_ICPR0 = (1<<copy_u8InterruptNumber);
        errorStatus = 0;
    }
    else if (copy_u8InterruptNumber < 60){
       // just trivial data processing to simply deal with ISPR1
        copy_u8InterruptNumber = copy_u8InterruptNumber - 32;
        NVIC_ICPR1 = (1<<copy_u8InterruptNumber);
        errorStatus = 0;
    }
    else {
        errorStatus = 1;
    }
    return errorStatus;
}

u8 NVIC_u8GetActiveStatus (u8 copy_u8InterruptNumber){
    u8 activeStatus = 0;
     if (copy_u8InterruptNumber < 32){
         // get the active status of the required interrupt by reading the corresponding bit only
         // then shift the resulting value right so that the active status always returns '1' or '0'
        activeStatus = (NVIC_IABR0 & (1<<copy_u8InterruptNumber)) >> copy_u8InterruptNumber;
    }
    else if (copy_u8InterruptNumber < 60){
       // just trivial data processing to simply deal with ISPR1
        copy_u8InterruptNumber = copy_u8InterruptNumber - 32;
        // get the active status of the required interrupt by reading the corresponding bit only
        // then shift the resulting value right so that the active status always returns '1' or '0'
        activeStatus = (NVIC_IABR1 & (1<<copy_u8InterruptNumber)) >> copy_u8InterruptNumber;
    }
    return activeStatus;
}

u8 NVIC_u8SetInterruptPriority (u8 copy_u8InterruptNumber, u8 copy_u8Priority, u8 copy_u8SubPriority){
    u8 errorStatus = 0;

    // We deal with NVIC_IPR as array of registers.
    // To determine the specific IPR register corresponding to the interrupt number
    // we divide the interrupt number by 4 (ex.: if int. number is 10, then (10/4=2) so we write on IPR[2])
    // To determine the specific IP 8-bit register corresponding to the interrupt number in the
    // determine IPR register, we take the modulus of the interrupt number so that the result is the
    // location of the corresponding 8-bit register (ex.: 10%4=2, so we write in the IP[2])
    // But first, we determine the configuration done in the PRIGROUP field in the initialization function
    // to determine how will we deal with the binary point

    if (copy_u8InterruptNumber < 60) {
    #if NVIC_PRIORITY_GROUPS == NVIC_SIXTEEN_PRIORITY_GROUPS
    if (copy_u8Priority < 16){
    // clear targetted bits
    // note that we only access bits[4:7] of each 8-bit register, that's why we make additional 4 shifts at the end
    NVIC_IPR[(copy_u8InterruptNumber/4)] &= ~((0xF)<<(((copy_u8InterruptNumber%4)*8)+4));

    // bitmask the interrupt priority bits with the required priority value
    NVIC_IPR[(copy_u8InterruptNumber/4)] |= ((copy_u8Priority)<<(((copy_u8InterruptNumber%4)*8)+4));

    errorStatus = 0;
    }
    else {
        errorStatus = 1;
    }
    #endif
    #if NVIC_PRIORITY_GROUPS == NVIC_EIGHT_PRIORITY_GROUPS
    if ((copy_u8Priority < 8) && (copy_u8SubPriority < 2)){
    // clear targetted bits
    // note that we only access bits[4:7] of each 8-bit register, that's why we make additional 4 shifts at the end
    NVIC_IPR[(copy_u8InterruptNumber/4)] &= ~((0xF)<<(((copy_u8InterruptNumber%4)*8)+4));

    // bitmask the priority bits with the required priority value
    NVIC_IPR[(copy_u8InterruptNumber/4)] |= ((copy_u8Priority)<<(((copy_u8InterruptNumber%4)*8)+5));

    // bitmask the sub-priority bit with the required subpriority value
    NVIC_IPR[(copy_u8InterruptNumber/4)] |= ((copy_u8SubPriority)<<(((copy_u8InterruptNumber%4)*8)+4));

    errorStatus = 0;
    }
    else {
        errorStatus = 1;
    }
    #endif
     #if NVIC_PRIORITY_GROUPS == NVIC_FOUR_PRIORITY_GROUPS
    if ((copy_u8Priority < 4) && (copy_u8SubPriority < 4)){
    // clear targetted bits
    // note that we only access bits[4:7] of each 8-bit register, that's why we make additional 4 shifts at the end
    NVIC_IPR[(copy_u8InterruptNumber/4)] &= ~((0xF)<<(((copy_u8InterruptNumber%4)*8)+4));

    // bitmask the priority bits with the required priority value
    NVIC_IPR[(copy_u8InterruptNumber/4)] |= ((copy_u8Priority)<<(((copy_u8InterruptNumber%4)*8)+6));

    // bitmask the sub-priority bit with the required subpriority value
    NVIC_IPR[(copy_u8InterruptNumber/4)] |= ((copy_u8SubPriority)<<(((copy_u8InterruptNumber%4)*8)+4));
    
    errorStatus = 0;
    }
    else {
        errorStatus = 1;
    }
    #endif
     #if NVIC_PRIORITY_GROUPS == NVIC_TWO_PRIORITY_GROUPS
    if ((copy_u8Priority < 2) && (copy_u8SubPriority < 8)){
    // clear targetted bits
    // note that we only access bits[4:7] of each 8-bit register, that's why we make additional 4 shifts at the end
    NVIC_IPR[(copy_u8InterruptNumber/4)] &= ~((0xF)<<(((copy_u8InterruptNumber%4)*8)+4));

    // bitmask the priority bits with the required priority value
    NVIC_IPR[(copy_u8InterruptNumber/4)] |= ((copy_u8Priority)<<(((copy_u8InterruptNumber%4)*8)+7));

    // bitmask the sub-priority bit with the required subpriority value
    NVIC_IPR[(copy_u8InterruptNumber/4)] |= ((copy_u8SubPriority)<<(((copy_u8InterruptNumber%4)*8)+4));
    
    errorStatus = 0;
    }
    else {
        errorStatus = 1;
    }
    #endif
     #if NVIC_PRIORITY_GROUPS == NVIC_NO_PRIORITY_GROUPS
    if (copy_u8SubPriority < 16){
    // clear targetted bits
    // note that we only access bits[4:7] of each 8-bit register, that's why we make additional 4 shifts at the end
    NVIC_IPR[(copy_u8InterruptNumber/4)] &= ~((0xF)<<(((copy_u8InterruptNumber%4)*8)+4));

    // bitmask the sub-priority bit with the required subpriority value
    NVIC_IPR[(copy_u8InterruptNumber/4)] |= ((copy_u8SubPriority)<<(((copy_u8InterruptNumber%4)*8)+4));
    
    errorStatus = 0;
    }
    else {
        errorStatus = 1;
    }
    #endif
    }
    else {
        errorStatus =1;
    }


   return errorStatus;
}

u8 NVIC_u8SwTriggerInterrupt (u16 copy_u16InterruptID){
    u8 errorStatus = 0;
    if (copy_u16InterruptID < 240){
        NVIC_STIR = copy_u16InterruptID;
        errorStatus = 0;
    }
    else {
        errorStatus = 1;
    }
    return errorStatus;
}