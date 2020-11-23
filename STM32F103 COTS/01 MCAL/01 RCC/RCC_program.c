/********************************************************************************************
* @file RCC_program.c
* @brief This files contains the RCC driver functions definitions. 
* @author: Mohammed Abdelalim
* @version:
* @date: 10-11-2020
*********************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

// e3ml include b eltarteeb da (brattebhom 3ala 7sb el dependancy bta3t-hom)
#include "RCC_interface.h" // lazm yb2a awl include 3shan el functions declarations bykoon feeha el macros elly f el 2 files elgayeen
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInit(void){

	// enable and select the required clock source to be the system clock
	#if RCC_CLOCKTYPE == RCC_HSE
	// enable clock source
	RCC_CR |= (1<<16);
	// wait for the HSE ready flag to be set
	while ((RCC_CR & (1<<17)) == 0);
	// select HSE as the system clock
	RCC_CFGR |= (1<<0);
	RCC_CFGR &= ~(1<<1);
	//wait for the SWS flag to be set
	while ((RCC_CFGR & (1<<0)) != 1);

	#elif RCC_CLOCKTYPE == RCC_HSI
	RCC_CR |= (1<<0);
	while ((RCC_CR & (1<<1)) == 0);
	RCC_CFGR &= ~0x00000003;
	while ((RCC_CFGR & 0x00000003) != 0);

	#elif RCC_CLOCKTYPE == RCC_PLL
	// configure the PLL input clock source
	#ifdef RCC_PLL_HSI_HALVED
	RCC_CFGR &= ~(1<<16);
	#endif
	#ifdef RCC_PLL_HSE
	RCC_CFGR |= (1<<16);
	RCC_CFGR &= ~(1<<17);
	#endif
	#ifdef RCC_PLL_HSE_HALVED
	RCC_CFGR |= (1<<16);
	RCC_CFGR |= (1<<17);
	#endif
	// configure the PLL multiplication factor
	// either x(2,3,4,5,6,7,8,9,10,11,12,13,14,15,16)
	#ifdef RCC_PLL_MUL_2
	RCC_CFGR &= ~0x003C0000;
	#endif
	#ifdef RCC_PLL_MUL_3
	RCC_CFGR |= 0x00020000;
	RCC_CFGR &= ~0x00380000;
	#endif
	#ifdef RCC_PLL_MUL_4
	RCC_CFGR |= 0x00080000;
	RCC_CFGR &= ~0x00340000;
	#endif
	#ifdef RCC_PLL_MUL_5
	RCC_CFGR |= 0x000C0000;
	RCC_CFGR &= ~0x00300000;
	#endif
	#ifdef RCC_PLL_MUL_6
	RCC_CFGR |= 0x00100000;
	RCC_CFGR &= ~0x002C0000;
	#endif
	#ifdef RCC_PLL_MUL_7
	RCC_CFGR |= 0x00140000;
	RCC_CFGR &= ~0x00280000;
	#endif
	#ifdef RCC_PLL_MUL_8
	RCC_CFGR |= 0x00180000;
	RCC_CFGR &= ~0x00240000;
	#endif
	#ifdef RCC_PLL_MUL_9
	RCC_CFGR |= 0x001C0000;
	RCC_CFGR &= ~0x00200000;
	#endif
	#ifdef RCC_PLL_MUL_10
	RCC_CFGR |= 0x00200000;
	RCC_CFGR &= ~0x001C0000;
	#endif
	#ifdef RCC_PLL_MUL_11
	RCC_CFGR |= 0x00240000;
	RCC_CFGR &= ~0x00180000;
	#endif
	#ifdef RCC_PLL_MUL_12
	RCC_CFGR |= 0x00280000;
	RCC_CFGR &= ~0x00140000;
	#endif
	#ifdef RCC_PLL_MUL_13
	RCC_CFGR |= 0x002C0000;
	RCC_CFGR &= ~0x00100000;
	#endif
	#ifdef RCC_PLL_MUL_14
	RCC_CFGR |= 0x00300000;
	RCC_CFGR &= ~0x000C0000;
	#endif
	#ifdef RCC_PLL_MUL_15
	RCC_CFGR |= 0x00340000;
	RCC_CFGR &= ~0x00080000;
	#endif
	#ifdef RCC_PLL_MUL_16
	RCC_CFGR |= 0x003C0000;
	#endif
	// Enable the PLL clock source
	RCC_CR |= (1<<24);
	while ((RCC_CR & (1<<25)) == 0);
	// select PLL as the system clock
	RCC_CFGR |= (1<<1);
	RCC_CFGR &= ~(1<<0);
	while ((RCC_CFGR & 0x00000002) != 2);
	#else
		#error ("Wrong clock source choice!")
	#endif

	// enable the clock security system (it's disabled by default)
	#ifdef RCC_CSS
	RCC_CR |= (1<<19);
	#endif

	// set the prescaler of AHB, APB1, and APB2 bus whether the system clock is not divided
	// or divided by 2 or 4 or 8 or 16
	#ifdef RCC_APB2_NO_PRESCALER
	RCC_CFGR &= ~0x00002000;
	#endif
	#ifdef RCC_APB2_PRESCALER_2
	RCC_CFGR |= 0x00002000;
	RCC_CFGR &= ~0x00001800;
	#endif
	#ifdef RCC_APB2_PRESCALER_4
	RCC_CFGR |= 0x00002800;
	RCC_CFGR &= ~0x00001000;
	#endif
	#ifdef RCC_APB2_PRESCALER_8
	RCC_CFGR |= 0x00003000;
	RCC_CFGR &= ~0x00000800;
	#endif
	#ifdef RCC_APB2_PRESCALER_16
	RCC_CFGR |= 0x00003800;
	#endif

	#ifdef RCC_APB1_NO_PRESCALER
	RCC_CFGR &= ~0x00004000;
	#endif
	#ifdef RCC_APB1_PRESCALER_2
	RCC_CFGR |= 0x00004000;
	RCC_CFGR &= ~0x00003000;
	#endif
	#ifdef RCC_APB1_PRESCALER_4
	RCC_CFGR |= 0x00005000;
	RCC_CFGR &= ~0x00002000;
	#endif
	#ifdef RCC_APB1_PRESCALER_8
	RCC_CFGR |= 0x00006000;
	RCC_CFGR &= ~0x00001000;
	#endif
	#ifdef RCC_APB1_PRESCALER_16
	RCC_CFGR |= 0x00007000;
	#endif

	#ifdef RCC_AHB_NO_PRESCALER
	RCC_CFGR &= ~0x00000080;
	#endif
	#ifdef RCC_AHB_PRESCALER_2
	RCC_CFGR |= 0x00000080;
	RCC_CFGR &= ~0x00000070;
	#endif
	#ifdef RCC_AHB_PRESCALER_4
	RCC_CFGR |= 0x00000090;
	RCC_CFGR &= ~0x00000060;
	#endif
	#ifdef RCC_AHB_PRESCALER_8
	RCC_CFGR |= 0x000000A0;
	RCC_CFGR &= ~0x00000050;
	#endif
	#ifdef RCC_AHB_PRESCALER_16
	RCC_CFGR |= 0x000000B0;
	RCC_CFGR &= ~0x00000040;
	#endif
	#ifdef RCC_AHB_PRESCALER_64
	RCC_CFGR |= 0x000000C0;
	RCC_CFGR &= ~0x00000030;
	#endif
	#ifdef RCC_AHB_PRESCALER_128
	RCC_CFGR |= 0x000000D0;
	RCC_CFGR &= ~0x00000020;
	#endif
	#ifdef RCC_AHB_PRESCALER_256
	RCC_CFGR |= 0x000000E0;
	RCC_CFGR &= ~0x00000010;
	#endif
	#ifdef RCC_AHB_PRESCALER_512
	RCC_CFGR |= 0x000000F0;
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
