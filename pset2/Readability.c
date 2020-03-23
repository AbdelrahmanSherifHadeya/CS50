//Program based on Coleman-Liau index
//Any sequence of characters that ends with a . or a ! or a ? is a sentence according to that program
//So Mr. and Mrs. are 2 sentences which lower it's accuracy
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string text = get_string("text: ");
    float sentences = 0, letters = 0, words = 0;
    int i = 0;
    while (text[i] != '\0')
    {
        //this decrease the accuracy of the app but overall it's acceptable
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
        if (isalpha(text[i]))
        {
            letters++;
            //i think there is a better way to decided wether or not this is a word but i didn't get it
            if (isspace(text[i + 1]) || ispunct(text[i + 1]) || text[i + 1] == '\0')
            {
                if (text[i + 1] != '\'' && text[i + 1] != '-')
                {
                    words++;
                }
            }
        }
        i++;
    }
    //using Coleman-Liau index formula
    sentences *= 100 / words;
    letters *= 100 / words;
    float index = 0.0588 * letters - 0.296 * sentences - 15.8;
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(index));
    }
}
