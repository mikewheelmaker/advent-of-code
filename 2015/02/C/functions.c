#include <stdbool.h>

#include "functions.h"

int getTotalPlusExtra(int *dimensions)
{
    int a = dimensions[0] * dimensions[1]; // length * width
    int b = dimensions[0] * dimensions[2]; // length * height
    int c = dimensions[1] * dimensions[2]; // width * height
    bool aLessThanB = a < b;
    bool aLessThanC = a < c;
    bool bLessThanC = b < c;
    int smallestArea = -1;

    if(aLessThanB && aLessThanC)
    {
        smallestArea = a;
    }
    if(!aLessThanB && bLessThanC)
    {
        smallestArea = b;
    }
    if(!aLessThanC && !bLessThanC)
    {
        smallestArea = c;
    }

    return 2*a + 2*b + 2*c + smallestArea;
}

int first_puzzle(char *fileName)
{
    FILE *pFile = fopen(fileName, "r");
    if(pFile != NULL)
    {
        printf("Input file is open for reading.\n");

        int total = 0;
        int ch;
        int dimension = 0; // 0 - length, 1 - width, 2 - height
        int dimensions[3];
        dimensions[0] = dimensions[1] = dimensions[2] = -1;
        int digit = 0;
        int digits[2];
        digits[0] = digits[1] = -1;
        do
        {
            ch = getc(pFile);
            if(ch >= '0' && ch <= '9')
            {
                digits[digit] = ch - '0';
                ++digit;
            }
            if(ch == 'x')
            {
                if(digit == 2)
                {
                    dimensions[dimension] = digits[0] * 10 + digits[1];
                }
                else if(digit == 1)
                {
                    dimensions[dimension] = digits[0];
                }
                ++dimension;
                digit = 0;
                digits[0] = digits[1] = -1;
            }
            if(ch == '\n' || ch == EOF)
            {
                if(digit == 2)
                {
                    dimensions[dimension] = digits[0] * 10 + digits[1];
                }
                else if(digit == 1)
                {
                    dimensions[dimension] = digits[0];
                }

                if(dimension != 0)
                {
                    total += getTotalPlusExtra(dimensions);
                }
                dimension = 0;
                dimensions[0] = dimensions[1] = dimensions[2] = -1;
                digit = 0;
                digits[0] = digits[1] = -1;
            }
        } while (ch != EOF);

        fclose(pFile);
        return total;
    }
    else
    {
        printf("Could not open the input file for reading.\n");
    }

    fclose(pFile);
    return -1;
}

int getTotalRibbon(int *dimensions)
{
    int a = dimensions[0]; // length
    int b = dimensions[1]; // width
    int c = dimensions[2]; // height
    bool aMoreThanB = a > b;
    bool aMoreThanC = a > c;
    bool bMoreThanC = b > c;
    int totalPerimeter = 2*(a+b+c);
    int largestPerimeter = -1;

    if(aMoreThanB && aMoreThanC)
    {
        largestPerimeter = 2*a;
    }
    if(!aMoreThanB && bMoreThanC)
    {
        largestPerimeter = 2*b;
    }
    if(!aMoreThanC && !bMoreThanC)
    {
        largestPerimeter = 2*c;
    }

    return totalPerimeter - largestPerimeter + a*b*c;
}

int second_puzzle(char *fileName)
{
    FILE *pFile = fopen(fileName, "r");
    if(pFile != NULL)
    {
        printf("Input file is open for reading.\n");

        int total = 0;
        int ch = 0;
        int dimension = 0; // 0 - length, 1 - width, 2 - height
        int dimensions[3];
        dimensions[0] = dimensions[1] = dimensions[2] = -1;
        int digit = 0;
        int digits[2];
        digits[0] = digits[1] = -1;
        do
        {
            ch = getc(pFile);
            if(ch >= '0' && ch <= '9')
            {
                digits[digit] = ch - '0';
                ++digit;
            }
            if(ch == 'x')
            {
                if(digit == 2)
                {
                    dimensions[dimension] = digits[0] * 10 + digits[1];
                }
                else if(digit == 1)
                {
                    dimensions[dimension] = digits[0];
                }
                ++dimension;
                digit = 0;
                digits[0] = digits[1] = -1;
            }
            if(ch == '\n' || ch == EOF)
            {
                if(digit == 2)
                {
                    dimensions[dimension] = digits[0] * 10 + digits[1];
                }
                else if(digit == 1)
                {
                    dimensions[dimension] = digits[0];
                }

                if(dimension != 0)
                {
                    total += getTotalRibbon(dimensions);
                }
                dimension = 0;
                dimensions[0] = dimensions[1] = dimensions[2] = -1;
                digit = 0;
                digits[0] = digits[1] = -1;
            }
        } while (ch != EOF);

        fclose(pFile);
        return total;
    }
    else
    {
        printf("Could not open the input file for reading.\n");
    }

    fclose(pFile);
    return -1;
}