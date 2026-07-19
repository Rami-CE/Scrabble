#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 50
#define FAIL 1
#define SUCCESS 0

const int points[] = {
    1, 3, 3,  2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1,
    1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10}; // represents the values for each uppercase letter with
                                           // corresponding index

void ConvertToUpper(char[]);
int CalculateScore(char[]);
int Prompt(char[], char[]);
int Validate(char[]);

int main()
{
    char WordPlayer1[MAX_BUFFER_SIZE];
    char WordPlayer2[MAX_BUFFER_SIZE];
    int ScorePlayer1 = 0, ScorePlayer2 = 0;

    // prompting the user for input & validating

    if (Prompt(WordPlayer1, "Player 1: "))
    {
        printf("Error: out of range\n");
        return FAIL;
    }
    if (Prompt(WordPlayer2, "Player 2: "))
    {
        printf("Error: out of range\n");
        return FAIL;
    }

    if (Validate(WordPlayer1) || Validate(WordPlayer2))
    {
        printf("Error: enter alphabets only!\n");
        return FAIL;
    }

    // converting to uppercase

    ConvertToUpper(WordPlayer1);
    ConvertToUpper(WordPlayer2);

    // calculating the score for each player

    ScorePlayer1 = CalculateScore(WordPlayer1);
    ScorePlayer2 = CalculateScore(WordPlayer2);

    // comparing scores

    if (ScorePlayer1 > ScorePlayer2)
        printf("Player 1 wins!\n");
    else if (ScorePlayer2 > ScorePlayer1)
        printf("Player 2 wins!\n");
    else
        printf("Tie!\n");

    return 0;
}

void ConvertToUpper(char str[])
{
    int i = 0;
    while (str[i] != 0)
    {
        str[i] = toupper(str[i]);
        i++;
    }
}

int CalculateScore(char word[])
{
    int len = strlen(word), score = 0;

    for (int i = 0; i < len; i++)
    {
        score += points[word[i] - 'A'];
    }

    return score;
}

int Prompt(char word[], char message[])
{
    printf("%s", message);

    scanf("%s", word);

    return strlen(word) >= 50;
}

int Validate(char word[])
{
    int len = strlen(word);

    for (int i = 0; i < len; i++)
    {
        if (!(isalpha(word[i]) || ispunct(word[i])))
        {
            return FAIL;
        }
    }

    return SUCCESS;
}
