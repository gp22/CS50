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
    // for (int i = 0; i < n; i++)
    // {
    //     if (values[i] == value)
    //     {
    //         return true;
    //     }
    // }

    int min = 0;
    int max = n;
    int guess = n/2;    
    // printf("%i\n", n/2);

    do {
        if (value == guess)
        {
            return true;    
        }
        else if (value > guess)
        {
            printf("%i not equal to %i\n", value, guess);
            printf("min: %i, max: %i\n\n", min, max);
            
            min = guess + 1;
            guess = (min + max) / 2;
        }
        else // value < guess
        {
            printf("%i not equal to %i\n", value, guess);
            printf("min: %i, max: %i\n\n", min, max);

            max = guess - 1;
            guess = (min + max) / 2;
        }
    } while (value != guess);

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
