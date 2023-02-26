/*
 * File gie_test.c
 * Brief: This file tests the implementation of the GIE Driver
 * Created: 2/12/2023 6:46:07 PM
 * Author: Abd El-Rahman Kadah
 */ 


#if 0

#include "../MCAL/GIE/gie.h"

int main(void)
{
	/*
	Function to be tested: GIE_enable
	How to test: Check the I bit in the SREG to see if it's set.
	*/
	
	GIE_enable();
	
    /*
	Function to be tested: GIE_disable
	How to test: Check the I bit in the SREG to see if it's cleared.
	*/
	
	GIE_disable();
}

#endif