#include "functions.h"

void main()
{
    printf("Simple input:\n");
    printf("The result for the first puzzle is: %u\n", first_puzzle(SIMPLE_INPUT_FILE, "a"));
    printf("The result for the second puzzle is: %u\n", second_puzzle(SIMPLE_INPUT_FILE, NEW_SIMPLE_INPUT_FILE, "a"));
    printf("\n");
    printf("Provided input:\n");
    printf("The result for the first puzzle is: %u\n", first_puzzle(INPUT_FILE, "a"));
    printf("The result for the second puzzle is: %u\n", second_puzzle(INPUT_FILE, NEW_INPUT_FILE, "a"));
}