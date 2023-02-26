/*
 * File: led_test.c
 * Brief: This file tests the implementation of the LED Driver
 * Created: 2/12/2023 8:21:07 PM
 *  Author: Abd El-Rahman Kadah
 */ 

#if 0

#include "../ECUAL/LED/led.h"

int main(void)
{	
	/*
	Function to be tested: LED_init()
	How to test: See the microchip simulator to make sure that pin connected to each LED (PIN0, PIN1, and PIN2)
				 is set to 1 (OUT) in the DDRA and the DDRB Register.
	*/
	LED_init(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN);
	LED_init(CAR_RED_LED_PORT, CAR_RED_LED_PIN);
	LED_init(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN);
	
	LED_init(PED_GREEN_LED_PORT, PED_GREEN_LED_PIN);
	LED_init(PED_RED_LED_PORT, PED_RED_LED_PIN);
	LED_init(PED_YELLOW_LED_PORT, PED_YELLOW_LED_PIN);
	
	
	/*
	Function to be tested: LED_on()
	How to test: See the microchip simulator to make sure that pin connected to each LED (PIN0, PIN1, and PIN2)
				 is set to 1 (HIGH) in the PORTA and the PORTB Register.
	*/
	LED_on(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN);
	LED_on(CAR_RED_LED_PORT, CAR_RED_LED_PIN);
	LED_on(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN);
	
	LED_on(PED_GREEN_LED_PORT, PED_GREEN_LED_PIN);
	LED_on(PED_RED_LED_PORT, PED_RED_LED_PIN);
	LED_on(PED_YELLOW_LED_PORT, PED_YELLOW_LED_PIN);
	
	
	/*
	Function to be tested: LED_off()
	How to test: See the microchip simulator to make sure that pin connected to each LED (PIN0, PIN1, and PIN2)
		        is set to 0 (LOW) in the PORTA and the PORTB Register.
	*/
	
	LED_off(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN);
	LED_off(CAR_RED_LED_PORT, CAR_RED_LED_PIN);
	LED_off(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN);
	
	LED_off(PED_GREEN_LED_PORT, PED_GREEN_LED_PIN);
	LED_off(PED_RED_LED_PORT, PED_RED_LED_PIN);
	LED_off(PED_YELLOW_LED_PORT, PED_YELLOW_LED_PIN);
	
	/*
	Function to be tested:LED_toggle()
	How to test: See the microchip simulator to make sure that pin connected to each LED (PIN0, PIN1, and PIN2)
		         is toggled from 0 to 1 or from 1 to 0 (LOW) in the PORTA and the PORTB Register.
	*/
	
	LED_toggle(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN);
	LED_toggle(CAR_RED_LED_PORT, CAR_RED_LED_PIN);
	LED_toggle(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN);
	
	LED_toggle(PED_GREEN_LED_PORT, PED_GREEN_LED_PIN);
	LED_toggle(PED_RED_LED_PORT, PED_RED_LED_PIN);
	LED_toggle(PED_YELLOW_LED_PORT, PED_YELLOW_LED_PIN);
	
	
	/*
	Function to be tested: LED_read()
	How to test: See the microchip simulator to make sure that data variable value is equal  to
				 the state of the pin connected to each LED (PIN0, PIN1, and PIN2) in the PINA and the PINB Register.
	*/
	
	uint8_t data;
	LED_read(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN, &data);
	LED_read(CAR_RED_LED_PORT, CAR_RED_LED_PIN, &data);
	LED_read(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN, &data);
	
	LED_read(PED_GREEN_LED_PORT, PED_GREEN_LED_PIN, &data);
	LED_read(PED_RED_LED_PORT, PED_RED_LED_PIN, &data);
	LED_read(PED_YELLOW_LED_PORT, PED_YELLOW_LED_PIN, &data);
	
}

#endif

