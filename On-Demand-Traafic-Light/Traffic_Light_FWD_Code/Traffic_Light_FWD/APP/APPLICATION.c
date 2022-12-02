/*
 * APPLICATION.c
 *
 * Created: 11/28/2022 11:49:15 PM
 *  Author: Abd-Alrahman Sabaa
 */ 
#include "APPLICATION.h"

volatile uint8_t INT_COUNTER = 0 ;
uint8_t Button_Mode=0;

extern uint8_t flag;

void AppInit(void){
	
	LED_INIT(CAR_LEDS_PORT,CAR_LED_G_PIN);
	LED_INIT(CAR_LEDS_PORT,CAR_LED_Y_PIN);
	LED_INIT(CAR_LEDS_PORT,CAR_LED_R_PIN);
	LED_INIT(WALKER_LEDS_PORT,WALKER_LED_G_PIN);
	LED_INIT(WALKER_LEDS_PORT,WALKER_LED_Y_PIN);
	LED_INIT(WALKER_LEDS_PORT,WALKER_LED_R_PIN);
	P_B_INIT();
	EXT_INT_INIT();
	TIMER1_INIT();
	//** turn off all leds 
	LED_OFF(CAR_LEDS_PORT,CAR_LED_G_PIN);
	LED_OFF(CAR_LEDS_PORT,CAR_LED_Y_PIN);
	LED_OFF(CAR_LEDS_PORT,CAR_LED_R_PIN);
	LED_OFF(WALKER_LEDS_PORT,WALKER_LED_G_PIN);
	LED_OFF(WALKER_LEDS_PORT,WALKER_LED_Y_PIN);
	LED_OFF(WALKER_LEDS_PORT,WALKER_LED_R_PIN);
	delay_In_ms(1);
}

void ON_Green_led_Walker(void){
		LED_ON(CAR_LEDS_PORT,CAR_LED_R_PIN);
		LED_ON(WALKER_LEDS_PORT,WALKER_LED_G_PIN);
		
		delay_In_ms(5000);
		INT_COUNTER=0;flag=0;
		for(uint16_t k=0 ; k<5 ; k++)
		{
			//TOGBIT(PORTA,5);
			
			LED_ON(CAR_LEDS_PORT,CAR_LED_Y_PIN);
			LED_ON(WALKER_LEDS_PORT,WALKER_LED_Y_PIN);
			delay_In_ms(500);
			
			LED_OFF(CAR_LEDS_PORT,CAR_LED_Y_PIN);
			LED_OFF(WALKER_LEDS_PORT,WALKER_LED_Y_PIN);
			delay_In_ms(500);
			
		}
		LED_OFF(CAR_LEDS_PORT,CAR_LED_R_PIN);
		LED_OFF(WALKER_LEDS_PORT,WALKER_LED_G_PIN);	
	
}

void AppStart(void){
	//SETBIT(DDRA,5);
	// Normal mode start stage 1 
	kk:
	delay_In_ms(1);
	LED_ON(CAR_LEDS_PORT,CAR_LED_G_PIN);
	flag=0;// INT_COUNTER=0;
	delay_In_ms(5000);
	// aa for case 2 & case 3 car led green is on goto aa  
	aa:
	/// if pressed & car Green led is on or yellow led 
	if(Button_Mode==1){
		LED_OFF(CAR_LEDS_PORT,CAR_LED_Y_PIN);
		// stage 1 
		LED_ON(WALKER_LEDS_PORT,WALKER_LED_R_PIN);
		// stage 2 blink yellow
		for (uint8_t i=INT_COUNTER ; i<=4 ; i++)
		{
			flag=0;
			//TOGBIT(PORTA,5);
			LED_ON(CAR_LEDS_PORT,CAR_LED_Y_PIN);
			LED_ON(WALKER_LEDS_PORT,WALKER_LED_Y_PIN);
			delay_In_ms(500);
			LED_OFF(CAR_LEDS_PORT,CAR_LED_Y_PIN);
			LED_OFF(WALKER_LEDS_PORT,WALKER_LED_Y_PIN);
			delay_In_ms(500);
			
		}
		LED_OFF(CAR_LEDS_PORT,CAR_LED_G_PIN);
		LED_OFF(WALKER_LEDS_PORT,WALKER_LED_R_PIN);
		/*-------------------------------------*/
		// stage 3 & 4  
		ON_Green_led_Walker();
		Button_Mode=0;
		INT_COUNTER=0;
		goto kk;		
	}
	// continue in normal mode stage 2 
	else {
		//car_IS_yellow_flag = 1 ;
		for (uint8_t i=0 ; i<5 ; i++)
		{
			flag=0;
			LED_ON(CAR_LEDS_PORT,CAR_LED_Y_PIN);
			delay_In_ms(500);
			if(Button_Mode){goto aa;}
			LED_OFF(CAR_LEDS_PORT,CAR_LED_Y_PIN);
			delay_In_ms(500);
			INT_COUNTER++;
			if(Button_Mode){goto aa;}
		} 
	}
	INT_COUNTER=0;
	LED_OFF(CAR_LEDS_PORT,CAR_LED_G_PIN);
	
	///////////////////////////////////////
	// stage 3 normal mode 
	LED_ON(CAR_LEDS_PORT,CAR_LED_R_PIN);
	delay_In_ms(5000);
	//
	// aa for case 1 & case 3 car led green is on goto aa
	bb:
	if(Button_Mode){
		INT_COUNTER=0;
		LED_OFF(CAR_LEDS_PORT,CAR_LED_Y_PIN);
		ON_Green_led_Walker();
		Button_Mode=0;
		goto kk;
	}
	// stage 4 normal mode 
	else{
		for (uint8_t i=0 ; i<5 ; i++)
		{
			LED_ON(CAR_LEDS_PORT,CAR_LED_Y_PIN);
			delay_In_ms(500);
			if(Button_Mode){goto bb;}
			LED_OFF(CAR_LEDS_PORT,CAR_LED_Y_PIN);
			delay_In_ms(500);
			if(Button_Mode){goto bb;}
		}
	}
	LED_OFF(CAR_LEDS_PORT,CAR_LED_R_PIN);
	///////////////////////////////////////
	

	
}

ISR(INT0_vect){
	if(Button_Mode==1) return;
	else{
		Button_Mode = 1;
		flag=1;
	}
}
