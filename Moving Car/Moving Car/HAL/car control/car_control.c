/*
 * car_control.c
 *
 * Created: 4/15/2023 12:32:00 PM
 *  Author: basel
 */ 
#include"car_control.h"

/*APIs impelementation*/


/************************************************************************
*description : used to initlize the two motor as output 
*input       : this function take two pointers to motor structure
*return      : MOTOR_OK, MOTOR_NOK                                                             
************************************************************************/
EN_car_error_t CAR_INIT(ST_motor_t* motor_1,ST_motor_t* motor_2)
{
	EN_car_error_t ret_val=CAR_OK;
	EN_motor_error_t motor_error1=MOTOR_INIT(motor_1);
	EN_motor_error_t motor_error2=MOTOR_INIT(motor_2);
	if(motor_1==NULL || motor_2 ==NULL)
	{
		ret_val=CAR_NOK;
	}
	else if(motor_error1 != MOTOR_OK || motor_error2 != MOTOR_OK)
	{
		ret_val=CAR_NOK;
	}
	else
	{
		// do nothing
	}
	return ret_val;
}


/************************************************************************
*description : used to move the car forward by specific speed
*input       : this function take two pointers to motor structure and speed of the car
*return      : MOTOR_OK, MOTOR_NOK
************************************************************************/
EN_car_error_t CAR_FORWARD(ST_motor_t* motor_1,ST_motor_t* motor_2,uint8_t u8_a_speed)
{
	EN_car_error_t ret_val=CAR_OK;
	EN_motor_error_t motor_error1=MOTOR_FORWARD(motor_1,u8_a_speed);
	EN_motor_error_t motor_error2=MOTOR_FORWARD(motor_2,u8_a_speed);
	if(motor_1==NULL || motor_2 ==NULL)
	{
		ret_val=CAR_NOK;
	}
	else if(motor_error1 != MOTOR_OK || motor_error2 != MOTOR_OK)
	{
		ret_val=CAR_NOK;
	}
	else
	{
		// do nothing
	}
	return ret_val;
}


/************************************************************************
*description : used to reverse the car to the right
*input       : this function take two pointers to motor structure and speed of the car
*return      : MOTOR_OK, MOTOR_NOK
************************************************************************/
EN_car_error_t CAR_REVERSE_RIGHT(ST_motor_t* motor_1,ST_motor_t* motor_2,uint8_t u8_a_speed)
{
	EN_car_error_t ret_val=CAR_OK;
	EN_motor_error_t motor_error1=MOTOR_FORWARD(motor_1,u8_a_speed);
	EN_motor_error_t motor_error2=MOTOR_BACKWARD(motor_2,u8_a_speed);
	if(motor_1==NULL || motor_2 ==NULL)
	{
		ret_val=CAR_NOK;
	}
	else if(motor_error1 != MOTOR_OK || motor_error2 != MOTOR_OK)
	{
		ret_val=CAR_NOK;
	}
	else
	{
		// do nothing
	}
	return ret_val;
}


/************************************************************************
*description : used to stop gthe car
*input       : this function take two pointers to motor structure
*return      : MOTOR_OK, MOTOR_NOK
************************************************************************/
EN_car_error_t CAR_STOP(ST_motor_t* motor_1,ST_motor_t* motor_2)
{
	EN_car_error_t ret_val=CAR_OK;
	EN_motor_error_t motor_error1=MOTOR_STOP(motor_1);
	EN_motor_error_t motor_error2=MOTOR_STOP(motor_2);
	if(motor_1==NULL || motor_2 ==NULL)
	{
		ret_val=CAR_NOK;
	}
	else if(motor_error1 != MOTOR_OK || motor_error2 != MOTOR_OK)
	{
		ret_val=CAR_NOK;
	}
	else
	{
		// do nothing
	}
	return ret_val;
}