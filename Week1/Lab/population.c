#include <cs50.h>
#include <stdio.h>

void pop();
int main(void)
{
 pop();
}


void pop(void)
{
    int i = 0;
    int start;
    int end;

    //Prompt for start size
    do
    {
        start = get_int("Start Size: ");
    }
    while (start < 9);

    //Prompt for end size
    do
    {
        end = get_int("End Size: ");
    }
    while (end < start);

    // Calculate number of years until we reach threshold
    // np: new population
    int np = start;
    while (np < end)
    {
        np = np + np/3 - np/4;
        i++;
    }
    printf("Years: %i\n",i);
}
