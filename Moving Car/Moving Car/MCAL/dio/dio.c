#include "DIO_init.h"

/*****************************************************************************************/
/*    Function Description    : This Function to initialize the DIO module */
/*    Parameter in            : None */
/*    Parameter inout         : None */
/*    Parameter out           : None */
/*    Return value            : None */
/*    Requirment              : None */
/*****************************************************************************************/
/*void Dio_Init(void)
{
	for (uint8_t u8_Counter = 0 ; u8_Counter < 8 ; u8_Counter++)
	{
		DATA_DIRECTION_PORTA = DIO_Config[u8_Counter];
	}
	for (uint8_t u8_Counter = 0 ; u8_Counter < 8 ; u8_Counter++)
	{
		DATA_DIRECTION_PORTB = DIO_Config[u8_Counter+8];
	}
	for (uint8_t u8_Counter = 0 ; u8_Counter < 8 ; u8_Counter++)
	{
		DATA_DIRECTION_PORTC = DIO_Config[u8_Counter+16];
	}
	for (uint8_t u8_Counter = 0 ; u8_Counter < 8 ; u8_Counter++)
	{
		DATA_DIRECTION_PORTD = DIO_Config[u8_Counter+24];
	}
}
*/



/*****************************************************************************************/
/*    Function Description    : This Function Sets pin Direction */
/*    Parameter in            : Dio_ChannelType ChannelId , Dio_LevelType level */
/*    Parameter inout         : None */
/*    Parameter out           : None */
/*    Return value            : DIO_E_OK if done correctly
*								DIO_InvalidPin if the ChannelId is valid Id*/
/*    Requirment              : None */
/*****************************************************************************************/
DIO_Errors Dio_ChannelSetDIR(Dio_ChannelType ChannelId, Dio_DIRType dir)
{
	uint8_t pinNumber ;
	
	
	
	if (ChannelId < DIO_MAX_PINS)
	{
		if (ChannelId < DIO_PORTB_Channel0)
		{
			pinNumber = ChannelId;
			DATA_DIRECTION_PORTA |= dir << pinNumber;
		}
		else if (ChannelId < DIO_PORTC_Channel0)
		{
			pinNumber = ChannelId-8;
			DATA_DIRECTION_PORTB |= dir << pinNumber;
		}
		else if (ChannelId < DIO_PORTD_Channel0)
		{
			pinNumber = ChannelId-16;
			DATA_DIRECTION_PORTC |= dir << pinNumber;
		}
		else
		{
			pinNumber = ChannelId-24;
			DATA_DIRECTION_PORTD |= dir << pinNumber;
		}
		return DIO_E_OK;
	}
	else{
		return DIO_InvalidPin;
	}
}



/*****************************************************************************************/
/*    Function Description    : This Function to Read the Level of the pin */
/*    Parameter in            : Dio_ChannelType ChannelId  */
/*    Parameter inout         : None */
/*    Parameter out           : Dio_LevelType* level */
/*    Return value            : DIO_E_OK if done correctly 
*								DIO_InvalidPin if the ChannelId is valid Id*/
/*    Requirment              : None */
/*****************************************************************************************/
DIO_Errors Dio_ReadChannel(Dio_ChannelType ChannelId ,Dio_LevelType* level)
{
	uint8_t pinNumber ;
	
	
	if (ChannelId < DIO_MAX_PINS )
	{
		if (ChannelId < DIO_PORTB_Channel0)
		{
			pinNumber = ChannelId;
			*level = ((RE_PORT_A & (1U<<pinNumber))>>pinNumber); 
		}
		else if (ChannelId < DIO_PORTC_Channel0)
		{
			pinNumber = ChannelId-8;
			*level = ((RE_PORT_B & (1U<<pinNumber))>>pinNumber);
		}
		else if (ChannelId < DIO_PORTD_Channel0)
		{
			pinNumber = ChannelId-16;
			*level = ((RE_PORT_C & (1U<<pinNumber))>>pinNumber);
		}
		else
		{
			pinNumber = ChannelId-24;
			*level = ((RE_PORT_D & (1U<<pinNumber))>>pinNumber);
		}
		*level &= 0x01; 
		return DIO_E_OK;
	}
	else{
		return DIO_InvalidPin;
	}
		
}


/*****************************************************************************************/
/*    Function Description    : This Function Sets pin Level */
/*    Parameter in            : Dio_ChannelType ChannelId , Dio_LevelType level */
/*    Parameter inout         : None */
/*    Parameter out           : None */
/*    Return value            : DIO_E_OK if done correctly
*								DIO_InvalidPin if the ChannelId is valid Id*/
/*    Requirment              : None */
/*****************************************************************************************/
DIO_Errors Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType level)
{
	uint8_t pinNumber ;
	
	
	if (ChannelId < DIO_MAX_PINS )
	{
		if (ChannelId < DIO_PORTB_Channel0)
		{
			pinNumber = ChannelId;
			if (level == STD_HIGH)
			{
				WR_PORT_A |= (1U << pinNumber);
			}
			else{
				WR_PORT_A &= ~(1U << pinNumber);
			}
		}
		else if (ChannelId < DIO_PORTC_Channel0)
		{
			pinNumber = ChannelId-8;
			if (level == STD_HIGH)
			{
				WR_PORT_B |= (1U << pinNumber);
			}
			else{
				WR_PORT_B &= ~(1U << pinNumber);
			}
		}
		else if (ChannelId < DIO_PORTD_Channel0)
		{
			pinNumber = ChannelId-16;
			if (level == STD_HIGH)
			{
				WR_PORT_C |= (1U << pinNumber);
			}
			else{
				WR_PORT_C &= ~(1U << pinNumber);
			}
		}
		else
		{
			pinNumber = ChannelId-24;
			if (level == STD_HIGH)
			{
				WR_PORT_D |= (1U << pinNumber);
			}
			else{
				WR_PORT_D &= ~(1U << pinNumber);
			}
		}
		return DIO_E_OK;
	}
	else{
		return DIO_InvalidPin;
	}
	
}