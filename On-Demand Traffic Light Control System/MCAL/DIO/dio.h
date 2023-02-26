/*
 * File: dio.h
 * Brief: This file contains the DIO Driver typedefs and API interface
 * Created: 1/17/2023 9:56:35 AM
 * Author: Abd El-Rahman Kadah
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/registers.h"
#include "../../Utilities/types.h"
#include "../../Utilities/bit_manipulations.h"

typedef enum
{
	DIO_SUCCESS, DIO_FAIL
}En_dioError_t;

typedef enum
{
	PORT_A, PORT_B, PORT_C, PORT_D
	
}En_dioPort_t;

typedef enum
{
	PIN0, PIN1, PIN2, PIN3,
	PIN4, PIN5, PIN6, PIN7
}En_dioPin_t;

typedef enum
{
	IN, OUT
}En_dioDirection_t;

typedef enum
{
	LOW, HIGH
}En_dioValue_t;


En_dioError_t DIO_init(En_dioPort_t portNumber, En_dioPin_t pinNumber, En_dioDirection_t direction);
En_dioError_t DIO_write(En_dioPort_t portNumber, En_dioPin_t pinNumber, En_dioValue_t value);
En_dioError_t DIO_read(En_dioPort_t portNumber, En_dioPin_t pinNumber, uint8_t* value);
En_dioError_t DIO_toggle(En_dioPort_t portNumber, En_dioPin_t pinNumber);



#endif /* DIO_H_ */