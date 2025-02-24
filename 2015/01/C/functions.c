#include <limits.h>

#include "functions.h"

int first_puzzle(char *fileName)
{
    FILE *pFile = fopen(fileName, "r");
    if(pFile != NULL)
    {
        printf("Input file is open for reading.\n");

        int ch = 0;
        int result = 0;
        do
        {
            ch = getc(pFile);
            if(ch == '(') 
                ++result;
            if(ch == ')')
                --result;
        } while (ch != EOF);
        
        fclose(pFile);
        return result;
    }
    else
    {
        printf("Could not open the input file for reading.\n");
    }

    fclose(pFile);
    return INT_MIN;
}

int second_puzzle(char *fileName)
{
    FILE *pFile = fopen(fileName, "r");
    if(pFile != NULL)
    {
        printf("Input file is open for reading.\n");
        
        int ch = 0;
        int floor = 0;
        int result = 1;
        do
        {
            ch = getc(pFile);
            if(ch == '(') 
                ++floor;
            if(ch == ')')
                --floor;
            
            if(floor == FIRST_BASEMENT_LEVEL)
            {
                fclose(pFile);
                return result;
            }
            ++result;
        } while (ch != EOF);
    }
    else
    {
        printf("Could not open the input file for reading.\n");
    }

    fclose(pFile);
    return -1;
}