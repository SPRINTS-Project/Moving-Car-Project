/*
 * app.c
 *
 * Created: 4/15/2023 5:49:32 AM
 *  Author: Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 

#include "app.h"
#include <avr/io.h>



// Program state
static uint8_t u8_gs_v_progState = BTN_STOP;

// Delay Counter
uint8_t volatile u8_gv_delay = 0;

// PWM Counter
uint8_t volatile u8_gv_pwm = 0;


// LEDs configuration structure
const st_ledConfigType st_gc_ledsConfig[]={
	{porta,pin5},
	{porta,pin6},
	{porta,pin7},
	{portb,pin0}
};

// Buttons configuration structure
const st_btnConfigType st_gc_btn_config[]={
	{portd,pin3,Button_Start},
	{portd,pin2,0x01}
};

// Motors configuration structure 
const ST_motor_t st_gc_motorConfig[]={
	{
		porta,pin3,pin4
	},
	{
		porta,pin0,pin1
	}
	};


/******************************************************************************/
/*********************** Private Functions Declaration ************************/
/******************************************************************************/
void APP_init(void);
void APP_timer0OvfHandeler(void);
void APP_timer1OvfHandeler(void);
void APP_extInt0OvfHandeler(void);
void APP_longSide(void);
void APP_shortSide(void);
void APP_stop(void);
void App_rotate(void);
void APP_startState(void);
void APP_stopState(void);



// Timer 1 configuration structure 
// Will be used to generate delay 
const TimerManger_config_t st_gc_timer1 = {
		Timer1 , TIMER_NORMAL_MODE , APP_TIMER_1_INIT_VALUE , ((uint16_t)NULL) , APP_timer1OvfHandeler
	};

// Timer 0 configuration structure 
// Will be used to generate PWM
const TimerManger_config_t st_gc_timer0 = {
	Timer0 , TIMER_NORMAL_MODE , APP_TIMER_0_INIT_VALUE , ((uint16_t)NULL) , APP_timer0OvfHandeler
};







/******************************************************************************/
/*********************** Public Functions Implementation **********************/
/******************************************************************************/

void APP_start(void)
{
	// Initialize all modules used in the app
	APP_init();
	
	while(1)
	{
		while (u8_gs_v_progState == BTN_STOP)
		{
			// Perform stop state routine 
			APP_stopState();
		}
		while (u8_gs_v_progState == BTN_START)
		{
			// Perform start state routine
			APP_startState();
		}
	}
}





/******************************************************************************/
/*********************** Private Functions Implementation *********************/
/******************************************************************************/

void APP_init(void)
{
	// Initialize all LEDs
	for(uint8_t u8_index = 0 ; u8_index < 4 ; u8_index++)
	{
		LED_init((st_gc_ledsConfig[u8_index].u8_a_port) , (st_gc_ledsConfig[u8_index].u8_a_pin) );
	}
	
	// Initialize all buttons
	for (uint8_t u8_index = 0 ; u8_index < 2 ; u8_index++)
	{
		BUTTON_init(st_gc_btn_config[u8_index].u8_a_port,st_gc_btn_config[u8_index].u8_a_pin,st_gc_btn_config[u8_index].u8_a_ID);
	}
	
	// Initialize car module
	for (uint8_t u8_index = 0 ; u8_index < 2 ; u8_index+=2)
	{
		CAR_INIT(&st_gc_motorConfig[u8_index],&st_gc_motorConfig[u8_index+1]);
	}
	
	// Initialize Timer 1
	TIMER_MANGER_init(&st_gc_timer1);
	
	
	// Initialize Timer 0
	TIMER_MANGER_init(&st_gc_timer0);
	
	// Initialize External Interrupt module
	ext_interrupt_config_t st_l_int0Config ;
	st_l_int0Config.ext_interrupt_no = EXT_0;
	st_l_int0Config.edge_select = FALLING_EDGE;
	ext_init(&st_l_int0Config,APP_extInt0OvfHandeler);
	
	// Enable golbal interrupts
	sei();
}



