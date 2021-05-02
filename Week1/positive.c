#include <cs50.h>
#include <stdio.h>

int get_pos_int();
int main(void)
{
    get_pos_int();
}

int get_pos_int(void)
{
    int n;
    do
    {
        n = get_int("Positive Integer Input: ");
    }
    while (n < 1);
    return n;
}