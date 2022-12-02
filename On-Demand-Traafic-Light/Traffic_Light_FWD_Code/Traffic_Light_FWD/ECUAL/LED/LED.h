/*
 * LED.h
 *
 * Created: 11/27/2022 12:08:55 PM
 *  Author: Abd-Alrahman Sabaa
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../UTIL/header.h"
#include "../../UTIL/REG.h"
#include "../../MCAL/DIO/DIO.h"

#define	CAR_LEDS_PORT	DIO_PORTA
#define	CAR_LED_G_PIN	PIN0
#define	CAR_LED_Y_PIN	PIN1
#define	CAR_LED_R_PIN	PIN2

#define	WALKER_LEDS_PORT	DIO_PORTB
#define	WALKER_LED_G_PIN	PIN0
#define	WALKER_LED_Y_PIN	PIN1
#define	WALKER_LED_R_PIN	PIN2

void LED_INIT(uint8_t LED_PORT, uint8_t LED_PIN);
void LED_ON(  uint8_t LED_PORT, uint8_t LED_PIN);
void LED_OFF( uint8_t LED_PORT, uint8_t LED_PIN);
void LED_TOG( uint8_t LED_PORT, uint8_t LED_PIN);




#endif /* LED_H_ */