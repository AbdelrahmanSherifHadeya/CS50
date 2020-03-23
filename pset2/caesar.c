//A program that encrypts messages using Caesar’s cipher
//By getting an interger key in the same time with the execution of the program
//Prompt the user with plaintext and give a ciphertext
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    //checking if the user gave 2 arguments or not
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //this in case the other argument wasn't an inter or actually a letter i think if it can be done
    //with the previous check it would be better program
    int k = 0, x = strlen(argv[1]);
    while (k < x)
    {
        if (isalpha(argv[1][k]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        k++;
    }
    string plaintext = get_string("Plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, key = atoi(argv[1]), textlen = strlen(plaintext), answer; i < textlen; i++)
    {
        if (ispunct(plaintext[i]) || isspace(plaintext[i]))
        {
            printf("%c", plaintext[i]);
        }
        else if (islower(plaintext[i]) && plaintext[i] + key > 'z')
        {
            //decreasing the key by 26 the English alphabet in case the key was very large 65 for example :D
            while ((plaintext[i] + key - 26) > 'z')
            {
                key -= 26;
            }
            printf("%c", plaintext[i] + key - 26);
        }
        else if (isupper(plaintext[i]) && plaintext[i] + key > 'Z')
        {
            while ((plaintext[i] + key - 26) > 'Z')
            {
                key -= 26;
            }
            printf("%c", plaintext[i] + key - 26);
        }
        else
        {
            printf("%c", plaintext[i] + key);
        }
    }
    printf("\n");
    return 0;
}
