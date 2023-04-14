#ifndef EXT_INTERRUPT_H
#define EXT_INTERRUPT_H

#include "../interrupt.h"
#include "../../utilities/STD_TYPES.h"

#define GICR_ADD			 (*((volatile uint8_t *) 0x5B)) 
#define INT0_Globle		6
#define INT1_Globle		7

#define MCUCR_ADD			(*((volatile uint8_t *) 0x55))
#define INT1_MODE_INDEX	2
#define SREG_ADD			(*((volatile uint8_t *) 0x5F))
#define Globle_INT		7




typedef enum{
    EXT_0=0,
    EXT_1,
    EXT_2
}ext_interrupt_no_t;

typedef enum{
    LOW_LEVEL,
	LOGICAL_CHANGE,
	FALLING_EDGE,
	RISING_EDGE

}EDGE_detection_t;

/*
*   -Description-
*-this function init the external interrupt configuration
*
*   -Input Output parameters -
*-1-it is interrupt number  (ext_interrupt_no_t ext_interrupt_no)
*-2-it is the unterrupt condition   (EDGE_detection_t EDGE_detection)
*
*   -Return-
*   STD_return_t
*
*   -Return cases-
*-1- (E_NOK) if there is something wrong
*-2- (E_OK) otherwise
*/
STD_return_t ext_interrupt_init(ext_interrupt_no_t ext_interrupt_no, EDGE_detection_t EDGE_detection);

/*
*   -Description-
*-this function enable external interrupt depend on external interrupt number
*
*   -Input Output parameters -
*-1-it is interrupt number  (ext_interrupt_no_t ext_interrupt_no)
*
*
*   -Return-
*   STD_return_t
*
*   -Return cases-
*-1- (E_NOK) if there is something wrong
*-2- (E_OK) otherwise
*/
STD_return_t ext_interrupt_enable(ext_interrupt_no_t ext_interrupt_no);

/*
*   -Description-
*-this function disable external interrupt depend on external interrupt number
*
*   -Input Output parameters -
*-1-it is interrupt number  (ext_interrupt_no_t ext_interrupt_no)
*
*
*   -Return-
*   STD_return_t
*
*   -Return cases-
*-1- (E_NOK) if there is something wrong
*-2- (E_OK) otherwise
*/
STD_return_t ext_interrupt_disable(ext_interrupt_no_t ext_interrupt_no);


/*
*   -Description-
*-this function set callback function to external interrupt 
*
*   -Input Output parameters -
*-1-it is pointer to call back function  (void (*func)(void))
*
*   -Return-
*   STD_return_t
*
*   -Return cases-
*-1- (E_NOK) if there is something wrong
*-2- (E_OK) otherwise
*/
STD_return_t ext_interrupt_set_callback_init(ext_interrupt_no_t ext_interrupt_no ,void(*callback)(void));

#endif