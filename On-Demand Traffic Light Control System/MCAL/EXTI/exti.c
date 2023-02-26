/*
 * File: exti.c
 * Brief: This file contains the implementation of the EXTI Driver
 * Created: 2/8/2023 12:59:12 PM
 *  Author: Abd El-Rahman Kadah
 */ 

#include "exti.h"


//Global Pointer to Function that doesn't take and doesn't return any parameter
//It stores the upper layer function to be called in the interrupt service routine
void(*int0Callback)(void);


//This function enables the external interrupt 0.

En_extiError_t EXTI_int0Init(void)
{
	//Set the the external interrupt 0 bit in the GICR register.
	SET_BIT(GICR,INT0);
	
	return EXTI_SUCCESS;
}

//This function stores the upper layer function int0Func required to be calledback by the INT0 interrupt service routine.
En_extiError_t EXTI_int0SetCallback(void(*int0Func)(void))
{
	//Check for NULL pointer.
	if(int0Func != NULL)
	{
		//Make the global function pointer int0Callback points to the int0Func address.
		int0Callback = int0Func;
		return EXTI_SUCCESS;
	}
	else
	{
		return EXTI_FAIL;
	}
	
}


//This function sets the sense control of external int 0 interrupt.
En_extiError_t EXTI_int0SetInterruptTrigger(En_interruptTrigger_t interruptTrigger)
{
	//Select the interrupt trigger based on the given interruptTrigger parameter.
	switch(interruptTrigger)
	{
		//Set the ISC00 and ISC01 Bits in MCUCR register based on the required interrupt trigger.
		/*
			Interrupt Trigger	ISC01	ISC00
			Rising Edge			1		1
			Falling Edge		1		0
			Any Logical Change  0       1
			Low Level			0       0
		*/
		
		case RISING_EDGE:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
		case FALLING_EDGE:
			CLEAR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
		case ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			break;
		case LOW_LEVEL:
			CLEAR_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			break;
		default: 
			return EXTI_FAIL;
	}
	return EXTI_SUCCESS;
}


//The interrupt service routine of the external interrupt 0
ISR(EXT_INT0)
{
	//Callback the upper layer function registered in the function pointer int0Callback.
	int0Callback();
}
