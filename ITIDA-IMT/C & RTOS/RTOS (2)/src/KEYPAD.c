/******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: KEYPAD.c
 *
 * Description: Source file for the Keypad driver
 *
 * Author: Hossam Mohamed & Mohamed Tarek
 *
 *******************************************************************************/
#include "KEYPAD.h"
#include "GPIO.h"

#include "SETTINGS.h"
#include <util/delay.h>

/*******************************************************************************
 *                       Private Variables                                     *
 *******************************************************************************/
#ifdef STANDARD_KEYPAD /* for eta32mini kit */
	#if (KEYPAD_NUM_COLS == 3)
static unit8 KEYPAD_4x3[KEYPAD_NUM_ROWS][KEYPAD_NUM_COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {'*', 0, '#'}};

	#elif (KEYPAD_NUM_COLS == 4)
static uint8 KEYPAD_4x4[KEYPAD_NUM_ROWS][KEYPAD_NUM_COLS] = {
	{7, 8, 9, '/'}, {4, 5, 6, '*'}, {1, 2, 3, '-'}, {'C', 0, '=', '+'}};
	#endif /* KEYPAD_NUM_COLS */
#endif	   /* STANDARD_KEYPAD */

/*******************************************************************************
 *                      Functions Definitions                                  **
 *******************************************************************************/

uint8 KEYPAD_getPressedKey(void)
{
	uint8 col, row;
	GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID, PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID + 1, PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID + 2, PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID + 3, PIN_INPUT);

	GPIO_setupPinDirection(KEYPAD_COL_PORT_ID, KEYPAD_FIRST_COL_PIN_ID, PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_COL_PORT_ID, KEYPAD_FIRST_COL_PIN_ID + 1, PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_COL_PORT_ID, KEYPAD_FIRST_COL_PIN_ID + 2, PIN_INPUT);
#if (KEYPAD_NUM_COLS == 4)
	GPIO_setupPinDirection(KEYPAD_COL_PORT_ID, KEYPAD_FIRST_COL_PIN_ID + 3, PIN_INPUT);
#endif
	while (1)
	{
		for (row = 0; row < KEYPAD_NUM_ROWS; row++) /* loop for rows */
		{
			/*
			 * Each time setup the direction for all keypad port as input pins,
			 * except this row will be output pin
			 */
			GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID + row, PIN_OUTPUT);

			/* Set/Clear the row output pin */
			GPIO_writePin(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID + row, KEYPAD_BUTTON_PRESSED);

			for (col = 0; col < KEYPAD_NUM_COLS; col++) /* loop for columns */
			{
				/* Check if the switch is pressed in this column */
				if (GPIO_readPin(KEYPAD_COL_PORT_ID, KEYPAD_FIRST_COL_PIN_ID + col) == KEYPAD_BUTTON_PRESSED)
				{
#if (KEYPAD_NUM_COLS == 3)
	#ifdef STANDARD_KEYPAD
					// return KEYPAD_4x3_adjustKeyNumber((row * KEYPAD_NUM_COLS) + col + 1);
					return KEYPAD_4x3[row][col];
	#else
					return ((row * KEYPAD_NUM_COLS) + col + 1);
	#endif
#elif (KEYPAD_NUM_COLS == 4)
	#ifdef STANDARD_KEYPAD
					// return KEYPAD_4x4_adjustKeyNumber((row * KEYPAD_NUM_COLS) + col + 1);
					return KEYPAD_4x4[row][col];
	#else
					return ((row * KEYPAD_NUM_COLS) + col + 1);
	#endif

#endif					  /* KEYPAD_NUM_COLS */
				}
			}
			GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID + row, PIN_INPUT);
			_delay_ms(5); /* Add small delay to fix CPU load issue in proteus */
		}
	}
}
