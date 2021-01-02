/******************************************************************************
* @file STK_private.h
* @brief This files contains the registers addresses as well as static functions
* declratations (if exist) for the Systick (STK) peripheral
* @author: Mohammed Abdelalim
* @version: V01
* @date: 1-1-2021
******************************************************************************/

#ifndef _STK_PRIVATE_H
#define _STK_PRIVATE_H

typedef struct {
    volatile u32 CTRL;
    volatile u32 LOAD;
    volatile u32 VAL;
    volatile u32 CALIB;
} STK_type;

#define STK                             ((volatile STK_type *) 0xE000E010)
#endif
