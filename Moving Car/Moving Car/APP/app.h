/*
 * app.h
 *
 * Created: 4/15/2023 5:49:45 AM
 *  Author: Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 


#ifndef APP_H_
#define APP_H_
#define  F_CPU		8000000UL
#include "../HAL/button/button.h"
#include "../HAL/led/led.h"
#include "../HAL/EXT_interrupt_manager/ext_interrupt_manager.h"
#include "../HAL/car control/car_control.h"
#include "../HAL/timer_manager/timer_manger.h"
//#include "../MCAL/EXT_Interrupt/interrupt.h"
//#include <avr/interrupt.h>

typedef uint8_t u8_en_PROGRAM_STATE;
#define BTN_START		((u8_en_PROGRAM_STATE)0x00)
#define BTN_STOP		((u8_en_PROGRAM_STATE)0x01)


#define APP_TIMER_1_INIT_VALUE		61628
#define APP_TIMER_0_INIT_VALUE		240

// Create LED ID ENUM
typedef uint8_t u8_en_ledIdType;

#define LED_SHORT_SIDE		((u8_en_ledIdType)0x00)
#define LED_LONG_SIDE		((u8_en_ledIdType)0x01)
#define LED_STOP			((u8_en_ledIdType)0x02)
#define	LED_ROTATE			((u8_en_ledIdType)0x03)


void APP_start(void);


#endif /* APP_H_ */