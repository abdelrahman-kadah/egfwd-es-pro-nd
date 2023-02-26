/*
 * File: interrupts.c
 * Brief: This file contains the implementation of the Interrupt Driver
 * Created: 2/13/2023 11:19:12 AM
 *  Author: Abd El-Rahman Kadah
 */ 

#include "interrupts.h"


//This function enables the interrupts globally.

En_interruptError_t INTERRUPT_GIE_enable(void)
{
	//Call GIE_enable from the GIE driver API
	if(GIE_enable() == GIE_SUCCESS)
	{
		return INTERRUPT_SUCCESS;
	}
	else
	{
		return INTERRUPT_FAIL;
	}
}

//This function disables the interrupts globally.

En_interruptError_t INTERRUPT_GIE_disable(void)
{
	//Call GIE_disable from the GIE driver API
	if(GIE_disable() == GIE_SUCCESS)
	{
		return INTERRUPT_SUCCESS;
	}
	else
	{
		return INTERRUPT_FAIL;
	}
}

//This function enables the external interrupt int 0

En_interruptError_t INTERRUPT_EXTI_int0Init(void)
{
	//Call the function EXTI_int0Init from the EXTI driver API
	if(EXTI_int0Init() == EXTI_SUCCESS)
	{
		return INTERRUPT_SUCCESS;
	}
	else
	{
		return INTERRUPT_FAIL;
	}
}

//This functon sets the callback of the external interrupt int0

En_interruptError_t INTERRUPT_EXTI_int0SetCallback(void(*int0Func)(void))
{
	//Call the function EXTI_int0SetCallback from the EXTI driver API
	if(EXTI_int0SetCallback(int0Func) == EXTI_SUCCESS)
	{
		return INTERRUPT_SUCCESS;
	}
	else
	{
		return INTERRUPT_FAIL;
	}
}

//This function sets the interrupt trigger of the external interrupt int 0
En_interruptError_t INTERRUPT_EXTI_int0SetInterruptTrigger(En_interruptTrigger_t interruptTrigger)
{
	//Call the EXT_int0SetInterruptTrigger from the EXTI driver API
	if(EXTI_int0SetInterruptTrigger(interruptTrigger) == EXTI_SUCCESS)
	{
		return INTERRUPT_SUCCESS;
	}
	else
	{
		return INTERRUPT_FAIL;
	}
}