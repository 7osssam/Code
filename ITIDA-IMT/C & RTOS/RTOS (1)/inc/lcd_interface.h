/* ************************************************************* */
/* ******************name:/ Mohanad Mohamed ********************/
/* ******************date:13.6.2023*************************** */
/* ******************version:/ 1.0************************** */

#ifndef lcd_interface
#define lcd_interface

#define LCD_u8_LINE0 0
#define LCD_u8_LINE1 1

#define LCD_u8_LEFT 0b0000011000
#define LCD_u8_RIGHT 0b0000011100

#define LCD_u8_CHAR0 0b01000000
#define LCD_u8_CHAR1 0b01001000
#define LCD_u8_CHAR2 0b01010000
#define LCD_u8_CHAR3 0b01011000
#define LCD_u8_CHAR4 0b01100000
#define LCD_u8_CHAR5 0b01101000
#define LCD_u8_CHAR6 0b01110000
#define LCD_u8_CHAR7 0b01111000

void LCD_voidInitial(void);

void LCD_voidSendCommend(u8 Copy_u8Commend);

void LCD_voidSendChar(u8 Copy_u8Char);

void LCD_voidSendStr(u8 s[]);

void LCD_voidGoToXY(u8 Copy_u8X, u8 Copy_u8Y);

void LCD_voidClear(void);

void LCD_voidSpecialChar(u8 Copy_u8Char, u8 *Copy_pu8Pattern);

void LCD_voidShift(u8 Copy_u8Direction);

void LCD_voidSendNum(s16 Copy_u16Number);

#endif
