#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("n's place in memory is %p\n", p);
    printf("n again obtained by p: %i\n", *p);
    printf("The locaction of p in memory: %p\n", &p);
}