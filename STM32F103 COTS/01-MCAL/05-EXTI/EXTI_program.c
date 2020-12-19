/********************************************************************************************
* @file EXTI_program.c
* @brief This file contains the EXTI driver functions definitions. 
* @author: Mohammed Abdelalim
* @version:
* @date: 19-12-2020
*********************************************************************************************/

#include "../../04-LIB/STD_TYPES.h"
#include "../../04-LIB/BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

#define NULL (void *)0

// define array of pointers to functions so that each element corresponds to a single
// input line external interrupt callback pointer to function
static void (*EXTI_Callback[19]) (void) = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                                NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

u8 EXTI_u8EnableInterrupt (u8 copy_u8InputLine, u8 copy_u8SensingEdge){
    u8 errorStatus = 0;
    if (copy_u8InputLine < 19){
        // set the interrupt edge trigger type 
        switch (copy_u8SensingEdge){
            case EXTI_RISING_EDGE_TRIGGER:
            (EXTI -> RTSR) |= (1<<copy_u8InputLine);
            (EXTI -> FTSR) &= ~(1<<copy_u8InputLine);
            break;
            case EXTI_FALLING_EDGE_TRIGGER:
            (EXTI -> RTSR) &= ~(1<<copy_u8InputLine);
            (EXTI -> FTSR) |= (1<<copy_u8InputLine);
            break;
            case EXTI_RISING_AND_FALLING_EDGE_TRIGGER:
            (EXTI -> RTSR) |= (1<<copy_u8InputLine);
            (EXTI -> FTSR) |= (1<<copy_u8InputLine);
            break;
            default:
            break;
        }
        // enable the corresponding interrupt line
        (EXTI -> IMR) |= (1<<copy_u8InputLine);
        errorStatus = 0;
    }
    else {
        errorStatus = 1;
    }
    return errorStatus;
}

u8 EXTI_u8EnableEvent (u8 copy_u8InputLine, u8 copy_u8SensingEdge){
    u8 errorStatus = 0;
    if (copy_u8InputLine < 19){
        // set the event edge trigger type 
        switch (copy_u8SensingEdge){
            case EXTI_RISING_EDGE_TRIGGER:
            (EXTI -> RTSR) |= (1<<copy_u8InputLine);
            (EXTI -> FTSR) &= ~(1<<copy_u8InputLine);
            break;
            case EXTI_FALLING_EDGE_TRIGGER:
            (EXTI -> RTSR) &= ~(1<<copy_u8InputLine);
            (EXTI -> FTSR) |= (1<<copy_u8InputLine);
            break;
            case EXTI_RISING_AND_FALLING_EDGE_TRIGGER:
            (EXTI -> RTSR) |= (1<<copy_u8InputLine);
            (EXTI -> FTSR) |= (1<<copy_u8InputLine);
            break;
            default:
            break;
        }
        // enable the corresponding event line
        (EXTI -> EMR) |= (1<<copy_u8InputLine);
        errorStatus = 0;
    }
    else {
        errorStatus = 1;
    }
    return errorStatus;
}

u8 EXTI_u8DisableInterrupt (u8 copy_u8InputLine){
    u8 errorStatus = 0;
    if (copy_u8InputLine < 19){
        // clear the current interrupt edge triggered type
        (EXTI -> RTSR) &= ~(1<<copy_u8InputLine);
        (EXTI -> FTSR) &= ~(1<<copy_u8InputLine);
        // disable the corresponding interrupt line
        (EXTI -> IMR) &= ~(1<<copy_u8InputLine);
        errorStatus = 0;
    }
    else {
        errorStatus = 1;
    }
    return errorStatus;
}

u8 EXTI_u8DisableEvent (u8 copy_u8InputLine){
    u8 errorStatus = 0;
    if (copy_u8InputLine < 19){
        // clear the current event edge triggered type
        (EXTI -> RTSR) &= ~(1<<copy_u8InputLine);
        (EXTI -> FTSR) &= ~(1<<copy_u8InputLine);
        // disable the corresponding event line
        (EXTI -> EMR) &= ~(1<<copy_u8InputLine);
        errorStatus = 0;
    }
    else {
        errorStatus = 1;
    }
    return errorStatus;
}

u8 EXTI_u8FireSWInterrupt (u8 copy_u8InputLine){
    u8 errorStatus = 0;
    if (copy_u8InputLine < 19){
        // fire the corresponding SW interrupt line
        (EXTI -> SWIER) |= (1<<copy_u8InputLine);
        errorStatus = 0;
    }
    else {
        errorStatus = 1;
    }
    return errorStatus;
}

u8 EXTI_u8GetInterruptStatus (u8 copy_u8InputLine){
    u8 interruptStatus = 0;
    if (copy_u8InputLine < 19){
        // read the corresponding interrupt pending register bit 
       interruptStatus = ((EXTI -> PR) & (1<<copy_u8InputLine)) >> copy_u8InputLine;
    }
    else {
        // do nothing
    }
    return interruptStatus;
}

