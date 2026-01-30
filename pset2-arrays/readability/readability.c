#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Prototypes
int count_words(int character);
int count_sentences(int character);
int count_letters(int character);
float average_per_100_words(float n, int words);
void coleman_liau(int total_words, int total_sentences, int total_letters);


// Main function
int main(void)
{
    // Get user input
    string text = get_string("Text: ");

    // Count number of words, sentences and letters
    int total_words = 1;
    int total_sentences = 0;
    int total_letters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int character = tolower(text[i]);

        total_words += count_words(character);
        total_sentences += count_sentences(character);
        total_letters += count_letters(character);
    }

    coleman_liau(total_words, total_sentences, total_letters);

}





// Function: Count number of words
int count_words(int character)
{
    int words = 0;

    // A space (ASCII value 32) denotes the end of a word
    if (character == 32)
    {
        words += 1;
    }

    return words;
}


// Function: Count number of sentences
int count_sentences(int character)
{
    int sentences = 0;

    // An exclamation mark, full stop and question mark denotes the end of a sentence
    if (character == 33 || character == 46 || character == 63)
    {
        sentences += 1;
    }

    return sentences;
}


// Function: Count number of letters
int count_letters(int character)
{
    int letters = 0;

    if (character > 96 && character < 123)
    {
        letters += 1;
    }

    return letters;
}


// Function: Calculate average per 100 words
float average_per_100_words(float n, int words)
{
    float average = (n / words) * 100;
    return average;
}


// Function: Calculate Coleman-Liau index
void coleman_liau(int total_words, int total_sentences, int total_letters)
{
    // Calculate the average number of sentences
    float avg_letters = average_per_100_words(total_letters, total_words);
    float avg_sentences = average_per_100_words(total_sentences, total_words);

    float index = 0.0588 * avg_letters - 0.296 * avg_sentences - 15.8;

    if (index < 1)
    {
        printf("Grade: Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade: Grade 16+\n");
    }
    else
    {
        int final_grade;
        final_grade = round(index);
        printf("Grade %i\n", final_grade);
    }
}
