//Program to make mario's pyramid
#include <cs50.h>
#include <stdio.h>

int main(void)
{   
    int height;
    //checking if the input is between 1 to 8
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);
    //3 for loops 2 inside 1 which isn't the best way, can you implment something better?
    for (int i = 0; i < height; i++)
    {
        for (int j = 1; j < height - i; j++)
        {
            printf(" ");
        }
        for (int k = -1; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
