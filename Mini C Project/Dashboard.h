#include "SensorsMenu.h" // include the sensors menu header file

void TurnOFF()
{
	/*
	 no need to set the state to OFF because the menu only appears when the engine is ON
	 i will keep it here just to make the code more readable and the simulation more realistic
	 */
	DATA.Engine_state = OFF; // turn off the engine

	printf("\033[31m"); // red color for the message
	printf("\nVehicle Engine is off\n\n");
	printf("\033[0m\n"); // reset color to default
}

void TurnON()
{
	char option;

	while (1) // infinite loop to keep the program running
	{
		printf("\033[33m==================================\n"); // yellow color for the menu

		printf("a. Turn off the engine. \n");
		printf("b. Set the traffic light color. \n");
		printf("c. Set the room temperature. \n");
#if WITH_ENGINE_TEMP_CONTROLLER // check if the engine temperature controller is enabled
		printf("d. Set the engine temperature. \n");
#endif

		printf("==================================\033[0m\n"); // reset color to default

		scanf(" %c", &option);

		switch (option)
		{
		case 'a':
			TurnOFF();
			return; // return to the main menu after turning off the engine

		case 'b':
			trafficLight();
			break;

		case 'c':
			RoomTemperature();
			break;

#if WITH_ENGINE_TEMP_CONTROLLER // check if the engine temperature controller is enabled
		case 'd':
			EngineTemperature();
			break;
#endif

		default:
			printf("\033[41m"); // red color for the error message
			printf(" Wrong Option! try again ");
			printf("\033[0m\n"); // reset color to default
			break;
		}

		MenuDisplay(); // display the menu after each iteration
		printf("\n");  // print a new line for better readability
	}
}

// we can get red of this function and use the Quit function from the main file
void Quit() // function to exit the program
{

	printf("\033[31m"); // red color for the exit message
	printf("\nQuit the system\n");
	printf("\033[0m\n"); // reset color to default

	exit(0); // exit the program
}
