/*
 * button_types.h
 *
 * Created: 4/13/2023 11:46:06 PM
 *  Author: Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 


#ifndef BUTTON_TYPES_H_
#define BUTTON_TYPES_H_


#include <stdint.h>

#define BUTTON_HOLD_THRESHOLD    20
#define BUTTONS_NUM				 1U



// Create Button Level ENUM
typedef uint8_t Button_LevelType;

#define BT_PUSH_LEVEL				((Button_LevelType)0x00)
#define BT_RELEASE_LEVEL	        ((Button_LevelType)0x01)



// Create ButtonID ENUM
typedef uint8_t u8_en_btnIdType;

#define Button_Start			((u8_en_btnIdType)0x00)
//#define Button_Stop				((u8_en_btnIdType)0x01)



// Create Button State ENUM
typedef uint8_t u8_en_btnStateType;

#define BT_PRE_PUSH				((u8_en_btnStateType)0x00)
#define BT_PUSHED				((u8_en_btnStateType)0x01)
#define BT_PRE_HOLD				((u8_en_btnStateType)0x02)
#define BT_HOLD					((u8_en_btnStateType)0x03)
#define BT_PRE_RELEASE			((u8_en_btnStateType)0x04)
#define BT_RELEASED				((u8_en_btnStateType)0x05)
#define BT_UNDEFINED			((u8_en_btnStateType)0x06)



typedef struct{
	uint8_t u8_a_channelId;
	uint8_t u8_a_debounceThreshold;
	uint8_t u8_a_HoldThreshold;
}st_btnConfigType;






#endif /* BUTTON_TYPES_H_ */