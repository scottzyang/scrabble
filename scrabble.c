#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Takes user input and computes the score
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner by comparing score1 and score 2
    if (score1 > score2)
    {
        printf("Player 1 Wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 Wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int sum_word = 0;
    for (int i = 0, n = strlen(word); i < n; i++) // Loop through each letter of the user input
    {
        if (isalpha(word[i])) // checks if the char in the user input are alphabets
        {
            int array_place = toupper(word[i]) - 'A'; // Determines how far away the char in the user input string are from A
            sum_word = POINTS[array_place] + sum_word; // Puts puts the array_place into the POINTS array to determine points. 
        }
    }
    return sum_word;
}