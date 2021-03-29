/******************************************************************************
* @file GPIO_interface.h
* @brief This files contains the GPIO driver functions declratations as well as
* the used macros.
* @author: Mohammed Abdelalim
* @version: V01
* @date: 24-11-2020
******************************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define GPIO_PORTA_PERIPHERAL_ID                        2
#define GPIO_PORTB_PERIPHERAL_ID                        3
#define GPIO_PORTC_PERIPHERAL_ID                        4

#define GPIO_INPUT_ANALOG_MODE                          0b0000
#define GPIO_INPUT_FLOATING_MODE                        0b0100
#define GPIO_INPUT_PULL_UPDOWN_MODE                     0b1000
#define GPIO_OUTPUT_2MHZ_PUSH_PULL_MODE                 0b0010
#define GPIO_OUTPUT_2MHZ_OPEN_DRAIN_MODE                0b0110
#define GPIO_OUTPUT_10MHZ_PUSH_PULL_MODE                0b0001
#define GPIO_OUTPUT_10MHZ_OPEN_DRAIN_MODE               0b0101
#define GPIO_OUTPUT_50MHZ_PUSH_PULL_MODE                0b0011
#define GPIO_OUTPUT_50MHZ_OPEN_DRAIN_MODE               0b0111

#define PIN_0											0
#define PIN_1											1
#define PIN_2											2
#define PIN_3											3
#define PIN_4											4
#define PIN_5											5
#define PIN_6											6
#define PIN_7											7
#define PIN_8											8
#define PIN_9											9
#define PIN_10											10
#define PIN_11											11
#define PIN_12											12
#define PIN_13											13
#define PIN_14											14
#define PIN_15											15

#define GPIO_PIN_HIGH									1
#define GPIO_PIN_LOW									0


/**
 * @brief Enables a certain GPIO portx (in STM32F103C, x may be A,B, or C)
 *
 * This function takes as input the port number to be enabled to activate
 * its clock with the RCC peripheral
 * 
 * @pre_condition RCC_voidInit() has been called before calling this function
 * in main.c
 * 
 * @param copy_portNumber The port number to be enabled (GPIO_PORTx_PERIPHERAL_ID)
 *
 * @return void
 */
void GPIO_voidEnablePort(u8 copy_portNumber);


/**
 * @brief assigns the direction and mode of a specific pin in a specific port
 *
 * This function takes as input the port number in which the pin will be accessed,
 * the exact pin number, and the direction and its configuration to set them to this
 * specific pin
 * 
 * @param copy_portNumber The port number in which the pin will be accessed (GPIO_PORTx_PERIPHERAL_ID)
 * @param copy_pinNumber The exact pin number to be accessed (decimal from 0 to 15)
 * @param copy_modeAndConfig the mode and configuration to be assigned to the pin
 *
 * @return void
 */
void GPIO_voidSetPinDirection (u8 copy_portNumber, u8 copy_pinNumber, u8 copy_modeAndConfig);

/**
 * @brief assigns the direction and mode of the whole port
 *
 * This function takes as input the port number which will be accessed in this function,
 * and the direction and its configuration to set them to this
 * specific port
 * 
 * @param copy_portNumber The port number in which the pin will be accessed (GPIO_PORTx_PERIPHERAL_ID)
 * @param copy_modeAndConfig the mode and configuration to be assigned to the port
 *
 * @return void
 */
void GPIO_voidSetPortDirection (u8 copy_portNumber, u8 copy_modeAndConfig);


/**
 * @brief sets the output value of a specific pin to high or low value
 *
 * This function takes as input the port number in which the pin will be accessed,
 * the exact pin number, and the value to be written to this pin
 * 
 * @param copy_portNumber The port number in which the pin will be accessed (GPIO_PORTx_PERIPHERAL_ID)
 * @param copy_pinNumber The exact pin number to be written to (decimal from 0 to 15)
 * @param copy_value the value to be assigned to the pin (GPIO_PIN_HIGH, GPIO_PIN_LOW)
 *
 * @return void
 */
void GPIO_voidSetPinValue (u8 copy_portNumber, u8 copy_pinNumber, u8 copy_value);

/**
 * @brief sets the output value of the whole port to high or low value
 *
 * This function takes as input the port number which will be written to,
 * and the value to be written to this port
 * 
 * @param copy_portNumber The port number to be written to (GPIO_PORTx_PERIPHERAL_ID)
 * @param copy_value the value to be assigned to the port (0xFFFF or 0x0000)
 *
 * @return void
 */
void GPIO_voidSetPortValue (u8 copy_portNumber, u16 copy_value);

/**
 * @brief reads the input value of a specific pin whether it's high or low value
 *
 * This function takes as input the port number in which the pin will be read,
 * the exact pin number, and returns the value of this pin
 * 
 * @param copy_portNumber The port number in which the pin will be accessed (GPIO_PORTx_PERIPHERAL_ID)
 * @param copy_pinNumber The exact pin number to be read (decimal from 0 to 15)
 *
 * @return u8, the value of this pin (whether GPIO_PIN_HIGH or GPIO_PIN_LOW)
 */
u8 GPIO_u8GetPinValue (u8 copy_portNumber, u8 copy_pinNumber);

/**
 * @brief reads the input value of the whole port
 *
 * This function takes as input the port number to be read,
 * and returns the value of this port
 * 
 * @param copy_portNumber The port number to be read (GPIO_PORTx_PERIPHERAL_ID)
 *
 * @return u16, the value of this port
 */
u16 GPIO_u8GetPortValue (u8 copy_portNumber);

#endif