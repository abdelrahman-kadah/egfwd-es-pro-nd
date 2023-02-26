/*
 * File: gie.h
 * Brief: This file contains the global interrupt GIE Driver typedefs and APIs 
 * Created: 2/8/2023 12:55:31 PM
 *  Author: Abd El-Rahman Kadah
 */ 


#ifndef GIE_H_
#define GIE_H_

#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulations.h"

typedef enum
{
	GIE_FAIL,
	GIE_SUCCESS
}En_gieError_t;

#define I 7

En_gieError_t GIE_enable(void);
En_gieError_t GIE_disable(void);


#endif /* GIE_H_ */