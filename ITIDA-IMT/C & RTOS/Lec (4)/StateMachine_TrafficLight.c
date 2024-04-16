#include <stdio.h>
#include <unistd.h>

typedef enum
{
	RED,
	GREEN,
	YELLOW
} TrafficLightState_t;

void ChangeState(TrafficLightState_t* currentState)
{
	// State transition logic
	switch (*currentState)
	{
		case RED:
			*currentState = GREEN;
			break;
		case GREEN:
			*currentState = YELLOW;
			break;
		case YELLOW:
			*currentState = RED;
			break;
	}
}

void RunState(TrafficLightState_t currentState)
{
	// Output current state
	switch (currentState)
	{
		case RED:
			printf("RED\n");
			break;
		case GREEN:
			printf("GREEN\n");
			break;
		case YELLOW:
			printf("YELLOW\n");
			break;
	}
}

int main()
{
	TrafficLightState_t currentState = RED; // Initial state

	// Simulation loop
	while (1)
	{
		RunState(currentState);

		ChangeState(&currentState);

		sleep(3);
	}

	return 0;
}
