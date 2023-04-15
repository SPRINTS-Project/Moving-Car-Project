/*
 * led.c
 *
 * Created: 4/13/2023 11:43:29 PM
 *  Author: Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 
#include "led.h"
#include "../../MCAL/dio/dio.h"
/*
#define  LED_NUMs		4

const st_ledConfigType st_gc_ledConfig[LED_NUMs]={
	{{portb,pin0},							// LED_1 Channel ID
	LED_OFF},								// LED_1 State
	{{portb,pin1},							// LED_2 Channel ID
	LED_OFF},								// LED_2 State
	{{portb,pin2},							// LED_3 Channel ID
	LED_OFF},								// LED_3 State
	{{portb,pin3},							// LED_4 Channel ID
	LED_OFF}								// LED_4 State
};
*/

u8_en_ledErrorType LED_init(uint8_t u8_a_port , uint8_t u8_a_pin)
{
	return DIO_init(u8_a_port, u8_a_pin, STD_OUTPUT);
}



u8_en_ledErrorType LED_off(uint8_t u8_a_port , uint8_t u8_a_pin)
{
	return DIO_writePIN(u8_a_port,u8_a_pin ,LED_OFF);
}
u8_en_ledErrorType LED_on(uint8_t u8_a_port , uint8_t u8_a_pin)
{
	return DIO_writePIN(u8_a_port,u8_a_pin ,LED_ON);
}