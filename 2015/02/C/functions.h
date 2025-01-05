#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

#define SIMPLE_INPUT_FILE "../simple_input.txt"
#define INPUT_FILE "../input.txt"

int getTotalPlusExtra(int *dimensions);
int first_puzzle(char *fileName);
int getTotalRibbon(int *dimensions);
int second_puzzle(char *fileName);

#endif