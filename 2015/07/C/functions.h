#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

#define SIMPLE_INPUT_FILE "../simple_input.txt"
#define NEW_SIMPLE_INPUT_FILE "../new_simple_input.txt"
#define INPUT_FILE "../input.txt"
#define NEW_INPUT_FILE "../new_input.txt"
#define TOTAL_NUMBER_OF_OUTPUTS 702 // 26 letters and 26 * 26 two letter combinations
#define MAX_NUMBER_OF_OUTPUTS 339 // max combination is ma, which is on position 13*26 + 0 = 338

typedef enum
{
    AND = 0,
    OR,
    RSHIFT,
    LSHIFT,
    NOT,
    ASSIGN,
    DONE = -1
} Operations;

typedef struct
{
    int wireIndex; // a, b, ... , ma converted to int
    unsigned short int value;
    int firstOperandIndex;
    unsigned short int firstOperandValue;
    int secondOperandIndex;
    unsigned short int secondOperandValue;
    Operations op; // AND, OR, RSHIFT, LSHIFT, NOT
} WireInfo;

char *convertNumberToName(int number);
int convertNameToNumber(char *name);
unsigned short int getValue(int wireIndex, WireInfo **wireInfos);
unsigned short int first_puzzle(char *fileName, char *desiredOutput);
unsigned short int second_puzzle(char *fileName, char *newFileName, char *desiredOutput);

#endif