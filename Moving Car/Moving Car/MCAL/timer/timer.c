#include "timer.h"
#include "Timer_Reg.h"
#include "timer_app.h"
#include <avr/interrupt.h>


uint8_t Timers_status[Max_Timer_Numbers];

Timer_Errors Timer_Init(Timer_Number Timer_Num)
{
		if (Timer_Num >= Max_Timer_Numbers)
		{
			return Timer_E_InvalidValue;
		}
		else
		{
			if (Timers_status[Timer_Num] == Timer_S_Ready)
			{
				return Timer_E_TRANSITION;
			}
			else
			{
				switch(Timer_Num)
				{
					case Timer_0 :
									TIMER_0_CONTROL_REG |= (1U << TIMER_0_CLOCK_SELECT_BIT_0);
									TIMER_INTERRUPT_MASK_REG |= (1U << TIMER_0_OVERFLOW_INTERRUPT_ENABLE);
									Timers_status[Timer_Num] = Timer_S_Ready;
									break;
					case Timer_1 :
									TIMER_1_CONTROL_B_REG |= (1U << TIMER_1_CLOCK_SELECT_BIT_0);
									TIMER_INTERRUPT_MASK_REG |= (1U << TIMER_1_OVERFLOW_INTERRUPT_ENABLE);
									Timers_status[Timer_Num] = Timer_S_Ready;
									break;
					case Timer_2 :
									TIMER_2_CONTROL_REG |= (1U << TIMER_2_CLOCK_SELECT_BIT_0);
									TIMER_INTERRUPT_MASK_REG |= (1U << TIMER_2_OVERFLOW_INTERRUPT_ENABLE);
									Timers_status[Timer_Num] = Timer_S_Ready;
									break;
					default:
						break;
				}
			}
		}
	return Timer_E_OK;
}





Timer_Errors Timer_Set(Timer_Number Timer_Num , uint16_t Timer_value)
{
	if (Timer_Num < Max_Timer_Numbers		&&		Timer_value < Timers_Capacity[Timer_Num])
	{
		if (Timers_status[Timer_Num] == Timer_S_Ready)
		{
			switch(Timer_Num)
			{
				case Timer_0:
				TIMER_0_COUNTER_REG = Timer_value;
				break;
				
				case Timer_1:
				TIMER_1_COUNTER_REG = Timer_value;
				break;
				
				case Timer_2:
				TIMER_2_COUNTER_REG = Timer_value;
				break;
				
				default:
				break;
			}
			return Timer_E_OK;
		}
		else
		{
			return Timer_E_TRANSITION;
		}
	}
	else
	{
		return Timer_E_InvalidValue;
	}
}

/*

Timer_Errors Timer_Read(Timer_Number Timer_Num , uint16_t* Timer_value)
{
	if (Timer_Num < Max_Timer_Numbers)
	{
		if (Timers_status[Timer_Num] == Timer_S_Ready)
		{
			switch(Timer_Num)
			{
				case Timer_0:
				*Timer_value = TIMER_0_COUNTER_REG;
				break;
				
				case Timer_1:
				*Timer_value = TIMER_1_COUNTER_REG;
				break;
				
				case Timer_2:
				*Timer_value = TIMER_1_COUNTER_REG;
				break;
				
				default:
				break;
			}
			return Timer_E_OK;
		}
		else
		{
			return Timer_E_TRANSITION;
		}
	}
	else
	{
		return Timer_E_InvalidValue;
	}
}
*/
/*
Timer_Errors Timer_DeInit(Timer_Number Timer_Num)
{
	
	if (Timer_Num < Max_Timer_Numbers)
	{
		if (Timers_status[Timer_Num] == Timer_S_Ready)
		{
			switch(Timer_Num)
			{
				case Timer_0:
				TIMER_0_CONTROL_REG &= ~(1U << TIMER_0_CLOCK_SELECT_BIT_0);
				TIMER_INTERRUPT_MASK_REG &= ~(1U << TIMER_0_OVERFLOW_INTERRUPT_ENABLE);
				TIMER_0_COUNTER_REG = 0;
				Timers_status[Timer_Num] = Timer_S_UnInit;
				break;
				
				case Timer_1:
				TIMER_1_CONTROL_B_REG &= ~(1U << TIMER_1_CLOCK_SELECT_BIT_0);
				TIMER_INTERRUPT_MASK_REG &= ~(1U << TIMER_1_OVERFLOW_INTERRUPT_ENABLE);
				TIMER_1_COUNTER_REG = 0;
				Timers_status[Timer_Num] = Timer_S_UnInit;
				break;
				
				case Timer_2:
				TIMER_2_CONTROL_REG &= ~(1U << TIMER_2_CLOCK_SELECT_BIT_0);
				TIMER_INTERRUPT_MASK_REG &= ~(1U << TIMER_2_OVERFLOW_INTERRUPT_ENABLE);
				TIMER_2_COUNTER_REG = 0;
				Timers_status[Timer_Num] = Timer_S_UnInit;
				break;
				
				default:
				break;
			}
			return Timer_E_OK;
		}
		else
		{
			return Timer_E_TRANSITION;
		}
	}
	else
	{
		return Timer_E_InvalidValue;
	}
}
*/


Timer_Errors timer_delay_50ms(Timer_Number num)
{
	if (num < Max_Timer_Numbers)
	{
		Timer_Init(num);
		Timer_Set(num,15536);
		sei();
		
		return Timer_E_OK;
	}
	else
	{
		return Timer_E_InvalidValue;
	}
	
	return 0;
}