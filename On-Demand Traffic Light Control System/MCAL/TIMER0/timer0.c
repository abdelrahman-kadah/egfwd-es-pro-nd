/*
 * File: timer0.c
 * Brief: This file contains the implementation of Timer 0 Driver
 * Created: 2/5/2023 7:42:23 PM
 *  Author: Abd El-Rahman Kadah
 */ 

#include "timer0.h"

//This function configure the timer mode and its initial value.

En_timerError_t TIMER0_init(uint8_t timerInitValue)
{
	//Validate the input parameters.
	if ((timerInitValue >= 0) && (timerInitValue <= 255))
	{
		// Set the timer mode to be the normal mode.
		CLEAR_BIT(TCCR0, WGM00);
		CLEAR_BIT(TCCR0, WGM01);
		
		// Set the timer initial value.
		TCNT0 = timerInitValue;
		
		//Return TIMER_SUCCESS if everything is OK.
		return TIMER_SUCCESS;
	}
	else
	{
		//Return TIMER_FAIL if there is invalid parameter.
		return TIMER_FAIL;
	}
	
	
}

//This function starts the timer to start ticking based on given clockPrescaler

En_timerError_t TIMER0_start(En_timerPrescaler_t clockPrescaler)
{
	//Select the clock prescaler based on the given clockPrescaler
	switch(clockPrescaler)
	{
		/*Set and clear the clock select bits according to given prescaler.
		
			Prescaler	CS02	CS01	CS00
			 NO_CLOCK     0       0       0
				1	      0       0	      1
				8		  0       1	      0
				64        0       1	      1
				256       1       0	      0
				1024      1       0	      1		
		*/
		
		case NO_PRESCALER:
			SET_BIT(TCCR0, CS00);
			CLEAR_BIT(TCCR0, CS01);
			CLEAR_BIT(TCCR0, CS02);
			break;
		case PRESCALER_8:
			CLEAR_BIT(TCCR0, CS00);
			SET_BIT(TCCR0, CS01);
			CLEAR_BIT(TCCR0, CS02);
			break;
		case PRESCALER_64:
			SET_BIT(TCCR0, CS00);
			SET_BIT(TCCR0, CS01);
			CLEAR_BIT(TCCR0, CS02);
			break;
		case PRESCALER_256:
			CLEAR_BIT(TCCR0, CS00);
			CLEAR_BIT(TCCR0, CS01);
			SET_BIT(TCCR0, CS02);
			break;
		case PRESCALER_1024:
			SET_BIT(TCCR0, CS00);
			CLEAR_BIT(TCCR0, CS01);
			SET_BIT(TCCR0, CS02);
			break;
		default:
			//Return TIMER_FAIL if the given clockPrescaler is out of its available range.
			return TIMER_FAIL;
	}
	
	//Return TIMER_SUCCESS if everything is OK.
	return TIMER_SUCCESS;
}


//This function checks the timer state if it's overflowed or not and returns only if the timer is overflowed
En_timerError_t TIMER0_getState(void)
{
	//Busy wait the timer overflow flag until it's set (Timer Overflowed)
	while(READ_BIT(TIFR,TOV0) == 0);
	
	//Clear the timer overflow flag by setting 1 to it.
	SET_BIT(TIFR,TOV0);
	
	//Return TIMER_SUCCESS if everything is OK.
	return TIMER_SUCCESS;
}

//This function stops the timer from ticking.

En_timerError_t TIMER0_stop(void)
{
	//Turn off the timer clock source.
	CLEAR_BIT(TCCR0, CS00);
	CLEAR_BIT(TCCR0, CS01);
	CLEAR_BIT(TCCR0, CS02);
	
	//Return TIMER_SUCCESS if everything is OK.
	return TIMER_SUCCESS;
}