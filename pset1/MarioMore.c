//Building Mario's Pyramids
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //getting the valid height
    int height;
    do
    {
        height = get_int("height: ");
    }
    while (height < 1 || height > 8);

    //buliding the pyramid
    int x = height;
    for (int i = 1; i < height + 1; i++)
    {
        for (int j = 1; j < x; j++)
        {
            printf(" ");
        }
        x--; //decrement for x so the space will be aligned with hashes
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int z = 0; z < i; z++)
        {
            printf("#");
        }
        printf("\n");
    }
}
