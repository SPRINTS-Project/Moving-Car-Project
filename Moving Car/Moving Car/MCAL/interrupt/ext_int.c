/*
 * EXT_INT.c
 *
 * Created: 4/6/2023 11:13:31 PM
 *  Author: engma
 */ 
#include "EXT_INT_CONFIG.h"
#include "EXT_INT.h"


EXT_INT_ERR_TYPE eXT_INT_Enable(EXT_INT_ID_TYPE id , EXT_INT_MODE_TYPE mode)
{
	// valid ID
	if (id < EXT_INT_MAX_NUM	&&		mode <= EXT_INT_RISING_EDGE)
	{
		// Enable Interrupt
		GLOBAL_EXT_INT_REG |= (1U << EXT_PIN_ID[id]);
		
		if (id == INT_2_ID)
		{
			switch(mode)
			{
				case EXT_INT_FALLING_EDGE:
											//MCU_Control_Register_INT2 &= ~(1U << INT_2_BIT) ;
											break;
				case  EXT_INT_RISING_EDGE:
											MCU_Control_Register_INT2 |= (1U << INT_2_BIT) ;
											break;
				default:
						break;
			}
		}
		else if(id == INT_0_ID)
		{
			switch(mode)
			{
				case EXT_INT_FALLING_EDGE:
											MCU_Control_Register |=  (1U << INT_0_BIT_1) ;
											MCU_Control_Register &= ~(1U << INT_0_BIT_0) ;
											break;
				case  EXT_INT_RISING_EDGE:
											MCU_Control_Register |= (1U << INT_0_BIT_0) | (1U << INT_0_BIT_1) ;
											break;
				default:
						break;
			}
		}
		else
		{
			switch(mode)
			{
				case EXT_INT_FALLING_EDGE:
											MCU_Control_Register |=  (1U << INT_1_BIT_1) ;
											//MCU_Control_Register &= ~(1U << INT_1_BIT_0) ;
											break;
				case  EXT_INT_RISING_EDGE:
											MCU_Control_Register |= (1U << INT_1_BIT_0) | (1U << INT_1_BIT_1) ;
											break;
				default:
						break;
			}
		}
		return EXT_INT_ERR_OK;
	}
	else
	{
		return EXT_INT_ERR_OutOfRange;
	}
}