#include "EXT_interrupt_manager.h"



STD_return_t ext_init(ext_interrupt_config_t *ext_interrupt_config, void(*callback)(void)){

    STD_return ret_val=ok;
    ext_interrupt_init(ext_interrupt_config->ext_interrupt_no, ext_interrupt_config->edge_select);
    ext_interrupt_set_callback_init(ext_interrupt_config->ext_interrupt_no , callback);
    return ret_val;
}
STD_return_t ext_enable(ext_interrupt_config_t *ext_interrupt_config){
    
    STD_return ret_val=ok;
    ext_interrupt_enable(ext_interrupt_config->ext_interrupt_no);
    return ret_val;
}
STD_return_t ext_disable(ext_interrupt_config_t *ext_interrupt_config){

    STD_return ret_val=ok;
    ext_interrupt_disable(ext_interrupt_config->ext_interrupt_no);
    return ret_val;
}