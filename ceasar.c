#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int power_of(int num, int powerOn);
void encript_text(string plaintext, const int key);

int main(int argc, string argv[])
{
	// Read CLA and check if there are two argument entered by user
	// ./build/ceasar.c key
	if (argc != 2)
	{
		printf("Usage: ./build/ceasar key\n");
		return 1;
	}

	// Check if the key given by the user contains just digits
	for (int i = 0, length = strlen(argv[1]); i < length; i++)
	{
		if (!isdigit(argv[1][i]))
		{
			printf("Usage: ./build/ceasar key\n");
			return 1;
		}
	}

	// convert the key string to an integer
	int k = atoi(argv[1]);

	// Ask user to input plaintext
	string plaintext = get_string("plaintext: ");

	// Call function to change letters
	encript_text(plaintext, k);

	// Print ciphertext
	printf("ciphertext: %s\n", plaintext);

	return 0;
}

// Encript text and return with encrypted text
void encript_text(string plaintext, const int key)
{
	// Get the length of the plaintext string
	int length = strlen(plaintext);

	// Create constant for uppercase A letter's decimal value 
	const int uppercaseA_ASCII = 65;
	// Create constant for lowercase A letter's decimal value
	const int lowercaseA_ASCII = 97;

	// Declare a variable c for counting the characters from 0
	// Char A is 0, B is 1, C is 2 ...
	int c = 0;

	// Iterate through the string array
	for (int i = 0; i < length; i++)
	{
		// If character is other non alphabetical character then don't change it
		// Check if character is alphabetical and uppercase
		if (isalpha(plaintext[i]) && isupper(plaintext[i]))
		{
			// Subtract 'A' decimal value from the character and add key
			// f.e. plaintext[i] = 'A', then 'A' = 65 in ASCII, key = 1
			// 65 - 65 + 1 = 1, then calculate the remainder when devided by 26 
			// c = 1 
			c = (plaintext[i] - uppercaseA_ASCII + key) % 26;	

			// Add back the 'A's ASCII decimal value 
			// plaintext[i] = 1 + 65 = 66 = 'B'
			plaintext[i] = c + uppercaseA_ASCII;	
		}
		
		// Check if character is alphabetical and lowercase
		else if (isalpha(plaintext[i]) && islower(plaintext[i]))
		{
			// Subtract 'a' decimal value from the character and add key
			// f.e. plaintext[i] = 'a', then 'a' = 97 in ASCII, key = 1
			// 97 - 97 + 1 = 1, then calculate the remainder when devided by 26 
			// c = 1 
			c = (plaintext[i] - lowercaseA_ASCII + key) % 26;	

			// Add back the 'a's ASCII decimal value 
			// plaintext[i] = 1 + 97 = 98 = 'b'
			plaintext[i] = c + lowercaseA_ASCII;	
		}
	}
}