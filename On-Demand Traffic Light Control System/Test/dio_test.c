/*
 * File: dio_test.c
 * Brief: This file tests the implementation of the DIO Driver
 * Created: 2/12/2023 4:52:43 PM
 * Author: Abd El-Rahman Kadah
 */ 

#if 0

#include "../MCAL/DIO/dio.h"

int main(void)
{
	/*
	Function to be tested: DIO_init
	How to test: See the microchip simulator to see if the direction of the given pin of the register DDRx changes
				with the change of the pinDirection or not.
	
	*/
	for(uint8_t portNumber = 0; portNumber < 4; portNumber++)
	{
		for(uint8_t pinNumber = 0; pinNumber < 8; pinNumber++)
		{
			for(uint8_t pinDirection = 0; pinDirection < 2; pinDirection++)
			{
				DIO_init(portNumber, pinNumber, pinDirection);
			}
		}
	}
	
	
	
	/*
	Function to be tested: DIO_write
	How to test: See the microchip simulator to see if the value of the given pin of the register PORTx changes
				 with the change of the pinValue or not.
	*/
	for(uint8_t portNumber = 0; portNumber < 4; portNumber++)
	{
		for(uint8_t pinNumber = 0; pinNumber < 8; pinNumber++)
		{
			for(uint8_t pinValue = 0; pinValue < 2; pinValue++)
			{
				DIO_write(portNumber, pinNumber, pinValue);
			}
		}
	}
	
	/*
	Function to be tested: DIO_read
	How to test: See the microchip simulator with each iteration to see if the pinValue changes according
	             to actual state of the pin of the register PINx or not.
	
	*/
	
	volatile uint8_t pinValue;
	for(uint8_t portNumber = 0; portNumber < 4; portNumber++)
	{
		for(uint8_t pinNumber = 0; pinNumber < 8; pinNumber++)
		{
			DIO_read(portNumber, pinNumber, &pinValue);
		}
	}
	
	/*
	Function to be tested: DIO_toggle
	How to test: See the microchip simulator to see if the value of the given pin of the register PORTx is toggled.
	*/
	for(uint8_t portNumber = 0; portNumber < 4; portNumber++)
	{
		for(uint8_t pinNumber = 0; pinNumber < 8; pinNumber++)
		{
			DIO_toggle(portNumber, pinNumber);
		}
	}
}

#endif