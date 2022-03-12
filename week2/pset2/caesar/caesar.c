/* inluding lib */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cs50.h>

/* defining macros */
#define LETTERS_COUNT 26

/* functions prototype */
string encrypt_txt(string cpy_txt, int cpy_key);

int main(int argc, string argv[])
{
    /* declaring variables */
    string plain_txt, cipher_txt;
    int key;

    /* checking inputs if user ran the program corectly */
    if (argc == 2)
    {
        /* validating the entered key is a digit */
        for (int i = 0; argv[1][i] != '\0'; i++)
        {
            if (((argv[1][i] <= '0') || (argv[1][i] >= '9')))
            {
                /* printing the correct way to run the program to user*/
                printf("Usage: ./caesar key");
                return 1;
            }
        }
    }
    
    /* if user didn't enter 2 arguments */
    else 
    {
        /* printing the correct way to run the program to user*/
        printf("Usage: ./caesar key");
        return 1;
    } 
    
    /* converting input key from string to int */
    key = atoi(argv[1]);
    
    /* getting plain text from user */
    plain_txt = get_string("plaintext: ");
    
    /* encrypting plain text by given key */
    cipher_txt = encrypt_txt(plain_txt, key);
    
    /* printing out cipher text to user */
    printf("ciphertext: %s\n", cipher_txt);
}

/*  
    function:   encrypts a given string by a given key
    parameters: cpy_txt (string): the plain text to be encrypted
                cpy_key (int)   : the key to encrypt text by
    return:     cpy_txt (string): the encrypted text  
*/
string encrypt_txt(string cpy_txt, int cpy_key)
{
    /* go through every letter to encrypt, not that ci = (pi + k) % 26 */
    for (int i = 0; cpy_txt[i] != '\0'; i++)
    {
        /* if the letter is uppercase */
        if ((cpy_txt[i] >= 'A') && (cpy_txt[i] <= 'Z'))
        {
            cpy_txt[i] = (((cpy_txt[i] - 'A')+ cpy_key) % LETTERS_COUNT) + 'A';
        }
        
        /* if the letter is a lowercase */
        else if ((cpy_txt[i] >= 'a') && (cpy_txt[i] <= 'z'))
        {
            cpy_txt[i] = (((cpy_txt[i] - 'a')+ cpy_key) % LETTERS_COUNT) + 'a';
        }
        
        /* if the letter is digit, white space or mark */
        else
        {
            cpy_txt[i] = cpy_txt[i];
        }
    }
    return cpy_txt;
}
