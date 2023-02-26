/*
 * File: timer0.h
 * Brief: This file contains the Timer 0 Driver typedefs and API 
 * Created: 2/5/2023 7:42:12 PM
 *  Author: Abd El-Rahman Kadah
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#define F_CPU 1000000UL

#include "../../Utilities/types.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulations.h"

#define CS00 0
#define CS01 1
#define CS02 2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0 7

#define TOV0 0

#define TIMER0_MAX 256


typedef enum
{
	NO_PRESCALER = 1,
	PRESCALER_8 = 8,
	PRESCALER_64 = 64,
	PRESCALER_256 = 256,
	PRESCALER_1024 = 1024
}En_timerPrescaler_t;

typedef enum
{
	TIMER_FAIL,
	TIMER_SUCCESS
}En_timerError_t;



En_timerError_t TIMER0_init(uint8_t timerInitValue);
En_timerError_t TIMER0_start(En_timerPrescaler_t clockPrescaler);
En_timerError_t TIMER0_getState(void);
En_timerError_t TIMER0_stop(void);



#endif /* TIMER0_H_ */