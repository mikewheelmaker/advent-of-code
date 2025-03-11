#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

#define SIMPLE_INPUT_FILE "../simple_input.txt"
#define INPUT_FILE "../input.txt"
#define MAX_LENGTH 44

int getNumOfMemoryChars(char *str);
int first_puzzle(char *fileName);
void encode(char *str, char *dest);
int second_puzzle(char *fileName);

#endif