/******************************************************************************
* @file RCC_private.h
* @brief This files contains the registers addresses as well as static functions declratations (if exist) for the Reset and clock control (RCC) peripheral
* @author: Mohammed Abdelalim
* @version: V01
* @date: 10-11-2020
******************************************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

// Registers addresses
#define RCC_CR 			    *((volatile u32 *) 0x40021000)
#define RCC_CFGR 	    	*((volatile u32 *) 0x40021004)
#define RCC_CIR 		    *((volatile u32 *) 0x40021008)
#define RCC_APB2RSTR 		*((volatile u32 *) 0x4002100C)
#define RCC_APB1RSTR 		*((volatile u32 *) 0x40021010)
#define RCC_AHBENR 		    *((volatile u32 *) 0x40021014)
#define RCC_APB2ENR 		*((volatile u32 *) 0x40021018)
#define RCC_APB1ENR 		*((volatile u32 *) 0x4002101C)
#define RCC_BDCR 	    	*((volatile u32 *) 0x40021020)
#define RCC_CSR 		    *((volatile u32 *) 0x40021024)

#define RCC_HSI 		    0
#define RCC_HSE			    1
#define RCC_PLL			    2

#endif 
