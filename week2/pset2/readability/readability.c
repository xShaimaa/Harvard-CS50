/* inluding lib */
#include <stdio.h>
#include <math.h>
#include <cs50.h>

/* functions prototype */
int calc_letters(string cpy_txt);
int calc_words(string cpy_txt);
int calc_sentences(string cpy_txt);
int coleman_liau_algo(float cpy_l, float cpy_w, float cpy_s);

int main(void)
{
    /* declaring variables */
    string txt;
    int letters_num, words_num, sentences_num, grade = 0;

    /* getting input from user */
    txt = get_string("text: ");
    
    /* calculating letters, words and sentences counts */
    letters_num = calc_letters(txt);
    words_num = calc_words(txt);
    sentences_num = calc_sentences(txt);
    
    /* performing coleman liau's algorithm */
    grade = coleman_liau_algo((float)letters_num, (float)words_num, (float)sentences_num);

    /* printing apropriat grade */
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }

    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }

    else
    {
        printf("Grade %i\n", grade);
    }
}

/*
    description: counts letters on a given text
    parameters:  cpy_txt (string): text to count letters on
    return:      loc_letters_num (int): number of calculated letters
*/
int calc_letters(string cpy_txt)
{
    /* local variables*/
    int loc_letters_num = 0;

    /* calculating each letter in cpy_txt*/
    for (int i = 0; cpy_txt[i] != '\0'; i++)
    {
        if (((cpy_txt[i] >= 'a') && (cpy_txt[i] <= 'z')) || ((cpy_txt[i] >= 'A') && (cpy_txt[i] <= 'Z')))
        {
            loc_letters_num ++;
        }
    }
    return loc_letters_num;
} 

/*
    description: counts words on a given text
    parameters:  cpy_txt (string): text to count letters on
    return:      loc_words_num (int): number of calculated words
*/
int calc_words(string cpy_txt)
{
    /* local variables*/
    int loc_words_num = 1;

    /* calculating each word in cpy_txt*/
    for (int i = 0; cpy_txt[i] != '\0'; i++)
    {
        if (cpy_txt[i] == ' ')
        {
            loc_words_num ++;
        }
    }
    return loc_words_num;
}

/*
    description: counts sentences on a given text
    parameters:  cpy_txt (string): text to count letters on
    return:      loc_sentences_num (int): number of calculated sentences
*/
int calc_sentences(string cpy_txt)
{
    /* local variables*/
    int loc_sentences_num = 0;

    /* calculating each sentence in cpy_txt*/
    for (int i = 0; cpy_txt[i] != '\0'; i++)
    {
        if ((cpy_txt[i] == '.') || (cpy_txt[i] == '?') || (cpy_txt[i] == '!'))
        {
            loc_sentences_num ++;
        }
    }
    return loc_sentences_num;
}

/*
    description: performs Coleman Liau algorithm on a text
    parameters:  cpy_l (float): number of letters on a text
                 cpy_w (float): number of words on a text
                 cpy_s (float): number of senteces on a text
    return:      loc_index (int): the grade a text is suitable for
*/
int coleman_liau_algo(float cpy_l, float cpy_w, float cpy_s)
{
    /* local variables */
    int loc_index = 0;

    /* calculating number of letters and sentences per words */
    cpy_l = (100 * cpy_l) / cpy_w;
    cpy_s = (100 * cpy_s) / cpy_w;
  
    /* performing the formula */
    loc_index = round(0.0588 * cpy_l - 0.296 * cpy_s - 15.8);
    
    /* return rounded index */
    return loc_index;
}

