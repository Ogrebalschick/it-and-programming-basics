#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void separator(double number) {
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
    
    printf("integerPartCount: %d \n", integerPartCount);
    printf("fractionalPartCount: %d", fractionalPartCount);

    free(numberString);
}

int main () {
    
    double number;
    printf("Input number: ");
    scanf("%lf", &number);
    printf("\n");
    printf("Your number: %.16g", number);
    printf("\n");
    separator(number);

    return 0;
}