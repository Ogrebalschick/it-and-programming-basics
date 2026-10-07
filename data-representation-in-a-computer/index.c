#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void separator(double number, long *integerNumber, long *fractionalNumber) {
    char numberCount = snprintf(NULL, 0 , "%.16g", number);
    char *numberString = (char *)malloc((numberCount + 1) * sizeof(char));
    snprintf(numberString, numberCount + 1, "%.16g", number);
    int integerPartCount = 0;
    int fractionalPartCount = 0;
    int isIntegerPart = true;
    for (int i = 0; i < numberCount; i++) {
        if (numberString[i] == '.') {
            isIntegerPart = false;
            continue;
        }
        isIntegerPart ? integerPartCount++ : fractionalPartCount++;
    }


    char *integerPart = (char *)malloc((integerPartCount + 1) * sizeof(char));
    char *fractionalPart = (char *)malloc((fractionalPartCount + 1) * sizeof(char));
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

int main () {
    
    double number;
    printf("Input number: ");
    scanf("%lf", &number);
    printf("\n");
    printf("Your number: %.16g", number);
    printf("\n");
    
    long integerNumber, fractionalNumber;

    separator(number, &integerNumber, &fractionalNumber);
    printf("integerPart: %d \n", integerNumber);
    printf("fractionalPart: %d", fractionalNumber);

    return 0;
}