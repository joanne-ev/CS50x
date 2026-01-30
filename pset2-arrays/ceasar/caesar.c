#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h> // For atoi()

int ascii_value;
int alphabet;
int position;
char encrypted_character;


int ceasar_algorithm(int character, int k)
{
    int new_alphabet = (character + k) % 26;

    return new_alphabet;
}


void ceasar(int k, string plaintext)
{

    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        ascii_value = plaintext[i];

        // If letter is uppercase
        if (ascii_value > 64 && ascii_value < 91)
        {
            // Convert from ASCII value to alphabet position
            alphabet = ascii_value - 64;

            // Ceasar's algorithm
            int new_alphabet = ceasar_algorithm(alphabet, k);

            // Revert from alphabet position to ASCII value
            encrypted_character = new_alphabet + 64;

        }

        // If letter is lowercase
        else if (ascii_value > 96 && ascii_value < 123)
        {
            // Convert from ASCII value to alphabet position
            alphabet = ascii_value - 96;

            // Ceasar's algorithm
            int new_alphabet = ceasar_algorithm(alphabet, k);

            // Revert from alphabet position to ASCII value
            encrypted_character = new_alphabet + 96;
        }

        else
        {
            encrypted_character = ascii_value;
        }

        printf("%c", encrypted_character);
    }

    printf("\n");
}



int main(int argc, string argv[])
{

    // If more than two arguments are present
    if (argc != 2)
    {
        printf("Missing command-line argument\n");
        return 1;
    }

    // If input is not a positive number
    else
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            int character = argv[1][i];

            if (character < 48 || character > 57)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }

    // Convert string to integer
    int k = atoi(argv[1]);

    // Get plaintext input
    string plaintext = get_string("plaintext:  ");

    // Encrypt message
    ceasar(k, plaintext);
}
