/******************************************************************************
* @file AFIO_interface.h
* @brief This files contains the AFIO driver functions declratations as well as
* the used macros.
* Note: The only functions and configurations that are added so far are the ones 
* related to the functionality of the external interrupt.
* @author: Mohammed Abdelalim
* @version: V01
* @date: 18-12-2020
******************************************************************************/

#ifndef _AFIO_INTERFACE_H
#define _AFIO_INTERFACE_H

#define AFIO_EXTI0                      0
#define AFIO_EXTI1                      1
#define AFIO_EXTI2                      2
#define AFIO_EXTI3                      3
#define AFIO_EXTI4                      4
#define AFIO_EXTI5                      5
#define AFIO_EXTI6                      6
#define AFIO_EXTI7                      7
#define AFIO_EXTI8                      8
#define AFIO_EXTI9                      9
#define AFIO_EXTI10                     10
#define AFIO_EXTI11                     11
#define AFIO_EXTI12                     12
#define AFIO_EXTI13                     13
#define AFIO_EXTI14                     14
#define AFIO_EXTI15                     15

#define AFIO_PORTA                      0b0000
#define AFIO_PORTB                      0b0001
#define AFIO_PORTC                      0b0010


/**
 * @brief Enables a the RCC clock for the AFIO peripheral
 *
 * This functions simply enables the AFIO peripheral clock from the RCC
 *
 * @return void
 */
void AFIO_voidInit(void);


/**
 * @brief assigns the port required to be allowed as interrupt for a specific input line
 *
 * This functions takes as input the input line number (pin number) to be configured
 * as well as the port number in which this pin will be activated as interrupt pin, activates
 * this input line by writing in one of the AFIO_EXTICRx registers
 * Note that the microcontroller only allows one pin to be activated as interrupt source from
 * each input line (i.e: we can't configure PINA0 & PINB0 as interrupts at the same time as 
 * they are in the same input line)
 * 
 * @param copy_u8InputLineNumber The pin number which we want to activate as interrupt src
 *                               (AFIO_EXTIx, x=0:15)
 * @param copy_u8PortNumber The port number in which the pin is to be configured (AFIO_PORTA, B, or C)
 *
 * @return 0 if function completed successfully, 1 if otherwise
 */
u8 AFIO_u8SetInputLine(u8 copy_u8InputLineNumber, u8 copy_u8PortNumber);
#endif