#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



char *double2char(double num) {
    int numLen = snprintf(NULL, 0 , "%.16g", num);
    char *numStr = (char *)malloc((numLen + 1) * sizeof(char));
    snprintf(numStr, numLen + 1, "%.16g", num);

    return numStr;
}

void separator(double num, long *intPart, long *fracPart, int *fracPartLen) {
    char *numStr = double2char(num);
    int numLen = snprintf(NULL, 0 , "%.16g", num);
    int intPartLen = 0;
    bool isIntPart = true;

    // START: Counter for the length of the integer and fractional parts.
    for (int i = 0; i < numLen; i++) {
        if (numStr[i] == '.') {
            isIntPart = false;
            continue;
        }
        if (isIntPart) {
            intPartLen++;
        } else {
            (*fracPartLen)++;
        }
    }
    // END: Counter for the length of the integer and fractional parts.

    char *intPartStr = (char *)malloc((intPartLen + 1) * sizeof(char));
    char *fracPartStr = (char *)malloc(((*fracPartLen) + 1) * sizeof(char));
    int intIndex = 0;
    int fracIndex = 0;
    isIntPart = true;
    for (int i = 0; i < numLen; i++) {
        if (numStr[i] == '.') {
            isIntPart = false;
            continue;
        }
        if (isIntPart) {
            intPartStr[intIndex++] = numStr[i];
        } else {
            fracPartStr[fracIndex++] = numStr[i];
        }
    }

    intPartStr[intIndex] = '\0';
    fracPartStr[fracIndex] = '\0';

    *intPart = strtol(intPartStr, NULL, 10);
    *fracPart = strtol(fracPartStr, NULL, 10);

    free(numStr);
    free(intPartStr);
    free(fracPartStr);
}


char * int2Bin(long intPart, int *intBinLen) {
    int tempForLen = intPart;
    int tempForCovert = intPart;
    while (tempForLen > 0) {
        (*intBinLen)++;
        tempForLen = tempForLen / 2;
    }
    char *intPartBin = (char *)malloc(((*intBinLen) + 1) * sizeof(char));
    int intPartBinIndex = (*intBinLen);
    while (tempForCovert > 0) {
        intPartBin[intPartBinIndex - 1] = (tempForCovert % 2) + '0';
        tempForCovert /= 2;
        intPartBinIndex--;
    }
    intPartBin[(*intBinLen)] = '\0';
    
    return intPartBin;
}



void frac2Bin(long fracPart, int fracPartLen, char **fracPartBin) {
    double fracNum = fracPart;
    for (int i = 0; i < fracPartLen; i++) {
        fracNum /= 10.0;
    }
    int rounding;
    printf("Rounding precision: ");
    scanf("%d", &rounding);

    *fracPartBin = (char *)malloc((rounding + 1) * sizeof(char));
    for (int i = 0; i < rounding; i++) {
        fracNum *= 2;
        int intPart = (int)fracNum;
        (*fracPartBin)[i] = intPart + '0';
        fracNum -= intPart;
    }
    (*fracPartBin)[rounding] = '\0';
}


int main () {
    
    double num;
    printf("Input number: ");
    scanf("%lf", &num);
    printf("\n");

    long intPart = 0, fracPart = 0;
    int fracPartlen = 0;

    separator(num, &intPart, &fracPart, &fracPartlen);

    int intPartBinLen = 0;
    char * intPartBin = int2Bin(intPart, &intPartBinLen);

    printf("integerNumberBinary: %s \n", intPartBin);

    char *fracPartBin;
    frac2Bin(fracPart, fracPartlen, &fracPartBin);
    
    printf("fractionalNumberBinary: %s", fracPartBin);

    int sign;
    sign = (num >= 0) ? 0 : 1;

    return 0;
}