/*
 * dio.h
 *
 * Created: 4/14/2023 12:27:22 AM
 *  Author: engma
 */ 


#ifndef DIO_H_
#define DIO_H_

#include <stdint.h>

typedef enum DIO_PORTS
{
	porta, portb, portc, portd
} DIO_PORTS;
typedef enum DIO_PINS
{
	pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7
} DIO_PINS;


typedef enum PIN_DIRECTION
{
	STD_INPUT,
	STD_OUTPUT
} PIN_DIRECTION;

typedef enum PIN_STATE
{
	STD_LOW,
	STD_HIGH
} PIN_STATE;


uint8_t DIO_init (DIO_PORTS port, DIO_PINS pin, PIN_DIRECTION direction);
uint8_t DIO_writePIN (DIO_PORTS port, DIO_PINS pin, PIN_STATE state);
uint8_t DIO_readPIN (DIO_PORTS port, DIO_PINS pin, uint8_t* value);

#endif /* DIO_H_ */