/*
 * DIO.c
 *
 * Created: 11/26/2022 8:35:28 PM
 *  Author: DELL
 */
#include "DIO.h"

void DIO_DIRECTION(uint8_t port,uint8_t pin,uint8_t status)
{
	switch (status)
	{
		case INPUT:
		switch(port)
		{
			case DIO_PORTA:
			CLRBIT(DDRA,pin);
			break;
			case DIO_PORTB:
			CLRBIT(DDRB,pin);
			break;
			case DIO_PORTC:
			CLRBIT(DDRC,pin);
			break;
			case DIO_PORTD:
			CLRBIT(DDRD,pin);
			break;
		}
		break;

		case OUTPUT:
		switch(port)
		{
			case DIO_PORTA:
			SETBIT(DDRA,pin);
			break;
			case DIO_PORTB:
			SETBIT(DDRB,pin);
			break;
			case DIO_PORTC:
			SETBIT(DDRC,pin);
			break;
			case DIO_PORTD:
			SETBIT(DDRD,pin);
			break;
		}
	}
}


void DIO_WRITE(uint8_t port,uint8_t pin,uint8_t status)
{
	switch (status)
	{
		case LOW:
		switch(port)
		{
			case DIO_PORTA:
			CLRBIT(PORTA,pin);
			break;
			case DIO_PORTB:
			CLRBIT(PORTB,pin);
			break;
			case DIO_PORTC:
			CLRBIT(PORTC,pin);
			break;
			case DIO_PORTD:
			CLRBIT(PORTD,pin);
			break;
		}
		break;

		case HIGH:
		switch(port)
		{
			case DIO_PORTA:
			SETBIT(PORTA,pin);
			break;
			case DIO_PORTB:
			SETBIT(PORTB,pin);
			break;
			case DIO_PORTC:
			SETBIT(PORTC,pin);
			break;
			case DIO_PORTD:
			SETBIT(PORTD,pin);
			break;
		}
	}
}
 
 
uint8_t DIO_READ(uint8_t port , uint8_t pin , uint8_t status)
{
	uint8_t value = 0;
	switch(status){
		case OUTPUT:
			switch(port)
			{
				case DIO_PORTA:
				value = READBIT(PORTA,pin);
				break;
				case DIO_PORTB:
				value = READBIT(PORTB,pin);
				break;
				case DIO_PORTC:
				value = READBIT(PORTC,pin);
				break;
				case DIO_PORTD:
				value = READBIT(PORTD,pin);
				break;
			}
		break;
		case INPUT:
			switch(port)
			{
				case DIO_PORTA:
				value = READBIT(PINA,pin);
				break;
				case DIO_PORTB:
				value = READBIT(PINB,pin);
				break;
				case DIO_PORTC:
				value = READBIT(PINC,pin);
				break;
				case DIO_PORTD:
				value = READBIT(PIND,pin);
				break;
			}
		break;
		
	}
	return value;
}

void DIO_TOG(uint8_t port,uint8_t pin)
{
	switch(port)
	{
		case DIO_PORTA:
		TOGBIT(PORTA,pin);
		break;
		case DIO_PORTB:
		TOGBIT(PORTB,pin);
		break;
		case DIO_PORTC:
		TOGBIT(PORTC,pin);
		break;
		case DIO_PORTD:
		TOGBIT(PORTD,pin);
		break;
	}
}