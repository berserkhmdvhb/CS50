#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(int argc, string argv[])
{
    if (argc == 2 && isdigit(*argv[1]))
    {
    int k = atoi(argv[1]);
    person people[k];

    for (int i = 0; i < k; i++)
    {
        people[i].name = get_string("Enther the person %i,'s name: ",i+1);
        people[i].number = get_string("Enther the person %i,'s number: ",i+1);
    }

    for (int i = 0; i < k; i++)
    {
      if(strcmp(people[i].name, "David") == 0)
      {
          printf("Found %s\n", people[i].number);
          return 0;
      }

    }
    printf("Not Found\n");
    return 1;
    }

    else
    {
    printf("Usage: database number of elements put wrong format!\n");
    return 1;
    }
}