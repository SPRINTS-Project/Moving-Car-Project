/*
 * motor.c
 *
 * Created: 4/14/2023 5:35:05 PM
 *  Author: basel
 */ 
/*including sections*/
#include "motor.h"

/* APIs impelementation*/
EN_motor_error_t MOTOR_INIT(ST_motor_t* motor)
{
	if((DIO_init(motor->port,motor->pin_num1,STD_OUTPUT)==DIO_E_OK) && (DIO_init(motor->port,motor->pin_num2,STD_OUTPUT)==DIO_E_OK ))
	{
		return MOTOR_OK;
	}
	else
	{
		return MOTOR_NOK;
	}
}
EN_motor_error_t MOTOR_FORWARD(ST_motor_t* motor,uint8_t u8_a_speed)
{
	if(DIO_writePIN(motor->port,motor->pin_num1,STD_HIGH)==DIO_E_OK && DIO_writePIN(motor->port,motor->pin_num2,STD_LOW)==DIO_E_OK)
	{   MOTOR_SPEED(u8_a_speed);
		return MOTOR_OK;
	}
	else
	{
		return MOTOR_NOK;
	}
}
EN_motor_error_t MOTOR_BACKWARD(ST_motor_t* motor,uint8_t u8_a_speed)
{
	if(DIO_writePIN(motor->port,motor->pin_num1,STD_LOW)==DIO_E_OK && DIO_writePIN(motor->port,motor->pin_num2,STD_HIGH)==DIO_E_OK)
	{    MOTOR_SPEED(u8_a_speed);
		return MOTOR_OK;
	}
	else
	{
		return MOTOR_NOK;
	}
}
EN_motor_error_t MOTOR_STOP(ST_motor_t* motor)
{
	if(DIO_writePIN(motor->port,motor->pin_num1,STD_LOW)==DIO_E_OK && DIO_writePIN(motor->port,motor->pin_num2,STD_LOW)==DIO_E_OK)
	{   
		return MOTOR_OK;
	}
	else
	{
		return MOTOR_NOK;
	}
}
void MOTOR_SPEED(uint8_t u8_a_speed)
{
	
}