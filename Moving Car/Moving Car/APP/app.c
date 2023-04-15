/*
 * app.c
 *
 * Created: 4/15/2023 5:49:32 AM
 *  Author: Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 

#include "app.h"
#include <avr/io.h>




static uint8_t u8_gs_v_progState = BTN_STOP;


const st_ledConfigType st_gc_ledsConfig[]={
	{porta,pin5},
	{porta,pin6},
	{porta,pin7},
	{portb,pin0}
};


const st_btnConfigType st_gc_btn_config[]={
	{portd,pin3,Button_Start},
	{portd,pin2,0x01}
};


const ST_motor_t st_gc_motorConfig[]={
	{
		porta,pin3,pin4
	},
	{
		porta,pin0,pin1
	}
	};




void APP_init(void);
void APP_timer0OvfHandeler(void);
void APP_timer1OvfHandeler(void);
void APP_extInt0OvfHandeler(void);



uint8_t volatile u8_gv_delay = 0; 
uint8_t volatile u8_gv_pwm = 0;

/*ISR(TIMER1_OVF)
{
	APP_timer1OvfHandeler();
}*/

/*ISR(TIMER0_OVF)
{
	APP_timer0OvfHandeler();
}*/


/*ISR(EXT_INT0)
{
	APP_extInt0OvfHandeler();
}*/




