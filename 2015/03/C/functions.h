#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define SIMPLE_INPUT_FILE "../simple_input.txt"
#define INPUT_FILE "../input.txt"
/** 
 * The minimum number that would result in the correct output of the first problem for the provided input
 * (manually found this out, easier than writing a function which calculates it, since input does not change)
 */
#define MAX_SIZE 144 

int first_puzzle(char *fileName);
int second_puzzle(char *fileName);

#endif