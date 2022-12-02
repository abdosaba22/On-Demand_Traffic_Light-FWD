/*
 * EX_INT.c
 *
 * Created: 11/26/2022 8:38:15 PM
 *  Author: Abd-Alrahman Sabaa
 */ 

#include "EX_INT.h"

void EXT_INT_INIT(void){
	
	SETBIT(SREG,I);            // ENABLE THE GLOBAL INT 
	SETBIT(GICR,INT0);         // ENABLE INT0
	
	SETBIT(MCUCR,ISC00);       // MAKE Interrupt with RISING Edge
	SETBIT(MCUCR,ISC01);                         
}