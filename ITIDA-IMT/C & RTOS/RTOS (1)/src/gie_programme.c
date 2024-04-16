#include "type.h"
#include "bit.h"
#include "gie_interface.h"

// Defination of SREG
#define SRGE_u8_REG *((volatile u8*)0x5F)

void EXTI_voidControlGIE(u8 Copy_State)
{
	switch (Copy_State)
	{
		case (GIE_u8_ON):
		{
			SET_BIT(SRGE_u8_REG, 7);
			break;
		}
		case (GIE_u8_OFF):
		{
			CLEAR_BIT(SRGE_u8_REG, 7);
			break;
		}
	}
}
