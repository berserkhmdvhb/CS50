#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s = "HI!";
    printf("s as a pointer: %p\n", s);
    printf("pointing to s: %c\n", *s);
    printf("s's location in memory: %p\n\n", &s);
    printf("s[0]'s location: %p", &s[0]);
}