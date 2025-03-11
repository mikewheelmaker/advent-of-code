#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>
#include <stdio.h>

#define SIMPLE_INPUT_FILE "../simple_input.txt"
#define INPUT_FILE "../input.txt"
#define MAX_LENGTH 33
#define NUMBER_OF_LIGHT_ROWS 1000
#define NUMBER_OF_LIGHT_COLUMNS 1000

typedef enum
{
    TOGGLE = 0,
    TURN_ON,
    TURN_OFF
} Operation;

void handleLights(bool *lights, Operation op, int startI, int startJ, int finishI, int finishJ);
int first_puzzle(char *fileName);
void handleLightsBrightness(int *lights, Operation op, int startI, int startJ, int finishI, int finishJ);
int second_puzzle(char *fileName);

#endif