/*
 * File: dio.c
 * Brief: this file contains the DIO Driver implementation
 * Created: 1/17/2023 9:56:43 AM
 * Author: Abd El-Rahman Kadah
 */ 


#include "dio.h"


//This function initializes a given pin of a given port to be input or output.

En_dioError_t DIO_init(En_dioPort_t portNumber, En_dioPin_t pinNumber, En_dioDirection_t direction)
{
	//Validate the input parameters. 
	if ((portNumber < PORT_A) || (portNumber > PORT_D) 
		|| (pinNumber < PIN0) || (pinNumber > PIN7) 
		|| (direction < IN) || (direction > OUT) )
	{
		//Return DIO_FAIL if there is invalid parameter.
		return DIO_FAIL;
	} 
	else
	{
		//Select the required port based on the given portNumber parameter.
		switch(portNumber)
		{
			case PORT_A:
				//Select the data direction based on the given direction parameter.
				if(direction == IN)
				{
					//Clear the DDRA pin based on the given pinNumber parameter if the direction is input.
					CLEAR_BIT(DDRA,pinNumber);
				}
				else if(direction == OUT)
				{
					//Set the DDRA pin based on the given pinNumber parameter if the direction is output.
					SET_BIT(DDRA, pinNumber);
				}
				break;
			case PORT_B:
				if(direction == IN)
				{
					CLEAR_BIT(DDRB,pinNumber);
				}
				else
				{
					SET_BIT(DDRB, pinNumber);
				}
				break;
			case PORT_C:
				if(direction == IN)
				{
					CLEAR_BIT(DDRC,pinNumber);
				}
				else
				{
					SET_BIT(DDRC, pinNumber);
				}
			break;
			case PORT_D:
				if(direction == IN)
				{
					CLEAR_BIT(DDRD,pinNumber);
				}
				else
				{
					SET_BIT(DDRD, pinNumber);
				}
				break;
		}
		//Return DIO_SUCCESS if everything is OK.
		return DIO_SUCCESS;

	}

}

//This function write HIGH or LOW to a given pin of a given port.

En_dioError_t DIO_write(En_dioPort_t portNumber, En_dioPin_t pinNumber, En_dioValue_t value)
{
	//Validate the input parameters.
	if ((portNumber < PORT_A) || (portNumber > PORT_D) 
		|| (pinNumber < PIN0) || (pinNumber > PIN7) 
		|| (value < LOW) || (value > HIGH) )
	{
		//Return DIO_FAIL if there is invalid parameter.
		return DIO_FAIL;
	} 
	else
	{
		//Select the required port based on the given portNumber parameter.
		switch(portNumber)
		{
			case PORT_A:
				//Select the data value if it's high or low based on the given value parameter.
				if(value == HIGH)
				{
					//Set the PORTA pin based on the given pinNumber parameter if the value is HIGH.
					SET_BIT(PORTA,pinNumber);
				}
				else
				{
					//Clear the PORTA pin based on the given pinNumber parameter if the value is LOW.
					CLEAR_BIT(PORTA,pinNumber);
				}
				break;
			case PORT_B:
				if(value == HIGH)
				{
					SET_BIT(PORTB,pinNumber);
				}
				else
				{
					CLEAR_BIT(PORTB,pinNumber);
				}
				break;
			case PORT_C:
				if(value == HIGH)
				{
					SET_BIT(PORTC,pinNumber);
				}
				else
				{
					CLEAR_BIT(PORTC,pinNumber);
				}
				break;
			case PORT_D:
				if(value == HIGH)
				{
					SET_BIT(PORTD,pinNumber);
				}
				else
				{
					CLEAR_BIT(PORTD,pinNumber);
				}
				break;
		}
		//Return DIO_SUCCESS if everything is OK.
		return DIO_SUCCESS;
	}

}

//This function reads the state of a given pin of a given port and stores it into a the pointer variable value.

En_dioError_t DIO_read(En_dioPort_t portNumber, En_dioPin_t pinNumber, uint8_t* value)
{
	//Validate the input parameters.
	if ((portNumber < PORT_A) || (portNumber > PORT_D) || (pinNumber < PIN0) || (pinNumber > PIN7))
	{
		//Return DIO_FAIL if there is invalid parameter.
		return DIO_FAIL;
	} 
	else
	{
		//Select the required port based on the given portNumber parameter.
		switch(portNumber)
		{
			case PORT_A:
				//Read the pin state and stores it into the pointer variable value by dereferencing.
				(*value) = READ_BIT(PINA,pinNumber);
				break;
			case PORT_B:
				(*value) = READ_BIT(PINB,pinNumber);
				break;
			case PORT_C:
				(*value) = READ_BIT(PINC,pinNumber);
				break;
			case PORT_D:
				(*value) = READ_BIT(PIND,pinNumber);
				break;
		}
		//Return DIO_SUCCESS if everything is OK.
		return DIO_SUCCESS;
	}

}

//This function complements/toggles the value of a given pin of a given port.

En_dioError_t DIO_toggle(En_dioPort_t portNumber, En_dioPin_t pinNumber)
{
	//Validate the input parameters.
	if ((portNumber < PORT_A) || (portNumber > PORT_D) || (pinNumber < PIN0) || (pinNumber > PIN7))
	{
		//Return DIO_FAIL if there is invalid parameter.
		return DIO_FAIL;
	}
	else
	{
		//Select the required port based on the given portNumber parameter.
		switch(portNumber)
		{
			case PORT_A:
				//Toggle the PORTA pin based on the given pinNubmer parameter.
				TOGGLE_BIT(PORTA,pinNumber);
				break;
			case PORT_B:
				TOGGLE_BIT(PORTB,pinNumber);
				break;
			case PORT_C:
				TOGGLE_BIT(PORTC,pinNumber);
				break;
			case PORT_D:
				TOGGLE_BIT(PORTD,pinNumber);
				break;
		}
		
		//Return DIO_SUCCESS if everything is OK.
		return DIO_SUCCESS;
	}
}
