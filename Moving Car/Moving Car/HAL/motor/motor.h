/*
 * motor.h
 *
 * Created: 4/14/2023 5:27:17 PM
 *  Author: basel
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_
/*including sections*/
#include "../../MCAL/DIO/dio.h"

/*typedefs*/
typedef struct ST_motor_t
{   
	en_dioPortsType port;
	en_dioPinsType pin_num1;
	en_dioPinsType pin_num2;
}ST_motor_t;
typedef enum EN_motor_error_t 
{ 
	MOTOR_OK,
    MOTOR_NOK
}EN_motor_error_t;
	
/*************************************************************APIs prototypes*******************************************************************/



/************************************************************************
* description : this function used to init the motor as output
* input       : pointer to structure which have port and two pin number
* return      :MOTOR_OK or MOTR_NOK                                                                     
************************************************************************/
EN_motor_error_t MOTOR_INIT(ST_motor_t* motor);


/************************************************************************
* description : this function used to move the motor forward
* input       : pointer to structure which have port and two pin number and speed of motor
* return      :MOTOR_OK or MOTR_NOK
************************************************************************/
EN_motor_error_t MOTOR_FORWARD(ST_motor_t* motor,uint8_t u8_a_speed);


/************************************************************************
* description : this function used to move the motor backward
* input       : pointer to structure which have port and two pin number and speed of motor
* return      :MOTOR_OK or MOTR_NOK
************************************************************************/
EN_motor_error_t MOTOR_BACKWARD(ST_motor_t* motor,uint8_t u8_a_speed);


/************************************************************************
* description : this function used to stop the motor
* input       : pointer to structure which have port and two pin number 
* return      :MOTOR_OK or MOTR_NOK
************************************************************************/
EN_motor_error_t MOTOR_STOP(ST_motor_t* motor);


/************************************************************************
* description : this function take speed of motor
* input       : speed of motor
* return      :void
************************************************************************/
void MOTOR_SPEED(uint8_t u8_a_speed);




#endif /* MOTOR_H_ */