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
    FILE *filePointer = fopen(fileName, "r");
    if(filePointer != NULL)
    {
        printf("Input file is open for reading.\n");

        bool *lights = (bool *)calloc(1000000, sizeof(bool));

        char str[33];
        do
        {
            fgets(str, 33, filePointer);
            if(strlen(str) > 6)
            {
                int op;
                int startI, startJ, finishI, finishJ;
                char *pointerToFirstToken = strtok(str, " ");  // "toggle/turn"
                if(strcmp(pointerToFirstToken, "toggle") == 0)
                {
                    op = TOGGLE;
                }
                if(strcmp(pointerToFirstToken, "turn") == 0)
                {
                    char *pointerToSecondToken = strtok(NULL, " ");  // "off/on"
                    if(strcmp(pointerToSecondToken, "on") == 0)
                    {
                        op = TURN_ON;
                    }
                    if(strcmp(pointerToSecondToken, "off") == 0)
                    {
                        op = TURN_OFF;
                    }
                }
                char *pointerToStartToken = strtok(NULL, " "); // "startI,startJ"
                strtok(NULL, " "); // "through"
                char *pointerToFinishToken = strtok(NULL, " "); // "finishI,finishJ"
                char *pointerToStartIToken = strtok(pointerToStartToken, ",");
                startI = atoi(pointerToStartIToken);
                char *pointerToStartJToken = strtok(NULL, ",");
                startJ = atoi(pointerToStartJToken);
                char *pointerToFinishIToken = strtok(pointerToFinishToken, ",");
                finishI = atoi(pointerToFinishIToken);
                char *pointerToFinishJToken = strtok(NULL, ",");
                finishJ = atoi(pointerToFinishJToken);
                handleLights(lights, op, startI, startJ, finishI, finishJ);
            }
        } while(!feof(filePointer));

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

        fclose(filePointer);
        return total;
    }
    else
    {
        printf("Could not open the input file for reading.\n");
    }

    fclose(filePointer);
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
    printf("got here\n");
    FILE *filePointer = fopen(fileName, "r");
    if(filePointer != NULL)
    {
        printf("Input file is open for reading.\n");

        int *lights = (int *)calloc(1000000, sizeof(int));
        char str[33];
        do
        {
            fgets(str, 33, filePointer);
            if(strlen(str) > 6)
            {
                int op;
                int startI, startJ, finishI, finishJ;
                char *pointerToFirstToken = strtok(str, " ");  // "toggle/turn"
                if(strcmp(pointerToFirstToken, "toggle") == 0)
                {
                    op = TOGGLE;
                }
                if(strcmp(pointerToFirstToken, "turn") == 0)
                {
                    char *pointerToSecondToken = strtok(NULL, " ");  // "off/on"
                    if(strcmp(pointerToSecondToken, "on") == 0)
                    {
                        op = TURN_ON;
                    }
                    if(strcmp(pointerToSecondToken, "off") == 0)
                    {
                        op = TURN_OFF;
                    }
                }
                char *pointerToStartToken = strtok(NULL, " "); // "startI,startJ"
                strtok(NULL, " "); // "through"
                char *pointerToFinishToken = strtok(NULL, " "); // "finishI,finishJ"
                char *pointerToStartIToken = strtok(pointerToStartToken, ",");
                startI = atoi(pointerToStartIToken);
                char *pointerToStartJToken = strtok(NULL, ",");
                startJ = atoi(pointerToStartJToken);
                char *pointerToFinishIToken = strtok(pointerToFinishToken, ",");
                finishI = atoi(pointerToFinishIToken);
                char *pointerToFinishJToken = strtok(NULL, ",");
                finishJ = atoi(pointerToFinishJToken);
                handleLightsBrightness(lights, op, startI, startJ, finishI, finishJ);
            }
        } while(!feof(filePointer));

        int total = 0;
        int i, j;
        for(i = 0; i < 1000; ++i)
        {
            for(j = 0; j < 1000; ++j)
            {
                total += lights[i * 1000 + j];
            }
        }

        fclose(filePointer);
        return total;
    }
    else
    {
        printf("Could not open the input file for reading.\n");
    }

    fclose(filePointer);
    return -1;
}