void APP_timer0OvfHandeler(void)
{
	// Increment PWM counter
	u8_gv_pwm++;
	
	// Set timer 0 with the Initial value to generate interrupt every 2 ms
	TIMER_MANGER_setValue(Timer0,st_gc_timer0.timer_InitialValue);		// 2 ms with prescaler 1024 and F_CPU = 8M
}

void APP_timer1OvfHandeler(void)
{
	// Increment Delay counter
	u8_gv_delay++;
	
	// Set timer 1 value to generate interrupt every 500 ms
	TIMER_MANGER_setValue(Timer1,st_gc_timer1.timer_InitialValue);	// 500 ms with prescaler 1024 and F_CPU = 8M
}

void APP_extInt0OvfHandeler(void)
{
	// Set Delay counter and PWM Counter to zero
	u8_gv_delay = 0;
	u8_gv_pwm = 0 ;
	
	// Change program state to stop 
	u8_gs_v_progState = BTN_STOP;
}


void APP_longSide(void)
{
	// Turn all LEDs off and turn long side LED on
	LED_off(st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_port , st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_pin);
	LED_on(st_gc_ledsConfig[LED_LONG_SIDE].u8_a_port , st_gc_ledsConfig[LED_LONG_SIDE].u8_a_pin);
	LED_off(st_gc_ledsConfig[LED_ROTATE].u8_a_port , st_gc_ledsConfig[LED_ROTATE].u8_a_pin);
	LED_off(st_gc_ledsConfig[LED_STOP].u8_a_port , st_gc_ledsConfig[LED_STOP].u8_a_pin);
	
	
	// car move forward with 50% speed
	
	u8_gv_pwm = 0;
	TIMER_MANGER_start(F_CPU_1024,Timer0);							// start timer 0
	while (u8_gv_pwm <= 5)						// 10 ms ON
	{
		CAR_FORWARD(&st_gc_motorConfig[0],&st_gc_motorConfig[1]);
	}
	while (u8_gv_pwm > 5 && u8_gv_pwm <= 10)	// 10 ms OFF
	{
		CAR_STOP(&st_gc_motorConfig[0],&st_gc_motorConfig[1]);
	}
	TIMER_MANGER_stop(Timer0);										// stop timer 0
	u8_gv_pwm = 0;
}


void APP_shortSide(void)
{
	// Turn all LEDs off and turn short side LED on
	LED_on(st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_port , st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_pin);
	LED_off(st_gc_ledsConfig[LED_LONG_SIDE].u8_a_port , st_gc_ledsConfig[LED_LONG_SIDE].u8_a_pin);
	LED_off(st_gc_ledsConfig[LED_ROTATE].u8_a_port , st_gc_ledsConfig[LED_ROTATE].u8_a_pin);
	LED_off(st_gc_ledsConfig[LED_STOP].u8_a_port , st_gc_ledsConfig[LED_STOP].u8_a_pin);
	
	
	// move forward with 30% speed
	
	u8_gv_pwm = 0;
	TIMER_MANGER_start(F_CPU_1024,Timer0);									// start timer 0
	while (u8_gv_pwm <= 3)							// 6 ms ON
	{
		CAR_FORWARD(&st_gc_motorConfig[0],&st_gc_motorConfig[1]);
	}
	while (u8_gv_pwm > 3 && u8_gv_pwm <= 10)		// 14 ms OFF
	{
		CAR_STOP(&st_gc_motorConfig[0],&st_gc_motorConfig[1]);
	}
	TIMER_MANGER_stop(Timer0);										// stop timer 0
	u8_gv_pwm = 0;
}



