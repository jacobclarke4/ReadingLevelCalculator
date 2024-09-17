#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int count_words(string text);
int count_letters(string text);
int count_sentences(string text);
int main(void)
{
    //text input
    string text = get_string("Text: ");

    int letterCount = count_letters(text);
    //printf("%i\n",letterCount);

    int wordCount = count_words(text);
    //printf("%i\n",wordCount);

    int sentenceCount = count_sentences(text);
    //printf("%i\n",sentenceCount);

    //formula to determine reading level
    float l = 100.0 * letterCount / wordCount;
    float s = 100.0 * sentenceCount / wordCount;

    float index = .0588 * l - .296 * s - 15.8; //coleman-liau index

    //print the grade level
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        int grade = round(index);
        printf("Grade %i\n", grade);
    }


}
//count the words in the inputted text
int count_words(string text)
{
    int wordCount = 0;
    //check spac for spaces in sentence
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ')
        {
            wordCount++;
        }
    }
    wordCount = wordCount + 1; //to count the last word
    return wordCount;
}
//count total number of letters
int count_letters(string text)
{
    int letterCount = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        //dont count these special characters as letters
        if (text[i] == ' ' || text[i] == '!' || text[i] == '.' || text[i] == '?'
            || text[i] == ',' || text[i] == ';' || text[i] == '\'' || text[i] == '\"' || text[i] == '-')
        {
            //printf("Butt");
        }
        else
        {
            letterCount++;
        }
    }
    return letterCount;
}
//count number of sentences
int count_sentences(string text)
{
    int sentenceCount = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        //check if this is a special character that ends a sentence
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentenceCount++;
        }
    }
    return sentenceCount;
}