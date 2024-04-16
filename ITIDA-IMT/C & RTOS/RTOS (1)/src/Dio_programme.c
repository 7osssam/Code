/* ************************************************************* */
/* ******************name:/ Mohanad Mohamed ********************/
/* ******************date:8.6.2023*************************** */
/* ******************version:/ 1.0************************** */
#include "type.h"
#include "bit.h"
#include "Dio_private.h"
#include "Dio_config.h"
#include "Dio_interface.h"

void DIO_u8IntialValue(void)
{
	PORTA_u8_REG = CONC(DIO_u8_PORTA_PIN7_INITIAL_VALUE, DIO_u8_PORTA_PIN6_INITIAL_VALUE, DIO_u8_PORTA_PIN5_INITIAL_VALUE, DIO_u8_PORTA_PIN4_INITIAL_VALUE,
						DIO_u8_PORTA_PIN3_INITIAL_VALUE, DIO_u8_PORTA_PIN2_INITIAL_VALUE, DIO_u8_PORTA_PIN1_INITIAL_VALUE, DIO_u8_PORTA_PIN0_INITIAL_VALUE);
	PORTB_u8_REG = CONC(DIO_u8_PORTB_PIN7_INITIAL_VALUE, DIO_u8_PORTB_PIN6_INITIAL_VALUE, DIO_u8_PORTB_PIN5_INITIAL_VALUE, DIO_u8_PORTB_PIN4_INITIAL_VALUE,
						DIO_u8_PORTB_PIN3_INITIAL_VALUE, DIO_u8_PORTB_PIN2_INITIAL_VALUE, DIO_u8_PORTB_PIN1_INITIAL_VALUE, DIO_u8_PORTB_PIN0_INITIAL_VALUE);
	PORTC_u8_REG = CONC(DIO_u8_PORTC_PIN7_INITIAL_VALUE, DIO_u8_PORTC_PIN6_INITIAL_VALUE, DIO_u8_PORTC_PIN5_INITIAL_VALUE, DIO_u8_PORTC_PIN4_INITIAL_VALUE,
						DIO_u8_PORTC_PIN3_INITIAL_VALUE, DIO_u8_PORTC_PIN2_INITIAL_VALUE, DIO_u8_PORTC_PIN1_INITIAL_VALUE, DIO_u8_PORTC_PIN0_INITIAL_VALUE);
	PORTD_u8_REG = CONC(DIO_u8_PORTD_PIN7_INITIAL_VALUE, DIO_u8_PORTD_PIN6_INITIAL_VALUE, DIO_u8_PORTD_PIN5_INITIAL_VALUE, DIO_u8_PORTD_PIN4_INITIAL_VALUE,
						DIO_u8_PORTD_PIN3_INITIAL_VALUE, DIO_u8_PORTD_PIN2_INITIAL_VALUE, DIO_u8_PORTD_PIN1_INITIAL_VALUE, DIO_u8_PORTD_PIN0_INITIAL_VALUE);
}
void DIO_u8IntialDirection(void)
{
	DDRA_u8_REG = CONC(DIO_u8_PORTA_PIN7_INITIAL_DIRECTION, DIO_u8_PORTA_PIN6_INITIAL_DIRECTION, DIO_u8_PORTA_PIN5_INITIAL_DIRECTION, DIO_u8_PORTA_PIN4_INITIAL_DIRECTION,
					   DIO_u8_PORTA_PIN3_INITIAL_DIRECTION, DIO_u8_PORTA_PIN2_INITIAL_DIRECTION, DIO_u8_PORTA_PIN1_INITIAL_DIRECTION, DIO_u8_PORTA_PIN0_INITIAL_DIRECTION);
	DDRB_u8_REG = CONC(DIO_u8_PORTB_PIN7_INITIAL_DIRECTION, DIO_u8_PORTB_PIN6_INITIAL_DIRECTION, DIO_u8_PORTB_PIN5_INITIAL_DIRECTION, DIO_u8_PORTB_PIN4_INITIAL_DIRECTION,
					   DIO_u8_PORTB_PIN3_INITIAL_DIRECTION, DIO_u8_PORTB_PIN2_INITIAL_DIRECTION, DIO_u8_PORTB_PIN1_INITIAL_DIRECTION, DIO_u8_PORTB_PIN0_INITIAL_DIRECTION);
	DDRC_u8_REG = CONC(DIO_u8_PORTC_PIN7_INITIAL_DIRECTION, DIO_u8_PORTC_PIN6_INITIAL_DIRECTION, DIO_u8_PORTC_PIN5_INITIAL_DIRECTION, DIO_u8_PORTC_PIN4_INITIAL_DIRECTION,
					   DIO_u8_PORTC_PIN3_INITIAL_DIRECTION, DIO_u8_PORTC_PIN2_INITIAL_DIRECTION, DIO_u8_PORTC_PIN1_INITIAL_DIRECTION, DIO_u8_PORTC_PIN0_INITIAL_DIRECTION);
	DDRD_u8_REG = CONC(DIO_u8_PORTD_PIN7_INITIAL_DIRECTION, DIO_u8_PORTD_PIN6_INITIAL_DIRECTION, DIO_u8_PORTD_PIN5_INITIAL_DIRECTION, DIO_u8_PORTD_PIN4_INITIAL_DIRECTION,
					   DIO_u8_PORTD_PIN3_INITIAL_DIRECTION, DIO_u8_PORTD_PIN2_INITIAL_DIRECTION, DIO_u8_PORTD_PIN1_INITIAL_DIRECTION, DIO_u8_PORTD_PIN0_INITIAL_DIRECTION);
}

