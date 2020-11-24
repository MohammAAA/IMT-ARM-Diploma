/******************************************************************************
* @file RCC_config.h
* @brief This files contains the required RCC driver user configurations
* @author: Mohammed Abdelalim
* @version: V01
* @date: 10-11-2020
******************************************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

																/* For HSI configurations */
// #define RCC_CLOCKTYPE		RCC_HSI

																/* For HSE configurations */
#define RCC_CLOCKTYPE		RCC_HSE

																/* For PLL configurations */
//#define RCC_CLOCKTYPE		RCC_PLL
/* Note: Select one of these macros only after you select the PLL clock type */
#if RCC_CLOCKTYPE == RCC_PLL //for protection from el user el3'aby
// #define RCC_PLL_HSE_DIV_2
// #define RCC_PLL_HSE
// #define RCC_PLL_HSI_DIV_2
#endif

/* Note: Select one of these macros only after you select the PLL clock type */
/* @options : 	may be 2,3,4,5,6,7,...,16 */
#if RCC_CLOCK_TYPE == RCC_PLL
// #define RCC_PLL_MUL_2
// #define RCC_PLL_MUL_3
// #define RCC_PLL_MUL_4
// #define RCC_PLL_MUL_5
// #define RCC_PLL_MUL_6
// #define RCC_PLL_MUL_7
// #define RCC_PLL_MUL_8
// #define RCC_PLL_MUL_9
// #define RCC_PLL_MUL_10
// #define RCC_PLL_MUL_11
// #define RCC_PLL_MUL_12
// #define RCC_PLL_MUL_13
// #define RCC_PLL_MUL_14
// #define RCC_PLL_MUL_15
// #define RCC_PLL_MUL_16
#endif

																/* For clock security system enable */
																/* optional */
// #define RCC_CSS

																/* APB2 prescaling configurations */
																/* mandatory */
#define RCC_APB2_NO_PRESCALER
// #define RCC_APB2_PRESCALER_2
// #define RCC_APB2_PRESCALER_4
// #define RCC_APB2_PRESCALER_8
// #define RCC_APB2_PRESCALER_16

																/* APB1 prescaling configurations */
																/* mandatory */
#define RCC_APB1_NO_PRESCALER
// #define RCC_APB1_PRESCALER_2
// #define RCC_APB1_PRESCALER_4
// #define RCC_APB1_PRESCALER_8
// #define RCC_APB1_PRESCALER_16

																/* AHB prescaling configurations */
																/* mandatory */
#define RCC_AHB_NO_PRESCALER
// #define RCC_AHB_PRESCALER_2
// #define RCC_AHB_PRESCALER_4
// #define RCC_AHB_PRESCALER_8
// #define RCC_AHB_PRESCALER_16
// #define RCC_AHB_PRESCALER_64
// #define RCC_AHB_PRESCALER_128
// #define RCC_AHB_PRESCALER_256
// #define RCC_AHB_PRESCALER_512

	

#endif 
