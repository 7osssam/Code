#ifndef SENSORS_MENU_H_
#define SENSORS_MENU_H_

#include <stdio.h>
#include <stdlib.h>

#define WITH_ENGINE_TEMP_CONTROLLER 0 // set this to 0 to disable the engine temperature controller

/// ================================ user defined data types ================================ ///
typedef enum
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

void trafficLight(VEHICLE_t *vehicle_data);
void RoomTemperature(VEHICLE_t *vehicle_data);
#if WITH_ENGINE_TEMP_CONTROLLER
void EngineTemperature(VEHICLE_t *vehicle_data);
#endif
void MenuDisplay(const VEHICLE_t *vehicle_data);

#endif // SENSORS_MENU_H_
