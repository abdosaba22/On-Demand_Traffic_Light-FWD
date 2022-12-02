/*
 * REG.h
 *
 * Created: 11/26/2022 8:06:38 PM
 *  Author: Abd-Alrahman Sabaa
 */ 


#ifndef REG_H_
#define REG_H_

/*************** DIO_REGISTERS *************/

#define PORTA      (*((volatile uint8_t*)0x3B))
#define DDRA       (*((volatile uint8_t*)0x3A))
#define PINA       (*((volatile uint8_t*)0x39))
								
#define PORTB      (*((volatile uint8_t*)0x38))
#define DDRB       (*((volatile uint8_t*)0x37))
#define PINB       (*((volatile uint8_t*)0x36))
								
#define PORTC      (*((volatile uint8_t*)0x35))
#define DDRC       (*((volatile uint8_t*)0x34))
#define PINC       (*((volatile uint8_t*)0x33))
								
#define PORTD      (*((volatile uint8_t*)0x32))
#define DDRD       (*((volatile uint8_t*)0x31))
#define PIND       (*((volatile uint8_t*)0x30))

/*************** EX_INT_REGISTERS *************/

#define SREG        (*((volatile uint8_t*)0x5F))
#define MCUCR       (*((volatile uint8_t*)0x55))
#define GICR        (*((volatile uint8_t*)0x5B))
#define GIFR        (*((volatile uint8_t*)0x5A))


/************* TIMER_0_REGISTERS **************/

#define TCNT0       (*((volatile uint8_t*)0x52))
#define TCCR0       (*((volatile uint8_t*)0x53))
#define TIMSK       (*((volatile uint8_t*)0x59))
#define OCR0        (*((volatile uint8_t*)0x5C))

/************* TIMER_1_REGISTERS **************/

#define TCCR1A      (*((volatile uint8_t*)0x4F))
#define TCCR1B      (*((volatile uint8_t*)0x4E))
#define OCR1A       (*((volatile uint16_t*)0x4A))
#define ICR1        (*((volatile uint16_t*)0x46))
#define TIFR        (*((volatile uint8_t*)0x58))
#define TCNT1       (*((volatile uint16_t*)0x4C))









#endif /* REG_H_ */