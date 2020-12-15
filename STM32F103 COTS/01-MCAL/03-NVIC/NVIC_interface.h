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
 * @pre_condition: only one of the following macros should be defined in
 * NVIC_config.h:
 * (NVIC_SIXTEEN_PRIORITY_GROUPS), (NVIC_EIGHT_PRIORITY_GROUPS),
 * (NVIC_FOUR_PRIORITY_GROUPS), (NVIC_TWO_PRIORITY_GROUPS), (NVIC_NO_PRIORITY_GROUPS)
 * 
 * @return: void
 */
void NVIC_voidInit (void);

/**
 * @brief Enables a certain NVIC interrupt
 *
 * This functions takes as input the interrupt number as specified in the
 * register description manual and enables the corresponding NVIC enable bit
 * 
 * @param copy_u8InterruptNumber The interrupt number to be enabled
 *                               (as specified in the register description manual)
 *
 * @return '0' if function is successfully finished, '1' if otherwise
 */
u8 NVIC_u8EnableInterrupt (u8 copy_u8InterruptNumber);

/**
 * @brief Disables a certain NVIC interrupt
 *
 * This functions takes as input the interrupt number as specified in the
 * register description manual and disables the corresponding NVIC enable bit
 * 
 * @param copy_u8InterruptNumber The interrupt number to be disabled
 *                               (as specified in the register description manual)
 *
 * @return '0' if function is successfully finished, '1' if otherwise
 */
u8 NVIC_u8DisableInterrupt (u8 copy_u8InterruptNumber);

/**
 * @brief Force a certain NVIC pending interrupt flag to be set
 *
 * This functions takes as input the interrupt number as specified in the
 * register description manual and force-sets the corresponding pending flag by SW
 * 
 * @param copy_u8InterruptNumber The interrupt number for which the pending flag is set
 *                               (as specified in the register description manual)
 *
 * @return '0' if function is successfully finished, '1' if otherwise
 */
u8 NVIC_u8ForcePendingInterrupt (u8 copy_u8InterruptNumber);

/**
 * @brief clears a certain NVIC pending interrupt flag
 *
 * This functions takes as input the interrupt number as specified in the
 * register description manual and clears the corresponding pending flag by SW
 * 
 * @param copy_u8InterruptNumber The interrupt number for which the pending flag is to be
 *                               cleared (as specified in the register description manual)
 *
 * @return '0' if function is successfully finished, '1' if otherwise
 */
u8 NVIC_u8ClearPendingInterrupt (u8 copy_u8InterruptNumber);


/**
 * @brief reads the active status of a certain NVIC interrupt
 *  
 * This functions takes as input the interrupt number as specified in the
 * register description manual and reads the corresponding active status
 * (whether the interrupt is being executed already or not)
 * 
 * @param copy_u8InterruptNumber The interrupt number for which the active status is to
 *                               be read
 *
 * @return '0' if interrupt is not being executed, '1' if interrupt is being executed
 */
u8 NVIC_u8GetActiveStatus (u8 copy_u8InterruptNumber);

/**
 * @brief sets the interrupt priority of a specific interrupt
 *  
 * This functions takes as input the interrupt number as specified in the
 * register description manual, and the priority to be assigned to this interrupt
 * and sets this priority to this interrupt
 * 
 * @param copy_u8InterruptNumber The interrupt number for which the priority level
 *                               to be set
 * @param copy_u8Priority The priority level to be set for the interrupt, the assigned 
 *                        priority must be in range [0:15], taking into consideration the group/subgroup configuration
 *                        which is been applied in the init function  
 * @param copy_u8SubPriority The sub-priority level to be set for the interrupt, the assigned 
 *                        sub-priority must be in range [0:15], taking into consideration the group/subgroup configuration
 *                        which is been applied in the init function
 *
 * @return '0' if function is successfully finished, '1' if otherwise
 */
u8 NVIC_u8SetInterruptPriority (u8 copy_u8InterruptNumber, u8 copy_u8Priority, u8 copy_u8SubPriority);

/**
 * @brief triggers a certain interrupt by software
 *  
 * This functions takes as input the interrupt number as specified in the
 * register description manual and triggers the corresponding interrupt manually
 * by software
 * 
 * @param copy_u8InterruptNumber The interrupt number for which the interrupt is to
 *                               be triggered by software
 *
 * @return '0' if function is successfully finished, '1' if otherwise
 */
u8 NVIC_u8SwTriggerInterrupt (u16 copy_u16InterruptID);
#endif 
