/********************************************************************************************
* @file AFIO_program.c
* @brief This files contains the GPIO driver functions definitions.
* @author: Mohammed Abdelalim
* @version:
* @date: 18-12-2020
*********************************************************************************************/

#include "../../04-LIB/STD_TYPES.h"
#include "../../04-LIB/BIT_MATH.h"

#include "../01-RCC/RCC_interface.h"
#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"


void AFIO_voidInit(void){
    RCC_voidEnableClock(RCC_APB2, 0);
}

u8 AFIO_u8SetInputLine(u8 copy_u8InputLineNumber, u8 copy_u8PortNumber){
    u8 errorStatus = 0;

    if ((copy_u8InputLineNumber >= AFIO_EXTI0) && (copy_u8InputLineNumber < AFIO_EXTI4)){
        // clear the required bits in the required area in the register
        (AFIO->EXTICR1) &= ~((0xF) << (4*(copy_u8InputLineNumber % 4)));
        // write the required bits in the required area
        (AFIO->EXTICR1) |= ((copy_u8PortNumber) << (4*(copy_u8InputLineNumber % 4)));
        errorStatus = 0;
    }
    else if ((copy_u8InputLineNumber > AFIO_EXTI3) && (copy_u8InputLineNumber < AFIO_EXTI8)){
         // clear the required bits in the required area in the register
        (AFIO->EXTICR2) &= ~((0xF) << (4*(copy_u8InputLineNumber % 4)));
        // write the required bits in the required area
        (AFIO->EXTICR2) |= ((copy_u8PortNumber) << (4*(copy_u8InputLineNumber % 4)));
        errorStatus = 0;
    }
    else if ((copy_u8InputLineNumber > AFIO_EXTI7) && (copy_u8InputLineNumber < AFIO_EXTI12)){
         // clear the required bits in the required area in the register
        (AFIO->EXTICR3) &= ~((0xF) << (4*(copy_u8InputLineNumber % 4)));
        // write the required bits in the required area
        (AFIO->EXTICR3) |= ((copy_u8PortNumber) << (4*(copy_u8InputLineNumber % 4)));
        errorStatus = 0;
    }
    else if ((copy_u8InputLineNumber > AFIO_EXTI11) && (copy_u8InputLineNumber < AFIO_EXTI6)){
         // clear the required bits in the required area in the register
        (AFIO->EXTICR4) &= ~((0xF) << (4*(copy_u8InputLineNumber % 4)));
        // write the required bits in the required area
        (AFIO->EXTICR4) |= ((copy_u8PortNumber) << (4*(copy_u8InputLineNumber % 4)));
        errorStatus = 0;
    }
    else{
        errorStatus = 1;
    }
    return errorStatus;
}