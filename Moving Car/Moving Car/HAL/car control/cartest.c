/*
 * cartest.c
 *
 * Created: 4/15/2023 12:58:24 PM
 *  Author: basel
 */ 
/*#include "car_control.h"
#define F_CPU 1000000U
#include <util/delay.h>
void main(void)
{  
 /************************************************************************/
/*  use this method to initailize the car motors                                                                    */
/************************************************************************/
	/*ST_motor_t motor_1;
	ST_motor_t motor_2;
	motor_1.port=porta;
	motor_1.pin_num1=pin0;
	motor_1.pin_num2=pin1;
	motor_2.port=porta;
	motor_2.pin_num1=pin2;
	motor_2.pin_num2=pin3;
	CAR_INIT(&motor_1,&motor_2);
	while(1)
	{
		CAR_FORWARD(&motor_1,&motor_2,20);
		_delay_ms(1000);
		CAR_STOP(&motor_1,&motor_2);
		_delay_ms(1000);
		CAR_REVERSE_RIGHT(&motor_1,&motor_2,20);
		_delay_ms(1000);
		CAR_STOP(&motor_1,&motor_2);
		_delay_ms(1000);
	}

	
}*/