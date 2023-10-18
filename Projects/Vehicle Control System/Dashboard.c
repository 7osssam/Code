#include <stdio.h>
#include <stdbool.h>
#include "Dashboard.h"

/* Global variable to store the vehicle data with initial values */
VEHICLE_t DATA = {.Engine_state = OFF,
				  .AC_state = OFF,
				  .Engine_Temp_state = OFF,
				  .Speed = 0,
				  .Room_Temp = 25,
				  .Engine_Temp_data = 90};

void TurnON(VEHICLE_t* data)
{
	int option;
	int Turn_on_flag = false;

	while (Turn_on_flag == false)
	{
		TerminalColor_YELLOW();
		printf("==================================\n");
		printf("|| 1. Turn off the engine. \n");
		printf("|| 2. Set the traffic light color. \n");
		printf("|| 3. Set the room temperature. \n");
#if WITH_ENGINE_TEMP_CONTROLLER
		printf("|| 4. Set the engine temperature. \n");
#endif
		printf("==================================\n");
		TerminalColor_RESET();

#if WITH_ENGINE_TEMP_CONTROLLER
		printf("Enter an option (1-4): ");
#else
		printf("Enter an option (1-3): ");
#endif
		int scanfResult = scanf("%d", &option);

		if (scanfResult == true)
		{
#if WITH_ENGINE_TEMP_CONTROLLER
			if (1 <= option && option <= 4)
#else
			if (1 <= option && option <= 3)
#endif
			{
				switch (option)
				{
					case 1:
						TurnOFF(data);
						Turn_on_flag = true;
						break;

					case 2:
						trafficLight(data);
						break;

					case 3:
						RoomTemperature(data);
						break;

#if WITH_ENGINE_TEMP_CONTROLLER // check if the engine temperature controller is enabled
					case 4:
						EngineTemperature(data);
						break;
#endif
				}
			}
			else
			{
				WrongOption_Message();
			}
		}
		else
		{
			// Clear the input buffer
			while (getchar() != '\n')
				;
			WrongOption_Message();
		}

		MenuDisplay(data);
	}
}

void TurnOFF(VEHICLE_t* data)
{
	/* NOTE:
     * no need to set the DATA values to 0 because the menu only appears when the engine is ON but this
     * will keep the code more readable and the simulation more realistic
     */

	data->Engine_state = OFF;
	data->Speed = 0;
	data->AC_state = OFF;
	data->Room_Temp = 0;
	data->Engine_Temp_state = OFF;
	data->Engine_Temp_data = 0;

	TerminalColor_RED();
	printf("\n==== Vehicle Engine is off ====\n");
	TerminalColor_RESET();
}

void DashboardMenu(void)
{
	int option;

	TerminalColor_BLUE();

	printf("====================================\n||\n||");
	TerminalColor_YELLOW();
	printf("       Vehicle Control System    \n");
	TerminalColor_BLUE();
	printf("||\n|| 1. Turn on the vehicle engine\n");
	printf("|| 2. Turn off the vehicle engine\n");
	printf("|| 3. Quit the system\n");
	printf("====================================\n");

	TerminalColor_RESET();

	printf("Enter an option (1-3): ");
	int scanfResult = scanf("%d", &option);

	if (scanfResult == true) // if the user entered a number not a character
	{
		if (1 <= option && option <= 3)
		{
			switch (option)
			{
				case 1:
					system("cls"); // for Windows terminal
					TurnON(&DATA);
					break;

				case 2:
					TurnOFF(&DATA);
					break;

				case 3:
					exit(0); // exit the program
					break;
			}
		}
		else
		{
			WrongOption_Message();
		}
	}
	else
	{
		// Clear the input buffer
		while (getchar() != '\n')
			;
		WrongOption_Message();
	}
}