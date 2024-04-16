/******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.h
 *
 * Description: Header file for the LCD driver
 *
 * Author: Hossam Mohamed & Mohamed Tarek
 *
 *******************************************************************************/

#ifndef LCD_H_
#define LCD_H_

#include "STD_TYPES.h"

/*******************************************************************************
 *                                LCD Commands                                 *
 *******************************************************************************/
#define LCD_CLEAR_COMMAND				   0x01 /* replace all characters with ASCII 'space' */
#define LCD_GO_TO_HOME					   0x02 /* return cursor to first position on first line */
#define LCD_DECREMENT_CURSOR			   0x04 /* shift cursor to left */
#define LCD_INCREMENT_CURSOR			   0x06 /* shift cursor to right */
#define LCD_SHIFT_DISPLAY_RIGHT			   0x05 /* shift display to right */
#define LCD_SHIFT_DISPLAY_LEFT			   0x07 /* shift display to left */
#define LCD_CURSOR_BLINK				   0x0F /* (cursor on, blink char */
#define LCD_SHIFT_CURSOR_POSITION_TO_LEFT  0x10 /* (shift cursor to left) */
#define LCD_TWO_LINES_EIGHT_BITS_MODE	   0x38 /* 0x38 for 8-bit mode */
#define LCD_TWO_LINES_FOUR_BITS_MODE	   0x28 /* 0x28 for 4-bit mode */
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1 0x33 /* 0x33 for 4-bit mode */
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2 0x32 /* 0x32 for 4-bit mode */
#define LCD_CURSOR_OFF					   0x0C /* when cursor is off, no need to blink */
#define LCD_CURSOR_ON					   0x0E /* when cursor is on, no need to blink */
#define LCD_SET_CURSOR_LOCATION			   0x80 /* Set cursor position in DDRAM */

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_init(void);

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(uint8 command);

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_Goto_XY(uint8 row, uint8 col);

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayCharacter(uint8 data);

/*
 * Description :
 * Display the required string on the screen
 */
void LCD_displayString(const char* Str);

/*
 * Description :
 * Display the required string in the center of the screen of specified row
 */
void LCD_displayStringCenter(uint8 row, const char* Str);

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(uint8 row, uint8 col, const char* Str);

/*
 * Description :
 * Display special character at a specified location on the screen (GDDRAM)
 */
void LCD_displaySpecialCharacter(uint8* Pattern, uint8 Location);

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_displayInteger(sint32 num);

/*
 * Description :
 * Display the required float value on the screen
 */
void LCD_displayFloat(float32 num, uint8 numAfterDecimal);

/*
 * Description :
 * Display Binary number on the screen (8-bits)
 */
void LCD_displayBinary(uint8 num);

/*
 * Description :
 * Display Hexadecimal number on the screen (8-bits)
 */
void LCD_displayHex(uint8 num);

/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(void);

#endif /* LCD_H_ */
