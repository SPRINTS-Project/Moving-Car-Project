/*
 * EXT_INT_CONFIG.h
 *
 * Created: 4/6/2023 11:15:02 PM
 *  Author: engma
 */ 


#ifndef EXT_INT_CONFIG_H_
#define EXT_INT_CONFIG_H_

#include <avr/io.h>





#define MCU_Control_Register			MCUCR					// for external interrupt 0 , 1
#define MCU_Control_Register_INT2		MCUCSR					// for external interrupt 2
#define GLOBAL_EXT_INT_REG				GICR


#define INT_0_BIT_0				ISC00
#define INT_0_BIT_1				ISC01
#define INT_1_BIT_0				ISC10
#define INT_1_BIT_1				ISC11
#define INT_2_BIT				ISC2






const uint8_t EXT_PIN_ID[3]={INT0,INT1,INT2};



#endif /* EXT_INT_CONFIG_H_ */