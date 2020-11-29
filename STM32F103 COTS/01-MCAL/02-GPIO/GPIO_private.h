/******************************************************************************
* @file GPIO_private.h
* @brief This files contains the registers addresses as well as static functions declratations (if exist) for the GPIO peripheral
* @author: Mohammed Abdelalim
* @version: V01
* @date: 24-11-2020
******************************************************************************/

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

// GPIOx base addresses
#define GPIO_PORTA_BASE_ADDRESS 			    	 0x40010800UL
#define GPIO_PORTB_BASE_ADDRESS 			    	 0x40010C00UL
#define GPIO_PORTC_BASE_ADDRESS 			    	 0x40011000UL

// Registers addresses
#define GPIO_PORTA_CRL                              *((volatile u32 *) (GPIO_PORTA_BASE_ADDRESS))
#define GPIO_PORTA_CRH                              *((volatile u32 *) (GPIO_PORTA_BASE_ADDRESS + 0x04))
#define GPIO_PORTA_IDR                              *((volatile u32 *) (GPIO_PORTA_BASE_ADDRESS + 0x08))
#define GPIO_PORTA_ODR                              *((volatile u32 *) (GPIO_PORTA_BASE_ADDRESS + 0x0C))
#define GPIO_PORTA_BSRR                             *((volatile u32 *) (GPIO_PORTA_BASE_ADDRESS + 0x10))
#define GPIO_PORTA_BRR                              *((volatile u32 *) (GPIO_PORTA_BASE_ADDRESS + 0x14))
#define GPIO_PORTA_LCKR                             *((volatile u32 *) (GPIO_PORTA_BASE_ADDRESS + 0x18))
#define GPIO_PORTB_CRL                              *((volatile u32 *) (GPIO_PORTB_BASE_ADDRESS))
#define GPIO_PORTB_CRH                              *((volatile u32 *) (GPIO_PORTB_BASE_ADDRESS + 0x04))
#define GPIO_PORTB_IDR                              *((volatile u32 *) (GPIO_PORTB_BASE_ADDRESS + 0x08))
#define GPIO_PORTB_ODR                              *((volatile u32 *) (GPIO_PORTB_BASE_ADDRESS + 0x0C))
#define GPIO_PORTB_BSRR                             *((volatile u32 *) (GPIO_PORTB_BASE_ADDRESS + 0x10))
#define GPIO_PORTB_BRR                              *((volatile u32 *) (GPIO_PORTB_BASE_ADDRESS + 0x14))
#define GPIO_PORTB_LCKR                             *((volatile u32 *) (GPIO_PORTB_BASE_ADDRESS + 0x18))
#define GPIO_PORTC_CRL                              *((volatile u32 *) (GPIO_PORTC_BASE_ADDRESS))
#define GPIO_PORTC_CRH                              *((volatile u32 *) (GPIO_PORTC_BASE_ADDRESS + 0x04))
#define GPIO_PORTC_IDR                              *((volatile u32 *) (GPIO_PORTC_BASE_ADDRESS + 0x08))
#define GPIO_PORTC_ODR                              *((volatile u32 *) (GPIO_PORTC_BASE_ADDRESS + 0x0C))
#define GPIO_PORTC_BSRR                             *((volatile u32 *) (GPIO_PORTC_BASE_ADDRESS + 0x10))
#define GPIO_PORTC_BRR                              *((volatile u32 *) (GPIO_PORTC_BASE_ADDRESS + 0x14))
#define GPIO_PORTC_LCKR                             *((volatile u32 *) (GPIO_PORTC_BASE_ADDRESS + 0x18))


#define GPIO_PORTA_PERIPHERAL_ID                    2
#define GPIO_PORTB_PERIPHERAL_ID                    3
#define GPIO_PORTC_PERIPHERAL_ID                    4




#endif 
