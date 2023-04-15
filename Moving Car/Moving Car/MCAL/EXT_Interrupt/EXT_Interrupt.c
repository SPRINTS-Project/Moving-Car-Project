#include "ext_interrupt.h"
static void (*callback_EXT_0)(void);
static void (*callback_EXT_1)(void);

u8_en_interruptErrorType ext_interrupt_init(ext_interrupt_no_t ext_interrupt_no, EDGE_detection_t EDGE_detection){
    u8_en_interruptErrorType ret_val=INT_E_OK;
    switch (ext_interrupt_no)
    {
    case EXT_0:
        MCUCR_ADD |= EDGE_detection;	
		SREG_ADD |= Globle_INT;
        break;

    case EXT_1:
        MCUCR_ADD |= (EDGE_detection<<2);	
		SREG_ADD |= (1<<Globle_INT);
        break;

    case EXT_2:
        /* code */
        break;    
    
    default:
        break;
    }

    return ret_val;
}
u8_en_interruptErrorType ext_interrupt_enable(ext_interrupt_no_t ext_interrupt_no){
    u8_en_interruptErrorType ret_val=INT_E_OK;
    switch (ext_interrupt_no)
    {
    case EXT_0:
        GICR_ADD |= (1<<INT0_Globle);

		
        break;

    case EXT_1:
        GICR_ADD |= (1<<INT1_Globle);

        break;

    case EXT_2:
        /* code */
        break;    
    
    default:
        break;
    }
    return ret_val;
}
u8_en_interruptErrorType ext_interrupt_disable(ext_interrupt_no_t ext_interrupt_no){
    u8_en_interruptErrorType ret_val=INT_E_OK;
    switch (ext_interrupt_no)
    {
    case EXT_0:
       GICR_ADD &= ~(1<<INT0_Globle);

        break;

    case EXT_1:
        GICR_ADD &= ~(1<<INT1_Globle);

        break;

    case EXT_2:
        /* code */
        break;    
    
    default:
        break;
    }
    return ret_val;

}

u8_en_interruptErrorType ext_interrupt_set_callback_init(ext_interrupt_no_t ext_interrupt_no ,void(*callback)(void)){
    u8_en_interruptErrorType ret_val=INT_E_OK;
    switch (ext_interrupt_no)
    {
    case EXT_0:
        GICR_ADD &= ~(1<<INT0_Globle);
        callback_EXT_0 = callback;
		
        break;

    case EXT_1:
        GICR_ADD &= ~(1<<INT1_Globle);
        callback_EXT_1 = callback;
        break;

    case EXT_2:
        /* code */
        break;    
    
    default:
        break;
    }
    return ret_val;
}

/*
*   -Description-
*-interrupt service routine for  external interrupt 0
*
*/
ISR(EXT_INT0)
{
	callback_EXT_0();
}


/*
*   -Description-
*-interrupt service routine for  external interrupt10
*
*/
/*ISR(EXT_INT1)
{
	callback_int1();
}
*/
/*
*   -Description-
*-interrupt service routine for  external interrupt 2
*
*/
/*ISR(EXT_INT2)
{
	callback_int2();
}*/