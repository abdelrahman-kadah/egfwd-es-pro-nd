/*
 * File: delay_test.c
 * Brief: This file tests the implementation of the Delay Driver
 * Created: 2/12/2023 9:36:47 PM
 * Author: Abd El-Rahman Kadah
 */ 

#if 0

#include "../ECUAL/DELAY/delay.h"

int main(void)
{
	/*
	Function to be tested: setDelayInMs
	How to test: See the microchip simulator stop watch  in the processor status windows 
				 to check if the amount of delay is correct.
	*/
	for(uint16_t i = 0; i < 65535; i++)
	{
		setDelayInMsec(i);
	}
}

#endif
