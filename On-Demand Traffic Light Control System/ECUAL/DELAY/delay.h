/*
 * File: delay.h
 * Brief: This file contains the typedefs and API of the Delay Driver
 * Created: 2/8/2023 9:43:50 AM
 *  Author: Abd El-Rahman Kadah
 */ 


#ifndef DELAY_H_
#define DELAY_H_

#include "../../MCAL/TIMER0/timer0.h"
#include <math.h>

typedef enum
{
	DELAY_FAIL,
	DELAY_SUCCESS
}En_delayError_t;
	
En_delayError_t setDelayInMsec(uint16_t delay);


#endif /* DELAY_H_ */