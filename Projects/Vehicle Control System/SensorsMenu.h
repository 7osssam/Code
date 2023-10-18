#ifndef SENSORS_MENU_H_
#define SENSORS_MENU_H_

#include <stdbool.h>

/******************************************************************
 * 						Preprocessor Macros					  	  *
 ******************************************************************/
#define ON							true
#define OFF							false

/******************************************************************
 * 						System Configuration					  *
 ******************************************************************/
#define WITH_ENGINE_TEMP_CONTROLLER (OFF)

typedef struct
{
	bool Engine_state;
	bool AC_state;
	bool Engine_Temp_state;
	int	 Speed;
	int	 Room_Temp;
	int	 Engine_Temp_data;
} VEHICLE_t;

/******************************************************************
 * 					Terminal Color and Message					  *
 ******************************************************************/
void TerminalColor_RED(void);
void TerminalColor_YELLOW(void);
void TerminalColor_BLUE(void);
void TerminalColor_GREEN(void);
void TerminalColor_RESET(void);
void WrongOption_Message(void);

/******************************************************************
 * 						Sensors Menu Functions					  *
 ******************************************************************/

/**
 * The trafficLight function takes user input for the current traffic light color and updates the speed
 * and other data of a vehicle accordingly.
 * 
 * @param vehicle_data A pointer to a structure of type VEHICLE_t, which contains information about the
 * vehicle such as speed, AC state, room temperature, and engine temperature.
 */
void trafficLight(VEHICLE_t* vehicle_data);

/**
 * The function sets the AC state and room temperature of a vehicle based on user input.
 * 
 * @param vehicle_data A pointer to a structure of type VEHICLE_t, which likely contains information
 * about a vehicle, such as its current state and temperature.
 */
void RoomTemperature(VEHICLE_t* vehicle_data);

#if WITH_ENGINE_TEMP_CONTROLLER

/**
 * The function EngineTemperature takes user input for engine temperature and updates the vehicle_data
 * structure accordingly.
 * 
 * @param vehicle_data A pointer to a structure of type VEHICLE_t, which likely contains information
 * about a vehicle, such as its engine temperature.
 * 
 * @note This function is only compiled if the preprocessor macro WITH_ENGINE_TEMP_CONTROLLER is set to 1.
 */
void EngineTemperature(VEHICLE_t* vehicle_data);
#endif

/**
 * The function MenuDisplay displays the vehicle dashboard information including engine state, vehicle
 * speed, AC state, room temperature, and engine temperature (if engine temperature controller is
 * enabled).
 * 
 * @param vehicle_data The parameter `vehicle_data` is a pointer to a structure of type `VEHICLE_t`.
 * This structure contains information about the vehicle, such as the engine state, vehicle speed, AC
 * state, room temperature, engine temperature state, and engine temperature data.
 */
void MenuDisplay(const VEHICLE_t* vehicle_data);

#endif // SENSORS_MENU_H_
