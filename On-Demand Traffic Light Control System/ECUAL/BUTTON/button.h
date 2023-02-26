/*
 * File: button.h
 * Brief: This file contains the Button Driver typedefs and API
 * Created: 1/18/2023 9:14:08 AM
 *  Author: Abd El-Rahman Kadah
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/dio.h"


#define EXTERNAL_INT_BUTTON_PORT PORT_D
#define EXTERNAL_INT_BUTTON_PIN PIN2

typedef enum
{
	BUTTON_FAIL,
	BUTTON_SUCCESS
	
}En_buttonError_t;



En_buttonError_t BUTTON_init(En_dioPort_t buttonPort, En_dioPin_t buttonPin);
En_buttonError_t BUTTON_read(En_dioPort_t buttonPort, En_dioPin_t buttonPin, uint8_t* value);




#endif /* BUTTON_H_ */