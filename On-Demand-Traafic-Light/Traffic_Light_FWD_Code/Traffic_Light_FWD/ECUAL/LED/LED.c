/*
 * LED.c
 *
 * Created: 11/27/2022 12:08:40 PM
 *  Author: DELL
 */ 
#include "LED.h"
void LED_INIT(uint8_t LED_PORT, uint8_t LED_PIN)
{

	DIO_DIRECTION(LED_PORT,LED_PIN,OUTPUT);

}
void LED_ON(uint8_t LED_PORT, uint8_t LED_PIN)
{

	DIO_WRITE(LED_PORT,LED_PIN,HIGH);

}
void LED_OFF(uint8_t LED_PORT, uint8_t LED_PIN)
{

	DIO_WRITE(LED_PORT,LED_PIN,LOW);

}
void LED_TOG(uint8_t LED_PORT, uint8_t LED_PIN)
{
	DIO_TOG(LED_PORT,LED_PIN);
}