/******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.c
 *
 * Description: Source file for the LCD driver
 *
 * Author: Hossam Mohamed & Mohamed Tarek
 *
 *******************************************************************************/
#include "BIT_MACROS.h"
#include "SETTINGS.h"

#include "LCD_config.h"
#include <util/delay.h> /* For the delay functions */

#include "GPIO.h"
#include "LCD.h"

#include <stdlib.h> // for itoa() function and dtostrf()
/*******************************************************************************
 *                      private Functions                                      *
 *******************************************************************************/
/*
 * Description :
 * convert the integer number to string and store it in the array
 * Parameters  :
 * num : the number to be converted
 * str : the array that will store the string
 * static : because this function is only used in this file
 */
// static void intToSting(int num, unsigned char *str) // convert int to string
//{
//	int i = 0;			// index
//	int isNegative = 0; // flag

//	if (num < 0) // if the number is negative
//	{
//		isNegative = 1; // set the flag
//		num = num * -1; // make the number positive
//	}

//	do // we use do while to make sure that the loop will run at least once even if the number is 0
//	{
//		int mod = num % 10;	  // get the remainder
//		str[i++] = mod + '0'; // convert the remainder to char and put it in the array and increment the index

//		num = num / 10; // update the number (remove the last digit)

//	} while (num > 0); // num is positive

//	if (isNegative) // if the number is negative
//	{
//		str[i++] = '-'; // put the negative sign at the end of the string and increment the index
//	}
//	str[i] = 0; //! null at the end

//	/*
//	 the array of this number is reversed
//	 so we need to reverse it (we can use the function we made before)
//	 but this is better because we didn't stringlength function,
//	 we already have the index of the last char in the array (i)
//	! but note that i is the index of the null char so we need to decrement it by 1
//	*/

//	i--; // decrement i by 1

//	for (int k = 0; k <= i / 2; k++) // don't forget = in <= (if the number is 2 digits)
//	{
//		char temp = str[k];
//		str[k] = str[i - k];
//		str[i - k] = temp;
//	}
//}

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_init(void)
{
	/* Configure the direction for RS and E pins as output pins */
	GPIO_setupPinDirection(LCD_RS_PORT_ID, LCD_RS_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_E_PORT_ID, LCD_E_PIN_ID, PIN_OUTPUT);

	_delay_ms(20); /* LCD Power ON delay always > 15ms */

#if (LCD_DATA_BITS_MODE == _4_BIT_MODE)
	/* Configure 4 pins in the data port as output pins */
	GPIO_setupPinDirection(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, PIN_OUTPUT);

	/* Send for 4 bit initialization of LCD  */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

	/* use 2-lines LCD + 4-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);

#elif (LCD_DATA_BITS_MODE == _8_BIT_MODE)
	/* Configure the data port as output port */
	GPIO_setupPortDirection(LCD_DATA_PORT_ID, PORT_OUTPUT);

	/* use 2-lines LCD + 8-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);

#endif

	LCD_sendCommand(LCD_CURSOR_OFF);	/* cursor off */
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* clear LCD at the beginning */
}

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(uint8 command)
{
	GPIO_writePin(LCD_RS_PORT_ID, LCD_RS_PIN_ID, LOGIC_LOW); /* Instruction Mode RS=0 */
	_delay_ms(1);											 /* delay for processing Tas = 50ns */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH);	 /* Enable LCD E=1 */
	_delay_ms(1);											 /* delay for processing Tpw - Tdws = 190ns */

#if (LCD_DATA_BITS_MODE == _4_BIT_MODE)
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, READ_BIT(command, 4));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, READ_BIT(command, 5));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, READ_BIT(command, 6));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, READ_BIT(command, 7));

	_delay_ms(1);											/* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW);	/* Disable LCD E=0 */
	_delay_ms(1);											/* delay for processing Th = 13ns */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1);											/* delay for processing Tpw - Tdws = 190ns */

	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, READ_BIT(command, 0));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, READ_BIT(command, 1));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, READ_BIT(command, 2));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, READ_BIT(command, 3));

	_delay_ms(1);										   /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1);										   /* delay for processing Th = 13ns */

#elif (LCD_DATA_BITS_MODE == _8_BIT_MODE)
	GPIO_writePort(LCD_DATA_PORT_ID, command); /* out the required command to the data bus D0 --> D7 */
	_delay_ms(1);							   /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1);										   /* delay for processing Th = 13ns */
#endif
}

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_Goto_XY(uint8 row, uint8 col)
{
	uint8 lcd_memory_address = 0;

	/* Calculate the required address in the LCD DDRAM */
	switch (row)
	{
		case 0:
			lcd_memory_address = col;
			break;
		case 1:
			lcd_memory_address = col + 0x40;
			break;
		case 2:
			lcd_memory_address = col + 0x10;
			break;
		case 3:
			lcd_memory_address = col + 0x50;
			break;
	}
	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayCharacter(uint8 data)
{
	GPIO_writePin(LCD_RS_PORT_ID, LCD_RS_PIN_ID, LOGIC_HIGH); /* Data Mode RS=1 */
	_delay_ms(1);											  /* delay for processing Tas = 50ns */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH);	  /* Enable LCD E=1 */
	_delay_ms(1);											  /* delay for processing Tpw - Tdws = 190ns */

#if (LCD_DATA_BITS_MODE == 4)
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, READ_BIT(data, 4));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, READ_BIT(data, 5));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, READ_BIT(data, 6));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, READ_BIT(data, 7));

	_delay_ms(1);											/* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW);	/* Disable LCD E=0 */
	_delay_ms(1);											/* delay for processing Th = 13ns */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1);											/* delay for processing Tpw - Tdws = 190ns */

	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, READ_BIT(data, 0));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, READ_BIT(data, 1));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, READ_BIT(data, 2));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, READ_BIT(data, 3));

	_delay_ms(1);										   /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1);										   /* delay for processing Th = 13ns */

