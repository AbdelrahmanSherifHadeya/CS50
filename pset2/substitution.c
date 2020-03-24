//A program that implements a substitution cipher
//Takes 26 alphabetic characters as a key and incipher a plaintext based on them
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //checking the key from line 10 to line 53
    //checking if the user gave 2 arguments or not
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //26 character or not
    if (strlen(argv[1]) != 26)
    {
        printf("key must contain 26 characters.\n");
        return 1;
    }
    //checking if it's all alphabet or not
    int argvlen = strlen(argv[1]);
    for (int i = 0; i < argvlen; i++)
    {
        if (isalpha(argv[1][i]) == false)
        {
            printf("key must only contain alphabetic characters.\n");
            return 1;
        }
    }
    //initializing 2 dimensional array to use it in the key check and incipher the text
    //i don't know if it's unnecessary step or not tbh please let me know
    char alphabet[2][26];
    for (int i = 0; i < argvlen; i++)
    {
        alphabet[0][i] = 'A' + i;
        alphabet[1][i] = argv[1][i];
    }
    //checking for repeated items inside the key 2 or more of the same letter
    for (int i = 0; i < argvlen; i++)
    {
        int j = 0;
        for (int k = 0; k < argvlen; k++)
        {
            if (toupper(alphabet[1][k]) == toupper(alphabet[1][i]))
            {
                j++;
                if (j == 2)
                {
                    printf("repeated value, check the key\n");
                    return 1;
                }
            }
        }
    }
    //finally made it to the algorithm; please recommend something better
    string plaintext = get_string("Plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, j = strlen(plaintext); i < j; i++)
    {
        if (isalpha(plaintext[i]))
        {  
            if (islower(plaintext[i]))
            {
                for (int k = 0; k < argvlen; k++)
                {
                    if (tolower(alphabet[0][k]) == plaintext[i])
                    {   
                        printf("%c", tolower(alphabet[1][k]));
                    }
                }
            }
            if (isupper(plaintext[i]))
            {
                for (int k = 0; k < argvlen; k++)
                {
                    if (toupper(alphabet[0][k]) == plaintext[i])
                    {   
                        printf("%c", toupper(alphabet[1][k]));
                    }
                }
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}
