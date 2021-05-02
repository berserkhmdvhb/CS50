#include <stdio.h>
#include <cs50.h>

float avg();
int main(void)
{
    int total = get_int("Number of Scores: ");
    int scores[total];
    for (int i = 0; i < total; i++)
    {
        scores[i] = get_int("Enter Score %i:",i+1);
    }
    printf("Average: %f\n", avg(total, scores));
}

float avg(int length, int arr[])
{
    int sum = 0;
    for (int i = 0;i < length; i++)
    {
        sum += arr[i];
    }
    return sum/ (float) length;

}