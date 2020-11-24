/********************************************************************************************
* @file RCC_program.c
* @brief This files contains the RCC driver functions definitions. 
* @author: Mohammed Abdelalim
* @version:
* @date: 10-11-2020
*********************************************************************************************/

#include "../include/STD_TYPES.h"
#include "BIT_MATH.h"

// e3ml include b eltarteeb da (brattebhom 3ala 7sb el dependancy bta3t-hom)
#include "../include/RCC_interface.h" // lazm yb2a awl include 3shan el functions declarations bykoon feeha el macros elly f el 2 files elgayeen
#include "../include/RCC_private.h"
#include "RCC_config.h"

void RCC_voidInit(void){

	// enable and select the required clock source to be the system clock
	#if RCC_CLOCKTYPE == RCC_HSE
	// enable clock source
	RCC_CR |= RCC_CR_HSE_ON;
	// wait for the HSE ready flag to be set
	while ((RCC_CR & RCC_CR_HSE_ON_RDY) == 0);
	// select HSE as the system clock
	RCC_CFGR |=  RCC_CFGR_SW_HSE1;
	RCC_CFGR &= ~RCC_CFGR_SW_HSE2;
	// wait for the SWS flag to be set
	while ((RCC_CFGR & RCC_CFGR_SWS_HSE) != 4);

	#elif RCC_CLOCKTYPE == RCC_HSI
	// enable clock source
	RCC_CR |= RCC_CR_HSI_ON;
	// wait for the HSI ready flag to be set
	while ((RCC_CR & RCC_CR_HSI_ON_RDY) == 0);
	// select HSI as the system clock
	RCC_CFGR &= ~RCC_CFGR_SW_HSI;
	// wait for the SWS flag to be set
	while ((RCC_CFGR & RCC_CFGR_SWS_HSI) != 0);

	#elif RCC_CLOCKTYPE == RCC_PLL
	// configure the PLL input clock source
	#ifdef RCC_PLL_HSI_DIV_2
	// set the PLL entry clock source to HSI/2
	RCC_CFGR &= ~RCC_CFGR_PLL_SRC;
	#endif
	#ifdef RCC_PLL_HSE
	// set the PLL entry clock source to HSE
	RCC_CFGR |= RCC_CFGR_PLL_SRC;
	// disable the HSE divider for PLL entry
	RCC_CFGR &= ~RCC_CFGR_PLL_XTPRE;
	#endif
	#ifdef RCC_PLL_HSE_DIV_2
	// set the PLL entry clock source to HSE
	RCC_CFGR |= RCC_CFGR_PLL_SRC;
	// enable the HSE divider for PLL entry
	RCC_CFGR |= RCC_CFGR_PLL_XTPRE;
	#endif
	// configure the PLL multiplication factor
	// either x(2,3,4,5,6,7,8,9,10,11,12,13,14,15,16)
	#ifdef RCC_PLL_MUL_2
	RCC_CFGR &= ~RCC_PLLMUL_X2;
	#endif
	#ifdef RCC_PLL_MUL_3
	RCC_CFGR |= RCC_PLLMUL_X3_1;
	RCC_CFGR &= ~RCC_PLLMUL_X3_2;
	#endif
	#ifdef RCC_PLL_MUL_4
	RCC_CFGR |= RCC_PLLMUL_X4_1;
	RCC_CFGR &= ~RCC_PLLMUL_X4_2;
	#endif
	#ifdef RCC_PLL_MUL_5
	RCC_CFGR |= RCC_PLLMUL_X5_1;
	RCC_CFGR &= ~RCC_PLLMUL_X5_2;
	#endif
	#ifdef RCC_PLL_MUL_6
	RCC_CFGR |= RCC_PLLMUL_X6_1;
	RCC_CFGR &= ~RCC_PLLMUL_X6_2;
	#endif
	#ifdef RCC_PLL_MUL_7
	RCC_CFGR |= RCC_PLLMUL_X7_1;
	RCC_CFGR &= ~RCC_PLLMUL_X7_2;
	#endif
	#ifdef RCC_PLL_MUL_8
	RCC_CFGR |= RCC_PLLMUL_X8_1;
	RCC_CFGR &= ~RCC_PLLMUL_X8_2;
	#endif
	#ifdef RCC_PLL_MUL_9
	RCC_CFGR |= RCC_PLLMUL_X9_1;
	RCC_CFGR &= ~RCC_PLLMUL_X9_2;
	#endif
	#ifdef RCC_PLL_MUL_10
	RCC_CFGR |= RCC_PLLMUL_X10_1;
	RCC_CFGR &= ~RCC_PLLMUL_X10_2;
	#endif
	#ifdef RCC_PLL_MUL_11
	RCC_CFGR |= RCC_PLLMUL_X11_1;
	RCC_CFGR &= ~RCC_PLLMUL_X11_2;
	#endif
	#ifdef RCC_PLL_MUL_12
	RCC_CFGR |= RCC_PLLMUL_X12_1;
	RCC_CFGR &= ~RCC_PLLMUL_X12_2;
	#endif
	#ifdef RCC_PLL_MUL_13
	RCC_CFGR |= RCC_PLLMUL_X13_1;
	RCC_CFGR &= ~RCC_PLLMUL_X13_2;
	#endif
	#ifdef RCC_PLL_MUL_14
	RCC_CFGR |= RCC_PLLMUL_X14_1;
	RCC_CFGR &= ~RCC_PLLMUL_X14_2;
	#endif
	#ifdef RCC_PLL_MUL_15
	RCC_CFGR |= RCC_PLLMUL_X15_1;
	RCC_CFGR &= ~RCC_PLLMUL_X15_2;
	#endif
	#ifdef RCC_PLL_MUL_16
	RCC_CFGR |= RCC_PLLMUL_X16;
	#endif
	// Enable the PLL clock source
	RCC_CR |= RCC_CR_PLL_ON;
	while ((RCC_CR & RCC_CR_PLL_ON_RDY) == 0);
	// select PLL as the system clock
	RCC_CFGR |= RCC_CFGR_SW_PLL1;
	RCC_CFGR &= ~RCC_CFGR_SW_PLL2;
	// wait for the SWS flag to be set
	while ((RCC_CFGR & RCC_CFGR_SWS_PLL) != 8);
	#else
		#error ("Wrong clock source choice!") //use #error only with preprocessor operations
	#endif

	// enable the clock security system (it's disabled by default)
	#ifdef RCC_CSS
	RCC_CR |= RCC_CR_CSS_ON;
	#endif

	// set the prescaler of AHB, APB1, and APB2 bus whether the system clock is not divided
	// or divided by 2, 4, 8, or 16
	#ifdef RCC_APB2_NO_PRESCALER
	RCC_CFGR &= ~RCC_CFGR_PPRE2_DIV_1;
	#endif
	#ifdef RCC_APB2_PRESCALER_2
	RCC_CFGR |= RCC_CFGR_PPRE2_DIV_2_1;
	RCC_CFGR &= ~RCC_CFGR_PPRE2_DIV_2_2;
	#endif
	#ifdef RCC_APB2_PRESCALER_4
	RCC_CFGR |= RCC_CFGR_PPRE2_DIV_4_1;
	RCC_CFGR &= ~RCC_CFGR_PPRE2_DIV_4_2;
	#endif
	#ifdef RCC_APB2_PRESCALER_8
	RCC_CFGR |= RCC_CFGR_PPRE2_DIV_8_1;
	RCC_CFGR &= ~RCC_CFGR_PPRE2_DIV_8_2;
	#endif
	#ifdef RCC_APB2_PRESCALER_16
	RCC_CFGR |= RCC_CFGR_PPRE2_DIV_16;
	#endif

	#ifdef RCC_APB1_NO_PRESCALER
	RCC_CFGR &= ~RCC_CFGR_PPRE1_DIV_1;
	#endif
	#ifdef RCC_APB1_PRESCALER_2
	RCC_CFGR |= RCC_CFGR_PPRE1_DIV_2_1;
	RCC_CFGR &= ~RCC_CFGR_PPRE1_DIV_2_2;
	#endif
	#ifdef RCC_APB1_PRESCALER_4
	RCC_CFGR |= RCC_CFGR_PPRE1_DIV_4_1;
	RCC_CFGR &= ~RCC_CFGR_PPRE1_DIV_4_1;
	#endif
	#ifdef RCC_APB1_PRESCALER_8
	RCC_CFGR |= RCC_CFGR_PPRE1_DIV_8_1;
	RCC_CFGR &= ~RCC_CFGR_PPRE1_DIV_8_1;
	#endif
	#ifdef RCC_APB1_PRESCALER_16
	RCC_CFGR |= RCC_CFGR_PPRE1_DIV_16;
	#endif

	#ifdef RCC_AHB_NO_PRESCALER
	RCC_CFGR &= ~RCC_CFGR_HPRE_DIV_1;
	#endif
	#ifdef RCC_AHB_PRESCALER_2
	RCC_CFGR |= RCC_CFGR_HPRE_DIV_2_1;
	RCC_CFGR &= ~RCC_CFGR_HPRE_DIV_2_2;
	#endif
	#ifdef RCC_AHB_PRESCALER_4
	RCC_CFGR |= RCC_CFGR_HPRE_DIV_4_1;
	RCC_CFGR &= ~RCC_CFGR_HPRE_DIV_4_2;
	#endif
	#ifdef RCC_AHB_PRESCALER_8
	RCC_CFGR |= RCC_CFGR_HPRE_DIV_8_1;
	RCC_CFGR &= ~RCC_CFGR_HPRE_DIV_8_2;
	#endif
	#ifdef RCC_AHB_PRESCALER_16
	RCC_CFGR |= RCC_CFGR_HPRE_DIV_16_1;
	RCC_CFGR &= ~RCC_CFGR_HPRE_DIV_16_2;
	#endif
	#ifdef RCC_AHB_PRESCALER_64
	RCC_CFGR |= RCC_CFGR_HPRE_DIV_64_1;
	RCC_CFGR &= ~RCC_CFGR_HPRE_DIV_64_2;
	#endif
	#ifdef RCC_AHB_PRESCALER_128
	RCC_CFGR |= RCC_CFGR_HPRE_DIV_128_1;
	RCC_CFGR &= ~RCC_CFGR_HPRE_DIV_128_2;
	#endif
	#ifdef RCC_AHB_PRESCALER_256
	RCC_CFGR |= RCC_CFGR_HPRE_DIV_256_1;
	RCC_CFGR &= ~RCC_CFGR_HPRE_DIV_256_2;
	#endif
	#ifdef RCC_AHB_PRESCALER_512
	RCC_CFGR |= RCC_CFGR_HPRE_DIV_512;
	#endif
}



void RCC_voidEnableClock(u8 copy_u8BusID, u8 copy_u8PeripheralID) {
	if (copy_u8PeripheralID < 32){ 
		switch (copy_u8BusID){
			case RCC_AHB:
				SET_BIT(RCC_AHBENR, copy_u8PeripheralID);
				break;
			case RCC_APB1:
				SET_BIT(RCC_APB1ENR, copy_u8PeripheralID);
				break;
			case RCC_APB2:
				SET_BIT(RCC_APB2ENR, copy_u8PeripheralID);
				break;
		}
	}
}

void RCC_voidDisableClock(u8 copy_u8BusID, u8 copy_u8PeripheralID){
	if (copy_u8PeripheralID < 32){
		switch (copy_u8BusID){
			case RCC_AHB:
				CLEAR_BIT(RCC_AHBENR, copy_u8PeripheralID);
				break;
			case RCC_APB1:
				CLEAR_BIT(RCC_APB1ENR, copy_u8PeripheralID);
				break;
			case RCC_APB2:
				CLEAR_BIT(RCC_APB2ENR, copy_u8PeripheralID);
				break;
		}
	}
}
