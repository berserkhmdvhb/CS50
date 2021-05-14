#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
int ar[10];
printf("%p\n", ar);
printf("%p\n", &ar[0]);
printf("%p\n", &ar[1]);
}