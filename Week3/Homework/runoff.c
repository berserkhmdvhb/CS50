#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

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
}
candidate;

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
            for (int j = 0; j < candidate_count; j++)
            {
                if (!candidates[j].eliminated)
                {
                    printf("%s\n", candidates[j].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int j = 0; j < candidate_count; j++)
        {
            candidates[j].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
    bool occur = false;
    // record index of the candidate(j) in preferences array for ith voter and jth rank
    for (int j = 0; j < candidate_count; j++)
    {
        if (strcmp(candidates[j].name, name) == 0)
        {
            preferences[voter][rank] = j;
            occur = true;
        }
    }
    return occur;
}


// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    // add votes to
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (!candidates[preferences[i][j]].eliminated)
            {
                candidates[preferences[i][j]].votes += 1;
                //printf("%s\n", candidates[j].name);
                //since we want to only increase the vote of the top preferred candidate, we break here
                break;
            }
        }

    }

    return;
}


// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    bool occur = false;
    double sum = 0;
    for (int j = 0; j < candidate_count; j++)
    {
        sum += (double) candidates[j].votes;
    }
    sum = floor(sum / 2);
    for (int j = 0; j < candidate_count; j++)
    {
        if (((double) candidates[j].votes) > sum)
        {
            printf("%s\n", candidates[j].name);
            occur = true;
        }
    }
    return occur;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    int min = MAX_VOTERS;
    for (int j = 0; j < candidate_count; j++)
    {
        if (!candidates[j].eliminated && candidates[j].votes < min)
        {
            min = candidates[j].votes;
            //printf("min done: %i\n", min);
        }
    }
    return min;
}



// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    bool occur = true;
    // in case any of the votes were not eual to zero, then flag will be changed to 0
    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes != min && !candidates[j].eliminated)
        {
            occur = false;
        }
    }
    return occur;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes == min)
        {
            candidates[j].eliminated = true;
            //printf("eliminate %s: done\n", candidates[j].name);
        }
    }
    return;
}
