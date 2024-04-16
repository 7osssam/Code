#include "bit.h"
#include "type.h"
#include "timer_interface.h"
#include "gie_interface.h"
#include "rto_private.h"
#include "rto_config.h"
#include "rto_interface.h"

TCB RTO_aTCBNumberOfTasks[RTO_u8_MAX_PRIORITY];

u8 RTO_u8CreateTask(u8 Local_u8Priority, u32 Local_u8Priodicity, u32 Local_u8FirstDelay,
					void (*Local_voidPF)(void))
{
	// Check if the priority is within the valid range
	if (Local_u8Priority >= RTO_u8_MAX_PRIORITY)
	{
		return NOT_OK;
	}

	// Check if the task function pointer is not NULL
	if (Local_voidPF == NULL)
	{
		return NOT_OK;
	}

	// Initialize the task control block
	RTO_aTCBNumberOfTasks[Local_u8Priority].periodicity = Local_u8Priodicity;
	RTO_aTCBNumberOfTasks[Local_u8Priority].first_delay = Local_u8FirstDelay;
	RTO_aTCBNumberOfTasks[Local_u8Priority].pf = Local_voidPF;
	RTO_aTCBNumberOfTasks[Local_u8Priority].state = READY;

	return OK;
}

void RTO_voidScheduler(void)
{
	int i;
	for (i = 0; i < RTO_u8_MAX_PRIORITY; i++)
	{
		if (RTO_aTCBNumberOfTasks[i].state == SUSPENDED)
		{
			continue;
		}
		if (RTO_aTCBNumberOfTasks[i].first_delay == 0)
		{
			RTO_aTCBNumberOfTasks[i].first_delay = RTO_aTCBNumberOfTasks[i].periodicity - 1;
			RTO_aTCBNumberOfTasks[i].pf();
		}
		else
		{
			RTO_aTCBNumberOfTasks[i].first_delay--;
		}
	}
}

void RTO_voidStartSys(void)
{
	EXTI_voidControlGIE(GIE_u8_ON);
	TMR0_voidInit();
	TMR0_voidSetCallBack(TMR0_u8_NORMAL, &RTO_voidScheduler);
	TMR0_voidEnablePIE(TMR0_u8_OVERFLOW);
}

void RTO_voidStopSys(void)
{
	EXTI_voidControlGIE(GIE_u8_OFF);
	TMR0_voidStop();
}

void RTO_voidSuspendTask(u8 Local_u8Priority)
{
	RTO_aTCBNumberOfTasks[Local_u8Priority].state = SUSPENDED;
}

u8 RTO_u8ResumeTask(u8 Local_u8Priority)
{
	if (RTO_aTCBNumberOfTasks[Local_u8Priority].state == SUSPENDED)
	{
		RTO_aTCBNumberOfTasks[Local_u8Priority].state = READY;
		return OK;
	}
	return NOT_OK;
}