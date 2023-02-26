/*
 * bit_manipulations.h
 *
 * Created: 1/17/2023 9:47:25 AM
 *  Author: abdel
 */ 


#ifndef BIT_MANIPULATIONS_H_
#define BIT_MANIPULATIONS_H_

#define SET_BIT(REGISTER,PIN) (REGISTER |= (1 << PIN))
#define CLEAR_BIT(REGISTER,PIN) (REGISTER &= ~(1 << PIN))
#define TOGGLE_BIT(REGISTER,PIN) (REGISTER ^= (1 << PIN))
#define READ_BIT(REGISTER,PIN) ((REGISTER & (1 << PIN)) >> PIN)


#endif /* BIT_MANIPULATIONS_H_ */