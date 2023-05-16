#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string encript_text(string plaintext);

int main(int argc, string argv[])
{
	// Read CLA
	int k = 0;

	// Ask user to input plaintext
	string plaintext = get_string("plaintext: ");

	// Call function to change letters
	string ciphertext = encript_text(plaintext);

	// Print ciphertext
	printf("ciphertext: %s\n", ciphertext);

	return 0;
}

string encript_text(string plaintext)
{
	return plaintext;
}