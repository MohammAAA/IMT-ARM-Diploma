/******************************************************************************
* @file EXTI_private.h
* @brief This files contains the registers addresses as well as static functions
* declratations (if exist) for the External interrupt (EXTI)
* peripheral
* @author: Mohammed Abdelalim
* @version: V01
* @date: 19-12-2020
******************************************************************************/

#ifndef _EXTI_PRIVATE_H
#define _EXTI_PRIVATE_H

typedef struct
{
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;
} EXTI_type;

#define EXTI                                ((volatile EXTI_type *)0x40010400)


#endif
