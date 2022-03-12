#include <cs50.h>
#include <stdio.h>
#include <string.h>

/* Max number of candidates */
#define MAX 9

/* struct of candidates, each has name and a vote count */
typedef struct
{
    string name;
    int votes;
}
candidate;

/* Array of candidates */
candidate candidates[MAX];

/* Number of candidates */
int candidate_count;

/* Function prototypes */
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    /* Check for invalid usage */
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    /* Populate array of candidates */
    candidate_count = argc - 1;

    /* validate number of candidates to vote for */
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    /* getting all candidates names to start voting */
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    /* getting all candidates votes */
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        /* check votes for each candidate */
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    /* Display winner of election */
    print_winner();
}

/*  
    function: update number of votes for each name
    parameters: cpy_name (string): name of candidate
    return: true:  if there are for for the cadidatte
            false: if there are no votes for the candidate
*/
bool vote(string cpy_name)
{
    /* check if a certain name is voted for */
    for (int i = 0; i < candidate_count; i++)
    {
        if (cpy_name == candidates[i].name)
        {
            candidates[i].votes ++;
            return true;
        }
    }
    /* return false if no votes for certain name */
    return false;
}

/*  
    function: calculate max. number of votes and who is the winner
    parameters: void
    return:     void
*/void print_winner(void)
{
    /* defining local variables */
    int loc_max_vote = 0;

    /* figuring out max number of votes */
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > loc_max_vote)
        {
            loc_max_vote = candidates[i].votes;
        }
    }
    
    /* figuring out who got max number of votes */
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == loc_max_vote)
        {
            /* printing winner's name */
            printf("%s\n", candidates[i].name);
        }
    }
    
    return;
}

