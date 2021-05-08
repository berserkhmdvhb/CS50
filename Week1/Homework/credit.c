#include <cs50.h>
#include <stdio.h>

void check();
int main(void)
{
    check();
}

void check(void)
{
    int i = 0;
    long n, m, t = 1, r = 0, twod, sum1 = 0, sum2 = 0;
    n = get_long("Card Number: ");
    m = n;
    //long r = (m % 10);
    //Luhn’s Algorithm and
    //counting number of digits
    while (m != 0)
    {
        //printf("\n%ld\n",r);
        //printf("\nsum1: %ld\nsum2: %ld\n",sum1,sum2);
        r = m % 10;
        m /= 10;
        if (i % 2 == 0)
        {
            sum1 += r;
        }
        else
        {
            sum2 += ((2 * r) % 10 + (2 * r) / 10);
            //printf("\n%ld\n",sum2);
        }
        i += 1;
    }
    //printf("\n%ld\n%ld\n%i\n",sum1,sum2,i);
    if ((sum1 + sum2) % 10 == 0)
    {
        // finding the first two digits (twod)
        //checking length as well the starting two digits
        for (int j = 1; j < i; j++)
        {
            t *= 10;
        }
        twod = n / (t / 10);
        //printf("\n%ld\n%i\n", twod, i);
        if (i == 15)
        {
            if (twod == 34 || twod == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        else if (i == 16)
        {
            if (51 <= twod && twod <= 55)
            {
                printf("MASTERCARD\n");
            }
            else if (40 <= twod && twod <= 49)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (i == 13)
        {
            if (40 <= twod && twod <= 49)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
            // if ((first == 3 && second == 4) || (first == 3 && second == 7))
        }
    }
    else
    {
        printf("INVALID\n");
    }

}


