/*
 * File: app.h
 * Brief: This file contains the Application typedefs and interace
 * Created: 2/8/2023 1:25:03 PM
 * Author: Abd El-Rahman Kadah
 */ 


#ifndef APP_H_
#define APP_H_

#include "../ECUAL/LED/led.h"
#include "../ECUAL/DELAY/delay.h"
#include "../ECUAL/INTERRUPTS/interrupts.h"
#include "../ECUAL/BUTTON/button.h"

typedef enum
{
	APP_FAIL,
	APP_SUCCESS
}En_appError_t;

En_appError_t APP_init(void);
En_appError_t APP_start(void);



#endif /* APP_H_ */