#include <stdio.h>
#include <stdlib.h>

#define WITH_ENGINE_TEMP_CONTROLLER 1 // set this to 0 to disable the engine temperature controller

/// ================================ user defined data types ================================ ///
typedef enum Bool
{
	OFF,
	ON
} Bool;

typedef struct
{
	Bool Engine_state;
	Bool AC_state;
	Bool Engine_Temp_state;
	int Speed;
	int Room_Temp;
	int Engine_Temp_data;
} VEHICLE_t;

VEHICLE_t DATA = {ON, ON, ON, 100, 35, 90}; // initial values for the global variables
// ========================================================================================= //

void trafficLight()
{
	char input;

	while (1) // infinite loop to keep the program running to handle invalid inputs
	{
		printf("Enter traffic Light (G: Green, O: Orange, R: Red):\n");

		scanf(" %c", &input);

		switch (input)
		{

		case 'G':
		case 'g':
			DATA.Speed = 100;
			break;

		case 'O':
		case 'o':
			DATA.Speed = 30;

			// spacial case for the AC and Engine Temp sensors

			DATA.AC_state = ON;
			DATA.Room_Temp = DATA.Room_Temp * (5 / 4) + 1;

			DATA.Engine_Temp_state = ON;
			DATA.Engine_Temp_data = DATA.Engine_Temp_data * (5 / 4) + 1;
			break;

		case 'R':
		case 'r':
			DATA.Speed = 0;
			break;

		default:
			printf("\033[41m"); // red color for the error message
			printf(" Wrong Option! try again ");
			printf("\033[0m\n"); // reset color to default

			continue; // skip to next iteration of the while loop
		}

		break; // break out of the while loop if a valid option is entered
	}
}

void RoomTemperature()
{
	int input;

	printf("Enter Room Temperature:\n");

	scanf(" %d", &input);

	if (input < 10 || input > 30)
	{
		DATA.AC_state = ON;
		DATA.Room_Temp = 20;
	}
}

#if WITH_ENGINE_TEMP_CONTROLLER // this function is only compiled if WITH_ENGINE_TEMP_CONTROLLER is set to 1
void EngineTemperature()
{
	int input;

	printf("Enter Engine Temperature:\n");

	scanf(" %d", &input);

	if (input < 100 || input > 150)
	{
		DATA.Engine_Temp_state = ON;
		DATA.Engine_Temp_data = 20;
	}
}
#endif // end of WITH_ENGINE_TEMP_CONTROLLER check

void MenuDisplay()
{
	printf("\033[32m__________________________________\n"); // green color for the menu

	printf("Engine state: ");
	DATA.Engine_state ? printf("ON\n") : printf("OFF\n"); // print ON or OFF depending on the state

	printf("Vehicle Speed: %d km/h\n", DATA.Speed);

	printf("\nAC: ");
	DATA.AC_state ? printf("ON\n") : printf("OFF\n"); // print ON or OFF depending on the state

	printf("Room Temperature: %d C\n", DATA.Room_Temp);

#if WITH_ENGINE_TEMP_CONTROLLER // this code is only compiled if WITH_ENGINE_TEMP_CONTROLLER is set to 1

	printf("\nEngine Temperature Controller: ");
	DATA.Engine_Temp_state ? printf("ON\n") : printf("OFF\n"); // print ON or OFF depending on the state

	printf("Engine Temperature: %d C\n", DATA.Engine_Temp_data);
#endif // end of WITH_ENGINE_TEMP_CONTROLLER check

	printf("__________________________________\033[0m\n"); // reset color to default
}
