#include <string.h>

#include "functions.h"

bool p1_condition1(char *string)
{
    char vowels[] = "aeiou";
    char *pChar;
    int numberOfVowelsPresent = 0;
    pChar = strpbrk(string, vowels);
    while (pChar != NULL)
    {
        ++numberOfVowelsPresent;
        pChar = strpbrk(pChar + 1, vowels);
    }
    if(numberOfVowelsPresent >= 3)
    {
        return true;
    }
    return false;
}

bool p1_condition2(char *string)
{
    int i;
    for(i = 0; i < strlen(string) - 1; ++i)
    {
        if(string[i] == string[i+1])
        {
            return true;
        }
    }
    return false;
}

bool p1_condition3(char *string)
{
    if(strstr(string, "ab") != NULL)
    {
        return false;
    }
    if(strstr(string, "cd") != NULL)
    {
        return false;
    }
    if(strstr(string, "pq") != NULL)
    {
        return false;
    }
    if(strstr(string, "xy") != NULL)
    {
        return false;
    }
    return true;
}

int first_puzzle(char *fileName)
{
    FILE *pFile = fopen(fileName, "r");
    if(pFile != NULL)
    {
        printf("Input file is open for reading.\n");

        char str[17];
        int total = 0;
        do
        {
            fgets(str, 17, pFile);
            if(feof(pFile))
            {
                break;
            }
            if(p1_condition1(str) && p1_condition2(str) && p1_condition3(str))
            {
                ++total;
            }
        } while (!feof(pFile));

        fclose(pFile);
        return total;
    }
    else
    {
        printf("Could not open the input file for reading.\n");
    }

    fclose(pFile);
    return -1;
}

bool p2_triplets(char *string)
{
    int i;
    for(i = 0; i < strlen(string) - 2; ++i)
    {
        if(string[i] == string[i + 1] && string[i] == string[i + 2])
        {
            return true;
        }
    }
    return false;
}

bool p2_condition1(char *string)
{
    int i;
    for(i = 0; i < strlen(string) - 1; ++i)
    {
        char subString[3];
        subString[0] = string[i];
        subString[1] = string[i + 1];
        subString[2] = '\0';
        char *pSubString = strstr(string + i + 1, subString);
        if(pSubString != NULL)
        {
            return true;
        }
    }
    return false;
}
bool p2_condition2(char *string)
{
    int i;
    for(i = 0; i < strlen(string) - 2; ++i)
    {
        if(string[i] == string[i + 2] && string[i] != string[i + 1])
        {
            return true;
        }
    }
    return false;
}

int second_puzzle(char *fileName)
{
    FILE *pFile = fopen(fileName, "r");
    if(pFile != NULL)
    {
        printf("Input file is open for reading.\n");

        char str[17];
        int total = 0;
        do
        {
            fgets(str, 17, pFile);
            if(feof(pFile))
            {
                break;
            }
            if(p2_condition1(str) && !p2_triplets(str) && p2_condition2(str))
            {
                ++total;
            }
        } while (!feof(pFile));

        fclose(pFile);
        return total;
    }
    else
    {
        printf("Could not open the input file for reading.\n");
    }

    fclose(pFile);
    return -1;
}