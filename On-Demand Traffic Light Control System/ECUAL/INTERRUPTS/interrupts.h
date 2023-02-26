/*
 * File: interrupts.h
 * Brief: This file contains the typedefs and API for the Interrupt Driver
 * Created: 2/13/2023 11:18:54 AM
 *  Author: Abd El-Rahman Kadah
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "../../MCAL/EXTI/exti.h"
#include "../../MCAL/GIE/gie.h"

typedef enum
{
	INTERRUPT_FAIL,
	INTERRUPT_SUCCESS
}En_interruptError_t;

En_interruptError_t INTERRUPT_GIE_enable(void);
En_interruptError_t INTERRUPT_GIE_disable(void);
En_interruptError_t INTERRUPT_EXTI_int0Init(void);
En_interruptError_t INTERRUPT_EXTI_int0SetCallback(void(*int0Func)(void));
En_interruptError_t INTERRUPT_EXTI_int0SetInterruptTrigger(En_interruptTrigger_t interruptTrigger);

	




#endif /* INTERRUPTS_H_ */