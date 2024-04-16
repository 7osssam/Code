#ifndef rto_private
#define rto_private

typedef enum
{
	READY,
	RUNNING,
	WAITING,
	SUSPENDED
} TaskState;

typedef struct
{
	u32		  periodicity;
	u32		  first_delay;
	TaskState state;
	void (*pf)(void);

} TCB;

#endif
