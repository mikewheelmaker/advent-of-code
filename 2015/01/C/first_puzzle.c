#include <limits.h>
#include <stdio.h>

#include "first_puzzle.h"

int first_puzzle()
{
    FILE* filePointer = fopen("../input.txt", "r");
    if(filePointer != NULL)
    {
        printf("Input file is open for reading.\n");

        char up[1] = "(";
        char down[1] = ")";
        int ch = 0;
        int result = 0;
        do
        {
            ch = getc(filePointer);
            if(ch == 40) 
                ++result;
            if(ch == 41)
                --result;
        } while (ch != EOF);
        return result;
    }
    else
    {
        printf("Error upon opening input file for reading.\n");
    }

    return INT_MIN;
}