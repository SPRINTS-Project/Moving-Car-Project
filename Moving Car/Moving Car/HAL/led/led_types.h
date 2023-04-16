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






// Create LED state ENUM
typedef uint8_t u8_en_ledStateType;
#define LED_OFF		((u8_en_ledStateType)0x00)
#define LED_ON		((u8_en_ledStateType)0x01)



// Create LED ERROR ENUM
typedef uint8_t u8_en_ledErrorType;
#define LED_OK			((u8_en_ledErrorType)0x00)
#define LED_InvalidPin	((u8_en_ledErrorType)0x01)
#define LED_InvalidPort	((u8_en_ledErrorType)0x02)

typedef struct
{
	uint8_t u8_a_port;
	uint8_t u8_a_pin;
}st_ledConfigType;


#endif /* LED_TYPES_H_ */