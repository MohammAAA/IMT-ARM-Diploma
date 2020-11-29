/********************************************************************************************
* @file GPIO_program.c
* @brief This files contains the GPIO driver functions definitions. Note: pinA13, pinA14,
* pinB2, pinB3, pinB4 are not dedicated for GPIO, so they are not working here
* pinC13, pinC14, pinC15 are sink current pins 
* @author: Mohammed Abdelalim
* @version:
* @date: 24-11-2020
*********************************************************************************************/

#include "../../04-Lib/STD_TYPES.h"
#include "../../04-Lib/BIT_MATH.h"

#include "../01-RCC/RCC_interface.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void GPIO_voidEnablePort(u8 copy_portNumber){
    RCC_voidEnableClock(RCC_APB2, copy_portNumber);
}

void GPIO_voidSetPinDirection (u8 copy_portNumber, u8 copy_pinNumber, u8 copy_modeAndConfig){
    switch (copy_portNumber){
        case GPIO_PORTA_PERIPHERAL_ID:
        switch (copy_modeAndConfig){
            case GPIO_INPUT_ANALOG_MODE:
            if (copy_pinNumber < 8){
                GPIO_PORTA_CRL &= ~((0xF)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                GPIO_PORTA_CRH &= ~((0xF)<<(4*copy_pinNumber));
            }
            break;
            case GPIO_INPUT_FLOATING_MODE:
            if (copy_pinNumber < 8){
                // clear the targetted bits
                GPIO_PORTA_CRL &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTA_CRL |= ((GPIO_INPUT_FLOATING_MODE)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                // clear the targetted bits
                GPIO_PORTA_CRH &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTA_CRH |= ((GPIO_INPUT_FLOATING_MODE)<<(4*copy_pinNumber));            }
            break;
            case GPIO_INPUT_PULL_UPDOWN_MODE:
            if (copy_pinNumber < 8){
                // clear the targetted bits
                GPIO_PORTA_CRL &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTA_CRL |= ((GPIO_INPUT_PULL_UPDOWN_MODE)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                // clear the targetted bits
                GPIO_PORTA_CRH &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTA_CRH |= ((GPIO_INPUT_PULL_UPDOWN_MODE)<<(4*copy_pinNumber));            }
            break;
            case GPIO_OUTPUT_2MHZ_PUSH_PULL_MODE:
            if (copy_pinNumber < 8){
                // clear the targetted bits
                GPIO_PORTA_CRL &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTA_CRL |= ((GPIO_OUTPUT_2MHZ_PUSH_PULL_MODE)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                // clear the targetted bits
                GPIO_PORTA_CRH &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTA_CRH |= ((GPIO_OUTPUT_2MHZ_PUSH_PULL_MODE)<<(4*copy_pinNumber));            }
            break;
            case GPIO_OUTPUT_2MHZ_OPEN_DRAIN_MODE:
            if (copy_pinNumber < 8){
                // clear the targetted bits
                GPIO_PORTA_CRL &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTA_CRL |= ((GPIO_OUTPUT_2MHZ_OPEN_DRAIN_MODE)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                // clear the targetted bits
                GPIO_PORTA_CRH &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTA_CRH |= ((GPIO_OUTPUT_2MHZ_OPEN_DRAIN_MODE)<<(4*copy_pinNumber));            }
            break;
            case GPIO_OUTPUT_10MHZ_PUSH_PULL_MODE:
            if (copy_pinNumber < 8){
                // clear the targetted bits
                GPIO_PORTA_CRL &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTA_CRL |= ((GPIO_OUTPUT_10MHZ_PUSH_PULL_MODE)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                // clear the targetted bits
                GPIO_PORTA_CRH &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTA_CRH |= ((GPIO_OUTPUT_10MHZ_PUSH_PULL_MODE)<<(4*copy_pinNumber));            }
            break;
            case GPIO_OUTPUT_10MHZ_OPEN_DRAIN_MODE:
            if (copy_pinNumber < 8){
                // clear the targetted bits
                GPIO_PORTA_CRL &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTA_CRL |= ((GPIO_OUTPUT_10MHZ_OPEN_DRAIN_MODE)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                // clear the targetted bits
                GPIO_PORTA_CRH &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTA_CRH |= ((GPIO_OUTPUT_10MHZ_OPEN_DRAIN_MODE)<<(4*copy_pinNumber));            }
            break;
            case GPIO_OUTPUT_50MHZ_PUSH_PULL_MODE:
            if (copy_pinNumber < 8){
                // clear the targetted bits
                GPIO_PORTA_CRL &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTA_CRL |= ((GPIO_OUTPUT_50MHZ_PUSH_PULL_MODE)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                // clear the targetted bits
                GPIO_PORTA_CRH &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTA_CRH |= ((GPIO_OUTPUT_50MHZ_PUSH_PULL_MODE)<<(4*copy_pinNumber));            }
            break;
            case GPIO_OUTPUT_50MHZ_OPEN_DRAIN_MODE:
            if (copy_pinNumber < 8){
                // clear the targetted bits
                GPIO_PORTA_CRL &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTA_CRL |= ((GPIO_OUTPUT_50MHZ_OPEN_DRAIN_MODE)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                // clear the targetted bits
                GPIO_PORTA_CRH &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTA_CRH |= ((GPIO_OUTPUT_50MHZ_OPEN_DRAIN_MODE)<<(4*copy_pinNumber));            }
            break;
        }
        break;
        case GPIO_PORTB_PERIPHERAL_ID:
        switch (copy_modeAndConfig){
            case GPIO_INPUT_ANALOG_MODE:
            if (copy_pinNumber < 8){
                GPIO_PORTB_CRL &= ~((0xF)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                GPIO_PORTB_CRH &= ~((0xF)<<(4*copy_pinNumber));
            }
            break;
            case GPIO_INPUT_FLOATING_MODE:
            if (copy_pinNumber < 8){
                // clear the targetted bits
                GPIO_PORTB_CRL &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTB_CRL |= ((GPIO_INPUT_FLOATING_MODE)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                // clear the targetted bits
                GPIO_PORTB_CRH &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTB_CRH |= ((GPIO_INPUT_FLOATING_MODE)<<(4*copy_pinNumber));            }
            break;
            case GPIO_INPUT_PULL_UPDOWN_MODE:
            if (copy_pinNumber < 8){
                // clear the targetted bits
                GPIO_PORTB_CRL &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTB_CRL |= ((GPIO_INPUT_PULL_UPDOWN_MODE)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                // clear the targetted bits
                GPIO_PORTB_CRH &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTB_CRH |= ((GPIO_INPUT_PULL_UPDOWN_MODE)<<(4*copy_pinNumber));            }
            break;
            case GPIO_OUTPUT_2MHZ_PUSH_PULL_MODE:
            if (copy_pinNumber < 8){
                // clear the targetted bits
                GPIO_PORTB_CRL &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTB_CRL |= ((GPIO_OUTPUT_2MHZ_PUSH_PULL_MODE)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                // clear the targetted bits
                GPIO_PORTB_CRH &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTB_CRH |= ((GPIO_OUTPUT_2MHZ_PUSH_PULL_MODE)<<(4*copy_pinNumber));            }
            break;
            case GPIO_OUTPUT_2MHZ_OPEN_DRAIN_MODE:
            if (copy_pinNumber < 8){
                // clear the targetted bits
                GPIO_PORTB_CRL &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTB_CRL |= ((GPIO_OUTPUT_2MHZ_OPEN_DRAIN_MODE)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                // clear the targetted bits
                GPIO_PORTB_CRH &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTB_CRH |= ((GPIO_OUTPUT_2MHZ_OPEN_DRAIN_MODE)<<(4*copy_pinNumber));            }
            break;
            case GPIO_OUTPUT_10MHZ_PUSH_PULL_MODE:
            if (copy_pinNumber < 8){
                // clear the targetted bits
                GPIO_PORTB_CRL &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTB_CRL |= ((GPIO_OUTPUT_10MHZ_PUSH_PULL_MODE)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                // clear the targetted bits
                GPIO_PORTB_CRH &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTB_CRH |= ((GPIO_OUTPUT_10MHZ_PUSH_PULL_MODE)<<(4*copy_pinNumber));            }
            break;
            case GPIO_OUTPUT_10MHZ_OPEN_DRAIN_MODE:
            if (copy_pinNumber < 8){
                // clear the targetted bits
                GPIO_PORTB_CRL &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTB_CRL |= ((GPIO_OUTPUT_10MHZ_OPEN_DRAIN_MODE)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                // clear the targetted bits
                GPIO_PORTB_CRH &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTB_CRH |= ((GPIO_OUTPUT_10MHZ_OPEN_DRAIN_MODE)<<(4*copy_pinNumber));            }
            break;
            case GPIO_OUTPUT_50MHZ_PUSH_PULL_MODE:
            if (copy_pinNumber < 8){
                // clear the targetted bits
                GPIO_PORTB_CRL &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTB_CRL |= ((GPIO_OUTPUT_50MHZ_PUSH_PULL_MODE)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                // clear the targetted bits
                GPIO_PORTB_CRH &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTB_CRH |= ((GPIO_OUTPUT_50MHZ_PUSH_PULL_MODE)<<(4*copy_pinNumber));            }
            break;
            case GPIO_OUTPUT_50MHZ_OPEN_DRAIN_MODE:
            if (copy_pinNumber < 8){
                // clear the targetted bits
                GPIO_PORTB_CRL &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTB_CRL |= ((GPIO_OUTPUT_50MHZ_OPEN_DRAIN_MODE)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                // clear the targetted bits
                GPIO_PORTB_CRH &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTB_CRH |= ((GPIO_OUTPUT_50MHZ_OPEN_DRAIN_MODE)<<(4*copy_pinNumber));            }
            break;
        }
        break;
        case GPIO_PORTC_PERIPHERAL_ID:
        switch (copy_modeAndConfig){
            case GPIO_INPUT_ANALOG_MODE:
            if (copy_pinNumber < 8){
                GPIO_PORTC_CRL &= ~((0xF)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                GPIO_PORTC_CRH &= ~((0xF)<<(4*copy_pinNumber));
            }
            break;
            case GPIO_INPUT_FLOATING_MODE:
            if (copy_pinNumber < 8){
                // clear the targetted bits
                GPIO_PORTC_CRL &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTC_CRL |= ((GPIO_INPUT_FLOATING_MODE)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                // clear the targetted bits
                GPIO_PORTC_CRH &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTC_CRH |= ((GPIO_INPUT_FLOATING_MODE)<<(4*copy_pinNumber));            }
            break;
            case GPIO_INPUT_PULL_UPDOWN_MODE:
            if (copy_pinNumber < 8){
                // clear the targetted bits
                GPIO_PORTC_CRL &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTC_CRL |= ((GPIO_INPUT_PULL_UPDOWN_MODE)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                // clear the targetted bits
                GPIO_PORTC_CRH &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTC_CRH |= ((GPIO_INPUT_PULL_UPDOWN_MODE)<<(4*copy_pinNumber));            }
            break;
            case GPIO_OUTPUT_2MHZ_PUSH_PULL_MODE:
            if (copy_pinNumber < 8){
                // clear the targetted bits
                GPIO_PORTC_CRL &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTC_CRL |= ((GPIO_OUTPUT_2MHZ_PUSH_PULL_MODE)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                // clear the targetted bits
                GPIO_PORTC_CRH &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTC_CRH |= ((GPIO_OUTPUT_2MHZ_PUSH_PULL_MODE)<<(4*copy_pinNumber));            }
            break;
            case GPIO_OUTPUT_2MHZ_OPEN_DRAIN_MODE:
            if (copy_pinNumber < 8){
                // clear the targetted bits
                GPIO_PORTC_CRL &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTC_CRL |= ((GPIO_OUTPUT_2MHZ_OPEN_DRAIN_MODE)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                // clear the targetted bits
                GPIO_PORTC_CRH &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTC_CRH |= ((GPIO_OUTPUT_2MHZ_OPEN_DRAIN_MODE)<<(4*copy_pinNumber));            }
            break;
            case GPIO_OUTPUT_10MHZ_PUSH_PULL_MODE:
            if (copy_pinNumber < 8){
                // clear the targetted bits
                GPIO_PORTC_CRL &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTC_CRL |= ((GPIO_OUTPUT_10MHZ_PUSH_PULL_MODE)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                // clear the targetted bits
                GPIO_PORTC_CRH &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTC_CRH |= ((GPIO_OUTPUT_10MHZ_PUSH_PULL_MODE)<<(4*copy_pinNumber));            }
            break;
            case GPIO_OUTPUT_10MHZ_OPEN_DRAIN_MODE:
            if (copy_pinNumber < 8){
                // clear the targetted bits
                GPIO_PORTC_CRL &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTC_CRL |= ((GPIO_OUTPUT_10MHZ_OPEN_DRAIN_MODE)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                // clear the targetted bits
                GPIO_PORTC_CRH &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTC_CRH |= ((GPIO_OUTPUT_10MHZ_OPEN_DRAIN_MODE)<<(4*copy_pinNumber));            }
            break;
            case GPIO_OUTPUT_50MHZ_PUSH_PULL_MODE:
            if (copy_pinNumber < 8){
                // clear the targetted bits
                GPIO_PORTC_CRL &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTC_CRL |= ((GPIO_OUTPUT_50MHZ_PUSH_PULL_MODE)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                // clear the targetted bits
                GPIO_PORTC_CRH &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTC_CRH |= ((GPIO_OUTPUT_50MHZ_PUSH_PULL_MODE)<<(4*copy_pinNumber));            }
            break;
            case GPIO_OUTPUT_50MHZ_OPEN_DRAIN_MODE:
            if (copy_pinNumber < 8){
                // clear the targetted bits
                GPIO_PORTC_CRL &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTC_CRL |= ((GPIO_OUTPUT_50MHZ_OPEN_DRAIN_MODE)<<(4*copy_pinNumber));
            }
            else if ((copy_pinNumber >=8) && (copy_pinNumber < 16)){
                copy_pinNumber = copy_pinNumber - 8; // it's just trivial data processing to deal with CRH as we deal with CRL register
                // clear the targetted bits
                GPIO_PORTC_CRH &= ~((0xF)<<(4*copy_pinNumber));
                // overwrite the targetted bits with the required value
                GPIO_PORTC_CRH |= ((GPIO_OUTPUT_50MHZ_OPEN_DRAIN_MODE)<<(4*copy_pinNumber));            }
            break;
        }    
        break;
    }
}
void GPIO_voidSetPortDirection (u8 copy_portNumber, u8 copy_modeAndConfig){
    switch (copy_portNumber){
        case GPIO_PORTA_PERIPHERAL_ID:
        switch (copy_modeAndConfig){
            case GPIO_INPUT_ANALOG_MODE:
                GPIO_PORTA_CRL &= ~(0xFFFFFFFF);
                GPIO_PORTA_CRH &= ~(0xFFFFFFFF);
            break;
            case GPIO_INPUT_FLOATING_MODE:
            GPIO_PORTA_CRL = (0x44444444);
            GPIO_PORTA_CRH = (0x44444444);
            break;
            case GPIO_INPUT_PULL_UPDOWN_MODE:
            GPIO_PORTA_CRL = (0x88888888);
            GPIO_PORTA_CRH = (0x88888888);
            break;
            case GPIO_OUTPUT_2MHZ_PUSH_PULL_MODE:
            GPIO_PORTA_CRL = (0x22222222);
            GPIO_PORTA_CRH = (0x22222222);
            break;
            case GPIO_OUTPUT_2MHZ_OPEN_DRAIN_MODE:
            GPIO_PORTA_CRL = (0x66666666);
            GPIO_PORTA_CRH = (0x66666666);
            break;
            case GPIO_OUTPUT_10MHZ_PUSH_PULL_MODE:
            GPIO_PORTA_CRL = (0x11111111);
            GPIO_PORTA_CRH = (0x11111111);
            break;
            case GPIO_OUTPUT_10MHZ_OPEN_DRAIN_MODE:
            GPIO_PORTA_CRL = (0x55555555);
            GPIO_PORTA_CRH = (0x55555555);
            break;
            case GPIO_OUTPUT_50MHZ_PUSH_PULL_MODE:
            GPIO_PORTA_CRL = (0x33333333);
            GPIO_PORTA_CRH = (0x33333333);
            break;
            case GPIO_OUTPUT_50MHZ_OPEN_DRAIN_MODE:
            GPIO_PORTA_CRL = (0x77777777);
            GPIO_PORTA_CRH = (0x77777777);
            break;
        }
        break;
        case GPIO_PORTB_PERIPHERAL_ID:
        switch (copy_modeAndConfig){
            case GPIO_INPUT_ANALOG_MODE:
                GPIO_PORTB_CRL &= ~(0xFFFFFFFF);
                GPIO_PORTB_CRH &= ~(0xFFFFFFFF);
            break;
            case GPIO_INPUT_FLOATING_MODE:
            GPIO_PORTB_CRL = (0x44444444);
            GPIO_PORTB_CRH = (0x44444444);
            break;
            case GPIO_INPUT_PULL_UPDOWN_MODE:
            GPIO_PORTB_CRL = (0x88888888);
            GPIO_PORTB_CRH = (0x88888888);
            break;
            case GPIO_OUTPUT_2MHZ_PUSH_PULL_MODE:
            GPIO_PORTB_CRL = (0x22222222);
            GPIO_PORTB_CRH = (0x22222222);
            break;
            case GPIO_OUTPUT_2MHZ_OPEN_DRAIN_MODE:
            GPIO_PORTB_CRL = (0x66666666);
            GPIO_PORTB_CRH = (0x66666666);
            break;
            case GPIO_OUTPUT_10MHZ_PUSH_PULL_MODE:
            GPIO_PORTB_CRL = (0x11111111);
            GPIO_PORTB_CRH = (0x11111111);
            break;
            case GPIO_OUTPUT_10MHZ_OPEN_DRAIN_MODE:
            GPIO_PORTB_CRL = (0x55555555);
            GPIO_PORTB_CRH = (0x55555555);
            break;
            case GPIO_OUTPUT_50MHZ_PUSH_PULL_MODE:
            GPIO_PORTB_CRL = (0x33333333);
            GPIO_PORTB_CRH = (0x33333333);
            break;
            case GPIO_OUTPUT_50MHZ_OPEN_DRAIN_MODE:
            GPIO_PORTB_CRL = (0x77777777);
            GPIO_PORTB_CRH = (0x77777777);
            break;
        }
        break;
        case GPIO_PORTC_PERIPHERAL_ID:
        switch (copy_modeAndConfig){
            case GPIO_INPUT_ANALOG_MODE:
                GPIO_PORTC_CRL &= ~(0xFFFFFFFF);
                GPIO_PORTC_CRH &= ~(0xFFFFFFFF);
            break;
            case GPIO_INPUT_FLOATING_MODE:
            GPIO_PORTC_CRL = (0x44444444);
            GPIO_PORTC_CRH = (0x44444444);
            break;
            case GPIO_INPUT_PULL_UPDOWN_MODE:
            GPIO_PORTC_CRL = (0x88888888);
            GPIO_PORTC_CRH = (0x88888888);
            break;
            case GPIO_OUTPUT_2MHZ_PUSH_PULL_MODE:
            GPIO_PORTC_CRL = (0x22222222);
            GPIO_PORTC_CRH = (0x22222222);
            break;
            case GPIO_OUTPUT_2MHZ_OPEN_DRAIN_MODE:
            GPIO_PORTC_CRL = (0x66666666);
            GPIO_PORTC_CRH = (0x66666666);
            break;
            case GPIO_OUTPUT_10MHZ_PUSH_PULL_MODE:
            GPIO_PORTC_CRL = (0x11111111);
            GPIO_PORTC_CRH = (0x11111111);
            break;
            case GPIO_OUTPUT_10MHZ_OPEN_DRAIN_MODE:
            GPIO_PORTC_CRL = (0x55555555);
            GPIO_PORTC_CRH = (0x55555555);
            break;
            case GPIO_OUTPUT_50MHZ_PUSH_PULL_MODE:
            GPIO_PORTC_CRL = (0x33333333);
            GPIO_PORTC_CRH = (0x33333333);
            break;
            case GPIO_OUTPUT_50MHZ_OPEN_DRAIN_MODE:
            GPIO_PORTC_CRL = (0x77777777);
            GPIO_PORTC_CRH = (0x77777777);
            break;
        }
        break;
    }

}

void GPIO_voidSetPinValue (u8 copy_portNumber, u8 copy_pinNumber, u8 copy_value){
    if (copy_value == 1){
        switch (copy_portNumber){
            case GPIO_PORTA_PERIPHERAL_ID:
            SET_BIT(GPIO_PORTA_BSRR, copy_pinNumber);
            break;
            case GPIO_PORTB_PERIPHERAL_ID:
            SET_BIT(GPIO_PORTB_BSRR, copy_pinNumber);
            break;
            case GPIO_PORTC_PERIPHERAL_ID:
            SET_BIT(GPIO_PORTC_BSRR, copy_pinNumber);
            break;
        }
    }
    else if (copy_value == 0){
        switch (copy_portNumber){
            case GPIO_PORTA_PERIPHERAL_ID:
            SET_BIT(GPIO_PORTA_BRR, copy_pinNumber);
            break;
            case GPIO_PORTB_PERIPHERAL_ID:
            SET_BIT(GPIO_PORTB_BRR, copy_pinNumber);
            break;
            case GPIO_PORTC_PERIPHERAL_ID:
            SET_BIT(GPIO_PORTC_BRR, copy_pinNumber);
            break;
        }
    }
}

void GPIO_voidSetPortValue (u8 copy_portNumber, u16 copy_value){
    if (copy_value == 0xFFFF){
        switch (copy_portNumber){
            case GPIO_PORTA_PERIPHERAL_ID:
            for (int pinCounter=0; pinCounter<16; pinCounter++){
              SET_BIT(GPIO_PORTA_BSRR, pinCounter);
            }
            break;
            case GPIO_PORTB_PERIPHERAL_ID:
            for (int pinCounter=0; pinCounter<16; pinCounter++){
                SET_BIT(GPIO_PORTB_BSRR, pinCounter);
            }
            break;
            case GPIO_PORTC_PERIPHERAL_ID:
            for (int pinCounter=0; pinCounter<16; pinCounter++){
                SET_BIT(GPIO_PORTC_BSRR, pinCounter);
            }
            break;
        }
    }
    else if (copy_value == 0){
        switch (copy_portNumber){
            case GPIO_PORTA_PERIPHERAL_ID:
            for (int pinCounter=0; pinCounter<16; pinCounter++){
              SET_BIT(GPIO_PORTA_BRR, pinCounter);
            }
            break;
            case GPIO_PORTB_PERIPHERAL_ID:
            for (int pinCounter=0; pinCounter<16; pinCounter++){
              SET_BIT(GPIO_PORTB_BRR, pinCounter);
            }
            break;
            case GPIO_PORTC_PERIPHERAL_ID:
            for (int pinCounter=0; pinCounter<16; pinCounter++){
              SET_BIT(GPIO_PORTC_BRR, pinCounter);
            }
            break;
        }
    }
}

u8 GPIO_u8GetPinValue (u8 copy_portNumber, u8 copy_pinNumber){
    switch (copy_portNumber){
        case GPIO_PORTA_PERIPHERAL_ID:
        return (GET_BIT(GPIO_PORTA_IDR, copy_pinNumber));
        case GPIO_PORTB_PERIPHERAL_ID:
        return (GET_BIT(GPIO_PORTB_IDR, copy_pinNumber));
        case GPIO_PORTC_PERIPHERAL_ID:
        return (GET_BIT(GPIO_PORTC_IDR, copy_pinNumber));
    }
}
u16 GPIO_u8GetPortValue (u8 copy_portNumber){
    switch (copy_portNumber){
        case GPIO_PORTA_PERIPHERAL_ID:
        return (GPIO_PORTA_IDR & 0xFFFF);
        case GPIO_PORTB_PERIPHERAL_ID:
        return (GPIO_PORTB_IDR & 0xFFFF);
        case GPIO_PORTC_PERIPHERAL_ID:
        return (GPIO_PORTC_IDR & 0xFFFF);
    }
}