#elif (LCD_DATA_BITS_MODE == 8)
	GPIO_writePort(LCD_DATA_PORT_ID, data); /* out the required command to the data bus D0 --> D7 */
	_delay_ms(1);							/* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1);										   /* delay for processing Th = 13ns */
#endif
}

/*
 * Description :
 * Display the required string on the screen
 */
void LCD_displayString(const char* Str)
{
	uint8 i = 0;
	while (Str[i] != '\0')
	{
		LCD_displayCharacter(Str[i]);
		i++;
	}
}

/*
 * Description :
 * Display the required string in the center of the screen of specified row
 */
void LCD_displayStringCenter(uint8 row, const char* Str)
{
	uint8 postion = 0;
	while (Str[postion] != '\0')
	{
		postion++;
	}
	LCD_Goto_XY(row, (LCD_NUM_POSITIONS - postion) / 2); /* go to to the required LCD position */
	LCD_displayString(Str);								 /* display the string */
}

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(uint8 row, uint8 col, const char* Str)
{
	LCD_Goto_XY(row, col);	/* go to to the required LCD position */
	LCD_displayString(Str); /* display the string */
}

/*
 * Description :
 * Display special character at a specified location on the screen (GDDRAM)
 */
void LCD_displaySpecialCharacter(uint8* Pattern, uint8 Location)
{
	uint8 iLoop;
	uint8 CGRAMAddress = 0x40 + (Location * 8); /* Set CGRAM Address */

	/* Send the Special Character Pattern to CGRAM */
	LCD_sendCommand(CGRAMAddress);

	for (iLoop = 0; iLoop < 8; iLoop++)
	{
		LCD_displayCharacter(Pattern[iLoop]);
	}
	///* Go back to the DDRAM to display the pattern */
	// LCD_Goto_XY(X, Y); /* Set DDRAM Address */
	///*Display the pattern written in the CGRAM*/
	// LCD_displayCharacter(Location);
	/* Return to the home location */
	LCD_sendCommand(LCD_GO_TO_HOME);
}

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_displayInteger(sint32 num)
{
	uint8 str[32];		  /* create char array to store the digits of the number in it */

	uint8 i = 0;		  // index
	uint8 isNegative = 0; // flag

	if (num == 0)
	{
		LCD_displayCharacter('0');
		return;
	}
	else
	{
		if (num < 0)		// if the number is negative
		{
			isNegative = 1; // set the flag
			num = num * -1; // make the number positive
		}
		do // we use do while to make sure that the loop will run at least once even if the number is 0
		{
			int mod = num % 10; // get the remainder
			str[i++] =
				mod + '0';	// convert the remainder to char and put it in the array and increment the index

			num = num / 10; // update the number (remove the last digit)
		} while (num > 0); // num is positive

		if (isNegative)		// if the number is negative
		{
			str[i++] = '-'; // put the negative sign at the end of the string and increment the index
		}
		str[i] = 0;			//! null at the end
	}

	/*
	 * the array of this number is reversed
	 * so we need to reverse it easier to print each char in the array from the last element to the first one
	 * we already have the index of the last char in the array (i)
	 * //! but note that i is the index of the null char at this momment so we need to decrement it by 1
	 */

	i--;						 // decrement i by 1

	for (int k = i; k >= 0; k--) // don't forget = in <= (if the number is 2 digits)
	{
		LCD_displayCharacter(str[k]);
	}

	// =================== another way ===================
	// char buff[16];			 /* String to hold the ascii result */
	// itoa(data, buff, 10);	 /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
	// LCD_displayString(buff); /* Display the string */
}

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_displayFloat(float32 num, uint8 numAfterDecimal)
{
	char buff[16];			 /* String to hold the ascii result */
	dtostrf(num, 2, numAfterDecimal, buff);
	LCD_displayString(buff); /* Display the string */
}

/*
 * Description :
 * Display Binary number on the screen (8-bits)
 */
void LCD_displayBinary(uint8 num)
{
	unsigned int mask = 1 << (sizeof(num) * 8 - 1);
	while (mask)
	{
		if (num & mask)
			LCD_displayCharacter('1');
		else
			LCD_displayCharacter('0');
		mask >>= 1;
	}
}

/*
 * Description :
 * Display Hexadecimal number on the screen (8-bits)
 */
void LCD_displayHex(uint8 num)
{
	const char hexLookup[] = "0123456789ABCDEF";
	uint8	   hex = num >> 4;
	uint8	   hexReminder = num & 0x0F;

	LCD_displayCharacter(hexLookup[hex]);
	LCD_displayCharacter(hexLookup[hexReminder]);
}

/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* Send clear display command */
}

										/*************** Another Method for LCD_displayHex ***************/
/*
 void LCD_displayHex(uint8 num)
{
	uint8 hex = num >> 4;

	if (hex <= 9)
	{
		LCD_displayCharacter(hex + '0');
	}
	else
	{
		LCD_displayCharacter(hex - 10 + 'A');
	}

	uint8 hexReminder = num & 0x0F;

	if (hexReminder <= 9)
	{
		LCD_displayCharacter(hexReminder + '0');
	}
	else
	{
		LCD_displayCharacter(hexReminder - 10 + 'A');
	}
}
*/