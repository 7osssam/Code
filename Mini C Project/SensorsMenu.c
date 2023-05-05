#include "SensorsMenu.h"

void trafficLight(VEHICLE_t *vehicle_data)
{
  char input;

  while (1)
  { // infinite loop to keep the program running to handle invalid inputs
    printf("Enter traffic Light (G: Green, O: Orange, R: Red):\n");

    fflush(stdout); // flush the output buffer to print the message immediately
    scanf(" %c", &input);

    switch (input)
    {
    case 'G':
    case 'g':
      vehicle_data->Speed = 100;
      break;

    case 'O':
    case 'o':
      vehicle_data->Speed = 30;

      // special case for the AC and Engine Temp sensors

      vehicle_data->AC_state = ON;
      vehicle_data->Room_Temp = vehicle_data->Room_Temp * (5 / 4) + 1;

      vehicle_data->Engine_Temp_state = ON;
      vehicle_data->Engine_Temp_data = vehicle_data->Engine_Temp_data * (5 / 4) + 1;
      break;

    case 'R':
    case 'r':
      vehicle_data->Speed = 0;
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

void RoomTemperature(VEHICLE_t *vehicle_data)
{
  int input;

  printf("Enter Room Temperature:\n");

  fflush(stdout); // flush the output buffer to print the message immediately
  scanf(" %d", &input);

  if (input < 10 || input > 30)
  {
    vehicle_data->AC_state = ON;
    vehicle_data->Room_Temp = 20;
  }
}

#if WITH_ENGINE_TEMP_CONTROLLER // check if the engine temperature controller is enabled
void EngineTemperature(VEHICLE_t *vehicle_data)
{
  int input;

  printf("Enter Engine Temperature:\n");

  fflush(stdout); // flush the output buffer to print the message immediately
  scanf(" %d", &input);

  if (input < 100 || input > 150)
  {
    vehicle_data->Engine_Temp_state = ON;
    vehicle_data->Engine_Temp_data = 20;
  }
}
#endif // end of WITH_ENGINE_TEMP_CONTROLLER check

void MenuDisplay(const VEHICLE_t *vehicle_data)
{
  printf("\033[32m__________________________________\n\n"); // green color for the menu
  printf("Engine state: %s\n", vehicle_data->Engine_state ? "ON" : "OFF");
  printf("Vehicle Speed: %d Km/hr\n", vehicle_data->Speed);

  printf("AC state: %s\n", vehicle_data->AC_state ? "ON" : "OFF");
  printf("Room Temperature: %d C\n", vehicle_data->Room_Temp);

#if WITH_ENGINE_TEMP_CONTROLLER // this code is only compiled if WITH_ENGINE_TEMP_CONTROLLER is set to 1
  printf("Engine Temperature state: %s\n", vehicle_data->Engine_Temp_state ? "ON" : "OFF");
  printf("Engine Temperature: %d C\n", vehicle_data->Engine_Temp_data);
#endif // end of WITH_ENGINE_TEMP_CONTROLLER check

  printf("__________________________________\033[0m\n"); // reset color to default
}