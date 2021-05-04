#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[] = {"Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"};
    char ch = 'r';
    for (int i = 0; i < sizeof(names); i++)
    {
        //strcmp check if two strings are eual
        printf("cmp: %i\n",strcmp(names[i], "Ron"));

        //strch checks for the characters after first occurence of ch in the string
        printf("chr: %s\n",strchr(names[i], ch));
    }
}