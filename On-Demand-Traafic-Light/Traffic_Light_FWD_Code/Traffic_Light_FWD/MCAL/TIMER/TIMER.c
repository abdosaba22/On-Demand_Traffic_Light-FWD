/*
 * TIMER.c
 *
 * Created: 11/26/2022 8:36:37 PM
 *  Author: DELL
 */ 
#include "TIMER.h"
uint8_t flag=0;
void TIMER1_INIT(void)
{
	//to select CTC mode in timer 1 -->TOP=OCR1A .. 
	CLRBIT(TCCR1A,0);
	CLRBIT(TCCR1A,1);
	SETBIT(TCCR1B,3);
	CLRBIT(TCCR1B,4);

	// enable global interrupt and timer 1 interrupt 
	//SETBIT(SREG,7);
	//SETBIT(TIMSK,4);
	
	// initialize counter
	TCNT1 = 0;
}

/*********************************
the following function is built for F_CPU 8000000 HZ
and prescaler 1024 .. Count number of ticks to delay required time
**********************************/
void TIMER1_SET_TIME(uint32_t desired_time) // desired_time in mill seconds
{
	if (desired_time <= 8000)
	{
		uint8_t  tick_time  = 1024 / 8;      // result will be in micro second -> 128 us
		uint32_t total_ticks = desired_time*1000 / tick_time; // 
		OCR1A = total_ticks - 1; // we subtract "1" cause the compare match in hardware take one tick to execute

	}
}
// function to start count from 0 To CTC 
void TIMER1_START(void)
{
	SETBIT(TCCR1B,0);
	CLRBIT(TCCR1B,1);
	SETBIT(TCCR1B,2);
}
// function to stop Timer No-CLK for timer 
void TIMER1_STOP(void)
{
	CLRBIT(TCCR1B,0);
	CLRBIT(TCCR1B,1);
	CLRBIT(TCCR1B,2);
}

void delay_In_ms(uint32_t TIME)
{
	SETBIT(TIFR,4); //clear timer1 overflow flag
	flag=0;
	TIMER1_SET_TIME(TIME);
	TIMER1_START();
	while( (READBIT(TIFR,4)== 0 ) && flag==0 ){}// wait till the timer Output Compare Match .. flag inside loop for me ..
	TIMER1_STOP();
	TCNT1 = 0;
	flag=0;
	SETBIT(TIFR,4); //clear timer1 overflow flag
}

void End_Delay(void){flag=1;}
