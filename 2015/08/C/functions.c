#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

int getNumOfMemoryChars(char *str)
{
    int result = 0;
    int i;
    for(i = 0; i < strlen(str); ++i)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            ++result;
        }
        if(str[i] == '\\')
        {
            ++i;
            if(str[i] != 'x')
            {
                ++result;
            }
            else
            {
                i += 2;
                ++result;
            }
        }
    }
    return result;
}

int first_puzzle(char *fileName)
{
    FILE *pFile = fopen(fileName, "r");
    if(pFile != NULL)
    {
        printf("Input file is open for reading.\n");
        char str[MAX_LENGTH];
        int totalNumOfCodeChars = 0;
        int totalNumOfMemoryChars = 0;
        do
        {
            fgets(str, MAX_LENGTH, pFile);
            if(feof(pFile))
            {
                break;
            }
            if(strlen(str) > 2)
            {
                int i;
                for(i = 0; i < strlen(str); ++i)
                {
                    if(str[i] == '\n')
                    {
                        str[i] = '\0';
                    }
                }
            }
            totalNumOfCodeChars += strlen(str);
            totalNumOfMemoryChars += getNumOfMemoryChars(str);
        } while (!feof(pFile));
        return totalNumOfCodeChars - totalNumOfMemoryChars;
    }
    else
    {
        printf("Could not open the input file for reading.\n");
    }

    fclose(pFile);
    return -1;
}

void encode(char *str, char *dest)
{
    int i;
    int j = 0;
    dest[j++] = '\"';
    for(i = 0; i < strlen(str); ++i)
    {
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9'))
        {
            dest[j++] = str[i];
        }
        if(str[i] == '\"' || str[i] == '\\')
        {
            dest[j++] = '\\';
            dest[j++] = str[i];
        }
    }
    dest[j++] = '\"';
    dest[j] = '\0';
}

int second_puzzle(char *fileName)
{
    FILE *pFile = fopen(fileName, "r");
    if(pFile != NULL)
    {
        printf("Input file is open for reading.\n");
        char str[MAX_LENGTH];
        int totalNumOfCodeChars = 0;
        int totalNumOfMemoryChars = 0;
        do
        {
            fgets(str, MAX_LENGTH, pFile);
            if(feof(pFile))
            {
                break;
            }
            if(strlen(str) > 2)
            {
                int i;
                for(i = 0; i < strlen(str); ++i)
                {
                    if(str[i] == '\n')
                    {
                        str[i] = '\0';
                    }
                }
            }
            char *tmp = (char *)malloc(2 * MAX_LENGTH * sizeof(char));
            encode(str, tmp);
            totalNumOfCodeChars += strlen(tmp);
            totalNumOfMemoryChars += strlen(str);
            free(tmp);
        } while (!feof(pFile));
        return totalNumOfCodeChars - totalNumOfMemoryChars;
    }
    else
    {
        printf("Could not open the input file for reading.\n");
    }

    fclose(pFile);
    return -1;
}