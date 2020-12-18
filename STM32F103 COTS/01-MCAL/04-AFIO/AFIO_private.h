/******************************************************************************
* @file AFIO_private.h
* @brief This files contains the registers addresses as well as static functions declratations (if exist) for the AFIO peripheral
* @author: Mohammed Abdelalim
* @version: V01
* @date: 18-12-2020
******************************************************************************/

#ifndef _AFIO_PRIVATE_H
#define _AFIO_PRIVATE_H

typedef struct {
    volatile u32 EVCR;
    volatile u32 MAPR;
    volatile u32 EXTICR1;
    volatile u32 EXTICR2;
    volatile u32 EXTICR3;
    volatile u32 EXTICR4;
} AFIO_type;

#define AFIO_MAPR2                              *((volatile u32 *) 40010000 + 0x1C)

#define AFIO                ((volatile AFIO_type *)0x40010000)

#endif 
