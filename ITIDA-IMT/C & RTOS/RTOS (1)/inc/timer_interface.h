#ifndef timer_interface
#define timer_interface

#define TMR0_u8_OVERFLOW 0
#define TMR0_u8_COMPARE_MATCH 1

#define TMR0_u8_CTC 0
#define TMR0_u8_NORMAL 1

/*APIS FOR TMR0*/
void TMR0_voidInit(void);
void TMR0_voidStop(void);
void TMR0_voidEnablePIE(u8 Copy_u8PIE);
void TMR0_voidSetCallBack(u8 Copy_u8Mode, void (*Copy_PF)(void));
void TMR0_voidSetCompareMatch(u8 Copy_u8CompareMatch);

/*APIS FOR TMR1*/
void TMR1_voidInit(void);
void TMR1_voidInitICU(void);
void TMR1_voidStopTimer(void);
u16 TMR1_u16GetCounter(void);
void TMR1_voidSetCompareMatch(u16 Copy_u8CompareMatch);
void TMR1_voidSetICR(u16 Copy_u8ICR);
u32 ICU_voidTotalPeriod(void);
u8 ICU_u8DutyCycle(void);
#endif
