#include <cs50.h>
#include <stdio.h>

// Points assigned to each letter of the alphabet
const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
void test_letter_score(void);
int letter_score(char letter);

int main(void)
{
    // test_letter_score();

    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);


    // // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
}

int compute_score(string word)
{
    /*
    compute_score: Compute and return score for a word represented by a string

    Args:
        word:string -> the word to be punctued
    Return:
        int -> the punctuation of the word according with the scrabble game
    */


    int pointsWord = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        pointsWord += letter_score(word[i]);
    }

    return pointsWord;
}


int letter_score(char letter)
{
    /*
    letter_score: Compute and return score for a letter represented by a char, according with the scrabble game

    Args:
        letter:char -> the letter to be punctued. Its points are independent from the case of the letter
    Return:
        int -> the punctuation of the letter according with the scrabble game
    */


    const int ascii = (int)letter;

    //if the character passed as parameter isn't a letter, the function returns 0 points
    if (ascii < 65 || (ascii > 90 && ascii < 97) || ascii > 122)
    {
        return 0;
    }


    //if the character is a lowercase letter make one operation; otherwise, if it's an uppercase letter, make another operation
    if (ascii >= 97)
    {
        return (POINTS[letter - 97]);
    }
    else
    {
        return (POINTS[letter - 65]);
    }
}


void test_letter_score(void)
{
    printf("%i\n", letter_score('a') == 1);
    printf("%i\n", letter_score('A') == 1);
    printf("%i\n", letter_score('b') == 3);
    printf("%i\n", letter_score('B') == 3);
    printf("%i\n", letter_score('q') == 10);
    printf("%i\n", letter_score('Q') == 10);
}