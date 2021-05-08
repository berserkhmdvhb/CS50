#include <stdio.h>
#include <cs50.h>
void hash();
int main(void)
{
    hash();
}

void hash(void)
{
    int i, space, rows, k = 0;
    //prompt for proper number of rows
    do
    {
        rows = get_int("Enter the number of rows: ");
    }
    while (rows < 1 || rows > 8);


    for (i = 1; i <= rows; ++i, k = 0)
    {
        //create initial spaces for each row
        for (space = 1; space <= rows - i; ++space)
        {
            printf(" ");
        }
        //print the hash marks
        while (k != 2 * i)
        {
            printf("#");

            //print space if it reached the middle
            if (k == i - 1)
            {
                printf("  ");
            }
            ++k;
        }
        printf("\n");
    }
}
