#include "functions.h"

int first_puzzle(char *fileName)
{
    FILE *pFile = fopen(fileName, "r");
    if(pFile != NULL)
    {
        printf("Input file is open for reading.\n");

        int houses[MAX_SIZE][MAX_SIZE];
        int i, j; // i -> W-E axis; j -> N-S axis
        for(i = 0; i < MAX_SIZE; ++i)
        {
            for(j = 0; j < MAX_SIZE; ++j)
            {
                houses[i][j] = 0;
            }
        }
        i = MAX_SIZE / 2;
        j = MAX_SIZE / 2;
        houses[i][j] = 1;

        int ch;
        do
        {
            ch = getc(pFile);
            switch(ch)
            {
                case '^':
                    ++houses[i][++j];
                    break;
                case 'v':
                    ++houses[i][--j];
                    break;
                case '<':
                    ++houses[--i][j];
                    break;
                case '>':
                    ++houses[++i][j];
                    break;
                default:
                    // do nothing
                    break;
            }
        } while (ch != EOF);

        int numberOfHousesVisited = 0;
        for(i = 0; i < MAX_SIZE; ++i)
        {
            for(j = 0; j < MAX_SIZE; ++j)
            {
                if(houses[i][j] > 0)
                {
                    ++numberOfHousesVisited;
                }
            }
        }

        fclose(pFile);
        return numberOfHousesVisited;
    }
    else
    {
        printf("Could not open the input file for reading.\n");
    }

    fclose(pFile);
    return -1;
}

int second_puzzle(char *fileName)
{
    FILE *pFile = fopen(fileName, "r");
    if(pFile != NULL)
    {
        printf("Input file is open for reading.\n");

        int housesSanta[MAX_SIZE][MAX_SIZE];
        int housesRoboSanta[MAX_SIZE][MAX_SIZE];
        int housesTotal[MAX_SIZE][MAX_SIZE];
        int i, j; // i -> W-E axis; j -> N-S axis
        for(i = 0; i < MAX_SIZE; ++i)
        {
            for(j = 0; j < MAX_SIZE; ++j)
            {
                housesSanta[i][j] = 0;
                housesRoboSanta[i][j] = 0;
                housesTotal[i][j] = 0;
            }
        }
        int iSanta = MAX_SIZE / 2;
        int iRoboSanta = MAX_SIZE / 2;
        int jSanta = MAX_SIZE / 2;
        int jRoboSanta = MAX_SIZE / 2;
        housesSanta[iSanta][jSanta] = 1;
        housesRoboSanta[iRoboSanta][jRoboSanta] = 1;

        int ch;
        int index = 0;
        do
        {
            ch = getc(pFile);
            if(++index % 2 == 0)
            {
                // RoboSanta's turn
                switch(ch)
                {
                    case '^':
                        ++housesRoboSanta[iRoboSanta][++jRoboSanta];
                        break;
                    case 'v':
                        ++housesRoboSanta[iRoboSanta][--jRoboSanta];
                        break;
                    case '<':
                        ++housesRoboSanta[--iRoboSanta][jRoboSanta];
                        break;
                    case '>':
                        ++housesRoboSanta[++iRoboSanta][jRoboSanta];
                        break;
                    default:
                        // do nothing
                        break;
                }
            }
            else
            {
                // Santa's turn
                switch(ch)
                {
                    case '^':
                        ++housesSanta[iSanta][++jSanta];
                        break;
                    case 'v':
                        ++housesSanta[iSanta][--jSanta];
                        break;
                    case '<':
                        ++housesSanta[--iSanta][jSanta];
                        break;
                    case '>':
                        ++housesSanta[++iSanta][jSanta];
                        break;
                    default:
                        // do nothing
                        break;
                }
            }
        } while (ch != EOF);

        int numberOfHousesVisited = 0;
        for(i = 0; i < MAX_SIZE; ++i)
        {
            for(j = 0; j < MAX_SIZE; ++j)
            {
                housesTotal[i][j] = housesSanta[i][j] + housesRoboSanta[i][j];
                if(housesTotal[i][j] > 0)
                {
                    ++numberOfHousesVisited;
                }
            }
        }

        fclose(pFile);
        return numberOfHousesVisited;
    }
    else
    {
        printf("Could not open the input file for reading.\n");
    }

    fclose(pFile);
    return -1;
}