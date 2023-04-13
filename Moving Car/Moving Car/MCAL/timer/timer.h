


#ifndef _TIMER_H_
#define _TIMER_H_

#include "Timer_config.h"
#include "timer_shared.h"

#define Max_Timer_Numbers 3

// Timer_0 8bit  max_capacity = 256 ,
// Timer_1 16bit max_capacity = 65536 , 
// Timer_3 8bit  max_capacity = 256
 

// Timer Config Structure
typedef struct {
	Timer_Number timer_num;
	uint8_t mode;
	uint8_t com[2];
	uint16_t clock_select;
	uint8_t com_interrupt_enable[2];
	uint8_t overflow_interrupt_enable;	
}Timer_configType;

// Timer Status Enum
typedef uint8_t Timer_Status;

#define Timer_S_Ready			((Timer_Status)0x01)
#define Timer_S_UnInit			((Timer_Status)0x02)




Timer_Errors Timer_Init(Timer_Number Timer_Num);
Timer_Errors Timer_Set(Timer_Number Timer_Num , uint16_t Timer_value);
//Timer_Errors Timer_Read(Timer_Number Timer_Num , uint16_t* Timer_value);
//Timer_Errors Timer_DeInit(Timer_Number Timer_Num);



#endif /* TIMER_H */