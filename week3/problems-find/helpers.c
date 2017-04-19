/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // Immediately return false if value is less than 0.
    if (value < 0)
    {
        return false;
    }

    // TODO: implement a searching algorithm
    int minIndex = 0;
    int maxIndex = n-1;
    int guessIndex = maxIndex/2;

    int min = values[minIndex];
    int max = values[maxIndex];
    int guess = values[guessIndex];

    do {
        if (value == guess || value == min || value == max)
        {
            return true;    
        }
        else if (value > guess)
        {
            minIndex = guessIndex + 1;
            min = values[minIndex];

            guessIndex = (minIndex + maxIndex) / 2;
            guess = values[guessIndex];
        }
        else // value < guess
        {
            maxIndex = guessIndex - 1;
            max = values[maxIndex];

            guessIndex = (minIndex + maxIndex) / 2;
            guess = values[guessIndex];
        }
    } while (maxIndex - guessIndex > 0);

    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (values[j] > values[j+1])
            {
                int temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
            }
        }
    }
    return;
}
