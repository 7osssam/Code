/******************************************************************************
 *
 * Module: External Interrupt
 *
 * File Name: EXTI.h
 *
 * Description: Header file for External Interrupt Module.
 *
 * Author: Hossam Mohamed
 *
 *******************************************************************************/

#ifndef EXTI_H_
#define EXTI_H_

#include <avr/io.h>

/*******************************************************************************
 * 					       Types Declaration                               	   *
 * *****************************************************************************/
typedef enum
{
	EXTI_INT0,
	EXTI_INT1,
	EXTI_INT2
} EXTI_Interrupt;

typedef enum
{
	low_level,
	any_logical_change,
	falling_edge,
	rising_edge
} EXTI_State;

/*******************************************************************************
 * 								Configuration structure                        *
 * *****************************************************************************/
typedef struct
{
	EXTI_Interrupt interrupt;	  // EX_INT0, EX_INT1, EX_INT2
	EXTI_State	   sense_control; // low_level, any_logical_change, falling_edge, rising_edge
} Interrupt_ConfigType;

/*******************************************************************************
 * 								Functions Prototypes                           *
 * *****************************************************************************/
void EXTI_init(Interrupt_ConfigType* Config_Ptr);
void EXTI_enable(Interrupt_ConfigType* Config_Ptr);
void EXTI_disable(Interrupt_ConfigType* Config_Ptr);

/****************************** Call Back function *****************************/
void EXTI_setCallBack(Interrupt_ConfigType* Config_Ptr, void (*a_ptr)(void));

#endif /* EXTI_H_ */