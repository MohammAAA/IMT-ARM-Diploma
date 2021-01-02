/******************************************************************************
* @file STK_interface.h
* @brief This files contains the STK driver functions declratations as well as
* the used macros...
* @author: Mohammed Abdelalim
* @version: V01
* @date: 1-1-2021
******************************************************************************/

#ifndef _STK_INTERFACE_H
#define _STK_INTERFACE_H

/**
 * @brief Initializes the Systick peripheral
 *
 * This function initializes the systick peripheral by configuring the clock source
 * of the systick whether (AHB or AHB/8), disables timer and resets the load and
 * val registers
 * 
 * @pre_condition: define the STK_CLOCK in STK_config.h to the clock configuration
 * you want
 * 
 * @return: void
 */
void STK_voidInit (void);

/**
 * @brief Sets a specific single delay defined by number of ticks
 *
 * This function takes the number of ticks to be delayed as an input and sets
 * the systick to count those ticks, causing the required delay.
 * For 8 MHz AHB clock, AHB/8 clock source, each tick corresponds to 1 micro second.
 * This function polls on the flag that indicates that the systick has done its job,
 * if you want an interrupt based delay, use the STK_voidSetSingleIntervalus() instead.
 * 
 * @param copy_u32NumberOfTicks Number of ticks to be counted in the systick
 * 
 * @return: void
 */
void STK_voidSetDelayus (u32 copy_u32NumberOfTicks);

/**
 * @brief Sets a specific periodic delay/interval defined by number of ticks
 *
 * This function takes the number of ticks to be delayed as an input and sets
 * the systick to count those ticks, causing the required delay continuously.
 * For 8 MHz AHB clock, AHB/8 clock source, each tick corresponds to 1 micro second.
 * This function can be interrupt based so that an ISR is executed once the systick has done
 * its job
 * 
 * @param copy_u32NumberOfTicks Number of ticks to be counted in the systick
 * @param copy_u8InterruptStatus Determine if you want to enable interrupt or not ...
 *                               Use one of the following macros:
 *                               STK_COUNT_TO_ZERO_INTERRUPT_ENABLE,
 *                               STK_COUNT_TO_ZERO_INTERRUPT_DISABLE
 * @param Copy_pf A pointer to function that takes (void) and returns void, this function is
 *                user specified ISR .. if interrupt is disabled, pass "NULL" to this parameter.

 * 
 * @return: void
 */
void STK_voidSetPeriodicIntervalus (u32 copy_u32NumberOfTicks, u8 copy_u8InterruptStatus, void (*Copy_pf)(void));

/**
 * @brief Sets a specific single delay/interval defined by number of ticks
 *
 * This function takes the number of ticks to be delayed as an input and sets
 * the systick to count those ticks, causing the required single delay.
 * For 8 MHz AHB clock, AHB/8 clock source, each tick corresponds to 1 micro second.
 * This function can be interrupt based so that an ISR is executed once the systick has done
 * its job
 * 
 * @param copy_u32NumberOfTicks Number of ticks to be counted in the systick
 * @param copy_u8InterruptStatus Determine if you want to enable interrupt or not ...
 *                               Use one of the following macros:
 *                               STK_COUNT_TO_ZERO_INTERRUPT_ENABLE,
 *                               STK_COUNT_TO_ZERO_INTERRUPT_DISABLE
 * @param Copy_pf A pointer to function that takes (void) and returns void, this function is
 *                user specified ISR .. if interrupt is disabled, pass "NULL" to this parameter.

 * 
 * @return: void
 */
void STK_voidSetSingleIntervalus (u32 copy_u32NumberOfTicks, u8 copy_u8InterruptStatus, void (*Copy_pf)(void));

/**
 * @brief Stops the systick core peripheral
 *
 * This function stops the systick functionlaity, and resets the load and val registers to zero
 * 
 * @return: void
 */
void STK_voidStopInterval (void);

/**
 * @brief Gets the elapsed counts since the systick started counting
 *
 * This function returns the elapsed counts that the systick has already counted
 * since its last activation
 * 
 * @return: u32 number of elapsed ticks
 */
u32 STK_u32GetElapsedTicks (void);

/**
 * @brief Gets the remaining systick counts until reaching zero
 *
 * This function returns the remaining counts that the systick will need to reach
 * its zero
 * 
 * @return: u32 number of remaning ticks
 */

u32 STK_u32GetRemaningTicks (void);
#endif 
