#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX_NAME_LENGTH 30

typedef union
{
	char first_name[MAX_NAME_LENGTH];
	char last_name[MAX_NAME_LENGTH];
} family_name_u;

// @test
void test_family_name(char* first_name, char* last_name)
{
	assert(strcmp(first_name, last_name) == 0);
	assert(sizeof(family_name_u) == MAX_NAME_LENGTH);
	printf("\n===All tests passed===\n");
}

int main()
{
	family_name_u name;
	strcpy(name.first_name, "Hossam");

	printf("Last name: %s\n", name.last_name);
	printf("Size of union: %lu\n", sizeof(name));

	// extra test :)
	test_family_name(name.first_name, name.last_name);
	return 0;
}