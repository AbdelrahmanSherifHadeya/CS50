//Simple program to check wehther or not the credit card numbers are legit
#include <cs50.h>
#include <stdio.h>

int main(void)
{ 
    //getting intial valid number
    long number;
    do
    {
        number = get_long("Number: ");
    }
    //normally the expression was while (number < 1000000000000 || number > 10000000000000000);
    //but there was a problem with this, so I had to decrease the number
    while (number < 1000000000 || number > 10000000000000000);
    //calculating the number digits and getting to know the first 2 digits of the number
    int digits = 2;
    long strnumber = number;    
    while (strnumber > 100)
    {
        strnumber /= 10;
        digits++;
    }
    //using Luhn's algorithm
    int sum = 0, xsum = 0, extra;
    for (int i = 0; i < digits; i++)
    {
        if (i % 2 == 0) 
        {
            sum = sum + number % 10;
            number /= 10;
        }
        else
        {
            if ((number % 10 * 2) > 9)
            {
                extra = number % 10 * 2;
                xsum = xsum + extra % 10;
                extra /= 10;
                xsum += extra;
            }
            else
            {
                xsum = xsum + (number % 10 * 2);
            }
            number /= 10;
        }
    }
    if ((sum + xsum) % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    //deciding which credit card company is it
    if (strnumber == 34 || strnumber == 37) 
    {
        printf("AMEX\n");
    }
    else if (strnumber > 50 && strnumber < 56)
    {
        printf("MASTERCARD\n");
    }
    else if (strnumber / 10 == 4 && digits > 12)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
