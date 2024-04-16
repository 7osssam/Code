/******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: KEYPAD.h
 *
 * Description: Header file for the Keypad driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "STD_TYPES.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define STANDARD_KEYPAD

/* Keypad configurations for number of rows and columns */
#define KEYPAD_NUM_COLS			4
#define KEYPAD_NUM_ROWS			4

/* Keypad Port Configurations */
#define KEYPAD_ROW_PORT_ID		PORTA_ID
#define KEYPAD_FIRST_ROW_PIN_ID PIN0_ID

#define KEYPAD_COL_PORT_ID		PORTA_ID
#define KEYPAD_FIRST_COL_PIN_ID PIN4_ID

/* Keypad button logic configurations */
#define KEYPAD_BUTTON_PRESSED	LOGIC_LOW
#define KEYPAD_BUTTON_RELEASED	LOGIC_HIGH

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Get the Keypad pressed button
 */
uint8 KEYPAD_getPressedKey(void);

#endif /* KEYPAD_H_ */
