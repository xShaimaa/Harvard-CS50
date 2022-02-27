/* inluding lib */ 
#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    /* declaring variables */
    float change;
    int counter = 0;
    
    /* getting and validating input from user */
    do
    {
        change = get_float("Change owed: ");
        /* round up the dollars to cents (dollar = 100 * cent) */
        change = round(change * 100);
    }
    while (change < 0);
    
    /* checking for change of each set */
    while (change > 0)
    {
        if (change >= 25)
        {
            change -= 25;
        }
        
        else if (change >= 10)
        {
            change -= 10;
        }
        
        else if (change >= 5)
        {
            change -= 5;
        }
        
        else if (change >= 1)
        {
            change --;
        }
        
        counter ++;
    }
    
    printf("%d\n", counter);
}
