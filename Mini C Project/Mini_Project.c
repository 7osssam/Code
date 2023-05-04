/*
 ============================================================================
 Name        : Mini_Project.c
 Author      : Hossam Muhammad
 Description :  C Project - Vehicle Control System for MT Embedded Systems Diploma
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "Dashboard.h" // include the dashboard source file

int main()
{
	char option; // option entered by the user

	while (1) // infinite loop to keep the program running
	{
		printf("\033[34m==================================\n"); // blue color for the menu

		printf("a. Turn on the vehicle engine\n");
		printf("b. Turn off the vehicle engine\n");
		printf("c. Quit the system\n");

		printf("==================================\033[0m\n"); // reset color to default

		fflush(stdout); // flush the output buffer to print the menu before getting the input
		scanf(" %c", &option);

		switch (option)
		{

		case 'A':
		case 'a':
			TurnON();
			break;

		case 'B':
		case 'b':
			TurnOFF();
			break;

		case 'C':
		case 'c':
			Quit(); // call the Quit function to exit the program
			break;

		default:
			printf("\033[41m"); // red color for the error message
			printf(" Wrong Option! try again ");
			printf("\033[0m\n"); // reset color to default
			break;
		}
	}
}
