/******************************************************************************
* @file NVIC_config.h
* @brief This files contains the required NVIC driver user configurations
* @author: Mohammed Abdelalim
* @version: V01
* @date: 15-12-2020
******************************************************************************/
#ifndef _NVIC_CONFIG_H
#define _NVIC_CONFIG_H

																/* For group priorities */
#define NVIC_PRIORITY_GROUPS						NVIC_SIXTEEN_PRIORITY_GROUPS
//#define NVIC_PRIORITY_GROUPS						NVIC_EIGHT_PRIORITY_GROUPS
//#define NVIC_PRIORITY_GROUPS						NVIC_FOUR_PRIORITY_GROUPS
//#define NVIC_PRIORITY_GROUPS						NVIC_TWO_PRIORITY_GROUPS
//#define NVIC_PRIORITY_GROUPS						NVIC_NO_PRIORITY_GROUPS

#define NVIC_SIXTEEN_PRIORITY_GROUPS				
#define NVIC_EIGHT_PRIORITY_GROUPS					
#define NVIC_FOUR_PRIORITY_GROUPS					
#define NVIC_TWO_PRIORITY_GROUPS					
#define NVIC_NO_PRIORITY_GROUPS		



#define NVIC_DISABLE_ALL_INTERRUPTS				0xFFFFFFFF;

#endif 
