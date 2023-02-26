/*
 * File: timer0_test.c
 * Brief: This file test the implmentation of the Timer 0 Driver
 * Created: 2/12/2023 5:44:40 PM
 * Author: Abd El-Rahman Kadah
 */ 


#if 0

#include "../MCAL/TIMER0/timer0.h"

int main(void)
{
	//Testing TIMER0_init()
	
	/*See the microchip simulator to notice two things:
	 * 1. The Wave Generation Mode bits in TCCR0 register is properly configured to initiate the timer normal mode.
	 * 2. the changes in TCNT0 register based on the change of variable value.
	 */
	for(uint8_t value = 1; value < 256; value++)
	{
	
		TIMER0_init(value);
	}
	
	//Testing TIMER0_start()
	
	/*See the microchip simulator to notice two things:
	 *1. the change in the CS bits in the TCCR0 register according to the change of prescaler
	 *2. the increment of TCNT0 register value after the timer is started.
	 */
	
	uint16_t prescalers[5] = {1, 8, 64, 256, 1024};
	for(uint8_t i = 0; i < 5; i++)
	{
	
		TIMER0_start(prescalers[i]);
	}
	
	//Testing TIMER0_getState()
	
	/*See the microchip simulator to notice two things:
	 *1. the timer delay in the stop watch in processor status windows according to preselected prescaler and initialValue
	 *2. Check the TOV0 flag in TCCR0 in the microchip simulator to check if it's cleared after the calling the function.
	 */
	
	TIMER0_getState();
	
	
	//Testing TIMER0_stop()
	
	/*See the microchip simulator to notice two things:
	 *1. the change in the CS bits in the TCCR0 register to be all zeros.
	 *2. the stop of incrementing of TCNT0 register value after the timer is stopped.
	 */
	
	TIMER0_stop();
	
}

#endif
