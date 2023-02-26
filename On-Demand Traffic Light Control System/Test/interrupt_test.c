/*
 * File: interrupt_test.c
 * Brief: This file tests the implementation of the Interrupt Driver
 * Created: 2/13/2023 12:02:08 PM
 * Author: Abd El-Rahman Kadah
 */ 


#if 0

#include "../ECUAL/INTERRUPTS/interrupts.h"
#include "../MCAL/DIO/dio.h"

void testCallback(void);

int main(void)
{
	/*
	Function to be tested: INTERRUPT_GIE_enable
	How to test: Check the I bit in the SREG to see if it's set.
	*/
	
	INTERRUPT_GIE_enable();
	
    /*
	Function to be tested: INTERRUPT_GIE_disable
	How to test: Check the I bit in the SREG to see if it's cleared.
	*/
	
	INTERRUPT_GIE_disable();
	
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
	INTERRUPT_EXTI_int0SetInterruptTrigger(RISING_EDGE);
	INTERRUPT_EXTI_int0SetInterruptTrigger(FALLING_EDGE);
	INTERRUPT_EXTI_int0SetInterruptTrigger(LOW_LEVEL);
	INTERRUPT_EXTI_int0SetInterruptTrigger(ANY_LOGICAL_CHANGE);
		
	/*
	Function to be tested: EXTI_int0SetCallback
	How to test: See the microchip simulator to see if testCallback is executed when the global interrupt is enabled
		         and the external interrupt is enabled.
	*/
	INTERRUPT_EXTI_int0SetCallback(testCallback);
	
	
	/*
	Function to be tested: EXTI_int0Init
	How to test: See the microchip simulator to notice the change in the INT0 bit
		         in the GICR register.
	*/
	INTERRUPT_EXTI_int0Init();
}

void testCallback(void)
{
	DIO_init(PORT_C, PIN0, OUT);
	DIO_write(PORT_C, PIN0, HIGH);
}

#endif