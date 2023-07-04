/*
 ? Link: https://www.hackerrank.com/challenges/grading/problem
 * Difficulty: Easy
 * Name: Grading Students
 *
 * Tags: Algorithms, Implementation
 *
 * Summary:
 * - If the difference between the grade and the next multiple of 5 is less than 3;
 * round grade up to the next multiple of 5.
 * - If the value of grade is less than 38, no rounding occurs as the result will still be a failing grade.
 */

#include <stdio.h>
#include <stdlib.h>

int roundGrade(int grade)
{
	if (grade < 38)
	{
		// No rounding needed for failing grades
		return grade;
	}

	int nextMultiple = (grade / 5 + 1) * 5; // time complexity O(1)

	//! old solution with for loop // time complexity O(n)
	// int nextMultiple = grade;
	// for (int i = 1; nextMultiple % 5 != 0; i++)
	//{
	//	nextMultiple++;
	// }

	if (nextMultiple - grade < 3)
	{
		// Round up to the next multiple of 5
		return nextMultiple;
	}
	else
	{
		// No rounding needed
		return grade;
	}
}

int *gradingStudents(int grades_count, int *grades, int *result_count)
{
	*result_count = grades_count;
	int *gradesAF = (int *)malloc(*result_count * sizeof(int));

	for (int i = 0; i < grades_count; i++)
	{
		gradesAF[i] = roundGrade(grades[i]);
	}

	return gradesAF;
}

int main()
{
	int grades_count;
	int result_count;

	scanf("%d", &grades_count);

	int *grades = (int *)malloc(sizeof(int) * grades_count);

	for (int i = 0; i < grades_count; i++)
	{
		scanf("%d", &grades[i]);
	}

	int *finalGrades = gradingStudents(grades_count, grades, &result_count);

	for (int i = 0; i < result_count; i++)
	{
		printf("%d\n", finalGrades[i]);
	}

	free(grades);
	free(finalGrades);
	return 0;
}
