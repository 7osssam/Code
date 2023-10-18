#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "SensorsMenu.h"

/**
 * The function "TurnON" allows the user to select various options such as turning off the engine,
 * setting the traffic light color, setting the room temperature, and setting the engine temperature
 * (if enabled), and displays a menu for the user to choose from.
 * 
 * @param data The parameter "data" is of type VEHICLE_t*, which is a pointer to a structure or object
 * of type VEHICLE_t. This structure or object likely contains information about a vehicle, such as its
 * engine status, traffic light color, room temperature, and engine temperature. The TurnON function is
 */
void TurnON(VEHICLE_t* data);

/**
 * The function TurnOFF sets the values of various data members of a VEHICLE_t struct to indicate that
 * the vehicle's engine is turned off.
 * 
 * @param data A pointer to a structure of type VEHICLE_t.
 */
void TurnOFF(VEHICLE_t* data);

/**
 * The function `DashboardMenu` displays a menu for a vehicle control system and allows the user to
 * select options such as turning on/off the vehicle engine or quitting the system.
 * @note This function is called from the main function in the file `Mini_Project.c`.
 */
void DashboardMenu(void);

#endif /* DASHBOARD_H */
