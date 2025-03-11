#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

char *convertNumberToName(int number)
{
    char *string = (char *)malloc(3 * sizeof(char));
    string[0] = '?';
    string[1] = '?';
    string[2] = '\0';
    if(number >= 0 && number < NUMBER_OF_LETTERS)
    {
        string[0] = number + 'a';
        string[1] = '\0';
    }
    else if(number >= NUMBER_OF_LETTERS && number < MAX_NUMBER_OF_OUTPUTS)
    {
        string[0] = number / NUMBER_OF_LETTERS + 'a' - 1;
        string[1] = number % NUMBER_OF_LETTERS + 'a';
    }
    return string;
}

int convertNameToNumber(char *name)
{
    if(strlen(name) == 1)
    {
        return name[0] - 'a';
    }
    else if(strlen(name) == 2)
    {
        return (name[0] - 'a' + 1) * NUMBER_OF_LETTERS + (name[1] - 'a');
    }
    else
    {
        return -1;
    }
}

unsigned short int getValue(int wireIndex, WireInfo **wireInfos)
{
    unsigned short int result = SHRT_MAX;
    if(wireInfos[wireIndex]->op == DONE)
    {
        result = wireInfos[wireIndex]->value;
    }
    else
    {
        unsigned short int firstOp = SHRT_MAX, secondOp = SHRT_MAX;
        if(wireInfos[wireIndex]->firstOperandValue != SHRT_MAX)
        {
            firstOp = wireInfos[wireIndex]->firstOperandValue;
        }
        else
        {
            if(wireInfos[wireIndex]->firstOperandIndex != -1)
            {
                firstOp = getValue(wireInfos[wireIndex]->firstOperandIndex, wireInfos);
            }
        }
        if(wireInfos[wireIndex]->secondOperandValue != SHRT_MAX)
        {
            secondOp = wireInfos[wireIndex]->secondOperandValue;
        }
        else
        {
            if(wireInfos[wireIndex]->secondOperandIndex != -1)
            {
                secondOp = getValue(wireInfos[wireIndex]->secondOperandIndex, wireInfos);
            }
        }
    
        switch(wireInfos[wireIndex]->op)
        {
            case AND:
                result = firstOp & secondOp;
                break;
            case OR:
                result = firstOp | secondOp;
                break;
            case RSHIFT:
                result = firstOp >> secondOp;
                break;
            case LSHIFT:
                result = firstOp << secondOp;
                break;
            case NOT:
                result = ~firstOp;
                break;
            case ASSIGN:
                result = firstOp;
                break;
        }
        wireInfos[wireIndex]->op = DONE;
        wireInfos[wireIndex]->firstOperandIndex = -1;
        wireInfos[wireIndex]->firstOperandValue = SHRT_MAX;
        wireInfos[wireIndex]->secondOperandIndex = -1;
        wireInfos[wireIndex]->secondOperandValue = SHRT_MAX;
        wireInfos[wireIndex]->value = result;
    }
    return result;
}

