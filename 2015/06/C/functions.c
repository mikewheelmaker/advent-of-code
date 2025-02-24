#include <stdlib.h>
#include <string.h>

#include "functions.h"

void handleLights(bool *lights, int operation, int startI, int startJ, int finishI, int finishJ)
{
    int i, j;
    for(i = startI; i <= finishI; ++i)
    {
        for(j = startJ; j <= finishJ; ++j)
        {
            int tmp = i * 1000 + j;
            switch(operation)
            {
                case TOGGLE:
                    lights[tmp] = !lights[tmp];
                    break;
                case TURN_ON:
                    lights[tmp] = true;
                    break;
                case TURN_OFF:
                    lights[tmp] = false;
                    break;
            }
        }
    }
}

int first_puzzle(char *fileName)
{
    FILE *pFile = fopen(fileName, "r");
    if(pFile != NULL)
    {
        printf("Input file is open for reading.\n");

        bool *lights = (bool *)calloc(1000000, sizeof(bool));

        char str[33];
        do
        {
            fgets(str, 33, pFile);
            if(strlen(str) > 6)
            {
                int op;
                int startI, startJ, finishI, finishJ;
                char *pFirstToken = strtok(str, " ");  // "toggle/turn"
                if(strcmp(pFirstToken, "toggle") == 0)
                {
                    op = TOGGLE;
                }
                if(strcmp(pFirstToken, "turn") == 0)
                {
                    char *pSecondToken = strtok(NULL, " ");  // "off/on"
                    if(strcmp(pSecondToken, "on") == 0)
                    {
                        op = TURN_ON;
                    }
                    if(strcmp(pSecondToken, "off") == 0)
                    {
                        op = TURN_OFF;
                    }
                }
                char *pStartToken = strtok(NULL, " "); // "startI,startJ"
                strtok(NULL, " "); // "through"
                char *pFinishToken = strtok(NULL, " "); // "finishI,finishJ"
                char *pStartIToken = strtok(pStartToken, ",");
                startI = atoi(pStartIToken);
                char *pStartJToken = strtok(NULL, ",");
                startJ = atoi(pStartJToken);
                char *pFinishIToken = strtok(pFinishToken, ",");
                finishI = atoi(pFinishIToken);
                char *pFinishJToken = strtok(NULL, ",");
                finishJ = atoi(pFinishJToken);
                handleLights(lights, op, startI, startJ, finishI, finishJ);
            }
        } while(!feof(pFile));

        int total = 0;
        int i, j;
        for(i = 0; i < 1000; ++i)
        {
            for(j = 0; j < 1000; ++j)
            {
                if(lights[i * 1000 + j] == true)
                {
                    ++total;
                }
            }
        }

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

void handleLightsBrightness(int *lights, int operation, int startI, int startJ, int finishI, int finishJ)
{
    int i, j;
    for(i = startI; i <= finishI; ++i)
    {
        for(j = startJ; j <= finishJ; ++j)
        {
            int tmp = i*1000 + j;
            switch(operation)
            {
                case TOGGLE:
                    lights[tmp] += 2;
                    break;
                case TURN_ON:
                    ++lights[tmp];
                    break;
                case TURN_OFF:
                    if(lights[tmp] != 0)
                    {
                        --lights[tmp];
                    }
                    break;
            }
        }
    }
}

int second_puzzle(char *fileName)
{
    FILE *pFile = fopen(fileName, "r");
    if(pFile != NULL)
    {
        printf("Input file is open for reading.\n");

        int *lights = (int *)calloc(1000000, sizeof(int));
        char str[33];
        do
        {
            fgets(str, 33, pFile);
            if(strlen(str) > 6)
            {
                int op;
                int startI, startJ, finishI, finishJ;
                char *pFirstToken = strtok(str, " ");  // "toggle/turn"
                if(strcmp(pFirstToken, "toggle") == 0)
                {
                    op = TOGGLE;
                }
                if(strcmp(pFirstToken, "turn") == 0)
                {
                    char *pSecondToken = strtok(NULL, " ");  // "off/on"
                    if(strcmp(pSecondToken, "on") == 0)
                    {
                        op = TURN_ON;
                    }
                    if(strcmp(pSecondToken, "off") == 0)
                    {
                        op = TURN_OFF;
                    }
                }
                char *pStartToken = strtok(NULL, " "); // "startI,startJ"
                strtok(NULL, " "); // "through"
                char *pFinishToken = strtok(NULL, " "); // "finishI,finishJ"
                char *pStartIToken = strtok(pStartToken, ",");
                startI = atoi(pStartIToken);
                char *pStartJToken = strtok(NULL, ",");
                startJ = atoi(pStartJToken);
                char *pFinishIToken = strtok(pFinishToken, ",");
                finishI = atoi(pFinishIToken);
                char *pFinishJToken = strtok(NULL, ",");
                finishJ = atoi(pFinishJToken);
                handleLightsBrightness(lights, op, startI, startJ, finishI, finishJ);
            }
        } while(!feof(pFile));

        int total = 0;
        int i, j;
        for(i = 0; i < 1000; ++i)
        {
            for(j = 0; j < 1000; ++j)
            {
                total += lights[i * 1000 + j];
            }
        }

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