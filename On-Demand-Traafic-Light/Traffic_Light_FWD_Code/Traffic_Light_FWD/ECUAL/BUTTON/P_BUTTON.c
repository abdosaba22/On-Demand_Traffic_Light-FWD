/*
 * P_BUTTON.c
 *
 * Created: 11/27/2022 2:17:53 PM
 *  Author: DELL
 */ 
#include "P_BUTTON.h"

void P_B_INIT(void)
{
	DIO_DIRECTION(P_B_PORT, P_B_PIN ,INPUT);
}
uint8_t P_B_READ(void)
{
	uint8_t value = 1;
	value = DIO_READ(P_B_PORT,P_B_PIN,INPUT);
	return value;
}