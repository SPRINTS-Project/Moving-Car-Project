/*
 * led.c
 *
 * Created: 4/13/2023 11:43:29 PM
 *  Author: Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 
#include "led.h"
#include "../../MCAL/dio/dio.h"

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


void led_Init(void)
{
	uint8_t u8_index;
	
	for (u8_index = 0 ; u8_index < LED_NUMs ; u8_index++)
	{
		DIO_init((st_gc_ledConfig[u8_index].u8_a_channelId[0]), (st_gc_ledConfig[u8_index].u8_a_channelId[1]) , STD_OUTPUT);
		if (st_gc_ledConfig[u8_index].u8_a_ledState == LED_ON)
		{
			LED_on(u8_index+1);
		}
		else
		{
			LED_off(u8_index+1);
		}
		
	}
}



u8_en_ledErrorType LED_off(u8_en_ledIdType led)
{
	if(led > LED_NUMs)
	{
		return LED_UNDEFINED;
	}
	DIO_writePIN((st_gc_ledConfig[led].u8_a_channelId[0]), (st_gc_ledConfig[led].u8_a_channelId[1]) ,LED_OFF);
	return  LED_OK;
}
u8_en_ledErrorType LED_on(u8_en_ledIdType led)
{
	if(led > LED_NUMs)
	{
		return LED_UNDEFINED;
	}
	DIO_writePIN((st_gc_ledConfig[led].u8_a_channelId[0]), (st_gc_ledConfig[led].u8_a_channelId[1]) ,LED_ON);
	return  LED_OK;
}