/* including lib */
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    /* defining variables */
    int height;
    int i, j, k, m;
    
    /* getting and validating user input */
    do
    {
        height = get_int("Height: ");
    } 
    while ((height < 1) || (height > 8));
    
    /* printing # and white spaces */
    for (i = 0; i < height; i++)
    {
        for (j = (height - 1); j > i; j--)
        {
            printf(" ");
        }
        
        for (k = 0; k <= i; k++)
        {
            printf("#");
        }
        
        printf("  ");
        
        for (m = 0; m <= i; m++)
        {
            printf("#");
        }
        
        printf("\n");
    }
    
}