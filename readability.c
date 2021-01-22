//This is solution that I created for CS50 2020 class problem set 2.
//Author : 430lyj
//Any suggestions would be appreciated! :)

#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include <math.h>

int letter(string);
int sentence(string);
int word(string);
int main(void)

{
    string text = get_string("What is your text?\n");
    float k = 0.0588 * letter(text) * 100 / word(text) - 0.296 * sentence(text) * 100 / word(text) - 15.8;
    if (k > 1 && k < 17)
    {
        printf("Grade %.i\n", (int) round (k));
    }
    else if (k >= 17)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}

//how many letters in the text
int letter(string text)
{
    int lsum = 0;
    for (int k = 0; k < strlen(text); k++)
    {
        if (isalpha(text[k]) != 0)
        {
            lsum += 1;
        }
        else
        {
            lsum += 0;
        }
    }
    return lsum;
}
// how many sentences in the text
int sentence(string text)
{
    int ssum = 0;
    for (int k = 0; k < strlen(text); k++)
    {
        if (text[k] == '.' || text[k] == '!' || text[k] == '?')
        {
            ssum += 1;
        }
        else
        {
            ssum += 0;
        }
    }
    return ssum;
}
//how many words in the text
int word(string text)
{
    int wsum = 0;
    for (int k = 0; k < strlen(text); k++)
    {
        if (text[k] == ' ')
        {
            wsum += 1;
        }
        else
        {
            wsum += 0;
        }
    }
    //sum + 1 because last word doesn't have space after the word.
    return wsum + 1;
}
