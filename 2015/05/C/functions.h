#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>
#include <stdio.h>

#define SIMPLE_INPUT_FILE_PART_1 "../simple_input_part_1.txt"
#define SIMPLE_INPUT_FILE_PART_2 "../simple_input_part_2.txt"
#define INPUT_FILE "../input.txt"
#define MAX_LENGTH 17

bool p1_condition1(char *string);
bool p1_condition2(char *string);
bool p1_condition3(char *string);
int first_puzzle(char *fileName);
bool p2_triplets(char *string);
bool p2_condition1(char *string);
bool p2_condition2(char *string);
int second_puzzle(char *fileName);

#endif