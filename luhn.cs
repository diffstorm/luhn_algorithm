using System;

class LuhnAlgorithm {

    public static bool luhnVerify(string ccNumber) {
        int sum = 0;
        bool alt = false;
        for (int i = ccNumber.Length - 1; i >= 0; i--) {
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

    public static string luhnGenerate(int length) {
        Random rand = new Random();
        char[] ccNumber = new char[length - 1];
        for (int i = 0; i < length - 2; i++) {
            ccNumber[i] = (char)('0' + rand.Next(10));
        }

        int sum = 0;
        bool alt = true;
        for (int i = length - 3; i >= 0; i--) {
            int digit = ccNumber[i] - '0';
            if (alt) {
                digit *= 2;
                if (digit > 9) digit -= 9;
            }
            sum += digit;
            alt = !alt;
        }

        int checkDigit = (10 - (sum % 10)) % 10;
        ccNumber[length - 2] = (char)('0' + checkDigit);
        return new string(ccNumber);
    }

    static void Main() {
        string ccNumber = luhnGenerate(16);
        Console.WriteLine("Generated CC Number: " + ccNumber);
        Console.WriteLine("Verification: " + (luhnVerify(ccNumber) ? "Valid" : "Invalid"));
    }
}
