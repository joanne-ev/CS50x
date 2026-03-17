#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // Loop through each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // Check if name is a match for the name of a valid candidate
        if (strcmp(candidates[i].name, name) == 0)
        {
            // Update the global preferences array to indicate that the voter `voter` has that candidate as their rank preference
            preferences[voter][rank] = i;

            // If the preference is successfully recorded, the function should return true
            return true;
        }
    }

    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // Loop over each vote
    for (int i = 0; i < voter_count; i++)
    {
        // Loop over each candidate
        for (int j = 0; j < candidate_count; j++)
        {
            // Identify the voters's choice candidate
            int voter_choice = preferences[i][j];

            // Check that the voters's choice candidate is not eliminated
            if (candidates[voter_choice].eliminated == false)
            {
                // Update votes for each voter’s preferred candidate
                candidates[voter_choice].votes += 1;

                // Stop after the voter’s first non-eliminated candidate is cast
                break;
            }
        }
    }

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int half_votes = voter_count / 2;

    // Loop through each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // Check if any candidate has more than half of the vote
        if (candidates[i].votes > half_votes)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }

    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min_votes = voter_count;

    // Loop through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // Check that the candidate is not eliminated
        if (candidates[i].eliminated == false)
        {
            // Compare candidates's votes with min_votes
            if (candidates[i].votes < min_votes)
            {
                // If candidates's votes is less than min_votes assign candidates's votes as new min_votes value
                min_votes = candidates[i].votes;
            }
        }
    }

    return min_votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int tie = 0;
    int not_eliminated = 0;

    // Loop over all non-eliminated candidates
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false)
        {
            // Count the number of non-eliminated candidates
            not_eliminated++;

            // Compare candidate's votes with min votes
            if (candidates[i].votes == min)
            {
                // Add 1 to tie if candidate's votes equal the min votes
                tie++;
            }
        }
    }

    // If the number of candidates with the min votes equals the number of non-eliminated candidates a tie is declared
    if (tie == not_eliminated)
    {
        return true;
    }

    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // Eliminate the candidate (or candidates) who have min number of votes

    // Loop over each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // Identify non-eliminated candidates with min votes
        if (candidates[i].eliminated == false && candidates[i].votes == min)
        {
            // Eliminate this candidate
            candidates[i].eliminated = true;
        }
    }

    return;
}
