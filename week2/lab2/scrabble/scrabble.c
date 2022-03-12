/* including lib. */
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

/* global variable */
/* Points assigned to each letter of the alphabet */
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

/* functions prototypes */
int compute_score(string cpy_word);

int main(void)
{
    /* defining variables */
    string word1, word2;
    int score1, score2;
    
    /* Get input words from both players */
    word1 = get_string("Player 1: ");
    word2 = get_string("Player 2: ");

    /* calculate score of both words */
    score1 = compute_score(word1);
    score2 = compute_score(word2);
    
    /* printing the winning word */
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    
    /* in case of equevelance */
    else
    {
        printf("Tie!\n");
    }
}

/*  
    function: calculates the score of a given word based on pre-set wight
    parameters: cpy_word (string): word to check its letters' score
    return:     loc_score (int):   score of each letter of the word
*/

int compute_score(string cpy_word)
{
    /* defining local variables */
    int loc_pos, loc_score = 0;
    
    /* summing each letter's score */
    for (int i = 0; cpy_word[i] != '\0'; i++)
    {
        /* if letter is uppercase */
        if ((cpy_word[i] >= 'A') && (cpy_word[i] <= 'Z'))
        {
            loc_pos = cpy_word[i] - 'A';
            loc_score += POINTS[loc_pos];
        }
        
        /* if letter is lowercase */
        else if ((cpy_word[i] >= 'a') && (cpy_word[i] <= 'z'))
        {
            loc_pos = cpy_word[i] - 'a';
            loc_score += POINTS[loc_pos];
        }
    }
    return loc_score;
}
