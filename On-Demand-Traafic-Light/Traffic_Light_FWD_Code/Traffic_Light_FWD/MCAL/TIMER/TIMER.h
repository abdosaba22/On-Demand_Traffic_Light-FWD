/*
 * TIMER.h
 *
 * Created: 11/26/2022 8:37:04 PM
 *  Author: Abd-Alrahman Sabaa
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../UTIL/header.h"
#include "../../UTIL/REG.h"



void TIMER1_INIT(void);
void TIMER1_SET_TIME(uint32_t desired_time);
void TIMER1_START(void);
void TIMER1_STOP(void);
void delay_In_ms(uint32_t TIME);
//void End_Delay(void);



#endif /* TIMER_H_ */