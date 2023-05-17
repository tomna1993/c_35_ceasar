#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int string_to_int(string number_text);
int power_of(int num, int powerOn);
string encript_text(string plaintext);

int main(int argc, string argv[])
{
	// Read CLA
	if (argc != 2)
	{
		printf("Usage: ./build/ceasar key\n");
		return 1;
	}

	int k = string_to_int(argv[1]);

	// Ask user to input plaintext
	string plaintext = get_string("plaintext: ");

	// Call function to change letters
	string ciphertext = encript_text(plaintext);

	// Print ciphertext
	printf("ciphertext: %s\n", ciphertext);

	return 0;
}

// Convert string number to integer number
int string_to_int(string number_text)
{
	// Get the length of the string 
	// Decrease it by one because strlen returns with the 
	// number of letters in the string
	// but the string array starts with index 0 
	int digits = strlen(number_text) - 1;

	// Declare variable to save the converted string
	int number = 0;
	int ten_power_of = 0;

	// Iterate through the digits starting the 0th index
	for (int i = 0; i <= digits; i++)
	{
		// If the character is not digit return with the number
		// Be careful, if the string is "34x5" just the 5 will be returned 
		if (!isdigit(number_text[digits - i]))
		{
			// printf("String %s is %i in decimal\n", number_text, number);
			return number;
		}
		
		// Calculate the power of 10
		ten_power_of = power_of(10, i);

		// Read the character (f.e. 8 = in ascii DEC 56)
		// 56 - 48 = 8
		// Digit = 8 * 10^ digit place - 1 (ones place = 10^0; tens place = 10^1)
		number += (number_text[digits - i] - 48) * ten_power_of;
	}

	// Debug code
	// printf("String %s is %i in decimal\n", number_text, number);
	// Return the converted string as integer
	return number;
}

// Calculate given number on power of another nuber
int power_of(int num, int powerOn)
{
	// A number on power of 0 is 1 
	if (powerOn == 0)
	{
		return 1;
	}
	
	// Declare and set a variable to calculate power of
	int power_of_num = 1;
	
	for(int i = powerOn; i > 0; i--)
	{
		power_of_num *= num;		
	}

	return power_of_num;
}

// Encript text and return with encrypted text
string encript_text(string plaintext)
{
	return plaintext;
}