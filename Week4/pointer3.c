// Capitalizes a copy of a string

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Get a string
    char *s = get_string("s: ");

    // Allocate memory for another string
    char *t = malloc(strlen(s) + 1);
    if (t == NULL)
    {
        return 1;
    }

    // Copy string into memory
    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
        // equiavlently: *(t + i) = *(s + i);
    }

    // Capitalize copy
    if (strlen(t) > 0)
    {
    t[0] = toupper(t[0]);
    //equivalently: *t = toupper(*t);
    }
    // Print strings
    printf("s: %s\n", s);
    printf("t: %s\n", t);
    free(t);
}