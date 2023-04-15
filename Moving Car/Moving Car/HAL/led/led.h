/*
 * led.h
 *
 * Created: 4/13/2023 11:43:45 PM
 *  Author: Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 


#ifndef LED_H_
#define LED_H_


#include "led_types.h"

u8_en_ledErrorType LED_init(uint8_t u8_a_port , uint8_t u8_a_pin);
u8_en_ledErrorType LED_off(uint8_t u8_a_port , uint8_t u8_a_pin);
u8_en_ledErrorType LED_on(uint8_t u8_a_port , uint8_t u8_a_pin);




#endif /* LED_H_ */