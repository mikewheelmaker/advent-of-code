#include <limits.h>
#include <stdio.h>

#include "functions.h"

int first_puzzle()
{
    FILE* filePointer = fopen(INPUT_FILE, "r");
    if(filePointer != NULL)
    {
        printf("Input file is open for reading.\n");

        int ch = 0;
        int result = 0;
        do
        {
            ch = getc(filePointer);
            if(ch == OPEN_PARANTHESIS) 
                ++result;
            if(ch == CLOSE_PARANTHESIS)
                --result;
        } while (ch != EOF);
        
        fclose(filePointer);
        return result;
    }
    else
    {
        printf("Could not open the input file for reading.\n");
    }

    return INT_MIN;
}

int second_puzzle()
{
    FILE* filePointer = fopen(INPUT_FILE, "r");
    if(filePointer != NULL)
    {
        printf("Input file is open for reading.\n");
        
        int ch = 0;
        int floor = 0;
        int result = 1;
        do
        {
            ch = getc(filePointer);
            if(ch == OPEN_PARANTHESIS) 
                ++floor;
            if(ch == CLOSE_PARANTHESIS)
                --floor;
            
            if(floor == FIRST_BASEMENT_LEVEL)
                return result;
            ++result;
        } while (ch != EOF);

        fclose(filePointer);
    }
    else
    {
        printf("Could not open the input file for reading.\n");
    }

    return -1;
}