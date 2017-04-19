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
        printf("min: %i, max: %i, guess: %i\n", min, max, guess);
        printf("minIndex: %i, maxIndex: %i, guessIndex: %i\n\n", minIndex, maxIndex, guessIndex);
        if (value == guess || value == min || value == max)
        {
            return true;    
        }
        else if (value > guess)
        {
            printf("%i not equal to %i, %i or %i\n", value, min, guess, max);
            
            minIndex = guessIndex + 1;
            min = values[minIndex];

            guessIndex = (minIndex + maxIndex) / 2;
            guess = values[guessIndex];
        }
        else // value < guess
        {
            printf("%i not equal to %i, %i or %i\n", value, min, guess, max);

            maxIndex = guessIndex - 1;
            max = values[maxIndex];

            guessIndex = (minIndex + maxIndex) / 2;
            guess = values[guessIndex];
        }
    // } while (value != guess && (maxIndex + 1) - (minIndex + 1) != 0);
    } while (value != guess);
    printf("min: %i, max: %i, guess: %i\n", min, max, guess);
    printf("minIndex: %i, maxIndex: %i, guessIndex: %i\n\n", minIndex, maxIndex, guessIndex);

    if (value == guess || value == min || value == max)
    {
        return true;    
    }
    
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
