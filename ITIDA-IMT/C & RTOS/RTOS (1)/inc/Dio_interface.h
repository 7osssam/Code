/* ************************************************************* */
/* ******************name:/ Mohanad Mohamed ********************/
/* ******************date:8.6.2023*************************** */
/* ******************version:/ 1.0************************** */
#ifndef interface
#define interface
/****Macros For Port Id********/

#define DIO_u8_PORTA 0
#define DIO_u8_PORTB 1
#define DIO_u8_PORTC 2
#define DIO_u8_PORTD 3

/****Macros For Pin Id********/

#define DIO_u8_PIN0 0
#define DIO_u8_PIN1 1
#define DIO_u8_PIN2 2
#define DIO_u8_PIN3 3
#define DIO_u8_PIN4 4
#define DIO_u8_PIN5 5
#define DIO_u8_PIN6 6
#define DIO_u8_PIN7 7

/****Macros For Pin Direction********/

#define DIO_u8_PIN_OUTPUT 1
#define DIO_u8_PIN_INPUT 0

/****Macros For Pin Value********/

#define DIO_u8_PIN_HIGH 1
#define DIO_u8_PIN_LOW 0

/****Macros For Port Direction********/

#define DIO_u8_PORT_INPUT 0x00
#define DIO_u8_PORT_OUTPUT 0xFF

/****prototype of DIO driver***/

void DIO_u8IntialValue(void);

void DIO_u8IntialDirection(void);

u8 DIO_u8SetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinDirection);

u8 DIO_u8SetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue);

u8 DIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 *Copy_pu8ReturnedPinValue);

u8 DIO_u8SetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDirection);

u8 DIO_u8SetPortValue(u8 Copy_u8PortId, u8 Copy_u8PortValue);

u8 DIO_u8GetPortValue(u8 Copy_u8PortId, u8 *Copy_pu8ReturnedPortValue);

#endif
