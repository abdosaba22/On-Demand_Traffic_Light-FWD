/*
 * APPLICATION.h
 *
 * Created: 11/28/2022 11:49:34 PM
 *  Author: Abd-Alrahman Sabaa
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_


#include "../UTIL/header.h"
#include "../UTIL/REG.h"
#include "../MCAL/DIO/DIO.h"
#include "../ECUAL/BUTTON/P_BUTTON.h"
#include "../ECUAL/LED/LED.h"
#include "../MCAL/TIMER/TIMER.h"
#include "../MCAL/EXTER_INT/EX_INT.h"

void AppInit(void);
void ON_Green_led_Walker(void);
void AppStart(void);

#endif /* APPLICATION_H_ */