void APP_start(void)
{
	
	u8_en_btnStateType btnState = BT_PRE_PUSH;
	
	APP_init();
	
	while(1)
	{
		BUTTON_mainTask();
		while (u8_gs_v_progState == BTN_STOP)
		{
			ext_disable(EXT_0);
			//TCCR1B = 0;						// stop timer 1
			TIMER_MANGER_stop(Timer1);
			BUTTON_mainTask();
			
			
			LED_off(st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_port , st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_pin);
			LED_off(st_gc_ledsConfig[LED_LONG_SIDE].u8_a_port , st_gc_ledsConfig[LED_LONG_SIDE].u8_a_pin);
			LED_off(st_gc_ledsConfig[LED_ROTATE].u8_a_port , st_gc_ledsConfig[LED_ROTATE].u8_a_pin);
			LED_on(st_gc_ledsConfig[LED_STOP].u8_a_port , st_gc_ledsConfig[LED_STOP].u8_a_pin);
			
			
			// Here We Will STOP motors
			CAR_STOP(&st_gc_motorConfig[0],&st_gc_motorConfig[1]);
			
			btnState = BUTTON_getState(st_gc_btn_config[0].u8_a_ID);
			
			if (btnState == BT_RELEASED)
			{
				u8_gs_v_progState = BTN_START;
			}
			u8_gv_delay = 0;
		}
		while (u8_gs_v_progState == BTN_START)
		{
			ext_enable(EXT_0);
			//TCCR1B = 1<< CS10 | 1<<CS12;								// start timer 1
			TIMER_MANGER_start(F_CPU_1024,Timer1);
			if (u8_gv_delay>= 2)										// 1s delay
			{
				if (u8_gv_delay <= 8 )									// longest side for 3s with speed 50%
				{
					// car move forward with 50% speed
					LED_off(st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_port , st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_pin);
					LED_on(st_gc_ledsConfig[LED_LONG_SIDE].u8_a_port , st_gc_ledsConfig[LED_LONG_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_ROTATE].u8_a_port , st_gc_ledsConfig[LED_ROTATE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_STOP].u8_a_port , st_gc_ledsConfig[LED_STOP].u8_a_pin);
					
					u8_gv_pwm = 0;
					//TCCR0 = 1<<CS02;									// start timer 0
					TIMER_MANGER_start(F_CPU_1024,Timer0);
					while (u8_gv_pwm <= 5)
					{
						CAR_FORWARD(&st_gc_motorConfig[0],&st_gc_motorConfig[1]);
					}
					while (u8_gv_pwm > 5 && u8_gv_pwm <= 10)
					{
						CAR_STOP(&st_gc_motorConfig[0],&st_gc_motorConfig[1]);
					}
					TIMER_MANGER_stop(Timer0);										// stop timer 0
					u8_gv_pwm = 0;
				}
				else if (u8_gv_delay>8 && u8_gv_delay <=9)				// stop for 0.5		
				{
					// car Stop
					LED_off(st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_port , st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_LONG_SIDE].u8_a_port , st_gc_ledsConfig[LED_LONG_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_ROTATE].u8_a_port , st_gc_ledsConfig[LED_ROTATE].u8_a_pin);
					LED_on(st_gc_ledsConfig[LED_STOP].u8_a_port , st_gc_ledsConfig[LED_STOP].u8_a_pin);
					
					// Here We Will STOP motors
					CAR_STOP(&st_gc_motorConfig[0],&st_gc_motorConfig[1]);
					
				}
				else if (u8_gv_delay >9 && u8_gv_delay <=10)			// rotate 90 degree to right
				{
					// rotate to right
					LED_off(st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_port , st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_LONG_SIDE].u8_a_port , st_gc_ledsConfig[LED_LONG_SIDE].u8_a_pin);
					LED_on(st_gc_ledsConfig[LED_ROTATE].u8_a_port , st_gc_ledsConfig[LED_ROTATE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_STOP].u8_a_port , st_gc_ledsConfig[LED_STOP].u8_a_pin);
					
					u8_gv_pwm = 0;
					TIMER_MANGER_start(F_CPU_1024,Timer0);									// start timer 0
					while (u8_gv_pwm <= 5)
					{
						CAR_REVERSE_RIGHT(&st_gc_motorConfig[0],&st_gc_motorConfig[1]);
					}
					while (u8_gv_pwm > 5 && u8_gv_pwm <= 10)
					{
						CAR_STOP(&st_gc_motorConfig[0],&st_gc_motorConfig[1]);
					}
					TIMER_MANGER_stop(Timer0);										// stop timer 0
					u8_gv_pwm = 0;
				}
				else if (u8_gv_delay > 10 && u8_gv_delay <=11)			// Stop the car for 0.5 s
				{
					// car Stop
					LED_off(st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_port , st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_LONG_SIDE].u8_a_port , st_gc_ledsConfig[LED_LONG_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_ROTATE].u8_a_port , st_gc_ledsConfig[LED_ROTATE].u8_a_pin);
					LED_on(st_gc_ledsConfig[LED_STOP].u8_a_port , st_gc_ledsConfig[LED_STOP].u8_a_pin);
					
					// Here We Will STOP motors
					CAR_STOP(&st_gc_motorConfig[0],&st_gc_motorConfig[1]);
					
					
				}
				else if (u8_gv_delay > 11 && u8_gv_delay <= 15)				// short size for 2 s with speed 30%
				{
					// move forward
					LED_on(st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_port , st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_LONG_SIDE].u8_a_port , st_gc_ledsConfig[LED_LONG_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_ROTATE].u8_a_port , st_gc_ledsConfig[LED_ROTATE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_STOP].u8_a_port , st_gc_ledsConfig[LED_STOP].u8_a_pin);
					
					
					
					u8_gv_pwm = 0;
					TIMER_MANGER_start(F_CPU_1024,Timer0);									// start timer 0
					while (u8_gv_pwm <= 3)
					{
						CAR_FORWARD(&st_gc_motorConfig[0],&st_gc_motorConfig[1]);
					}
					while (u8_gv_pwm > 3 && u8_gv_pwm <= 10)
					{
						CAR_STOP(&st_gc_motorConfig[0],&st_gc_motorConfig[1]);
					}
					TIMER_MANGER_stop(Timer0);										// stop timer 0
					u8_gv_pwm = 0;
				}
				else if (u8_gv_delay>15 && u8_gv_delay <=16)				// stop for 0.5		
				{
					// car Stop
					LED_off(st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_port , st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_LONG_SIDE].u8_a_port , st_gc_ledsConfig[LED_LONG_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_ROTATE].u8_a_port , st_gc_ledsConfig[LED_ROTATE].u8_a_pin);
					LED_on(st_gc_ledsConfig[LED_STOP].u8_a_port , st_gc_ledsConfig[LED_STOP].u8_a_pin);
					
					// Here We Will STOP motors
					CAR_STOP(&st_gc_motorConfig[0],&st_gc_motorConfig[1]);
					
					
				}
				else if (u8_gv_delay >16 && u8_gv_delay <=17)			// rotate 90 degree to right
				{
					// rotate to right
					LED_off(st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_port , st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_LONG_SIDE].u8_a_port , st_gc_ledsConfig[LED_LONG_SIDE].u8_a_pin);
					LED_on(st_gc_ledsConfig[LED_ROTATE].u8_a_port , st_gc_ledsConfig[LED_ROTATE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_STOP].u8_a_port , st_gc_ledsConfig[LED_STOP].u8_a_pin);
					
					u8_gv_pwm = 0;
					TIMER_MANGER_start(F_CPU_1024,Timer0);									// start timer 0
					while (u8_gv_pwm <= 5)
					{
						CAR_REVERSE_RIGHT(&st_gc_motorConfig[0],&st_gc_motorConfig[1]);
					}
					while (u8_gv_pwm > 5 && u8_gv_pwm <= 10)
					{
						CAR_STOP(&st_gc_motorConfig[0],&st_gc_motorConfig[1]);
					}
					TIMER_MANGER_stop(Timer0);										// stop timer 0
					u8_gv_pwm = 0;
				}
				else if (u8_gv_delay > 17 && u8_gv_delay <=18)			// Stop the car for 0.5 s
				{
					// car Stop
					LED_off(st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_port , st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_LONG_SIDE].u8_a_port , st_gc_ledsConfig[LED_LONG_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_ROTATE].u8_a_port , st_gc_ledsConfig[LED_ROTATE].u8_a_pin);
					LED_on(st_gc_ledsConfig[LED_STOP].u8_a_port , st_gc_ledsConfig[LED_STOP].u8_a_pin);
					
					// Here We Will STOP motors
					CAR_STOP(&st_gc_motorConfig[0],&st_gc_motorConfig[1]);
					
				}
				else{
					u8_gv_delay = 2;
				}
				
			}
		}
	}
}

