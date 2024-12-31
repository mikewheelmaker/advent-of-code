#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define SIMPLE_INPUT_FILE "../simple_input.txt"
#define INPUT_FILE "../input.txt"
#define MAX_SIZE 144 // manually found this out, the minimum number that would result in the correct output of the first problem for the provided input (easier than writing a function which calculates it, since input does not change)
#define NORTH 94
#define SOUTH 118
#define WEST 60
#define EAST 62

int first_puzzle(char* fileName);
int second_puzzle(char* fileName);

#endif