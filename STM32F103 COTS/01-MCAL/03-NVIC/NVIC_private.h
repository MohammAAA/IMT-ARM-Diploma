/******************************************************************************
* @file NVIC_private.h
* @brief This files contains the registers addresses as well as static functions
* declratations (if exist) for the nested vector interrupt controller (NVIC)
* peripheral
* @author: Mohammed Abdelalim
* @version: V01
* @date: 15-12-2020
******************************************************************************/

#ifndef _NVIC_PRIVATE_H
#define _NVIC_PRIVATE_H

#define NVIC_BASE_ADDRESS           0xE000E100

// For STM32F103C8T6 we only have 60 interrupts so we only need 2 registers
#define NVIC_ISER0                  *((volatile u32 *) (NVIC_BASE_ADDRESS+0x000))
#define NVIC_ISER1                  *((volatile u32 *) (NVIC_BASE_ADDRESS+0x004))

#define NVIC_ICER0                  *((volatile u32 *) (NVIC_BASE_ADDRESS+0x080))
#define NVIC_ICER1                  *((volatile u32 *) (NVIC_BASE_ADDRESS+0x040))

#define NVIC_ISPR0                  *((volatile u32 *) (NVIC_BASE_ADDRESS+0x100))
#define NVIC_ISPR1                  *((volatile u32 *) (NVIC_BASE_ADDRESS+0x104))

#define NVIC_ICPR0                  *((volatile u32 *) (NVIC_BASE_ADDRESS+0x180))
#define NVIC_ICPR1                  *((volatile u32 *) (NVIC_BASE_ADDRESS+0x184))

#define NVIC_IABR0                  *((volatile u32 *) (NVIC_BASE_ADDRESS+0x200))
#define NVIC_IABR1                  *((volatile u32 *) (NVIC_BASE_ADDRESS+0x204))

/* This following register is considered as an array whose first index is IPR[0],
 we can get along with this array until we (ideally) reach the IPR[20] which is
 specified in datasheet */
#define NVIC_IPR                     ((volatile u32 *) (NVIC_BASE_ADDRESS+0x300))

#define NVIC_STIR                   *((volatile u32 *) (NVIC_BASE_ADDRESS+0xE00))
#endif
