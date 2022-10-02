#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc == 2 && isdigit(*argv[1]))
    {
        int temp = atoi(argv[1]);
        printf("You entered: %d\n", temp);

    }
    else {
        printf("Usage: ./test temperature\n");
        return 1;
    }
    return 0;
}
