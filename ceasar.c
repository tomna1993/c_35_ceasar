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

int string_to_int(string number_text)
{
	int digits = strlen(number_text) - 1;

	int number = 0;
	int ten_power_of = 0;

	for (int i = 0; i <= digits; i++)
	{
		if (!isdigit(number_text[digits - i]))
		{
			return number;
		}
		
		ten_power_of = power_of(10, i);

		number += (number_text[digits - i] - 48) * ten_power_of;
	}

	printf("String %s is %i in decimal\n", number_text, number);
	return number;
}

int power_of(int num, int powerOn)
{
	if (powerOn == 0)
	{
		return 1;
	}
	
	int power_of_num = 1;
	
	for(int i = powerOn; i > 0; i--)
	{
		power_of_num *= num;		
	}

	return power_of_num;
}

string encript_text(string plaintext)
{
	return plaintext;
}