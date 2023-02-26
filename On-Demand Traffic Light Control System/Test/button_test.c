/*
 * File: button_test.c
 * Brief: This file tests the implemntation of the Button Driver.
 * Created: 2/12/2023 8:55:09 PM
 * Author: Abd El-Rahman Kadah
 */ 

#if 0

#include "../ECUAL/BUTTON/button.h"


int main(void)
{
	/*
	Function to be tested: Button_init
	How to test: See the microchip simulator to see if the pin to which the button is connected (PIN2)
				is configured as input in the DDRD register.
	
	*/
	BUTTON_init(EXTERNAL_INT_BUTTON_PORT, EXTERNAL_INT_BUTTON_PIN);
	
	/*
	Function to be tested: Button_read
	How to test: See the microchip simulator to see if value variable value is equal to
				the state of the pin to which the button is connected (PIN2) in the PIND register.
	
	*/
	uint8_t value;
	BUTTON_read(EXTERNAL_INT_BUTTON_PORT, EXTERNAL_INT_BUTTON_PIN, &value);
}

#endif