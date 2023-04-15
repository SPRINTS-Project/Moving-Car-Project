/*
 * app.c
 *
 * Created: 4/15/2023 5:49:32 AM
 *  Author: Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 

#include "app.h"
#include <avr/io.h>
enum en_dioPorts
{
	porta, portb, portc, portd
};
enum en_dioPins
{
	pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7
};
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


uint8_t volatile u8_gv_delay = 0; 


ISR(TIMER1_OVF)
{
	u8_gv_delay++;
	
	TCNT1 = 61629;		// 500 ms with prescaler 1024 and F_CPU = 8M
}


ISR(EXT_INT0)
{
	u8_gv_delay = 0;
	u8_gs_v_progState = BTN_STOP;
	
}


void APP_start(void)
{
	
	u8_en_btnStateType btnState = BT_PRE_PUSH;
	
	
	for(uint8_t u8_index = 0 ; u8_index < 4 ; u8_index++)
	{
		LED_init((st_gc_ledsConfig[u8_index].u8_a_port) , (st_gc_ledsConfig[u8_index].u8_a_pin) );
	}
	
	
	for (uint8_t u8_index = 0 ; u8_index < 2 ; u8_index++)
	{
		BUTTON_init(portd,st_gc_btn_config[u8_index].u8_a_pin,st_gc_btn_config[u8_index].u8_a_ID);
	}
	/*TimerManger_config_t timer1;
	timer1.timer_num = 1;
	timer1.timer_mode = 0;
	timer1.timer_InitialValue = 61629;
	TIMER_MANGER_init(&timer1);*/
	
	
	GICR = 1<<INT0;
	MCUCR = 1<<ISC01;
	
	
	TCCR1A = 0x00;
	
	TIMSK = 1 << TOIE1;
	TCNT1 = 61629;
	
	
	sei();
	while(1)
	{
		BUTTON_mainTask();
		while (u8_gs_v_progState == BTN_STOP)
		{
			TCCR1B = 0;						// stop timer 1
			BUTTON_mainTask();
			
			
			LED_off(st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_port , st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_pin);
			LED_off(st_gc_ledsConfig[LED_LONG_SIDE].u8_a_port , st_gc_ledsConfig[LED_LONG_SIDE].u8_a_pin);
			LED_off(st_gc_ledsConfig[LED_ROTATE].u8_a_port , st_gc_ledsConfig[LED_ROTATE].u8_a_pin);
			LED_on(st_gc_ledsConfig[LED_STOP].u8_a_port , st_gc_ledsConfig[LED_STOP].u8_a_pin);
			
			
			// Here We Will STOP motors
			
			// Here Stop timer 1
			
			
			btnState = BUTTON_getState(st_gc_btn_config[0].u8_a_ID);
			
			if (btnState == BT_RELEASED)
			{
				u8_gs_v_progState = BTN_START;
			}
			u8_gv_delay = 0;
		}
		while (u8_gs_v_progState == BTN_START)
		{
			TCCR1B = 1<< CS10 | 1<<CS12;								// start timer 1
			if (u8_gv_delay>= 2)										// 1s delay
			{
				if (u8_gv_delay <= 8 )									// longest side for 3s with speed 50%
				{
					// car move forward with 50% speed
					LED_off(st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_port , st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_pin);
					LED_on(st_gc_ledsConfig[LED_LONG_SIDE].u8_a_port , st_gc_ledsConfig[LED_LONG_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_ROTATE].u8_a_port , st_gc_ledsConfig[LED_ROTATE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_STOP].u8_a_port , st_gc_ledsConfig[LED_STOP].u8_a_pin);
				}
				else if (u8_gv_delay>8 && u8_gv_delay <=9)				// stop for 0.5		
				{
					// car Stop
					LED_off(st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_port , st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_LONG_SIDE].u8_a_port , st_gc_ledsConfig[LED_LONG_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_ROTATE].u8_a_port , st_gc_ledsConfig[LED_ROTATE].u8_a_pin);
					LED_on(st_gc_ledsConfig[LED_STOP].u8_a_port , st_gc_ledsConfig[LED_STOP].u8_a_pin);
					
					// Here We Will STOP motors
					
					
				}
				else if (u8_gv_delay >9 && u8_gv_delay <=10)			// rotate 90 degree to right
				{
					// rotate to right
					LED_off(st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_port , st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_LONG_SIDE].u8_a_port , st_gc_ledsConfig[LED_LONG_SIDE].u8_a_pin);
					LED_on(st_gc_ledsConfig[LED_ROTATE].u8_a_port , st_gc_ledsConfig[LED_ROTATE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_STOP].u8_a_port , st_gc_ledsConfig[LED_STOP].u8_a_pin);
				}
				else if (u8_gv_delay > 10 && u8_gv_delay <=11)			// Stop the car for 0.5 s
				{
					// car Stop
					LED_off(st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_port , st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_LONG_SIDE].u8_a_port , st_gc_ledsConfig[LED_LONG_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_ROTATE].u8_a_port , st_gc_ledsConfig[LED_ROTATE].u8_a_pin);
					LED_on(st_gc_ledsConfig[LED_STOP].u8_a_port , st_gc_ledsConfig[LED_STOP].u8_a_pin);
					
					// Here We Will STOP motors
					
					
					
				}
				else if (u8_gv_delay > 11 && u8_gv_delay <= 15)				// short size for 2 s with speed 30%
				{
					// move forward
					LED_on(st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_port , st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_LONG_SIDE].u8_a_port , st_gc_ledsConfig[LED_LONG_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_ROTATE].u8_a_port , st_gc_ledsConfig[LED_ROTATE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_STOP].u8_a_port , st_gc_ledsConfig[LED_STOP].u8_a_pin);
				}
				else if (u8_gv_delay>15 && u8_gv_delay <=16)				// stop for 0.5		
				{
					// car Stop
					LED_off(st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_port , st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_LONG_SIDE].u8_a_port , st_gc_ledsConfig[LED_LONG_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_ROTATE].u8_a_port , st_gc_ledsConfig[LED_ROTATE].u8_a_pin);
					LED_on(st_gc_ledsConfig[LED_STOP].u8_a_port , st_gc_ledsConfig[LED_STOP].u8_a_pin);
					
					// Here We Will STOP motors
					
					
					
				}
				else if (u8_gv_delay >16 && u8_gv_delay <=17)			// rotate 90 degree to right
				{
					// rotate to right
					LED_off(st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_port , st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_LONG_SIDE].u8_a_port , st_gc_ledsConfig[LED_LONG_SIDE].u8_a_pin);
					LED_on(st_gc_ledsConfig[LED_ROTATE].u8_a_port , st_gc_ledsConfig[LED_ROTATE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_STOP].u8_a_port , st_gc_ledsConfig[LED_STOP].u8_a_pin);
				}
				else if (u8_gv_delay > 17 && u8_gv_delay <=18)			// Stop the car for 0.5 s
				{
					// car Stop
					LED_off(st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_port , st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_LONG_SIDE].u8_a_port , st_gc_ledsConfig[LED_LONG_SIDE].u8_a_pin);
					LED_off(st_gc_ledsConfig[LED_ROTATE].u8_a_port , st_gc_ledsConfig[LED_ROTATE].u8_a_pin);
					LED_on(st_gc_ledsConfig[LED_STOP].u8_a_port , st_gc_ledsConfig[LED_STOP].u8_a_pin);
					
					// Here We Will STOP motors
					
					
				}
				else{
					u8_gv_delay = 2;
				}
				
			}
		}
	}
}