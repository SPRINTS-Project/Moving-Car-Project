/*
 * dio.h
 *
 * Created: 4/14/2023 12:27:22 AM
 *  Author: Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 


#ifndef DIO_H_
#define DIO_H_

#include <stdint.h>

typedef enum en_dioPortsType
{
	porta, portb, portc, portd
} en_dioPortsType;
typedef enum en_dioPinsType
{
	pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7
} en_dioPinsType;


// DIO Level type ENUM
typedef uint8_t u8_en_dioLevelType;

#define STD_LOW					((u8_en_dioLevelType)0x00)
#define STD_HIGH				((u8_en_dioLevelType)0x01)


// DIO Errors ENUM
typedef uint8_t u8_en_dioErrors;

#define DIO_E_OK				((u8_en_dioErrors)0x00)
#define DIO_InvalidPin			((u8_en_dioErrors)0x01)
#define DIO_InvalidPort			((u8_en_dioErrors)0x02)


// DIO DIR type ENUM
typedef uint8_t u8_en_dioDirType;

#define STD_INPUT					((u8_en_dioDirType)0x00)
#define STD_OUTPUT					((u8_en_dioDirType)0x01)

u8_en_dioErrors DIO_init (en_dioPortsType port, en_dioPinsType pin, u8_en_dioDirType direction);
u8_en_dioErrors DIO_writePIN (en_dioPortsType port, en_dioPinsType pin, u8_en_dioLevelType state);
u8_en_dioErrors DIO_readPIN (en_dioPortsType port, en_dioPinsType pin, uint8_t* value);

#endif /* DIO_H_ */