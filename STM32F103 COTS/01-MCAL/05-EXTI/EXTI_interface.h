/******************************************************************************
* @file EXTI_interface.h
* @brief This files contains the EXTI driver functions declratations as well as
* the used macros...
* @author: Mohammed Abdelalim
* @version: V01
* @date: 19-12-2020
******************************************************************************/

#ifndef _EXTI_INTERFACE_H
#define _EXTI_INTERFACE_H

/**
 * @brief Enables a certain external interrupt line
 *
 * This function takes as input the input line number as well as the required
 * interrupt sensing edge, configures the triggering edge and enables the
 * corresponding interrupt
 * 
 * @param copy_u8InputLine The input line number to be enabled (EXTI_EXTI0:18)
 * @param copy_u8SensingEdge The sensing interrupt edge trigger to be configured
 *                          for this EXTI (EXTI_RISING_EDGE_TRIGGER,
 *                          EXTI_FALLING_EDGE_TRIGGER, EXTI_RISING_AND_FALLING_EDGE_TRIGGER)
 *
 * @return '0' if function is successfully finished, '1' if otherwise
 */
u8 EXTI_u8EnableInterrupt (u8 copy_u8InputLine, u8 copy_u8SensingEdge);

/**
 * @brief Enables a certain event
 *
 * This function takes as input the input line number as well as the required
 * event sensing edge, configures the triggering edge and enables the
 * corresponding event
 * 
 * @param copy_u8InputLine The input line number to be enabled (EXTI_EXTI0:18)
 * @param copy_u8SensingEdge The sensing event edge trigger to be configured
 *                          for this EXTI (EXTI_RISING_EDGE_TRIGGER,
 *                          EXTI_FALLING_EDGE_TRIGGER, EXTI_RISING_AND_FALLING_EDGE_TRIGGER)
 *
 * @return '0' if function is successfully finished, '1' if otherwise
 */
u8 EXTI_u8EnableEvent (u8 copy_u8InputLine, u8 copy_u8SensingEdge);

/**
 * @brief Disables a certain external interrupt line
 *
 * This function takes as input the input line number, and disables the
 * corresponding interrupt
 * 
 * @param copy_u8InputLine The input line number to be disabled (EXTI_EXTI0:18)
 *
 * @return '0' if function is successfully finished, '1' if otherwise
 */
u8 EXTI_u8DisableInterrupt (u8 copy_u8InputLine);

/**
 * @brief Disables a certain event
 *
 * This function takes as input the input line number, and disables the
 * corresponding event
 * 
 * @param copy_u8InputLine The input line number to be disabled (EXTI_EXTI0:18)
 *
 * @return '0' if function is successfully finished, '1' if otherwise
 */
u8 EXTI_u8DisableEvent (u8 copy_u8InputLine);

/**
 * @brief Forces software interrupt
 *
 * This function takes as input the input line number, and fires its software
 * interrupt which in turn sets the pending flag or the input line automatically
 * 
 * @param copy_u8InputLine The input line number to be fired by SW (EXTI_EXTI0:18)
 *
 * @return '0' if function is successfully finished, '1' if otherwise
 */
u8 EXTI_u8FireSWInterrupt (u8 copy_u8InputLine);

/**
 * @brief Reads the status of a specific interrupt line
 *
 * This function takes as input the input line number, and reads its pending status
 * whether it's 1, meaning that interrupt occurred or 0, meaning that interrupt didn't
 * occur yet
 * 
 * @param copy_u8InputLine The input line number to be investigated (EXTI_EXTI0:18)
 *
 * @return '0' if interrupt hasn't occurred yet, '1' if interrupt occurred
 */
u8 EXTI_u8GetInterruptStatus (u8 copy_u8InputLine);

/**
 * @brief Callbacks a function from a higher layer to the lower layer
 *
 * These functions take as input the address of the function to be callbacked, assigns this
 * address to the global static pointer to function so that the higher layer function can be
 * accessed and called by a lower layer SW component by this global pointer to function.
 * The global pointer to function that can be accessed is called (EXTI_Callback[x]),
 * where x = [0:18]
 * 
 * @param pf a pointer to the function to be callbacked
 *
 */
void EXTI_voidEXTI0SetCallback (void *pf (void));
void EXTI_voidEXTI1SetCallback (void *pf (void));
void EXTI_voidEXTI2SetCallback (void *pf (void));
void EXTI_voidEXTI3SetCallback (void *pf (void));
void EXTI_voidEXTI4SetCallback (void *pf (void));
void EXTI_voidEXTI5SetCallback (void *pf (void));
void EXTI_voidEXTI6SetCallback (void *pf (void));
void EXTI_voidEXTI7SetCallback (void *pf (void));
void EXTI_voidEXTI8SetCallback (void *pf (void));
void EXTI_voidEXTI9SetCallback (void *pf (void));
void EXTI_voidEXTI10SetCallback (void *pf (void));
void EXTI_voidEXTI11SetCallback (void *pf (void));
void EXTI_voidEXTI12SetCallback (void *pf (void));
void EXTI_voidEXTI13SetCallback (void *pf (void));
void EXTI_voidEXTI14SetCallback (void *pf (void));
void EXTI_voidEXTI15SetCallback (void *pf (void));
void EXTI_voidEXTI16SetCallback (void *pf (void));
void EXTI_voidEXTI17SetCallback (void *pf (void));
void EXTI_voidEXTI18SetCallback (void *pf (void));

#endif 
