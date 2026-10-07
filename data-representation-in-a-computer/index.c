#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



void separator(double number, long *integerNumber, long *fractionalNumber, int * fractionalPartCount) {
    char numberCount = snprintf(NULL, 0 , "%.16g", number);
    char *numberString = (char *)malloc((numberCount + 1) * sizeof(char));
    snprintf(numberString, numberCount + 1, "%.16g", number);

    int integerPartCount = 0;
    int isIntegerPart = true;
    for (int i = 0; i < numberCount; i++) {
        if (numberString[i] == '.') {
            isIntegerPart = false;
            continue;
        }
        isIntegerPart ? integerPartCount++ : (*fractionalPartCount)++;
    }


    char *integerPart = (char *)malloc((integerPartCount + 1) * sizeof(char));
    char *fractionalPart = (char *)malloc(((*fractionalPartCount) + 1) * sizeof(char));
    int integerIdx = 0;
    int fractionalIdx = 0;
    isIntegerPart = true;
    for (int i = 0; i < numberCount; i++) {
        if (numberString[i] == '.') {
            isIntegerPart = false;
            continue;
        }
        if (isIntegerPart) {
            integerPart[integerIdx] = numberString[i];
            integerIdx++;
        } else {
            fractionalPart[fractionalIdx] = numberString[i];
            fractionalIdx++;
        }
    }

    integerPart[integerIdx] = '\0';
    fractionalPart[fractionalIdx] = '\0';


    *integerNumber = strtol(integerPart, NULL, 10);
    *fractionalNumber = strtol(fractionalPart, NULL, 10);


 

    free(numberString);
    free(integerPart);
    free(fractionalPart);
}


char * integerDecimal2Binary(int integerNumber, int *integerNumberTwoSize) {
    int integerNumber4integerNumberTwoSize = integerNumber;
    int integerNumber4integerNumberTwo = integerNumber;
    while (integerNumber4integerNumberTwoSize > 0) {
        (*integerNumberTwoSize)++;
        integerNumber4integerNumberTwoSize = integerNumber4integerNumberTwoSize / 2;
    }
    char *integerNumberTwo = (char *)malloc(((*integerNumberTwoSize) + 1) * sizeof(char));
    int integerNumberTwoInd = (*integerNumberTwoSize);
    while (integerNumber4integerNumberTwo > 0) {
        integerNumberTwo[integerNumberTwoInd - 1] = (integerNumber4integerNumberTwo % 2) + '0';
        integerNumber4integerNumberTwo = integerNumber4integerNumberTwo / 2;
        integerNumberTwoInd--;
    }
    integerNumberTwo[(*integerNumberTwoSize)] = '\0';
    
    return integerNumberTwo;
}



void fractionalDecimal2Binary(int fractionalNumber, int fractionalPartCount, char **fractionalNumberReady) {
    char *fractionalNumberWithIntager = (char *)malloc((fractionalPartCount + 3) * sizeof(char));
    fractionalNumberWithIntager[0] = '0';
    fractionalNumberWithIntager[1] = '.';
    char fractionalNumberCount = snprintf(NULL, 0 , "%.16g", fractionalNumber);
    char *fractionalNumberString = (char *)malloc((fractionalPartCount + 1) * sizeof(char));
    snprintf(fractionalNumberString, fractionalPartCount + 1, "%d", fractionalNumber); 
    for (int i = 2; i < fractionalPartCount + 2; i++) {
        fractionalNumberWithIntager[i] = fractionalNumberString[i - 2];
    }
    fractionalNumberWithIntager[fractionalPartCount + 2] = '\0';
    double fractionalNumberWithIntagerInteger = strtod(fractionalNumberWithIntager, NULL);
    long fractionalNumberWithIntagerIntegerIntegerNumber = 0;
    long fractionalNumberWithIntagerIntegerfractionalNumber = 0;
    int fractionalNumberWithIntagerIntegerfractionalPart = 0;
    int rounding;
    printf("Rounding precision: ");
    scanf("%d", &rounding);

    *fractionalNumberReady = (char *)malloc((rounding + 1) * sizeof(char));
    for (int i = 0; i<rounding; i++) {
        fractionalNumberWithIntagerInteger = fractionalNumberWithIntagerInteger * 2;
        fractionalNumberWithIntagerIntegerIntegerNumber = 0;
        fractionalNumberWithIntagerIntegerfractionalNumber = 0;
        fractionalNumberWithIntagerIntegerfractionalPart = 0;
        int tempFractionalPartCount = 0; 

        separator(fractionalNumberWithIntagerInteger, &fractionalNumberWithIntagerIntegerIntegerNumber, &fractionalNumberWithIntagerIntegerfractionalNumber, &tempFractionalPartCount);
        (*fractionalNumberReady)[i] = fractionalNumberWithIntagerIntegerIntegerNumber + '0';
        fractionalNumberWithIntagerInteger -= fractionalNumberWithIntagerIntegerIntegerNumber;
    }
    (*fractionalNumberReady)[rounding] = '\0';
}


int main () {
    
    double number;
    printf("Input number: ");
    scanf("%lf", &number);
    printf("\n");
    printf("Your number: %.16g", number);
    printf("\n");
    
    long integerNumber, fractionalNumber;

    int fractionalPartCount = 0;
    separator(number, &integerNumber, &fractionalNumber, &fractionalPartCount);

    int integerNumberTwoSize = 0;
    
    char * integerNumberBinary = integerDecimal2Binary(integerNumber, &integerNumberTwoSize);

    printf("integerNumberBinary: %s \n", integerNumberBinary);

    char *fractionalNumberReady;
    fractionalDecimal2Binary(fractionalNumber, fractionalPartCount, &fractionalNumberReady);
    
    printf("fractionalNumberBinary: %s", fractionalNumberReady);
    return 0;
}