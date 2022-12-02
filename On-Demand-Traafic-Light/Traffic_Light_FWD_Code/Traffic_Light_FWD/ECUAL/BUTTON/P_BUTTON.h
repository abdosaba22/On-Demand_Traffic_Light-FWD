/*
 * P_BUTTON.h
 *
 * Created: 11/27/2022 2:17:40 PM
 *  Author: DELL
 */ 


#ifndef P_BUTTON_H_
#define P_BUTTON_H_

#include "../../UTIL/header.h"
#include "../../UTIL/REG.h"
#include "../../MCAL/DIO/DIO.h"

#define P_B_PORT     DIO_PORTD
#define P_B_PIN      INT_0			// INT0 input PIN2 --> 2


void P_B_INIT(void);
uint8_t P_B_READ(void);




#endif /* P_BUTTON_H_ */