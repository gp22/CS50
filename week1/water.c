/*
Write, in a file called water.c in your ~/workspace/pset1/ directory, a
program that prompts the user for the length of his or her shower in minutes
(as a positive integer) and then prints the equivalent number of bottles of
water (as an integer). For simplicity, you may assume that the user will
input a positive integer, so no need for error-checking (or any loops) this
time! And no need to worry about overflow!
*/

#include <stdio.h> 

int main(void)
{
    int minutes;

    printf("Enter time in minutes: ");
    scanf("%i", &minutes);
    printf("Minutes: %i\n", minutes);
    printf("Bottles: %d\n", (192 * minutes) / 16);
}