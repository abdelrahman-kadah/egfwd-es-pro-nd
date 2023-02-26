/*
 * File: exti_test.c
 * Brief: This file tests the implementation of the EXTI Driver
 * Created: 2/12/2023 7:00:14 PM
 * Author: Abd El-Rahman Kadah
 */ 

#if 0 

#include "../MCAL/EXTI/exti.h"
#include "../MCAL/DIO/dio.h"
void testCallback(void);

int main(void)
{
	
	/*
	Function to be tested:EXTI_Int0SetInterruptTrigger
	How to test: See the microchip simulator to notice the changes in the interrupt sense 
		         control bits in MCUCR register ISC00 and ISC01 suitable to each interrupt trigger.
				Interrupt Trigger	ISC01	ISC00
				Rising Edge			1		1
				Falling Edge		1		0
				Any Logical Change  0       1
				Low Level			0       0
	*/
	EXTI_int0SetInterruptTrigger(RISING_EDGE);
	EXTI_int0SetInterruptTrigger(FALLING_EDGE);
	EXTI_int0SetInterruptTrigger(LOW_LEVEL);
	EXTI_int0SetInterruptTrigger(ANY_LOGICAL_CHANGE);
		
	/*
	Function to be tested: EXTI_int0SetCallback
	How to test: See the microchip simulator to see if testCallback is executed when the global interrupt is enabled
		         and the external interrupt is enabled.
	*/
	EXTI_int0SetCallback(testCallback);
	
	
	/*
	Function to be tested: EXTI_int0Init
	How to test: See the microchip simulator to notice the change in the INT0 bit
		         in the GICR register.
	*/
	EXTI_int0Init();
	
	
	
}


void testCallback(void)
{
	DIO_init(PORT_C, PIN0, OUT);
	DIO_write(PORT_C, PIN0, HIGH);
}

#endif