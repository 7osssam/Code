/* ******************************************** */
/* ******************name:/ Mohanad Mohamed ********************/
/* ******************date:8.6.2023*************************** */
/* ******************version:/ 1.0************************** */
#ifndef private
#define private
/* Macros Defination */
#define PORTA_u8_REG *((volatile u8 *)0x3B)
#define DDRA_u8_REG *((volatile u8 *)0x3A)
#define PINA_u8_REG *((volatile u8 *)0x39)

#define PORTB_u8_REG *((volatile u8 *)0x38)
#define DDRB_u8_REG *((volatile u8 *)0x37)
#define PINB_u8_REG *((volatile u8 *)0x36)

#define PORTC_u8_REG *((volatile u8 *)0x35)
#define DDRC_u8_REG *((volatile u8 *)0x34)
#define PINC_u8_REG *((volatile u8 *)0x33)

#define PORTD_u8_REG *((volatile u8 *)0x32)
#define DDRD_u8_REG *((volatile u8 *)0x31)
#define PIND_u8_REG *((volatile u8 *)0x30)

#define DIO_u8_INPUT 0
#define DIO_u8_OUTPUT 1

#define DIO_u8_LOW 0
#define DIO_u8_HIGH 1
#define DIO_u8_FLOATING 0
#define DIO_u8_PULL_UP 1

/******************MARCOS FOR CONCATINATION************/

#define CONC(P7, P6, P5, P4, P3, P2, P1, P0) CONC_HELP(P7, P6, P5, P4, P3, P2, P1, P0)
#define CONC_HELP(P7, P6, P5, P4, P3, P2, P1, P0) 0b##P7##P6##P5##P4##P3##P2##P1##P0

#endif
