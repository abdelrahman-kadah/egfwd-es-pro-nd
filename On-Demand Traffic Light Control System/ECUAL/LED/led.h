/*
 * File: led.h
 * Brief: This file contains the LED Driver typedefs and API
 * Created: 1/17/2023 10:11:36 AM
 *  Author: Abd El-Rahman Kadah
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/dio.h"


//Cars' LEDs
#define CAR_GREEN_LED_PORT PORT_A
#define CAR_GREEN_LED_PIN PIN0

#define CAR_YELLOW_LED_PORT PORT_A
#define CAR_YELLOW_LED_PIN PIN1

#define CAR_RED_LED_PORT PORT_A
#define CAR_RED_LED_PIN PIN2

//Pedestrian's LEDs
#define PED_GREEN_LED_PORT PORT_B
#define PED_GREEN_LED_PIN PIN0

#define PED_YELLOW_LED_PORT PORT_B
#define PED_YELLOW_LED_PIN PIN1

#define PED_RED_LED_PORT PORT_B
#define PED_RED_LED_PIN PIN2

typedef enum
{
	LED_FAIL,
	LED_SUCCESS
}En_ledError_t;


En_ledError_t LED_init(En_dioPort_t ledPort, En_dioPin_t ledPin);
En_ledError_t LED_on(En_dioPort_t ledPort, En_dioPin_t ledPin);
En_ledError_t LED_off(En_dioPort_t ledPort, En_dioPin_t ledPin);
En_ledError_t LED_toggle(En_dioPort_t ledPort, En_dioPin_t ledPin);
En_ledError_t LED_read(En_dioPort_t ledPort, En_dioPin_t ledPin, uint8_t* data);




#endif /* LED_H_ */