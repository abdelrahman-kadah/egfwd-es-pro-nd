/*
 * File: delay.c
 * Brief: This file contains the implementation of the Delay Driver
 * Created: 2/8/2023 9:44:02 AM
 *  Author: Abd El-Rahman Kadah
 */ 

#include "delay.h"

//This function generates a delay in milliseconds.
En_delayError_t setDelayInMsec(uint16_t delayInMs)
{
	//Select the prescaler.
	volatile En_timerPrescaler_t selectedPrescaler = PRESCALER_1024;
	
	//Calculate the timer tick.
	volatile float timerTick = (float) PRESCALER_1024 / F_CPU;
	
	//Calculate the maximum delay of the timer.
	volatile float timerMaxDelay = timerTick * TIMER0_MAX;
	
	//Convert the delay in milliseconds to delay in seconds.
	volatile float delayInSec = (float) delayInMs / 1000;
	
	//Calculate the needed overflows to generate the required delay.
	volatile uint16_t numberOfOverflows = ceil(delayInSec / timerMaxDelay);
	
	//Calculate the timer initial value based on the number of required overflows
	volatile uint8_t timerInitValue = TIMER0_MAX - (delayInSec / timerTick) / numberOfOverflows;
	
	//Initialize the timer with the timer initial value
	if(TIMER0_init(timerInitValue) == TIMER_FAIL)
	{
		return DELAY_FAIL;
	}
	
	uint16_t overflowsCounter = 0;
	
	//Start the timer with the selected prescaler
	if(TIMER0_start(selectedPrescaler) == TIMER_FAIL)
	{
		return DELAY_FAIL;
	}

	//Wait until the overflows counter reaches the required number of overflows
	while(overflowsCounter < numberOfOverflows)
	{
		//Check for timer overflow
		if(TIMER0_getState() == TIMER_FAIL)
		{
			return DELAY_FAIL;
		}
		overflowsCounter++;
	}
	
	return DELAY_SUCCESS;
		
		
}

