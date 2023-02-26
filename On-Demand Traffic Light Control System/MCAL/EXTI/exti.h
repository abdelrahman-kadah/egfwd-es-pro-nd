/*
 * File: exti.h
 * Brief: This file contains the External Interrupts EXTI Driver typedefs and API.
 * Created: 2/8/2023 12:59:23 PM
 *  Author: Abd El-Rahman Kadah
 */ 


#ifndef EXTI_H_
#define EXTI_H_

#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulations.h"
#include "../../Utilities/types.h"
#include <stddef.h>


#define EXT_INT0 __vector_1

#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

//Interrupt Sense Control Bits in MCUCR Register
#define ISC00 0
#define ISC01 1

//External Interrupt 0 Bit in GICR Register
#define INT0 6

typedef enum
{
	FALLING_EDGE,
	RISING_EDGE,
	ANY_LOGICAL_CHANGE,
	LOW_LEVEL
}En_interruptTrigger_t;

typedef enum
{
	EXTI_FAIL,
	EXTI_SUCCESS
}En_extiError_t;

En_extiError_t EXTI_int0Init(void);
En_extiError_t EXTI_int0SetCallback(void(*int0Func)(void));
En_extiError_t EXTI_int0SetInterruptTrigger(En_interruptTrigger_t interruptTrigger);



#endif /* EXTI_H_ */