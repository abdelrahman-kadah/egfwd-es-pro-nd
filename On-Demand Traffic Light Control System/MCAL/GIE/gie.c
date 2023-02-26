/*
 * File: gie.c
 * Brief: This file contains the implementation of the GIE Driver
 * Created: 2/8/2023 12:55:40 PM
 * Author: Abd El-Rahman Kadah
 */ 

#include "gie.h"

//This function enables the interrupts globally.

En_gieError_t GIE_enable(void)
{
	//Set the I bit in the status register SREG
	SET_BIT(SREG,I);
	
	return GIE_SUCCESS;
}

//This function disables the interrupts globally.

En_gieError_t GIE_disable(void)
{
	//Clear the I bit in the status register SREG.
	CLEAR_BIT(SREG,I);
	
	return GIE_SUCCESS;
}

