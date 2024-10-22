#include <iostream>
#include <cstdlib>
#include <ctime>

bool luhnVerify(const std::string& ccNumber) {
    int sum = 0, alt = 0;
    for (int i = ccNumber.length() - 1; i >= 0; --i) {
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

std::string luhnGenerate(int length) {
    srand(time(0));
    std::string ccNumber(length - 1, '0');
    for (int i = 0; i < length - 2; ++i) {
        ccNumber[i] = (rand() % 10) + '0';
    }

    int sum = 0, alt = 1;
    for (int i = length - 3; i >= 0; --i) {
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
    return ccNumber;
}

int main() {
    std::string ccNumber = luhnGenerate(16);
    std::cout << "Generated CC Number: " << ccNumber << std::endl;
    std::cout << "Verification: " << (luhnVerify(ccNumber) ? "Valid" : "Invalid") << std::endl;
    return 0;
}