unsigned short int first_puzzle(char *fileName, char *desiredOutput)
{
    FILE *pFile = fopen(fileName, "r");
    if(pFile != NULL)
    {
        printf("Input file is open for reading.\n");
        char str[MAX_LENGTH];
        WireInfo **wireInfos = (WireInfo **)malloc(MAX_NUMBER_OF_OUTPUTS * sizeof(WireInfo *));
        int i;
        for(i = 0; i < MAX_NUMBER_OF_OUTPUTS; ++i)
        {
            wireInfos[i] = (WireInfo *)malloc(sizeof(WireInfo));
            wireInfos[i]->wireIndex = i;
            wireInfos[i]->value = SHRT_MAX;
            wireInfos[i]->firstOperandIndex = -1;
            wireInfos[i]->firstOperandValue = SHRT_MAX;
            wireInfos[i]->secondOperandIndex = -1;
            wireInfos[i]->secondOperandValue = SHRT_MAX;
            wireInfos[i]->op = DONE;
        }
        do
        {
            fgets(str, MAX_LENGTH, pFile);
            if(feof(pFile))
            {
                break;
            }
            if(strlen(str) > 4)
            {
                if(str != NULL)
                {
                    for(i = 0; i < strlen(str); ++i)
                    {
                        if(str[i] == '\n')
                        {
                            str[i] = '\0';
                        }
                    }
                }
                char *pFirstToken = strtok(str, " ");
                char *pSecondToken = strtok(NULL, " ");
                char *pThirdToken = strtok(NULL, " ");
                char *pFourthToken = strtok(NULL, " ");
                char *pFifthToken = strtok(NULL, " ");
                if(strcmp(pSecondToken, "->") == 0) // direct assignment
                {
                    int index = convertNameToNumber(pThirdToken);
                    if(pFirstToken[0] >= '0' && pFirstToken[0] <= '9')
                    {
                        wireInfos[index]->value = atoi(pFirstToken);
                    }
                    else
                    {
                        wireInfos[index]->op = ASSIGN;
                        wireInfos[index]->firstOperandIndex = convertNameToNumber(pFirstToken);
                    }
                }
                if(pThirdToken != NULL && strcmp(pThirdToken, "->") == 0) // NOT
                {
                    int index = convertNameToNumber(pFourthToken);
                    if(pSecondToken[0] >= '0' && pSecondToken[0] <= '9')
                    {
                        wireInfos[index]->value = ~atoi(pSecondToken);
                    }
                    else
                    {
                        wireInfos[index]->op = NOT;
                        wireInfos[index]->firstOperandIndex = convertNameToNumber(pSecondToken);
                    }
                }
                if(pFourthToken != NULL && strcmp(pFourthToken, "->") == 0)
                {
                    int index = convertNameToNumber(pFifthToken);
                    if(pFirstToken[0] >= '0' && pFirstToken[0] <= '9')
                    {
                        wireInfos[index]->firstOperandValue = atoi(pFirstToken);
                    }
                    else
                    {
                        wireInfos[index]->firstOperandIndex = convertNameToNumber(pFirstToken);
                    }
                    if(pThirdToken[0] >= '0' && pThirdToken[0] <= '9')
                    {
                        wireInfos[index]->secondOperandValue = atoi(pThirdToken);
                    }
                    else
                    {
                        wireInfos[index]->secondOperandIndex = convertNameToNumber(pThirdToken);
                    }

                    if(strcmp(pSecondToken, "AND") == 0)
                    {
                        wireInfos[index]->op = AND;
                    }
                    if(strcmp(pSecondToken, "OR") == 0)
                    {
                        wireInfos[index]->op = OR;
                    }
                    if(strcmp(pSecondToken, "LSHIFT") == 0)
                    {
                        wireInfos[index]->op = LSHIFT;
                    }
                    if(strcmp(pSecondToken, "RSHIFT") == 0)
                    {
                        wireInfos[index]->op = RSHIFT;
                    }
                }
            }
        } while (!feof(pFile));

        return getValue(convertNameToNumber(desiredOutput), wireInfos);
    }
    else
    {
        printf("Could not open the input file for reading.\n");
    }

    fclose(pFile);
    return SHRT_MAX;
}

unsigned short int second_puzzle(char *fileName, char *newFileName, char *desiredOutput)
{
    FILE *pFile = fopen(fileName, "r");
    if(pFile != NULL)
    {
        unsigned short int newB = first_puzzle(fileName, desiredOutput);
        rewind(pFile);
        FILE *pNewFile = fopen(newFileName, "w");
        if(pNewFile != NULL)
        {
            printf("New file open for writing.\n");
            char str[MAX_LENGTH];
            do
            {
                fgets(str, MAX_LENGTH, pFile);
                if(feof(pFile))
                {
                    break;
                }
                if(strlen(str) > 4)
                {
                    if(str != NULL)
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
                    char *tmp = strcpy(tmp, str);
                    char *pFirstToken = strtok(tmp, " ");
                    char *pSecondToken = strtok(NULL, " ");
                    char *pThirdToken = strtok(NULL, " ");
                    char *pFourthToken = strtok(NULL, " ");
                    char *pFifthToken = strtok(NULL, " ");
                    if(strcmp(pSecondToken, "->") == 0) // direct assignment
                    {
                        if(pThirdToken != NULL && strcmp(pThirdToken, "b") == 0)
                        {
                            sprintf(str, "%u -> b", newB);
                        }
                    }
                    if(strcmp(pThirdToken, "->") == 0) // NOT
                    {
                        if(pFourthToken != NULL && strcmp(pFourthToken, "b") == 0)
                        {
                            sprintf(str, "%u -> b", newB);
                        }
                    }
                    if(pFourthToken != NULL && strcmp(pFourthToken, "->") == 0) // all other cases
                    {
                        if(pFifthToken != NULL && strcmp(pFifthToken, "b") == 0)
                        {
                            sprintf(str, "%u -> b", newB);
                        }
                    }
                    fprintf(pNewFile, "%s\n", str);
                }
            } while (!feof(pFile));
            fclose(pFile);
            fclose(pNewFile);
            return first_puzzle(newFileName, desiredOutput);
        }
        else
        {
            printf("Could not open the new input file for writing.\n");
        }
    }
    else
    {
        printf("Could not open the input file for reading.\n");
    }

    fclose(pFile);
    return SHRT_MAX;
}