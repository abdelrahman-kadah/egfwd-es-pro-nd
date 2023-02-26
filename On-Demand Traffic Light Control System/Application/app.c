/*
 * File: app.c
 * Brief: This file contains the implementation of the application.
 * Created: 2/8/2023 1:25:12 PM
 *  Author: Abd El-Rahman Kadah
 */ 




#include "app.h"

void enterNormalState(void);
void enterPedestrianState(void);
void enterPedestrianCrossingState(void);
void enterPedestrainWaitingState(void);

//This function initializes the application.

En_appError_t APP_init(void)
{
	//Initialize the pin to which the button is connected to be input.
	BUTTON_init(EXTERNAL_INT_BUTTON_PORT, EXTERNAL_INT_BUTTON_PIN);
	
	//Initialize the pins to which the LEDs are connected to be output.
	LED_init(CAR_RED_LED_PORT, CAR_RED_LED_PIN);
	LED_init(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN);
	LED_init(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN);
	
	LED_init(PED_RED_LED_PORT, PED_RED_LED_PIN);
	LED_init(PED_YELLOW_LED_PORT, PED_YELLOW_LED_PIN);
	LED_init(PED_GREEN_LED_PORT, PED_GREEN_LED_PIN);
	
	/*Initialize the external interrupt to be triggered on the falling edge of input signal.
	 If the button connection to the MCU is pull down, then this type of trigger handles
	 the long press event properly.
	*/
	INTERRUPT_EXTI_int0SetInterruptTrigger(FALLING_EDGE);
	
	//Set the pedestrian mode to be call backed from the external interrupt 0 ISR
	INTERRUPT_EXTI_int0SetCallback(enterPedestrianState);
	
	//Enable the interrupts globally.
	INTERRUPT_GIE_enable();
	
	//Enable the external interrupt 0
	INTERRUPT_EXTI_int0Init();
	
	return APP_SUCCESS;
	
}


//This function starts the application.

En_appError_t APP_start(void)
{
	//Repeatedly execute the normal state when the application is just started
	//until the pedestrian button is pressed.
	while(1)
	{
		enterNormalState();
	}
}

//This function starts the pedestrian crossing state.
void enterPedestrianCrossingState(void)
{
	LED_off(PED_RED_LED_PORT, PED_RED_LED_PIN);
	LED_on(CAR_RED_LED_PORT, CAR_RED_LED_PIN);
	LED_on(PED_GREEN_LED_PORT, PED_GREEN_LED_PIN);
	setDelayInMsec(5000);
	
	
	//Exit Activity
	
	LED_off(CAR_RED_LED_PORT, CAR_RED_LED_PIN);
	
	for(uint8_t i = 0; i < 5; i++)
	{
		LED_toggle(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN);
		LED_toggle(PED_YELLOW_LED_PORT, PED_YELLOW_LED_PIN);
		setDelayInMsec(1000);
	}
	
	LED_off(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN);
	LED_off(PED_YELLOW_LED_PORT, PED_YELLOW_LED_PIN);
	
	LED_off(PED_GREEN_LED_PORT, PED_GREEN_LED_PIN);
	
	LED_on(PED_RED_LED_PORT, PED_RED_LED_PIN);
	LED_on(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN);
}

//This function starts the pedestrian waiting state.

void enterPedestrainWaitingState(void)
{
	LED_on(PED_RED_LED_PORT, PED_RED_LED_PIN);
	
	for(uint8_t i = 0; i < 5; i++)
	{
		LED_toggle(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN);
		LED_toggle(PED_YELLOW_LED_PORT, PED_YELLOW_LED_PIN);
		setDelayInMsec(1000);
	}
	
	LED_off(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN);
	LED_off(PED_YELLOW_LED_PORT, PED_YELLOW_LED_PIN);
	
	LED_off(PED_RED_LED_PORT, PED_RED_LED_PIN);
	LED_off(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN);

			
}

//This function starts the normal state of the system.
void enterNormalState(void)
{
	LED_on(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN);
	setDelayInMsec(5000);
	
	for(uint8_t i = 0; i < 5; i++)
	{
		LED_toggle(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN);
		setDelayInMsec(1000);
	}
	
	LED_off(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN);
	LED_off(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN);
	
	LED_on(CAR_RED_LED_PORT, CAR_RED_LED_PIN);
	setDelayInMsec(5000);

	for(uint8_t i = 0; i < 5; i++)
	{
		LED_toggle(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN);
		setDelayInMsec(1000);
	}
	LED_off(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN);
	LED_off(CAR_RED_LED_PORT, CAR_RED_LED_PIN);
}

//This function starts the pedestrian state of the system when the button is pressed.
void enterPedestrianState(void)
{
	uint8_t carRedLEDState;
	uint8_t carGreenLEDState;
	uint8_t carYellowLEDState;
	
	uint8_t pedRedLEDState;
	uint8_t pedGreenLEDState;
	uint8_t pedYellowLEDState;
	
	
	//1. Read the LED states.
	LED_read(CAR_RED_LED_PORT, CAR_RED_LED_PIN, &carRedLEDState);
	LED_read(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN, &carGreenLEDState);
	LED_read(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN, &carYellowLEDState);
	
	LED_read(PED_RED_LED_PORT, PED_RED_LED_PIN, &pedRedLEDState);
	LED_read(PED_GREEN_LED_PORT, PED_GREEN_LED_PIN, &pedGreenLEDState);
	LED_read(PED_YELLOW_LED_PORT, PED_YELLOW_LED_PIN, &pedYellowLEDState);
	
	/*2. If the cars' red LED is ON and the ped's green LED is OFF:
			The traffic light system must go into the pedestrian crossing state
			where the pedestrian is crossing the street, then the system goes into 
			the normal state.
		
		If the car's green LED is ON and the ped's red LED is OFF:
			the traffic light system must go into the pedestrian waiting state 
			where the pedestrian must wait for some time before being able to cross
			the street, then the system goes into the pedestrian crossing state,
			then the system goes into the normal state.
		
		If the the cars' yellow LED is blinking and the ped's red LED is ON:
			the traffic light system must go into the pedestrian waiting state
			where the pedestrian must wait for some time before being able to cross
			the street, then the system goes into the pedestrian crossing state,
			the the system goes into the normal state.
		*/
	
	if((carRedLEDState == HIGH) && (pedGreenLEDState == LOW))
	{
		enterPedestrianCrossingState();
	}
	else if(((carGreenLEDState == HIGH) && (pedRedLEDState == LOW))
	        || ((carYellowLEDState == HIGH) && (pedRedLEDState == HIGH)))
	{
		enterPedestrainWaitingState();
		enterPedestrianCrossingState();

	}

}