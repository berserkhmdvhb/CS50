#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void encrypt();
int main(int argc, string argv[])
{
      //printf("%s\n", argv[1]);
      //int k = get_int("Key: ");

      if (argc == 2 && isdigit(*argv[1]))
      {
            int k = atoi(argv[1]);
            //printf("%i\n", i);
            //printf("%c\n", (char)i);
            string str = get_string("plaintext: ");
            encrypt(str, k);
            return 0;

      }
      else
      {
            printf("Usage: ./caesar key\n");
            return 1;
      }
}


void encrypt(string str, int k)
{
      //string enc = str;
      char enc[strlen(str)];
      for(int i = 0; i < strlen(str); i++)
      {
            char shift = str[i];
            // check if it i'th elements is lowercase 97 = a to 112 = z
            if ('a' <= str[i] && str[i] <= 'z')
            {
                  //from shift roll back by 'a' and then add key, go to modulo 26, add 'a' to roll between lowercases
                  shift = (((shift - 'a') + k) % 26) + 'a';
            }
            // check if it i'th elements is uppercase
            else if ('A' <= str[i] && str[i] <= 'Z')
            {
                  shift = (((shift - 'A') + k) % 26) + 'A';
            }
            enc[i] = shift;
      }
      printf("ciphertext: %s\n", enc);
}