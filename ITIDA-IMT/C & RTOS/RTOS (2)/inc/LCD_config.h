/******************************************************************************
 *
 * Module: LCD
 *
 * File Name: LCD_config.h
 *
 * Description: Configuration file for the LCD driver
 *
 * Author: Hossam Mohamed
 *
 *******************************************************************************/

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/* LCD Modes */
#define _8_BIT_MODE		   8
#define _4_BIT_MODE		   4

/* LCD Number of lines and Number of dot matrix */
#define LCD_NUM_LINES	   2
#define LCD_NUM_POSITIONS  16

#define LCD_FIRST_LINE	   0x00
#define LCD_SECOND_LINE	   0x40

/* LCD Data bits mode configuration, its value should be 4 or 8*/
#define LCD_DATA_BITS_MODE _8_BIT_MODE

#if ((LCD_DATA_BITS_MODE != _4_BIT_MODE) && (LCD_DATA_BITS_MODE != _8_BIT_MODE))

	#error "Number of Data bits should be equal to 4 or 8"

#endif

/* LCD RS pin configuration */
#define LCD_RS_PORT_ID	 PORTC_ID
#define LCD_RS_PIN_ID	 PIN0_ID

/* LCD E pin configuration */
#define LCD_E_PORT_ID	 PORTC_ID
#define LCD_E_PIN_ID	 PIN2_ID

#define LCD_DATA_PORT_ID PORTB_ID

#if (LCD_DATA_BITS_MODE == _4_BIT_MODE)

	#define LCD_DB4_PIN_ID PIN3_ID
	#define LCD_DB5_PIN_ID PIN4_ID
	#define LCD_DB6_PIN_ID PIN5_ID
	#define LCD_DB7_PIN_ID PIN6_ID

#endif

#endif /* LCD_CONFIG_H_ */