void APP_init(void)
{
	for(uint8_t u8_index = 0 ; u8_index < 4 ; u8_index++)
	{
		LED_init((st_gc_ledsConfig[u8_index].u8_a_port) , (st_gc_ledsConfig[u8_index].u8_a_pin) );
	}
	
	
	for (uint8_t u8_index = 0 ; u8_index < 2 ; u8_index++)
	{
		BUTTON_init(st_gc_btn_config[u8_index].u8_a_port,st_gc_btn_config[u8_index].u8_a_pin,st_gc_btn_config[u8_index].u8_a_ID);
	}
	
	for (uint8_t u8_index = 0 ; u8_index < 2 ; u8_index+=2)
	{
		CAR_INIT(&st_gc_motorConfig[u8_index],&st_gc_motorConfig[u8_index+1]);
	}
	
	TimerManger_config_t st_l_timer1;
	st_l_timer1.timer_num = Timer1;
	st_l_timer1.timer_mode = TIMER_NORMAL_MODE;
	st_l_timer1.timer_InitialValue = APP_TIMER_1_INIT_VALUE;
	st_l_timer1.call_back_function = APP_timer1OvfHandeler;
	TIMER_MANGER_init(&st_l_timer1);
	
	
	TimerManger_config_t st_l_timer0;
	st_l_timer0.timer_num = Timer0;
	st_l_timer0.timer_mode = TIMER_NORMAL_MODE;
	st_l_timer0.timer_InitialValue = APP_TIMER_0_INIT_VALUE;
	st_l_timer0.call_back_function = APP_timer0OvfHandeler;
	TIMER_MANGER_init(&st_l_timer0);
	
	
	ext_interrupt_config_t st_l_int0Config ;
	st_l_int0Config.ext_interrupt_no = EXT_0;
	st_l_int0Config.edge_select = FALLING_EDGE;
	ext_init(&st_l_int0Config,APP_extInt0OvfHandeler);
	//ext_enable(EXT_0);
	
	/*GICR = 1<<INT0;
	MCUCR = 1<<ISC01;*/
	
	
	sei();
}



void APP_timer0OvfHandeler(void)
{
	u8_gv_pwm++;
	
	TCNT0 = 240;		// 2 ms with prescaler 1024 and F_CPU = 8M
}

void APP_timer1OvfHandeler(void)
{
	u8_gv_delay++;
	
	TCNT1 = 61629;		// 500 ms with prescaler 1024 and F_CPU = 8M
}

void APP_extInt0OvfHandeler(void)
{
	u8_gv_delay = 0;
	u8_gv_pwm = 0 ;
	u8_gs_v_progState = BTN_STOP;
}