/* include lib. */
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    /* define variables */
    int start, end, yrs = 0;
    
    /* get and validate start size */
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    /* get and validate end size */
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);
    
    /* Calculate number of years until we reach threshold */
    while (start < end)
    {
        start = start + (start / 3) - (start / 4);
        yrs ++;
    }

    /* Print number of years */
    printf("Years: %i", yrs);
}