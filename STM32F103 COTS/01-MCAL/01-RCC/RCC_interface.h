/******************************************************************************
* @file RCC_interface.h
* @brief This files contains the RCC driver functions declratations as well as
* the used macros...
* Functions and configurations to be added later: HSE bypass, HSI calibration & trim,
* MCO, ADC prescaler, USB prescaler, RCC peripheral interrupts, reset functions,
* and backup domain control.
* @author: Mohammed Abdelalim
* @version: V01
* @date: 10-11-2020
******************************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB			1
#define RCC_APB1		3
#define RCC_APB2		6

// functions naming convention: SWCOMPONENT_returnVerb

/**
 * @brief Initializes the RCC peripheral
 *
 * This function initializes the RCC peripheral by enabling the system clock
 * whether it's HSI, HSE, or PLL as well as the clock needed configurations.
 * 
 * @return void
 */
void RCC_voidInit(void);

/**
 * @brief Enables a certain peripheral clock
 *
 * This functions takes as inputs the peripheral bus ID (AHB, APB1, APB2) and the
 * required peripheral ID and enables its corresponding clock
 * 
 * @param copy_u8BusID The peripheral bus ID (found in datasheet)
 * @param copy_u8PeripheralID The targeted peripheral ID (found in datasheet)
 *
 * @return void
 */
void RCC_voidEnableClock(u8 copy_u8BusID, u8 copy_u8PeripheralID);

/**
 * @brief Disables a certain peripheral clock
 *
 * This functions takes as inputs the peripheral bus ID (AHB, APB1, APB2) and the
 * required peripheral ID and disables its corresponding clock
 * 
 * @param copy_u8BusID The peripheral bus ID (found in datasheet)
 * @param copy_u8PeripheralID The targeted peripheral ID (found in datasheet)
 *
 * @return void
 */
void RCC_voidDisableClock(u8 copy_u8BusID, u8 copy_u8PeripheralID);

#endif 
