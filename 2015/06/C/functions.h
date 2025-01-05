#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>
#include <stdio.h>

#define SIMPLE_INPUT_FILE "../simple_input.txt"
#define INPUT_FILE "../input.txt"
#define TOGGLE 0
#define TURN_ON 1
#define TURN_OFF 2

void handleLights(bool *lights, int operation, int startI, int startJ, int finishI, int finishJ);
int first_puzzle(char *fileName);
void handleLightsBrightness(int *lights, int operation, int startI, int startJ, int finishI, int finishJ);
int second_puzzle(char *fileName);

#endif