#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Array of scores
int scores[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};


// Prototype
int count_points(string word);


// Main function
int main(void)
{

    // Get user input
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // Count the number of points
    int points1 = count_points(player1);
    int points2 = count_points(player2);

    // Find player with the highest number of points
    if (points1 > points2)
    {
        printf("Player 1 wins!\n");
    }
    else if (points2 > points1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}





// Function: Count number of points for each letter in the word
int count_points(string word)
{
    char letter;
    int points = 0;

    // Iterate over each letter in the word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Convert lowercase letters to uppercase letters
        letter = toupper(word[i]);

        // Identify uppercase letters using ASCII values
        if (letter >= 65 && letter <= 90)
        {
            // Identify the position of letter
            int position = letter - 65;

            // Calculate scrabble score by summing the scores of each letter depending on its postion in the array
            points += scores[position];
        }
    }

    return points;
}
