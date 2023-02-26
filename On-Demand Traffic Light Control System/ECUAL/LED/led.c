/*
 * File: led.c
 * Brief: This file contains the LED Driver Implementation
 * Created: 1/17/2023 10:12:10 AM
 *  Author: Abd El-Rahman Kadah
 */ 

#include "led.h"

//This function initializes the pin to which the LED is connected to be Output.

En_ledError_t LED_init(En_dioPort_t ledPort, En_dioPin_t ledPin)
{
	//Call DIO_init() to initialize the given ledPin to be Output
	if(DIO_init(ledPort, ledPin, OUT) == DIO_SUCCESS)
	{
		//Returns LED_SUCCESS if the pin is configured without any errors.
		return LED_SUCCESS;
	}
	else
	{
		//Return LED_FAIL if there is an error in the DIO_init() funciton.
		return LED_FAIL;
	}

}

//This function turns on an LED by setting pin to which the LED is connected to HIGH.

En_ledError_t LED_on(En_dioPort_t ledPort, En_dioPin_t ledPin)
{
	//Set ledPin to HIGH.
	if(DIO_write(ledPort, ledPin, HIGH) == DIO_SUCCESS)
	{
		return LED_SUCCESS;
	}
	else
	{
		return LED_FAIL;
	}
}

//This function turns off an LED by setting pin to which the LED is connected to LOW.

En_ledError_t LED_off(En_dioPort_t ledPort, En_dioPin_t ledPin)
{
	//Set ledPin to LOW.
	if(DIO_write(ledPort, ledPin, LOW) == DIO_SUCCESS)
	{
		return LED_SUCCESS;
	}
	else
	{
		return LED_FAIL;
	}
}

//This function reads the LED state (HIGH/ON or LOW/OFF) and stores it into the pointer data.

En_ledError_t LED_read(En_dioPort_t ledPort, En_dioPin_t ledPin, uint8_t* data)
{
	//Read the ledPin state and store it into the pointer data
	if(DIO_read(ledPort, ledPin, data) == DIO_SUCCESS)
	{
		return LED_SUCCESS;
	}
	else
	{
		return LED_FAIL;
	}
}

//This function toggles the pin to which the LED is connected.
En_ledError_t LED_toggle(En_dioPort_t ledPort, En_dioPin_t ledPin)
{
	//Toggle ledPin
	if(DIO_toggle(ledPort, ledPin) == DIO_SUCCESS)
	{
		return LED_SUCCESS;
	}
	else
	{
		return LED_FAIL;
	}
}