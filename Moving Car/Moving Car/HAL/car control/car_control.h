#ifndef _CAR_CONTRO_H_
#define _CAR_CONTRO_H_
/*including sections*/
#include "../motor/motor.h"

/*typedefs*/

typedef enum EN_car_error_t
{
	CAR_OK,
	CAR_NOK,
}EN_car_error_t;
/*APIs prototypes*/
/************************************************************************
*description : used to initlize the two motor as output 
*input       : this function take two pointers to motor structure
*return      : MOTOR_OK, MOTOR_NOK                                                             
************************************************************************/
EN_car_error_t CAR_INIT(const ST_motor_t* motor_1,const ST_motor_t* motor_2);


/************************************************************************
*description : used to move the car forward by specific speed
*input       : this function take two pointers to motor structure and speed of the car
*return      : MOTOR_OK, MOTOR_NOK
************************************************************************/
EN_car_error_t CAR_FORWARD(const ST_motor_t* motor_1,const ST_motor_t* motor_2);


/************************************************************************
*description : used to reverse the car to the right
*input       : this function take two pointers to motor structure and speed of the car
*return      : MOTOR_OK, MOTOR_NOK
************************************************************************/
EN_car_error_t CAR_REVERSE_RIGHT(const ST_motor_t* motor_1,const ST_motor_t* motor_2);


/************************************************************************
*description : used to stop the car
*input       : this function take two pointers to motor structure
*return      : MOTOR_OK, MOTOR_NOK
************************************************************************/
EN_car_error_t CAR_STOP(const ST_motor_t* motor_1,const ST_motor_t* motor_2);

#endif