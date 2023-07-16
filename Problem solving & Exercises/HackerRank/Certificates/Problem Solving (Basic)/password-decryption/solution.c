#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to decrypt the password
char *decryptPassword(char *s)
{
	int len = strlen(s); // Length of the input string
	int NumIndex = 0;	 // Index of the last non-zero digit encountered

	int PassSize = 0;	   // Size of the password string
	char *password = NULL; // Pointer to the password string

	for (int i = 0; i < len; i++)
	{
		if (isdigit(s[i]) && s[i] != '0')
		{
			NumIndex++;
			continue;
		}
		else if ((i < len - 2) && s[i + 2] == '*')
		{
			// If the next two characters form a pair to be decrypted
			PassSize += 2; // Increase the password size by 2
			password = (char *)realloc(password, PassSize * sizeof(char));
			password[PassSize - 1] = s[i];	   // Assign the first character of the pair
			password[PassSize - 2] = s[i + 1]; // Assign the second character of the pair
			i += 2;							   // Skip the next two characters since they have been processed
		}
		else if (s[i] == '0')
		{
			// If the current character is '0', indicating decryption of previous non-zero digit
			PassSize++; // Increase the password size by 1
			password = (char *)realloc(password, PassSize * sizeof(char));
			password[PassSize - 1] = s[NumIndex - 1]; // Assign the last non-zero digit encountered
			NumIndex--;								  // Decrement NumIndex to update the index of the last non-zero digit
		}
		else
		{
			// Regular character in the decrypted password
			PassSize++; // Increase the password size by 1
			password = (char *)realloc(password, PassSize * sizeof(char));
			password[PassSize - 1] = s[i]; // Assign the current character
		}
	}

	if (password != NULL)
	{
		password[PassSize] = '\0'; // Add null-terminating character at the end of the password string
	}

	return password; // Return the decrypted password string
}
int main()
{
	char s[10005]; // Input string

	scanf("%s", s); // Read input from user

	char *originalPassword = decryptPassword(s); // Decrypt the password
	printf("%s\n", originalPassword);			 // Print the decrypted password

	free(originalPassword); // Free the allocated memory

	return 0;
}