u8 DIO_u8SetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinDirection)
{
	u8 Local_u8ReturnedState = OK;
	if ((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7) && (Copy_u8PinDirection <= DIO_u8_PIN_OUTPUT))
	{
		switch (Copy_u8PortId)
		{
		case (DIO_u8_PORTA):
		{
			switch (Copy_u8PinDirection)
			{
			case (DIO_u8_PIN_OUTPUT):
			{
				SET_BIT(DDRA_u8_REG, Copy_u8PinId);
				break;
			}
			case (DIO_u8_PIN_INPUT):
			{
				CLEAR_BIT(DDRA_u8_REG, Copy_u8PinId);
				break;
			}
			}
			break;
		}
		case (DIO_u8_PORTB):
		{
			switch (Copy_u8PinDirection)
			{
			case (DIO_u8_PIN_OUTPUT):
			{
				SET_BIT(DDRB_u8_REG, Copy_u8PinId);
				break;
			}
			case (DIO_u8_PIN_INPUT):
			{
				CLEAR_BIT(DDRB_u8_REG, Copy_u8PinId);
				break;
			}
			}
			break;
		}
		case (DIO_u8_PORTC):
		{
			switch (Copy_u8PinDirection)
			{
			case (DIO_u8_PIN_OUTPUT):
			{
				SET_BIT(DDRC_u8_REG, Copy_u8PinId);
				break;
			}
			case (DIO_u8_PIN_INPUT):
			{
				CLEAR_BIT(DDRC_u8_REG, Copy_u8PinId);
				break;
			}
			}
			break;
		}
		case (DIO_u8_PORTD):
		{
			switch (Copy_u8PinDirection)
			{
			case (DIO_u8_PIN_OUTPUT):
			{
				SET_BIT(DDRD_u8_REG, Copy_u8PinId);
				break;
			}
			case (DIO_u8_PIN_INPUT):
			{
				CLEAR_BIT(DDRD_u8_REG, Copy_u8PinId);
				break;
			}
			}
			break;
		}
		}
	}
	else
	{
		Local_u8ReturnedState = NOT_OK;
	}
	return Local_u8ReturnedState;
}
u8 DIO_u8SetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue)
{
	u8 Local_u8ReturnedState = OK;
	if ((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7) && (Copy_u8PinValue <= DIO_u8_PIN_HIGH))
	{
		switch (Copy_u8PortId)
		{
		case (DIO_u8_PORTA):
		{
			switch (Copy_u8PinValue)
			{
			case (DIO_u8_PIN_HIGH):
			{
				SET_BIT(PORTA_u8_REG, Copy_u8PinId);
				break;
			}
			case (DIO_u8_PIN_LOW):
			{
				CLEAR_BIT(PORTA_u8_REG, Copy_u8PinId);
				break;
			}
			}
			break;
		}
		case (DIO_u8_PORTB):
		{
			switch (Copy_u8PinValue)
			{
			case (DIO_u8_PIN_HIGH):
			{
				SET_BIT(PORTB_u8_REG, Copy_u8PinId);
				break;
			}
			case (DIO_u8_PIN_LOW):
			{
				CLEAR_BIT(PORTB_u8_REG, Copy_u8PinId);
				break;
			}
			}
			break;
		}
		case (DIO_u8_PORTC):
		{
			switch (Copy_u8PinValue)
			{
			case (DIO_u8_PIN_HIGH):
			{
				SET_BIT(PORTC_u8_REG, Copy_u8PinId);
				break;
			}
			case (DIO_u8_PIN_LOW):
			{
				CLEAR_BIT(PORTC_u8_REG, Copy_u8PinId);
				break;
			}
			}
			break;
		}
		case (DIO_u8_PORTD):
		{
			switch (Copy_u8PinValue)
			{
			case (DIO_u8_PIN_HIGH):
			{
				SET_BIT(PORTD_u8_REG, Copy_u8PinId);
				break;
			}
			case (DIO_u8_PIN_LOW):
			{
				CLEAR_BIT(PORTD_u8_REG, Copy_u8PinId);
				break;
			}
			}
			break;
		}
		}
	}
	else
	{
		Local_u8ReturnedState = NOT_OK;
	}
	return Local_u8ReturnedState;
}
u8 DIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 *Copy_pu8ReturnedPinValue)
{
	u8 Local_u8ReturnedState = OK;
	if ((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7) && (Copy_pu8ReturnedPinValue != NULL))
	{
		switch (Copy_u8PortId)
		{
		case (DIO_u8_PORTA):
		{
			*Copy_pu8ReturnedPinValue = GET_BIT(PINA_u8_REG, Copy_u8PinId);
			break;
		}
		case (DIO_u8_PORTB):
		{
			*Copy_pu8ReturnedPinValue = GET_BIT(PINB_u8_REG, Copy_u8PinId);
			break;
		}
		case (DIO_u8_PORTC):
		{
			*Copy_pu8ReturnedPinValue = GET_BIT(PINC_u8_REG, Copy_u8PinId);
			break;
		}
		case (DIO_u8_PORTD):
		{
			*Copy_pu8ReturnedPinValue = GET_BIT(PIND_u8_REG, Copy_u8PinId);
			break;
		}
		}
	}
	else
	{
		Local_u8ReturnedState = NOT_OK;
	}
	return Local_u8ReturnedState;
}
u8 DIO_u8SetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDirection)
{
	u8 Local_u8ReturnedState = OK;
	if ((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PortDirection <= DIO_u8_PORT_OUTPUT))
	{
		switch (Copy_u8PortId)
		{
		case (DIO_u8_PORTA):
		{
			switch (Copy_u8PortDirection)
			{
			case (DIO_u8_PORT_OUTPUT):
			{
				DDRA_u8_REG = DIO_u8_PORT_OUTPUT;
				break;
			}
			case (DIO_u8_PORT_INPUT):
			{
				DDRA_u8_REG = DIO_u8_PORT_INPUT;
				break;
			}
			}
			break;
		}
		case (DIO_u8_PORTB):
		{
			switch (Copy_u8PortDirection)
			{
			case (DIO_u8_PORT_OUTPUT):
			{
				DDRB_u8_REG = DIO_u8_PORT_OUTPUT;
				break;
			}
			case (DIO_u8_PORT_INPUT):
			{
				DDRB_u8_REG = DIO_u8_PORT_INPUT;
				break;
			}
			}
			break;
		}
		case (DIO_u8_PORTC):
		{
			switch (Copy_u8PortDirection)
			{
			case (DIO_u8_PORT_OUTPUT):
			{
				DDRC_u8_REG = DIO_u8_PORT_OUTPUT;
				break;
			}
			case (DIO_u8_PORT_INPUT):
			{
				DDRC_u8_REG = DIO_u8_PORT_INPUT;
				break;
			}
			}
			break;
		}
		case (DIO_u8_PORTD):
		{
			switch (Copy_u8PortDirection)
			{
			case (DIO_u8_PORT_OUTPUT):
			{
				DDRD_u8_REG = DIO_u8_PORT_OUTPUT;
				break;
			}
			case (DIO_u8_PORT_INPUT):
			{
				DDRD_u8_REG = DIO_u8_PORT_INPUT;
				break;
			}
			}
			break;
		}
		}
	}
	else
	{
		Local_u8ReturnedState = NOT_OK;
	}
	return Local_u8ReturnedState;
}
u8 DIO_u8SetPortValue(u8 Copy_u8PortId, u8 Copy_u8PortValue)
{
	u8 Local_u8ReturnedState = OK;
	if (Copy_u8PortId <= DIO_u8_PORTD)
	{
		switch (Copy_u8PortId)
		{
		case (DIO_u8_PORTA):
		{
			PORTA_u8_REG = Copy_u8PortValue;
			break;
		}
		case (DIO_u8_PORTB):
		{
			PORTB_u8_REG = Copy_u8PortValue;
			break;
		}
		case (DIO_u8_PORTC):
		{
			PORTC_u8_REG = Copy_u8PortValue;
			break;
		}
		case (DIO_u8_PORTD):
		{
			PORTD_u8_REG = Copy_u8PortValue;
			break;
		}
		}
	}
	else
	{
		Local_u8ReturnedState = NOT_OK;
	}
	return Local_u8ReturnedState;
}
u8 DIO_u8GetPortValue(u8 Copy_u8PortId, u8 *Copy_pu8ReturnedPortValue)
{
	u8 local_u8ReturnedState = OK;
	if ((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_pu8ReturnedPortValue != NULL))
	{
		switch (Copy_u8PortId)
		{
		case (DIO_u8_PORTA):
		{
			*Copy_pu8ReturnedPortValue = PINA_u8_REG;
			break;
		}
		case (DIO_u8_PORTB):
		{
			*Copy_pu8ReturnedPortValue = PINB_u8_REG;
			break;
		}
		case (DIO_u8_PORTC):
		{
			*Copy_pu8ReturnedPortValue = PINC_u8_REG;
			break;
		}
		case (DIO_u8_PORTD):
		{
			*Copy_pu8ReturnedPortValue = PIND_u8_REG;
			break;
		}
		}
	}
	else
	{
		local_u8ReturnedState = NOT_OK;
	}
	return local_u8ReturnedState;
}
void DIO_u8TogglePortValue(u8 Copy_u8PortId)
{
	u8 Local_u8TempValue;
	switch (Copy_u8PortId)
	{
	case (DIO_u8_PORTA):
	{
		Local_u8TempValue = PINA_u8_REG;
		if (Local_u8TempValue == 0xff)
		{
			DIO_u8SetPortValue(DIO_u8_PORTA, 0x00);
		}
		else
		{
			DIO_u8SetPortValue(DIO_u8_PORTA, 0xff);
		}
		break;
	}
	case (DIO_u8_PORTB):
	{
		Local_u8TempValue = PINB_u8_REG;
		if (Local_u8TempValue == 0xff)
		{
			DIO_u8SetPortValue(DIO_u8_PORTB, 0x00);
		}
		else
		{
			DIO_u8SetPortValue(DIO_u8_PORTB, 0xff);
		}
		break;
	}
	case (DIO_u8_PORTC):
	{
		Local_u8TempValue = PINC_u8_REG;
		if (Local_u8TempValue == 0xff)
		{
			DIO_u8SetPortValue(DIO_u8_PORTC, 0x00);
		}
		else
		{
			DIO_u8SetPortValue(DIO_u8_PORTC, 0xff);
		}
		break;
	}
	case (DIO_u8_PORTD):
	{
		Local_u8TempValue = PIND_u8_REG;
		if (Local_u8TempValue == 0xff)
		{
			DIO_u8SetPortValue(DIO_u8_PORTD, 0x00);
		}
		else
		{
			DIO_u8SetPortValue(DIO_u8_PORTD, 0xff);
		}
		break;
	}
	}
}
