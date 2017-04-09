/*
Write, in a file called mario.c a program that recreates this half-pyramid
using hashes (#) for blocks. To make things more interesting, first prompt
the user for the half-pyramid’s height, a non-negative integer no greater
than 23. (The height of the half-pyramid pictured above happens to be 8.)
If the user fails to provide a non-negative integer no greater than 23,
you should re-prompt for the same again. Then, generate (with the help of
printf and one or more loops) the desired half-pyramid. Take care to align
the bottom-left corner of your half-pyramid with the left-hand edge of your
terminal window.
*/

#include <stdio.h> 

int main(void)
{
    int height;

    printf("Height: ");
    scanf("%i", &height);

    while (height < 0 || height > 23)
    {
        printf("Height: ");
        scanf("%i", &height);
    }
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height - (i+1); j++) {
            printf(" ");
        }
        for (int k = 0; k < i + 2; k++) {
            printf("#");
        }
        printf("\n");
    }    
}