void EXTI_voidEXTI0SetCallback (void *pf (void)){
    EXTI_Callback[0] = pf;
}
void EXTI_voidEXTI1SetCallback (void *pf (void)){
    EXTI_Callback[1] = pf;
}
void EXTI_voidEXTI2SetCallback (void *pf (void)){
    EXTI_Callback[2] = pf;
}
void EXTI_voidEXTI3SetCallback (void *pf (void)){
    EXTI_Callback[3] = pf;
}
void EXTI_voidEXTI4SetCallback (void *pf (void)){
    EXTI_Callback[4] = pf;
}
void EXTI_voidEXTI5SetCallback (void *pf (void)){
    EXTI_Callback[5] = pf;
}
void EXTI_voidEXTI6SetCallback (void *pf (void)){
    EXTI_Callback[6] = pf;
}
void EXTI_voidEXTI7SetCallback (void *pf (void)){
    EXTI_Callback[7] = pf;
}
void EXTI_voidEXTI8SetCallback (void *pf (void)){
    EXTI_Callback[8] = pf;
}
void EXTI_voidEXTI9SetCallback (void *pf (void)){
    EXTI_Callback[9] = pf;
}
void EXTI_voidEXTI10SetCallback (void *pf (void)){
    EXTI_Callback[10] = pf;
}
void EXTI_voidEXTI11SetCallback (void *pf (void)){
    EXTI_Callback[11] = pf;
}
void EXTI_voidEXTI12SetCallback (void *pf (void)){
    EXTI_Callback[12] = pf;
}
void EXTI_voidEXTI13SetCallback (void *pf (void)){
    EXTI_Callback[13] = pf;
}
void EXTI_voidEXTI14SetCallback (void *pf (void)){
    EXTI_Callback[14] = pf;
}
void EXTI_voidEXTI15SetCallback (void *pf (void)){
    EXTI_Callback[15] = pf;
}
void EXTI_voidEXTI16SetCallback (void *pf (void)){
    EXTI_Callback[16] = pf;
}
void EXTI_voidEXTI17SetCallback (void *pf (void)){
    EXTI_Callback[17] = pf;
}
void EXTI_voidEXTI18SetCallback (void *pf (void)){
    EXTI_Callback[18] = pf;
}

void EXTI0_IRQHandler(void)
{
    // call the user ISR
	EXTI_Callback[0]();
    // clear the pending interrupt flag
	(EXTI -> PR) |= (1<<EXTI_EXTI0);
}

void EXTI1_IRQHandler(void)
{
    // call the user ISR
	EXTI_Callback[1]();
    // clear the pending interrupt flag
	(EXTI -> PR) |= (1<<EXTI_EXTI1);
}

void EXTI2_IRQHandler(void)
{
    // call the user ISR
	EXTI_Callback[2]();
    // clear the pending interrupt flag
	(EXTI -> PR) |= (1<<EXTI_EXTI2);
}

void EXTI3_IRQHandler(void)
{
    // call the user ISR
	EXTI_Callback[3]();
    // clear the pending interrupt flag
	(EXTI -> PR) |= (1<<EXTI_EXTI3);
}

void EXTI4_IRQHandler(void)
{
    // call the user ISR
	EXTI_Callback[4]();
    // clear the pending interrupt flag
	(EXTI -> PR) |= (1<<EXTI_EXTI4);
}

void EXTI5_IRQHandler(void)
{
    // call the user ISR
	EXTI_Callback[5]();
    // clear the pending interrupt flag
	(EXTI -> PR) |= (1<<EXTI_EXTI5);
}

void EXTI6_IRQHandler(void)
{
    // call the user ISR
	EXTI_Callback[6]();
    // clear the pending interrupt flag
	(EXTI -> PR) |= (1<<EXTI_EXTI6);
}

void EXTI7_IRQHandler(void)
{
    // call the user ISR
	EXTI_Callback[7]();
    // clear the pending interrupt flag
	(EXTI -> PR) |= (1<<EXTI_EXTI7);
}

void EXTI8_IRQHandler(void)
{
    // call the user ISR
	EXTI_Callback[8]();
    // clear the pending interrupt flag
	(EXTI -> PR) |= (1<<EXTI_EXTI8);
}

void EXTI9_IRQHandler(void)
{
    // call the user ISR
	EXTI_Callback[9]();
    // clear the pending interrupt flag
	(EXTI -> PR) |= (1<<EXTI_EXTI9);
}

void EXTI10_IRQHandler(void)
{
    // call the user ISR
	EXTI_Callback[10]();
    // clear the pending interrupt flag
	(EXTI -> PR) |= (1<<EXTI_EXTI10);
}

void EXTI11_IRQHandler(void)
{
    // call the user ISR
	EXTI_Callback[11]();
    // clear the pending interrupt flag
	(EXTI -> PR) |= (1<<EXTI_EXTI11);
}

void EXTI12_IRQHandler(void)
{
    // call the user ISR
	EXTI_Callback[12]();
    // clear the pending interrupt flag
	(EXTI -> PR) |= (1<<EXTI_EXTI12);
}

void EXTI13_IRQHandler(void)
{
    // call the user ISR
	EXTI_Callback[13]();
    // clear the pending interrupt flag
	(EXTI -> PR) |= (1<<EXTI_EXTI13);
}

void EXTI14_IRQHandler(void)
{
    // call the user ISR
	EXTI_Callback[14]();
    // clear the pending interrupt flag
	(EXTI -> PR) |= (1<<EXTI_EXTI14);
}

void EXTI15_IRQHandler(void)
{
    // call the user ISR
	EXTI_Callback[15]();
    // clear the pending interrupt flag
	(EXTI -> PR) |= (1<<EXTI_EXTI15);
}

void EXTI16_IRQHandler(void)
{
    // call the user ISR
	EXTI_Callback[16]();
    // clear the pending interrupt flag
	(EXTI -> PR) |= (1<<EXTI_EXTI16);
}

void EXTI17_IRQHandler(void)
{
    // call the user ISR
	EXTI_Callback[17]();
    // clear the pending interrupt flag
	(EXTI -> PR) |= (1<<EXTI_EXTI17);
}

void EXTI18_IRQHandler(void)
{
    // call the user ISR
	EXTI_Callback[18]();
    // clear the pending interrupt flag
	(EXTI -> PR) |= (1<<EXTI_EXTI18);
}