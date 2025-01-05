#include <limits.h>

#include "functions.h"

int first_puzzle(char *fileName)
{
    FILE *filePointer = fopen(fileName, "r");
    if(filePointer != NULL)
    {
        printf("Input file is open for reading.\n");

        int ch = 0;
        int result = 0;
        do
        {
            ch = getc(filePointer);
            if(ch == '(') 
                ++result;
            if(ch == ')')
                --result;
        } while (ch != EOF);
        
        fclose(filePointer);
        return result;
    }
    else
    {
        printf("Could not open the input file for reading.\n");
    }

    fclose(filePointer);
    return INT_MIN;
}

int second_puzzle(char *fileName)
{
    FILE *filePointer = fopen(fileName, "r");
    if(filePointer != NULL)
    {
        printf("Input file is open for reading.\n");
        
        int ch = 0;
        int floor = 0;
        int result = 1;
        do
        {
            ch = getc(filePointer);
            if(ch == '(') 
                ++floor;
            if(ch == ')')
                --floor;
            
            if(floor == FIRST_BASEMENT_LEVEL)
            {
                fclose(filePointer);
                return result;
            }
            ++result;
        } while (ch != EOF);
    }
    else
    {
        printf("Could not open the input file for reading.\n");
    }

    fclose(filePointer);
    return -1;
}