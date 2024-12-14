#include <stdio.h>

#include "second_puzzle.h"

int second_puzzle()
{
    FILE* filePointer = fopen("../input.txt", "r");
    if(filePointer != NULL)
    {
        printf("Input file is open for reading.\n");

        char up[1] = "(";
        char down[1] = ")";
        int ch = 0;
        int floor = 0;
        int result = 1;
        do
        {
            ch = getc(filePointer);
            if(ch == 40) 
                ++floor;
            if(ch == 41)
                --floor;
            
            if(floor == -1)
                return result;
            ++result;
        } while (ch != EOF);
    }
    else
    {
        printf("Error upon opening input file for reading.\n");
    }

    return -1;
}