void APP_stop(void)
{
	// Turn all LEDs off and turn stop LED on
	LED_off(st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_port , st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_pin);
	LED_off(st_gc_ledsConfig[LED_LONG_SIDE].u8_a_port , st_gc_ledsConfig[LED_LONG_SIDE].u8_a_pin);
	LED_off(st_gc_ledsConfig[LED_ROTATE].u8_a_port , st_gc_ledsConfig[LED_ROTATE].u8_a_pin);
	LED_on(st_gc_ledsConfig[LED_STOP].u8_a_port , st_gc_ledsConfig[LED_STOP].u8_a_pin);
	
	
	// Here We Will STOP motors
	CAR_STOP(&st_gc_motorConfig[0],&st_gc_motorConfig[1]);
}




void App_rotate(void)
{
	// Turn all LEDs off and turn rotate LED on
	LED_off(st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_port , st_gc_ledsConfig[LED_SHORT_SIDE].u8_a_pin);
	LED_off(st_gc_ledsConfig[LED_LONG_SIDE].u8_a_port , st_gc_ledsConfig[LED_LONG_SIDE].u8_a_pin);
	LED_on(st_gc_ledsConfig[LED_ROTATE].u8_a_port , st_gc_ledsConfig[LED_ROTATE].u8_a_pin);
	LED_off(st_gc_ledsConfig[LED_STOP].u8_a_port , st_gc_ledsConfig[LED_STOP].u8_a_pin);
	
	
	
	// rotate to right with 50% speed for 0.5 s to achieve 90 degree rotate to side
	u8_gv_pwm = 0;
	TIMER_MANGER_start(F_CPU_1024,Timer0);									// start timer 0
	while (u8_gv_pwm <= 5)							// 10 ms ON
	{
		CAR_REVERSE_RIGHT(&st_gc_motorConfig[0],&st_gc_motorConfig[1]);
	}
	while (u8_gv_pwm > 5 && u8_gv_pwm <= 10)		// 10 ms OFF
	{
		CAR_STOP(&st_gc_motorConfig[0],&st_gc_motorConfig[1]);
	}
	TIMER_MANGER_stop(Timer0);										// stop timer 0
	u8_gv_pwm = 0;
}



void APP_startState(void)
{
	ext_enable(EXT_0);											// Enable External interrupt 0
	TIMER_MANGER_start(F_CPU_1024,Timer1);						// start timer 1
	if (u8_gv_delay>= 2)										// 1s delay
	{
		if (u8_gv_delay <= 8 )									// longest side for 3s with speed 50%
		{
			APP_longSide();
		}
		else if (u8_gv_delay>8 && u8_gv_delay <=9)				// stop for 0.5
		{
			APP_stop();
			
		}
		else if (u8_gv_delay >9 && u8_gv_delay <=10)			// rotate 90 degree to right
		{
			App_rotate();
		}
		else if (u8_gv_delay > 10 && u8_gv_delay <=11)			// Stop the car for 0.5 s
		{
			APP_stop();
		}
		else if (u8_gv_delay > 11 && u8_gv_delay <= 15)				// short size for 2 s with speed 30%
		{
			APP_shortSide();
		}
		else if (u8_gv_delay>15 && u8_gv_delay <=16)				// stop for 0.5 s
		{
			APP_stop();
			
			
		}
		else if (u8_gv_delay >16 && u8_gv_delay <=17)			// rotate 90 degree to right
		{
			App_rotate();
		}
		else if (u8_gv_delay > 17 && u8_gv_delay <=18)			// Stop the car for 0.5 s
		{
			APP_stop();
			
		}
		else{
			u8_gv_delay = 2;
		}
		
	}
}
void APP_stopState(void)
{
	u8_en_btnStateType btnState = BT_PRE_PUSH;
	
	
	ext_disable(EXT_0);						// Disable External interrupt 0
	
	TIMER_MANGER_stop(Timer1);				// stop timer 1
	
	BUTTON_mainTask();						// Update all buttons states
	
	
	APP_stop();							
	
	
	// Read Start Button state
	btnState = BUTTON_getState(st_gc_btn_config[0].u8_a_ID);
	
	if (btnState == BT_RELEASED)
	{
		u8_gs_v_progState = BTN_START;
	}
	u8_gv_delay = 0;
}