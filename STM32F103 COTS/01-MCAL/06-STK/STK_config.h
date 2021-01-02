/******************************************************************************
* @file STK_config.h
* @brief This files contains the required STK driver user configurations
* @author: Mohammed Abdelalim
* @version: V01
* @date: 1-1-2021
******************************************************************************/
#ifndef _STK_CONFIG_H
#define _STK_CONFIG_H

                                /* Systick clock sources */
                                /* mandatory */
#define STK_CLOCK_AHB               1
#define STK_CLOCK_AHB_OVER_8        2    /* (default) */


                                /* Enable/Disable Interrupt Choices */
                                /* Default: Interrupt is disabled */
#define STK_COUNT_TO_ZERO_INTERRUPT_ENABLE      1
#define STK_COUNT_TO_ZERO_INTERRUPT_DISABLE     0 /* (default) */


                                /* Single/continuous mode */
#define STK_SINGLE_MODE                 1
#define STK_CONTINUOUS_MODE             2

                                /* Configurations of the STK */
#define STK_CLOCK                       STK_CLOCK_AHB_OVER_8

#endif 
