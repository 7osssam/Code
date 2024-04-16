#include <stdio.h>
#include <assert.h>

typedef struct
{
	int hours;
	int minutes;
	int seconds;
} Time_t;

void DiffBetweenTimePeriod(Time_t start, Time_t stop, Time_t* diff)
{
	// handling invalid input
	if (start.hours < stop.hours)
	{
		diff->hours = -1;
		diff->minutes = -1;
		diff->seconds = -1;
		return;
	}

	while (stop.seconds > start.seconds)		  // handling seconds first
	{
		--start.minutes;						  // decrement minutes
		start.seconds += 60;
	}

	diff->seconds = start.seconds - stop.seconds; // calculate final seconds difference

	while (stop.minutes > start.minutes)		  // handling minutes
	{
		--start.hours;							  // decrement hours
		start.minutes += 60;
	}

	diff->minutes = start.minutes - stop.minutes; // calculate final minutes difference
	diff->hours = start.hours - stop.hours;		  // calculate final hours difference
}

void test_DiffBetweenTimePeriod()
{
	Time_t startTime, stopTime, diff;

	// difference should be 2:20:20
	startTime = (Time_t){12, 30, 30};
	stopTime = (Time_t){10, 10, 10};
	DiffBetweenTimePeriod(startTime, stopTime, &diff);
	assert(diff.hours == 2);
	assert(diff.minutes == 20);
	assert(diff.seconds == 20);

	// difference should be 0:48:32
	startTime = (Time_t){4, 23, 45};
	stopTime = (Time_t){3, 35, 13};
	DiffBetweenTimePeriod(startTime, stopTime, &diff);
	assert(diff.hours == 0);
	assert(diff.minutes == 48);
	assert(diff.seconds == 32);

	// difference should be 0:0:0
	startTime = (Time_t){10, 30, 45};
	stopTime = (Time_t){10, 30, 45};
	DiffBetweenTimePeriod(startTime, stopTime, &diff);
	assert(diff.hours == 0);
	assert(diff.minutes == 0);
	assert(diff.seconds == 0);

	// difference should be -1:-1:-1 (invalid input)
	startTime = (Time_t){10, 30, 45};
	stopTime = (Time_t){11, 30, 45};
	DiffBetweenTimePeriod(startTime, stopTime, &diff);
	assert(diff.hours == -1);
	assert(diff.minutes == -1);
	assert(diff.seconds == -1);

	printf("===All tests passed===\n");
}

int main()
{
	test_DiffBetweenTimePeriod();
	return 0;
}