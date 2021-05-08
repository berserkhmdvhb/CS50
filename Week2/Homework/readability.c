#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int sent_count();
int word_count();
int let_count();
int main(void)
{
    //printf("%s\n", argv[1]);
    //int k = get_int("Key: ");
    string text = get_string("Text: ");
    //3 functions for counting number of sentences, words, letters, respectively
    int sc = sent_count(text);
    int wc = word_count(text);
    int lc = let_count(text);
    //print all the counts
    printf("%i letter(s)\n%i word(s)\n%i sentence(s)\n", lc, wc, sc);
    //L is the average number of letters per 100 words in the text,
    float L = (float)(lc * 100) / wc;
    //S is the average number of sentences per 100 words in the text
    float S = (float)(sc * 100) / wc;
    // Coleman-Liau index.
    int grade = (int) round(0.0588 * L - 0.296 * S - 15.8);
    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int sent_count(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count += 1;
        }
    }
    return count;
}

int word_count(string text)
{
    int count = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            count += 1;
        }
    }
    return count;
}

int let_count(string text)
{
    //only counts lowercase and uppercase letters
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        {
            count += 1;
        }
    }
    return count;
}

