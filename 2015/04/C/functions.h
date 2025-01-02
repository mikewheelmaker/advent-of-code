#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define SIMPLE_INPUT_FILE "../simple_input.txt"
#define INPUT_FILE "../input.txt"

void bytes2md5(const char *data, int len, char *md5buf);
int findNumber(char *fileName, int numberOfZeroes);
int first_puzzle(char *fileName);
int second_puzzle(char *fileName);

#endif