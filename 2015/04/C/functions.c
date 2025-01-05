#include <openssl/evp.h>
#include <stdbool.h>
#include <string.h>

#include "functions.h"

/**
 * Implemented using the code provided by devtty1er on stackoverflow.com
 * https://stackoverflow.com/questions/7627723/how-to-create-a-md5-hash-of-a-string-in-c/61333376#61333376
 * TO DO: implement algorithm directly from pseudocode (https://en.wikipedia.org/wiki/MD5)
 */
void bytes2md5(const char *data, int len, char *md5buf)
{
    EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
    const EVP_MD *md = EVP_md5();
    unsigned char md_value[EVP_MAX_MD_SIZE];
    unsigned int md_len, i;
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, data, len);
    EVP_DigestFinal_ex(mdctx, md_value, &md_len);
    EVP_MD_CTX_free(mdctx);
    for (i = 0; i < md_len; i++) {
        snprintf(&(md5buf[i * 2]), 16 * 2, "%02x", md_value[i]);
    }
}

int findNumber(char *fileName, int numberOfZeroes)
{
    FILE *filePointer = fopen(fileName, "r");
    if(filePointer != NULL)
    {
        printf("Input file is open for reading.\n");

        char inputString[33];
        fscanf(filePointer, "%s", inputString);
        char workingString[33];
        char numbers[33];
        char md5[33];
        bool zeroesMet = false;
        int number = 0;
        do
        {
            strcpy(workingString, inputString);
            sprintf(numbers, "%d", ++number);
            strcat(workingString, numbers);
            bytes2md5(workingString, strlen(workingString), md5);
            int i;
            zeroesMet = (md5[0] == '0');
            for(i = 1; i < numberOfZeroes; ++i)
            {
                zeroesMet = zeroesMet && (md5[i] == '0');
            }
        } while (!zeroesMet);
        printf("%s\n", md5);

        fclose(filePointer);
        return number;
    }
    else
    {
        printf("Could not open the input file for reading.\n");
    }

    fclose(filePointer);
    return -1;
}

int first_puzzle(char *fileName)
{
    return findNumber(fileName, 5);
}

int second_puzzle(char *fileName)
{
    return findNumber(fileName, 6);
}