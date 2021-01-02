/********************************************************************************************
* @file STK_program.c
* @brief This file contains the STK driver functions definitions. 
* @author: Mohammed Abdelalim
* @version:
* @date: 1-1-2021
*********************************************************************************************/

#include "../../04-LIB/STD_TYPES.h"
#include "../../04-LIB/BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

#define NULL (void *)0

u8 global_u8STKModeOfInterval;
static void (*STK_Callback) (void) = NULL;

void STK_voidInit (void){

    // Configure the clock source of the systick core peripheral
    #if STK_CLOCK == STK_CLOCK_AHB
    STK -> CTRL |= (1<<2);
    #elif STK_CLOCK == STK_CLOCK_AHB_OVER_8
    STK -> CTRL &= ~(1<<2);
    #else
    #error "Wrong clock source choice!"
    #endif

    // Stop Counter
    STK -> CTRL &= ~(1<<0);

    // CLear the load and val registers
    STK -> LOAD = 0;
    STK -> VAL = 0;
}

void STK_voidSetDelayus (u32 copy_u32NumberOfTicks){

    // Set the copy_u32NumberOfTicks value in the reload register
    STK -> LOAD = copy_u32NumberOfTicks;

    // Start counter
    STK -> CTRL |= (1<<0);

    // Wait until the counter counts to zero
    // and the count flag is asserted
    while (((STK -> CTRL) & (1<<16)) == 0);

    // Stop counter and confirm that the load and val are cleared
    STK -> CTRL &= ~(1<<0);
    STK -> LOAD = 0;
    STK -> VAL =0;
}

void STK_voidSetSingleIntervalus (u32 copy_u32NumberOfTicks, u8 copy_u8InterruptStatus, void (*Copy_pf)(void)){
    // Set the copy_u32NumberOfTicks value in the reload register
    STK -> LOAD = copy_u32NumberOfTicks;

    // Stop Counter until we finish our configurations
    STK -> CTRL &= ~(1<<0);

    // Check the interupt status whether enabled/disabled
    if (copy_u8InterruptStatus == STK_COUNT_TO_ZERO_INTERRUPT_ENABLE){
        // Interrupt enabled
        // Set the systick mode to single mode
        global_u8STKModeOfInterval = STK_SINGLE_MODE;

        // Start counter
        STK -> CTRL |= (1<<0);

        // Set Callback
        STK_Callback = Copy_pf;

        // Enable Interrupt
        STK -> CTRL |= (1<<1);
    }
    else {
        // Interrupt Disabled
        // Start counter
        STK -> CTRL |= (1<<0);

        // Wait until the counter counts to zero
        // and the count flag is asserted
        while (((STK -> CTRL) & (1<<16)) == 0);

        // Stop counter and clear the load and val registers
        STK -> CTRL &= ~(1<<0);
        STK -> LOAD = 0;
        STK -> VAL = 0;
    }
}

void STK_voidSetPeriodicIntervalus (u32 copy_u32NumberOfTicks, u8 copy_u8InterruptStatus, void (*Copy_pf)(void)){
    // Set the copy_u32NumberOfTicks value in the reload register
    STK -> LOAD = copy_u32NumberOfTicks;

    // Stop Counter until we finish our configurations
    STK -> CTRL &= ~(1<<0);

    // Check the interupt status whether enabled/disabled
    if (copy_u8InterruptStatus == STK_COUNT_TO_ZERO_INTERRUPT_ENABLE){
        // Interrupt enabled
        // Set the systick mode to continuous mode
        global_u8STKModeOfInterval = STK_CONTINUOUS_MODE;

        // Start counter
        STK -> CTRL |= (1<<0);

        // Set Callback
        STK_Callback = Copy_pf;

        // Enable Interrupt
        STK -> CTRL |= (1<<1);
    }
    else {
        // Interrupt Disabled
        // Start counter
        STK -> CTRL |= (1<<0);

        // Wait until the counter counts to zero
        // and the count flag is asserted
        while (((STK -> CTRL) & (1<<16)) == 0);
    }
}

void STK_voidStopInterval (void){
    STK -> CTRL &= ~(1<<0);
    STK -> LOAD = 0;
    STK -> VAL = 0;
}

u32 STK_u32GetElapsedTicks (void){
    return (((STK -> LOAD) - (STK -> VAL)));
}

u32 STK_u32GetRemaningTicks (void){
    return ((STK -> VAL));
}

void SysTick_Handler (void){
    if (global_u8STKModeOfInterval == STK_SINGLE_MODE){
        // Stop Interrupt
        STK -> CTRL &= ~(1<<1);
        
        // Stop counter
        STK -> CTRL &= ~(1<<0);
        STK -> LOAD = 0;
        STK -> VAL = 0;
    }
    STK_Callback();
    u8 readFLag = (STK->CTRL) & (1<<16);
}


