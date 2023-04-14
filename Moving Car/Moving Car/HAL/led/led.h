/*
 * led.h
 *
 * Created: 4/13/2023 11:43:45 PM
 *  Author: Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.comengma
 */ 


#ifndef LED_H_
#define LED_H_


#include "led_types.h"

void LED_init(void);
u8_en_ledErrorType LED_off(u8_en_ledIdType led);
u8_en_ledErrorType LED_on(u8_en_ledIdType led);




#endif /* LED_H_ */