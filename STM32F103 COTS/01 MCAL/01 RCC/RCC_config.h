/********************************************************************************************
* @Author: Mohammed Abdelalim
* @Version:
* @Date: 10-11-2020
*********************************************************************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* @options : 	RCC_HSI
*		RCC_HSE
*		RCC_PLL >>>> ha7otohom f el private.h */

//#define RCC_CLOCKTYPE		RCC_HSI
//#define RCC_CLOCKTYPE		RCC_HSE
#define RCC_CLOCKTYPE		RCC_PLL

/* Note: Select one of these values only if you select the PLL clock type */
/* @options : 	RCC_PLL_HSE_DIV_2
*		RCC_PLL_HSE
*		RCC_PLL_HSI_DIV_2 */
#if RCC_CLOCKTYPE == RCC_PLL //for protection from el user el3'aby
#define RCC_PLL_INPUT 	RCC_PLL_HSE
#endif


/* Note: Select one of these values only if you select the PLL clock type */
/* @options : 	may be 2,3,4,5,6,7,...,16 */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VAL		4
#endif




	

#endif 
