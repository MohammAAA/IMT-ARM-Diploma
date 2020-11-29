/******************************************************************************
* @file RCC_private.h
* @brief This files contains the registers addresses as well as static functions declratations (if exist) for the Reset and clock control (RCC) peripheral
* @author: Mohammed Abdelalim
* @version: V01
* @date: 10-11-2020
******************************************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

// Clocks macros
#define RCC_HSI 		    0
#define RCC_HSE			    1
#define RCC_PLL			    2

// Registers addresses
#define RCC_CR 			    	*((volatile u32 *) 0x40021000UL)
#define RCC_CFGR 	    		*((volatile u32 *) 0x40021004UL)
#define RCC_CIR 		    	*((volatile u32 *) 0x40021008UL)
#define RCC_APB2RSTR 			*((volatile u32 *) 0x4002100CUL)
#define RCC_APB1RSTR 			*((volatile u32 *) 0x40021010UL)
#define RCC_AHBENR 		    	*((volatile u32 *) 0x40021014UL)
#define RCC_APB2ENR 			*((volatile u32 *) 0x40021018UL)
#define RCC_APB1ENR 			*((volatile u32 *) 0x4002101CUL)
#define RCC_BDCR 	    		*((volatile u32 *) 0x40021020UL)
#define RCC_CSR 		    	*((volatile u32 *) 0x40021024UL)

// HSE configurations
#define RCC_CR_HSE_ON			(1<<16)
#define RCC_CR_HSE_ON_RDY		(1<<17)
#define RCC_CFGR_SW_HSE1		(1<<0)
#define RCC_CFGR_SW_HSE2		(1<<1)
#define RCC_CFGR_SWS_HSE 		(1<<2)

// HSI configurations
#define RCC_CR_HSI_ON			(1<<0)
#define RCC_CR_HSI_ON_RDY		(1<<1)
#define RCC_CFGR_SW_HSI			0x00000003UL
#define RCC_CFGR_SWS_HSI 		0x0000000CUL

// PLL configurations
#define RCC_CFGR_PLL_SRC		(1<<16)
#define RCC_CFGR_PLL_XTPRE		(1<<17)
#define RCC_CR_PLL_ON			(1<<24)
#define RCC_CR_PLL_ON_RDY		(1<<25)
#define RCC_CFGR_SW_PLL1		(1<<1)
#define RCC_CFGR_SW_PLL2		(1<<0)
#define RCC_CFGR_SWS_PLL 		0x00000008UL


#define RCC_PLLMUL_X2 			0x003C0000UL
#define RCC_PLLMUL_X3_1 		0x00020000UL
#define RCC_PLLMUL_X3_2 		0x00380000UL
#define RCC_PLLMUL_X4_1 		0x00080000UL
#define RCC_PLLMUL_X4_2 		0x00340000UL
#define RCC_PLLMUL_X5_1 		0x000C0000UL
#define RCC_PLLMUL_X5_2 		0x00300000UL
#define RCC_PLLMUL_X6_1 		0x00100000UL
#define RCC_PLLMUL_X6_2 		0x002C0000UL
#define RCC_PLLMUL_X7_1 		0x00140000UL
#define RCC_PLLMUL_X7_2 		0x00280000UL
#define RCC_PLLMUL_X8_1 		0x00180000UL
#define RCC_PLLMUL_X8_2 		0x00240000UL
#define RCC_PLLMUL_X9_1 		0x001C0000UL
#define RCC_PLLMUL_X9_2 		0x00200000UL
#define RCC_PLLMUL_X10_1 		0x00200000UL
#define RCC_PLLMUL_X10_2 		0x001C0000UL
#define RCC_PLLMUL_X11_1 		0x00240000UL
#define RCC_PLLMUL_X11_2 		0x00180000UL
#define RCC_PLLMUL_X12_1 		0x00280000UL
#define RCC_PLLMUL_X12_2 		0x00140000UL
#define RCC_PLLMUL_X13_1 		0x002C0000UL
#define RCC_PLLMUL_X13_2 		0x00100000UL
#define RCC_PLLMUL_X14_1 		0x00300000UL
#define RCC_PLLMUL_X14_2 		0x000C0000UL
#define RCC_PLLMUL_X15_1 		0x00340000UL
#define RCC_PLLMUL_X15_2 		0x00080000UL
#define RCC_PLLMUL_X16 			0x003C0000UL

// APB2 bus configurations
#define RCC_CFGR_PPRE2_DIV_1	0x00002000UL
#define RCC_CFGR_PPRE2_DIV_2_1	0x00002000UL
#define RCC_CFGR_PPRE2_DIV_2_2	0x00001800UL
#define RCC_CFGR_PPRE2_DIV_4_1	0x00002800UL
#define RCC_CFGR_PPRE2_DIV_4_2	0x00001000UL
#define RCC_CFGR_PPRE2_DIV_8_1	0x00003000UL
#define RCC_CFGR_PPRE2_DIV_8_2	0x00000800UL
#define RCC_CFGR_PPRE2_DIV_16	0x00003800UL

// APB1 bus configurations
#define RCC_CFGR_PPRE1_DIV_1	0x00004000UL
#define RCC_CFGR_PPRE1_DIV_2_1	0x00004000UL
#define RCC_CFGR_PPRE1_DIV_2_2	0x00003000UL
#define RCC_CFGR_PPRE1_DIV_4_1	0x00005000UL
#define RCC_CFGR_PPRE1_DIV_4_2	0x00002000UL
#define RCC_CFGR_PPRE1_DIV_8_1	0x00006000UL
#define RCC_CFGR_PPRE1_DIV_8_2	0x00001000UL
#define RCC_CFGR_PPRE1_DIV_16	0x00007000UL

// AHB bus configurations
#define RCC_CFGR_HPRE_DIV_1		0x00000080UL
#define RCC_CFGR_HPRE_DIV_2_1	0x00000080UL
#define RCC_CFGR_HPRE_DIV_2_2	0x00000070UL
#define RCC_CFGR_HPRE_DIV_4_1	0x00000090UL
#define RCC_CFGR_HPRE_DIV_4_2	0x00000060UL
#define RCC_CFGR_HPRE_DIV_8_1	0x000000A0UL
#define RCC_CFGR_HPRE_DIV_8_2	0x00000050UL
#define RCC_CFGR_HPRE_DIV_16_1	0x000000B0UL
#define RCC_CFGR_HPRE_DIV_16_2	0x00000040UL
#define RCC_CFGR_HPRE_DIV_64_1	0x000000C0UL
#define RCC_CFGR_HPRE_DIV_64_2	0x00000030UL
#define RCC_CFGR_HPRE_DIV_128_1	0x000000D0UL
#define RCC_CFGR_HPRE_DIV_128_2	0x00000020UL
#define RCC_CFGR_HPRE_DIV_256_1	0x000000E0UL
#define RCC_CFGR_HPRE_DIV_256_2	0x00000010UL
#define RCC_CFGR_HPRE_DIV_512	0x000000F0UL

// Clock security system configurations
#define RCC_CR_CSS_ON			(1<<19)


#endif 
