#include <stdio.h>
#include "Dashboard.h"

void TurnON(VEHICLE_t *data)
{
    char option; // option entered by the user

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

        fflush(stdout); // flush the output buffer to print the message immediately
        scanf(" %c", &option);

        switch (option)
        {
        case 'a':
            TurnOFF(data);
            return; // return to the main menu after turning off the engine

        case 'b':
            trafficLight(data);
            break;

        case 'c':
            RoomTemperature(data);
            break;

#if WITH_ENGINE_TEMP_CONTROLLER // check if the engine temperature controller is enabled
        case 'd':
            EngineTemperature(data);
            break;
#endif

        default:
            printf("\033[41m"); // red color for the error message
            printf(" Wrong Option! try again... ");
            printf("\033[0m\n"); // reset color to default
            break;
        }

        MenuDisplay(data);
    }
}

/// @brief  Turn off the vehicle engine and reset the vehicle data to zero
/// @param data  pointer to the vehicle data structure
void TurnOFF(VEHICLE_t *data)
{
    /***********************
     no need to set the DATA values to 0 because the menu only appears when the engine is ON but this
    will keep the code more readable and the simulation more realistic
    ************************/

    data->Engine_state = OFF;
    data->Speed = 0;
    data->AC_state = OFF;
    data->Room_Temp = 0;
    data->Engine_Temp_state = OFF;
    data->Engine_Temp_data = 0;

    printf("\033[31m"); // red color for the message
    printf("\nVehicle Engine is off\n\n");
    printf("\033[0m\n"); // reset color to default
}