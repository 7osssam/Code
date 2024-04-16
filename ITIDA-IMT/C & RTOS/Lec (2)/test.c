#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CLASSES	  3
#define NUM_STUDENTS  10
#define TOTAL_GRADE	  100
#define PASSING_GRADE 50

// Function to generate random grades for students
void generateRandomGrades(int grades[NUM_CLASSES][NUM_STUDENTS])
{
	srand(time(NULL)); // Seed the random number generator
	for (int i = 0; i < NUM_CLASSES; i++)
	{
		for (int j = 0; j < NUM_STUDENTS; j++)
		{
			grades[i][j] = rand() % (TOTAL_GRADE + 1); // Generate a random grade between 0 and 100
		}
	}
}

// Function to calculate and display statistics
void calculateAndDisplayStatistics(int grades[NUM_CLASSES][NUM_STUDENTS])
{
	int passedCount = 0, failedCount = 0;
	int highestGrade = 0, lowestGrade = TOTAL_GRADE;
	int totalGrade = 0;

	for (int i = 0; i < NUM_CLASSES; i++)
	{
		for (int j = 0; j < NUM_STUDENTS; j++)
		{
			// Calculate passed and failed students
			if (grades[i][j] >= PASSING_GRADE)
			{
				passedCount++;
			}
			else
			{
				failedCount++;
			}

			// Update highest and lowest grades
			if (grades[i][j] > highestGrade)
			{
				highestGrade = grades[i][j];
			}
			if (grades[i][j] < lowestGrade)
			{
				lowestGrade = grades[i][j];
			}

			// Update total grade
			totalGrade += grades[i][j];
		}
	}

	// Calculate average grade
	float averageGrade = (float)totalGrade / (NUM_CLASSES * NUM_STUDENTS);

	// Display statistics
	printf("Number of passed students: %d\n", passedCount);
	printf("Number of failed students: %d\n", failedCount);
	printf("Highest grade: %d\n", highestGrade);
	printf("Lowest grade: %d\n", lowestGrade);
	printf("Average grade: %.2f\n", averageGrade);
}

int main()
{
	int grades[NUM_CLASSES][NUM_STUDENTS];

	// Generate random grades
	generateRandomGrades(grades);

	// Calculate and display statistics
	calculateAndDisplayStatistics(grades);

	return 0;
}
