#include <stdio.h>

#include "functions.h"

void main()
{
    printf("Simple input:\n");
    printf("The result for the first puzzle is: %d\n", first_puzzle(SIMPLE_INPUT_FILE));
    printf("The result for the second puzzle is: %d\n", second_puzzle(SIMPLE_INPUT_FILE));
    printf("\n");
    printf("Provided input:\n");
    printf("The result for the first puzzle is: %d\n", first_puzzle(INPUT_FILE));
    printf("The result for the second puzzle is: %d\n", second_puzzle(INPUT_FILE));
}