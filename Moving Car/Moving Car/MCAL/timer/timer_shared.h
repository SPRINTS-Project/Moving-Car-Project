/*
 * timer_shared.h
 *
 * Created: 4/7/2023 5:01:19 AM
 *  Author: engma
 */ 


#ifndef TIMER_SHARED_H_
#define TIMER_SHARED_H_

// Timers Errors Enum
typedef uint8_t Timer_Errors;

#define Timer_E_OK				((Timer_Errors)0x00)
#define Timer_E_TRANSITION		((Timer_Errors)0x01)
#define Timer_E_PARAM_POINTER	((Timer_Errors)0x02)
#define Timer_E_INIT_FAILED		((Timer_Errors)0x03)
#define Timer_E_InvalidValue	((Timer_Errors)0x04)

typedef uint8_t Timer_Number;

#define Timer_0		((Timer_Number)0x00)
#define Timer_1		((Timer_Number)0x01)
#define Timer_2		((Timer_Number)0x02)







#endif /* TIMER_SHARED_H_ */