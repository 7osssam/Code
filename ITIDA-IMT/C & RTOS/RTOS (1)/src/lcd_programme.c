/* ************************************************************* */
/* ******************name:/ Mohanad Mohamed ********************/
/* ******************date:8.6.2023*************************** */
/* ******************version:/ 1.0************************** */
#include "bit.h"
#include "type.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include <string.h>
#include "Dio_interface.h"
#include "lcd_private.h"
#include "lcd_interface.h"
#include "lcd_config.h"

void LCD_voidInitial(void)
{
	_delay_ms(35);
	LCD_voidSendCommend(0b0000111000);
	_delay_us(40);
	LCD_voidSendCommend(0b0000001111);
	_delay_us(40);
	LCD_voidSendCommend(0b0000000001);
	_delay_ms(2);
	LCD_voidSendCommend(0b0000000110);
}
void LCD_voidSendCommend(u8 Copy_u8Commend)
{
	/******RS = 0******/
	DIO_u8SetPinDirection(LCD_u8_CONTROL_PINS_INITIAL_PORT, LCD_u8_RS_PIN, DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PINS_INITIAL_PORT, LCD_u8_RS_PIN, DIO_u8_PIN_LOW);
	/*****RW =0*******/
	DIO_u8SetPinDirection(LCD_u8_CONTROL_PINS_INITIAL_PORT, LCD_u8_RW_PIN, DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PINS_INITIAL_PORT, LCD_u8_RW_PIN, DIO_u8_PIN_LOW);
	/*****Send Command byte to data pin******/
	DIO_u8SetPortDirection(LCD_u8_DATA_PINS_INITIAL_PORT, DIO_u8_PORT_OUTPUT);
	DIO_u8SetPortValue(LCD_u8_DATA_PINS_INITIAL_PORT, Copy_u8Commend);
	/*******SEND PULSE ON ENABLE PIN****/
	DIO_u8SetPinDirection(LCD_u8_CONTROL_PINS_INITIAL_PORT, LCD_u8_E_PIN, DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PINS_INITIAL_PORT, LCD_u8_E_PIN, DIO_u8_PIN_HIGH);
	_delay_us(1);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PINS_INITIAL_PORT, LCD_u8_E_PIN, DIO_u8_PIN_LOW);
}
void LCD_voidSendChar(u8 Copy_u8Char)
{
	/******RS = 1******/
	DIO_u8SetPinDirection(LCD_u8_CONTROL_PINS_INITIAL_PORT, LCD_u8_RS_PIN, DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PINS_INITIAL_PORT, LCD_u8_RS_PIN, DIO_u8_PIN_HIGH);
	/*****RW =0*******/
	DIO_u8SetPinDirection(LCD_u8_CONTROL_PINS_INITIAL_PORT, LCD_u8_RW_PIN, DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PINS_INITIAL_PORT, LCD_u8_RW_PIN, DIO_u8_PIN_LOW);
	/*****Send Command byte to data pin******/
	DIO_u8SetPortDirection(LCD_u8_DATA_PINS_INITIAL_PORT, DIO_u8_PORT_OUTPUT);
	DIO_u8SetPortValue(LCD_u8_DATA_PINS_INITIAL_PORT, Copy_u8Char);
	/*******SEND PULSE ON ENABLE PIN****/
	DIO_u8SetPinDirection(LCD_u8_CONTROL_PINS_INITIAL_PORT, LCD_u8_E_PIN, DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PINS_INITIAL_PORT, LCD_u8_E_PIN, DIO_u8_PIN_HIGH);
	_delay_us(1);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PINS_INITIAL_PORT, LCD_u8_E_PIN, DIO_u8_PIN_LOW);
}
void LCD_voidSendStr(u8 s[])
{
	u8 i = 0;
	u8 size = strlen(s);
	while (i < size)
	{
		LCD_voidSendChar(s[i]);
		i++;
		_delay_ms(2);
	}
}
void LCD_voidGoToXY(u8 Copy_u8X, u8 Copy_u8Y)
{
	switch (Copy_u8X)
	{
	case (LCD_u8_LINE0):
	{
		LCD_voidSendCommend((0x80 + (Copy_u8Y)));
		break;
	}
	case (LCD_u8_LINE1):
	{
		LCD_voidSendCommend((0xC0 + (Copy_u8Y)));
		break;
	}
	}
}
void LCD_voidClear(void)
{
	LCD_voidSendCommend(0b0000000001);
	_delay_ms(2);
}
void LCD_voidSpecialChar(u8 Copy_u8Char, u8 *Copy_pu8Pattern)
{
	LCD_voidSendCommend(Copy_u8Char);
	u8 i;
	for (i = 0; i < 8; i++)
	{
		LCD_voidSendChar(Copy_pu8Pattern[i]);
	}
}
void LCD_voidShift(u8 Copy_u8Direction)
{
	switch (Copy_u8Direction)
	{
	case (LCD_u8_LEFT):
	{
		LCD_voidSendCommend(0b0000011000);
		break;
	}
	case (LCD_u8_RIGHT):
	{
		LCD_voidSendCommend(0b0000011100);
		break;
	}
	}
}
void LCD_voidSendNum(s16 Copy_u16Number)
{
	s8 count = 0, reminder;
	s16 Local_u16Reversed = 0;
	if (Copy_u16Number == 0)
	{
		LCD_voidSendChar(0 + 48);
	}
	else if (Copy_u16Number < 0)
	{
		LCD_voidSendChar('-');
		Copy_u16Number *= -1;
	}
	s16 test = Copy_u16Number;
	while (test)
	{
		reminder = test % 10;
		Local_u16Reversed = (Local_u16Reversed * 10) + reminder;
		test /= 10;
		count++;
	}
	while (count--)
	{
		reminder = Local_u16Reversed % 10;
		LCD_voidSendChar(reminder + 48);
		Local_u16Reversed /= 10;
	}
}
