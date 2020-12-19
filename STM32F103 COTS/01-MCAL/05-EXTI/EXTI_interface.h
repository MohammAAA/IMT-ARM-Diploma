/******************************************************************************
* @file EXTI_interface.h
* @brief This files contains the EXTI driver functions declratations as well as
* the used macros...
* @author: Mohammed Abdelalim
* @version: V01
* @date: 19-12-2020
******************************************************************************/

#ifndef _EXTI_INTERFACE_H
#define _EXTI_INTERFACE_H

u8 EXTI_u8EnableInterrupt (u8 copy_u8InputLine, u8 copy_u8SensingEdge);
u8 EXTI_u8EnableEvent (u8 copy_u8InputLine, u8 copy_u8SensingEdge);
u8 EXTI_u8DisableInterrupt (u8 copy_u8InputLine);
u8 EXTI_u8DisableEvent (u8 copy_u8InputLine);
u8 EXTI_u8FireSWInterrupt (u8 copy_u8InputLine);
u8 EXTI_u8GetInterruptStatus (u8 copy_u8InputLine);

void EXTI_voidEXTI0SetCallback (void *pf (void));
void EXTI_voidEXTI1SetCallback (void *pf (void));
void EXTI_voidEXTI2SetCallback (void *pf (void));
void EXTI_voidEXTI3SetCallback (void *pf (void));
void EXTI_voidEXTI4SetCallback (void *pf (void));
void EXTI_voidEXTI5SetCallback (void *pf (void));
void EXTI_voidEXTI6SetCallback (void *pf (void));
void EXTI_voidEXTI7SetCallback (void *pf (void));
void EXTI_voidEXTI8SetCallback (void *pf (void));
void EXTI_voidEXTI9SetCallback (void *pf (void));
void EXTI_voidEXTI10SetCallback (void *pf (void));
void EXTI_voidEXTI11SetCallback (void *pf (void));
void EXTI_voidEXTI12SetCallback (void *pf (void));
void EXTI_voidEXTI13SetCallback (void *pf (void));
void EXTI_voidEXTI14SetCallback (void *pf (void));
void EXTI_voidEXTI15SetCallback (void *pf (void));
void EXTI_voidEXTI16SetCallback (void *pf (void));
void EXTI_voidEXTI17SetCallback (void *pf (void));
void EXTI_voidEXTI18SetCallback (void *pf (void));




#endif 
