#include "bit.h"
#include "type.h"
#include "Dio_interface.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "timer_interface.h"
#include "rto_interface.h"
#include "gie_interface.h"
#include "lcd_interface.h"
#include "EXTI.h"

void Task_1(void);
void Task_2(void);
void Task_3(void);
void Task_4(void);
void Task_5(void);

void ExtiCallBack(void)
{
	static u8 flag = 0;
	if (flag == 0)
	{
		RTO_voidSuspendTask(4);
		flag = 1;
	}
	else
	{
		RTO_u8ResumeTask(4);
		flag = 0;
	}
}

int main()
{
	// when external interrupt triggered (button pressed), task 5 will be paused (suspended)
	// and when the button is pressed again, task 5 will be resumed
	Interrupt_ConfigType EXTI_Config = {EXTI_INT0, rising_edge};
	EXTI_init(&EXTI_Config);

	EXTI_setCallBack(&EXTI_Config, &ExtiCallBack);
	EXTI_enable(&EXTI_Config);

	DIO_u8IntialDirection();
	DIO_u8IntialValue();
	LCD_voidInitial();
	LCD_voidSendStr("Hossam");
	TMR1_voidInit();
	TMR1_voidSetICR(19999);

	RTO_u8CreateTask(0, 1000, 0, &Task_1);
	RTO_u8CreateTask(1, 2000, 0, &Task_2);
	RTO_u8CreateTask(2, 5000, 0, &Task_3);
	RTO_u8CreateTask(3, 300, 0, &Task_4);
	RTO_u8CreateTask(4, 1000, 0, &Task_5);

	RTO_voidStartSys();
	while (1)
		;
	return 0;
}
void Task_1(void)
{
	static u8 flag = 0;
	if (flag == 0)
	{
		DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN0, DIO_u8_PIN_HIGH);
		flag = 1;
	}
	else
	{
		flag = 0;
		DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN0, DIO_u8_PIN_LOW);
	}
}
void Task_2(void)
{
	static u8 flag = 0;
	if (flag == 0)
	{
		DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN1, DIO_u8_PIN_HIGH);
		flag = 1;
	}
	else
	{
		flag = 0;
		DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN1, DIO_u8_PIN_LOW);
	}
}
void Task_3(void)
{
	static u8 flag = 0;
	if (flag == 0)
	{
		DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN2, DIO_u8_PIN_HIGH);
		flag = 1;
	}
	else
	{
		flag = 0;
		DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN2, DIO_u8_PIN_LOW);
	}
}
void Task_4(void)
{
	static u16 counter = 999;
	counter += 100;
	if (counter == 1999)
	{
		counter = 999;
	}
	TMR1_voidSetCompareMatch(counter);
}
void Task_5(void)
{
	static u8 counter = 0;
	counter++;
	LCD_voidShift(LCD_u8_RIGHT);
	if (counter == 9)
	{
		LCD_voidClear();
		LCD_voidGoToXY(LCD_u8_LINE0, 0);
		LCD_voidSendStr("Hossam");
		counter = 0;
	}
}
