//Program based on Greedy Algorithm
//Minimze the number of coins in change as much as possible
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{   
    int change = 0;
    float owed;
    //getting positive number
    do
    {
        owed = get_float("Change owed: ");
    }
    while (owed < 0);
    //converting the float or just my solution to deal with them 
    owed *= 100;
    while (round(owed) >= 25)
    {
        owed -= 25;
        change++;
    }
    while (round(owed) >= 10)
    {
        owed -= 10;
        change++;
    }
    while (round(owed) >= 5)
    {
        owed -= 5;
        change++;
    }
    while (round(owed) >= 1)
    {
        owed -= 1;
        change++;
    }
    printf("%i\n", change);
}
