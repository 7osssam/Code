#ifndef rto_interface
#define rto_interface

u8 RTO_u8CreateTask(u8 Local_u8Priority, u32 Local_u8Priodicity, u32 Local_u8FirstDelay,
					void (*Local_voidPF)(void));

void RTO_voidScheduler(void);

void RTO_voidStartSys(void);

void RTO_voidStopSys(void);

void RTO_voidSuspendTask(u8 Local_u8Priority);

u8 RTO_u8ResumeTask(u8 Local_u8Priority);

#endif
