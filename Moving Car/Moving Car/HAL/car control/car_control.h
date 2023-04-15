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
EN_car_error_t CAR_INIT(ST_motor_t* motor_1,ST_motor_t* motor_2);
EN_car_error_t CAR_FORWARD(ST_motor_t* motor_1,ST_motor_t* motor_2,uint8_t u8_a_speed);
EN_car_error_t CAR_REVERSE_RIGHT(ST_motor_t* motor_1,ST_motor_t* motor_2,uint8_t u8_a_speed);
EN_car_error_t CAR_STOP(ST_motor_t* motor_1,ST_motor_t* motor_2);

#endif