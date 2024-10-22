#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Luhn checksum calculation
bool luhnVerify(const char* ccNumber) {
    int nDigits = 0, sum = 0, alt = 0;
    while (ccNumber[nDigits]) nDigits++;
    for (int i = nDigits - 1; i >= 0; i--) {
        int digit = ccNumber[i] - '0';
        if (alt) {
            digit *= 2;
            if (digit > 9) digit -= 9;
        }
        sum += digit;
        alt = !alt;
    }
    return (sum % 10 == 0);
}

// Generate valid Luhn number
void luhnGenerate(char* ccNumber, int length) {
    srand(time(0));
    for (int i = 0; i < length - 1; i++) {
        ccNumber[i] = (rand() % 10) + '0';
    }
    ccNumber[length - 1] = '\0';

    // Calculate check digit
    int sum = 0, alt = 1;
    for (int i = length - 2; i >= 0; i--) {
        int digit = ccNumber[i] - '0';
        if (alt) {
            digit *= 2;
            if (digit > 9) digit -= 9;
        }
        sum += digit;
        alt = !alt;
    }
    int checkDigit = (10 - (sum % 10)) % 10;
    ccNumber[length - 2] = checkDigit + '0';
}

int main() {
    char ccNumber[17];
    luhnGenerate(ccNumber, 16);
    printf("Generated CC Number: %s\n", ccNumber);
    printf("Verification: %s\n", luhnVerify(ccNumber) ? "Valid" : "Invalid");
    return 0;
}
