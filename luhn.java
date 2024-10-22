import java.util.Random;

public class LuhnAlgorithm {

    public static boolean luhnVerify(String ccNumber) {
        int sum = 0;
        boolean alt = false;
        for (int i = ccNumber.length() - 1; i >= 0; i--) {
            int digit = Character.getNumericValue(ccNumber.charAt(i));
            if (alt) {
                digit *= 2;
                if (digit > 9) digit -= 9;
            }
            sum += digit;
            alt = !alt;
        }
        return (sum % 10 == 0);
    }

    public static String luhnGenerate(int length) {
        Random rand = new Random();
        StringBuilder ccNumber = new StringBuilder();
        for (int i = 0; i < length - 1; i++) {
            ccNumber.append(rand.nextInt(10));
        }

        int sum = 0;
        boolean alt = true;
        for (int i = length - 2; i >= 0; i--) {
            int digit = Character.getNumericValue(ccNumber.charAt(i));
            if (alt) {
                digit *= 2;
                if (digit > 9) digit -= 9;
            }
            sum += digit;
            alt = !alt;
        }

        int checkDigit = (10 - (sum % 10)) % 10;
        ccNumber.append(checkDigit);

        return ccNumber.toString();
    }

    public static void main(String[] args) {
        String ccNumber = luhnGenerate(16);
        System.out.println("Generated CC Number: " + ccNumber);
        System.out.println("Verification: " + (luhnVerify(ccNumber) ? "Valid" : "Invalid"));
    }
}
