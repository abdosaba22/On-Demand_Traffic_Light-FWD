/*
 * DIO.h
 *
 * Created: 11/26/2022 8:35:16 PM
 *  Author: Abd-Alrahman Sabaa
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../UTIL/header.h"
#include "../../UTIL/REG.h"

// define macros for pins 

#define PIN0				0
#define PIN1				1
#define PIN2				2
#define PIN3				3
#define PIN4				4
#define PIN5				5
#define PIN6				6
#define PIN7				7

// define macros for ports

#define DIO_PORTA			0
#define DIO_PORTB			1
#define DIO_PORTC			2
#define DIO_PORTD			3

// define macros for Logical opera

#define INPUT				0
#define OUTPUT				1
#define HIGH				1
#define LOW					0

#define INT_0              PIN2

void DIO_DIRECTION(uint8_t port,uint8_t pin,uint8_t status);
void DIO_WRITE(uint8_t port,uint8_t pin,uint8_t status);
uint8_t DIO_READ(uint8_t port,uint8_t pin,uint8_t status);
void DIO_TOG(uint8_t port,uint8_t pin);

#endif /* DIO_H_ */