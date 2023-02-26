/*
 * File: button.c
 * Brief: This file contains the implementation of the Button Driver
 * Created: 1/18/2023 9:13:53 AM
 * Author: Abd El-Rahman Kadah
 */ 

#include "button.h"

//This function initializes the pin to which the button is connected to be input.
En_buttonError_t BUTTON_init(En_dioPort_t buttonPort, En_dioPin_t buttonPin)
{
	//Set the buttonPin to be input.
	if(DIO_init(buttonPort, buttonPin, IN) == DIO_SUCCESS)
	{
		return BUTTON_SUCCESS;
	}
	else
	{
		//Return BUTTON_FAIL if there is an error in the DIO_init function.
		return BUTTON_FAIL;
	}
}


//This function reads the state of the pin to which the button is connected and stores it into the pointer value.
En_buttonError_t BUTTON_read(En_dioPort_t buttonPort, En_dioPin_t buttonPin, uint8_t* value)
{
	//Read the buttonPin state and stores it into the pointer value.
	if(DIO_read(buttonPort, buttonPin, value) == DIO_SUCCESS)
	{
		return BUTTON_SUCCESS;
	}	
	else
	{
		//Return BUTTON_FAIL if there is an error in the DIO_read function.
		return BUTTON_FAIL;
	}
}