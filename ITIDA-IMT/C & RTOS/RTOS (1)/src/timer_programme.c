#include "bit.h"
#include "type.h"
#include "Dio_interface.h"
#include "timer_private.h"
#include "timer_config.h"
#include "timer_interface.h"

static void (*TMR0_OverFlow)(void) = NULL;
static void (*TMR0_CompareMatch)(void) = NULL;
static u8			TMR0_u8BusyFlag = 0;
volatile static u16 ICU_u16OFF;
volatile static u16 ICU_u16ON;

void TMR0_voidInit(void)
{
// Select TMR0 Mode
#if TMR0_MODE == TMR0_NORMAL_MODE
	CLEAR_BIT(TCCR0_u8_REG, 3);
	CLEAR_BIT(TCCR0_u8_REG, 6);
#elif TMR0_MODE == TMR0_PHASE_CORRECT_MODE
	CLEAR_BIT(TCCR0_u8_REG, 3);
	SET_BIT(TCCR0_u8_REG, 6);
	#if TMR0_PWM_MODE == TMR0_NON_INVERTING
	CLEAR_BIT(TCCR0_u8_REG, 4);
	SET_BIT(TCCR0_u8_REG, 5);
	#elif TMR0_PWM_MODE == TMR0_INVERTING
	SET_BIT(TCCR0_u8_REG, 4);
	SET_BIT(TCCR0_u8_REG, 5);
	#endif
#elif TMR0_MODE == TMR0_CTC_MODE
	SET_BIT(TCCR0_u8_REG, 3);
	CLEAR_BIT(TCCR0_u8_REG, 6);
	OCR0_u8_REG = TMR0_CTC_VALUE;
#elif TMR0_MODE == TMR0_FAST_PWM_MODE
	SET_BIT(TCCR0_u8_REG, 3);
	SET_BIT(TCCR0_u8_REG, 6);
	#if TMR0_PWM_MODE == TMR0_NON_INVERTING
	CLEAR_BIT(TCCR0_u8_REG, 4);
	SET_BIT(TCCR0_u8_REG, 5);
	#elif TMR0_PWM_MODE == TMR0_INVERTING
	SET_BIT(TCCR0_u8_REG, 4);
	SET_BIT(TCCR0_u8_REG, 5);
	#endif
#endif
	// Set Preload value
	if ((TMR0_PRELOAD_VALUE) && (TMR0_CASE == TMR0_CASE_2))
	{
		TCNT0_u8_REG = TMR0_PRELOAD_VALUE;
	}
	// Select TMR0 Clock
	CLEAR_BIT(TCCR0_u8_REG, 0);
	SET_BIT(TCCR0_u8_REG, 1);
	CLEAR_BIT(TCCR0_u8_REG, 2);
}
void TMR0_voidEnablePIE(u8 Copy_u8PIE)
{
	switch (Copy_u8PIE)
	{
		// PIE for Overflow
		case (TMR0_u8_OVERFLOW):
		{
			SET_BIT(TIMSK_u8_REG, 0);
			break;
		}
		// PIE for Compare Match
		case (TMR0_u8_COMPARE_MATCH):
		{
			SET_BIT(TIMSK_u8_REG, 1);
			break;
		}
	}
}
void TMR0_voidSetCallBack(u8 Copy_u8Mode, void (*Copy_PF)(void))
{
	if ((Copy_PF != NULL) && (TMR0_u8BusyFlag == 0))
	{
		TMR0_u8BusyFlag = 1;
		switch (Copy_u8Mode)
		{
			case (TMR0_u8_NORMAL):
			{
				TMR0_OverFlow = Copy_PF;
				break;
			}
			case (TMR0_u8_CTC):
			{
				TMR0_CompareMatch = Copy_PF;
				break;
			}
		}
	}
}
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
#if TMR0_CASE == TMR0_CASE_1
	if (TMR0_OverFlow != NULL)
	{
		TMR0_u8BusyFlag = 0;
		TMR0_OverFlow();
	}
#elif TMR0_CASE == TMR0_CASE_2

#elif TMR0_CASE == TMR0_CASE_3
	static u32 Local_u8Counter = 0;
	Local_u8Counter++;
	if (TMR0_ISR_VALUE == Local_u8Counter)
	{
		TCNT0_u8_REG = TMR0_ISR_PRELOAD_VALUE;
		Local_u8Counter = 0;
		if (TMR0_OverFlow != NULL)
		{
			TMR0_u8BusyFlag = 0;
			TMR0_OverFlow();
		}
	}
#endif
}
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if (TMR0_OverFlow != NULL)
	{
		TMR0_u8BusyFlag = 0;
		TMR0_CompareMatch();
	}
}
void TMR0_voidStop(void)
{
	// Select TMR0 Clock
	CLEAR_BIT(TCCR0_u8_REG, 0);
	CLEAR_BIT(TCCR0_u8_REG, 1);
	CLEAR_BIT(TCCR0_u8_REG, 2);
}

