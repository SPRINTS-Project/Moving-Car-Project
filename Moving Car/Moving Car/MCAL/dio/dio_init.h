/*
 * DIO_init.h
 *
 * Created: 4/5/2023 8:29:43 PM
 *  Author: Mahmoud Sarhan
 * Email  : Mahmoudsarhan02672@gmail.com
 */ 


#ifndef DIO_INIT_H_
#define DIO_INIT_H_
#include "DIO.h"
#include <avr/io.h>


const uint8_t DIO_Config[]={
	
	// PORT A
	STD_INPUT,
	STD_INPUT,
	STD_INPUT,
	STD_INPUT,
	STD_INPUT,
	STD_INPUT,
	STD_INPUT,
	STD_INPUT,
	
	// PORT B
	STD_OUTPUT,
	STD_OUTPUT,
	STD_OUTPUT,
	STD_OUTPUT,
	STD_INPUT,
	STD_INPUT,
	STD_INPUT,
	STD_INPUT,
	
	// PORT C
	STD_INPUT,
	STD_INPUT,
	STD_INPUT,
	STD_INPUT,
	STD_INPUT,
	STD_INPUT,
	STD_INPUT,
	STD_INPUT,
	
	// PORT D
	STD_INPUT,
	STD_INPUT,
	STD_INPUT,
	STD_INPUT,
	STD_INPUT,
	STD_INPUT,
	STD_INPUT,
	STD_INPUT
};

#define  DATA_DIRECTION_PORTA	DDRA
#define  DATA_DIRECTION_PORTB	DDRB
#define  DATA_DIRECTION_PORTC	DDRC
#define  DATA_DIRECTION_PORTD	DDRD


#define  WR_PORT_A					PORTA
#define  WR_PORT_B					PORTB
#define  WR_PORT_C					PORTC
#define  WR_PORT_D					PORTD




#define  RE_PORT_A					PINA
#define  RE_PORT_B					PINB
#define  RE_PORT_C					PINC
#define  RE_PORT_D					PIND


#endif /* DIO_INIT_H_ */