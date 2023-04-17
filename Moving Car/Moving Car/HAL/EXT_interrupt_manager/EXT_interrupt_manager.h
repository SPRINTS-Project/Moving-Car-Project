#ifndef EXT_INTERRUPT_MANAGER_H
#define EXT_INTERRUPT_MANAGER_H
#include "../../MCAL/ext_interrupt/ext_interrupt.h"

/*
*
*
* -ext_interrupt_config_t datatype hold the external interrupt config
*   -Members-
* -1-  (ext_interrupt_no_t ext_interrupt_no) number of external interrupt
* -2-  (EDGE_detection_t edge_select) the state of line will fire the interrupt
*
*/
typedef struct 
{
ext_interrupt_no_t ext_interrupt_no;
EDGE_detection_t edge_select;
}ext_interrupt_config_t;





/*
*   -Description-
*-this function init the external interrupt configuration
*
*   -Input Output parameters -
*-1-it is configuration of external interrupt (ext_interrupt_config_t *ext_interrupt_config)
*-2-it is pointer to callback function   (void(*callback)(void))
*
*   -Return-
*   STD_return_t
*
*   -Return cases-
*-1- (E_NOK) if there is something wrong
*-0- (E_OK) otherwise
*/
u8_en_interruptErrorType ext_init(ext_interrupt_config_t *ext_interrupt_config, void(*callback)(void));

/*
*   -Description-
*-this function enable external interrupt depend on external interrupt configuration
*
*   -Input Output parameters -
*-1-it is configuration of external interrupt (ext_interrupt_config_t *ext_interrupt_config)
*
*
*   -Return-
*   STD_return_t
*
*   -Return cases-
*-1- (E_NOK) if there is something wrong
*-0- (E_OK) otherwise
*/
u8_en_interruptErrorType ext_enable(uint8_t u8_intNum);

/*
*   -Description-
*-this function disable external interrupt depend on external interrupt configuration
*
*   -Input Output parameters -
*-1-it is configuration of external interrupt (ext_interrupt_config_t *ext_interrupt_config)
*
*
*   -Return-
*   STD_return_t
*
*   -Return cases-
*-1- (E_NOK) if there is something wrong
*-0- (E_OK) otherwise
*/
u8_en_interruptErrorType ext_disable(uint8_t u8_intNum);
#endif