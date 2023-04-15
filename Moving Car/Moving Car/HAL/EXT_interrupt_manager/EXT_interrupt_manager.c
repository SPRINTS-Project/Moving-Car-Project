#include "EXT_interrupt_manager.h"



u8_en_interruptErrorType ext_init(ext_interrupt_config_t *ext_interrupt_config, void(*callback)(void)){

    u8_en_interruptErrorType ret_val=INT_E_OK;
    ext_interrupt_init(ext_interrupt_config->ext_interrupt_no, ext_interrupt_config->edge_select);
    ext_interrupt_set_callback_init(ext_interrupt_config->ext_interrupt_no , callback);
    return ret_val;
}
u8_en_interruptErrorType ext_enable(ext_interrupt_config_t *ext_interrupt_config){
    
    u8_en_interruptErrorType ret_val=INT_E_OK;
    ext_interrupt_enable(ext_interrupt_config->ext_interrupt_no);
    return ret_val;
}
u8_en_interruptErrorType ext_disable(ext_interrupt_config_t *ext_interrupt_config){

    u8_en_interruptErrorType ret_val=INT_E_OK;
    ext_interrupt_disable(ext_interrupt_config->ext_interrupt_no);
    return ret_val;
}