void TMR0_voidSetCompareMatch(u8 Copy_u8CompareMatch)
{
	OCR0_u8_REG = Copy_u8CompareMatch;
}

void TMR1_voidInit(void)
{
/*Select Mode*/
#if TMR1_MODE == TMR1_NORMAL_MODE
	CLEAR_BIT(TCCR1A_u8_REG, 0);
	CLEAR_BIT(TCCR1A_u8_REG, 1);
	CLEAR_BIT(TCCR1B_u8_REG, 3);
	CLEAR_BIT(TCCR1B_u8_REG, 4);
#elif TMR1_MODE == TMR1_FAST_PWM_MODE
	CLEAR_BIT(TCCR1A_u8_REG, 0);
	SET_BIT(TCCR1A_u8_REG, 1);
	SET_BIT(TCCR1B_u8_REG, 3);
	SET_BIT(TCCR1B_u8_REG, 4);
	#if TMR1_CHANNAL == TMR1_CHANNAL_A
		#if TMR1_PWM_MODE == TMR1_NON_INVERTING
	CLEAR_BIT(TCCR1A_u8_REG, 6);
	SET_BIT(TCCR1A_u8_REG, 7);
		#elif TMR1_PWM_MODE == TMR1_INVERTING
	SET_BIT(TCCR1A_u8_REG, 6);
	SET_BIT(TCCR1A_u8_REG, 7);
		#endif
	#elif TMR1_CHANNAL == TMR1_CHANNAL_B
		#if TMR1_PWM_MODE == TMR1_NON_INVERTING
	CLEAR_BIT(TCCR1A_u8_REG, 4);
	SET_BIT(TCCR1A_u8_REG, 5);
		#elif TMR1_PWM_MODE == TMR1_INVERTING
	SET_BIT(TCCR1A_u8_REG, 4);
	SET_BIT(TCCR1A_u8_REG, 5);
		#endif
	#endif
#endif
	/*Set Prescaler 8*/
	CLEAR_BIT(TCCR1B_u8_REG, 0);
	SET_BIT(TCCR1B_u8_REG, 1);
	CLEAR_BIT(TCCR1B_u8_REG, 2);
}

void TMR1_voidStopTimer(void)
{
	CLEAR_BIT(TCCR1B_u8_REG, 0);
	CLEAR_BIT(TCCR1B_u8_REG, 1);
	CLEAR_BIT(TCCR1B_u8_REG, 2);
}

u16 TMR1_u16GetCounter(void)
{
	return TCNT1LH_u16_REG;
}

void TMR1_voidSetCompareMatch(u16 Copy_u8CompareMatch)
{
#if TMR1_CHANNAL == TMR1_CHANNAL_A
	OCR1ALH_u16_REG = Copy_u8CompareMatch;
#elif TMR1_CHANNAL == TMR1_CHANNAL_B
	OCR1BLH_u16_REG = Copy_u8CompareMatch;
#endif
}

void TMR1_voidSetICR(u16 Copy_u8ICR)
{
	ICR1LH_u16_REG = Copy_u8ICR;
}

void TMR1_voidInitICU(void)
{
	/*Noise cancel*/
	SET_BIT(TCCR1B_u8_REG, 7);
	/*Set Risisng Edge*/
	SET_BIT(TCCR1B_u8_REG, 6);
	/*PIE*/
	SET_BIT(TIMSK_u8_REG, 5);
}

void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	u16		   Local_u16CounterValue = ICR1LH_u16_REG;
	static u16 Local_u16OldCounterValue = 0;
	static u8  Local_u8Flag = 0;
	if (Local_u8Flag == 0)
	{
		/*Set Falling Edge*/
		CLEAR_BIT(TCCR1B_u8_REG, 6);
		Local_u8Flag = 1;
		ICU_u16OFF = Local_u16CounterValue - Local_u16OldCounterValue;
	}
	if (Local_u8Flag == 1)
	{
		/*Set Falling Edge*/
		SET_BIT(TCCR1B_u8_REG, 6);
		Local_u8Flag = 0;
		ICU_u16ON = Local_u16CounterValue - Local_u16OldCounterValue;
	}
	Local_u16OldCounterValue = Local_u16CounterValue;
}

u32 ICU_voidTotalPeriod(void)
{
	u32 Local_u32TotalPeriod = ICU_u16OFF + ICU_u16ON;
	return Local_u32TotalPeriod;
}

u8 ICU_u8DutyCycle(void)
{
	u32 Local_u32TotalPeriod = ICU_voidTotalPeriod();
	u8	Local_u8DutyCycle = (u8)((u32)(ICU_u16ON * 100UL) / (u32)Local_u32TotalPeriod);
	return Local_u8DutyCycle;
}