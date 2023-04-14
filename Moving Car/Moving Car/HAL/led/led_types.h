/*
 * led_types.h
 *
 * Created: 4/13/2023 11:45:50 PM
 *  Author: Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 


#ifndef LED_TYPES_H_
#define LED_TYPES_H_

#include <stdint.h>


// Create LED ID ENUM
typedef uint8_t u8_en_ledIdType;

#define LED_1		((u8_en_ledIdType)0x01)
#define LED_2		((u8_en_ledIdType)0x02)
#define LED_3		((u8_en_ledIdType)0x03)
#define	LED_4		((u8_en_ledIdType)0x04)



// Create LED state ENUM
typedef uint8_t u8_en_ledStateType;
#define LED_OFF		((u8_en_ledStateType)0x00)
#define LED_ON		((u8_en_ledStateType)0x01)



// Create LED ERROR ENUM
typedef uint8_t u8_en_ledErrorType;
#define LED_OK			((u8_en_ledErrorType)0x00)
#define LED_UNDEFINED	((u8_en_ledErrorType)0x01)

typedef struct
{
	uint8_t u8_a_ledChannelID[2];
	uint8_t u8_a_ledState;
}st_ledConfigType;


#endif /* LED_TYPES_H_ */