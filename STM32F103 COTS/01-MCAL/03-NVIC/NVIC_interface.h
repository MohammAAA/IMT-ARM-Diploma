/******************************************************************************
* @file NVIC_interface.h
* @brief This files contains the NVIC driver functions declratations as well as
* the used macros...
* @author: Mohammed Abdelalim
* @version: V01
* @date: 15-12-2020
******************************************************************************/

#ifndef _NVIC_INTERFACE_H
#define _NVIC_INTERFACE_H

/**
 * @brief Initializes the NVIC peripheral
 *
 * This function initializes the NVIC peripheral by disabling all the NVIC
 * interrupts and configuring the number of required priority groups and
 * subgroups
 * 
 * @pre_condition: only one of the following macros should be defined in NVIC_config.h:
 * (NVIC_SIXTEEN_PRIORITY_GROUPS), (NVIC_EIGHT_PRIORITY_GROUPS),
 * (NVIC_FOUR_PRIORITY_GROUPS), (NVIC_TWO_PRIORITY_GROUPS), (NVIC_NO_PRIORITY_GROUPS)
 * 
 * @return: void
 */
void NVIC_voidInit (void);

u8 NVIC_u8EnableInterrupt (u8 copy_u8InterruptNumber);
u8 NVIC_u8DisableInterrupt (u8 copy_u8InterruptNumber);
u8 NVIC_u8ForcePendingInterrupt (u8 copy_u8InterruptNumber);
u8 NVIC_u8ClearPendingInterrupt (u8 copy_u8InterruptNumber);
u8 NVIC_u8GetActiveStatus (u8 copy_u8InterruptNumber);
u8 NVIC_u8SetInterruptPriority (u8 copy_u8InterruptNumnber, u8 copy_u8Priority);
u8 NVIC_u8SwTriggerInterrupt (u16 copy_u16InterruptID);
#endif 
