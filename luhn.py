import random

def luhn_verify(cc_number):
    sum = 0
    alt = False
    for digit in reversed(cc_number):
        digit = int(digit)
        if alt:
            digit *= 2
            if digit > 9:
                digit -= 9
        sum += digit
        alt = not alt
    return sum % 10 == 0

def luhn_generate(length):
    cc_number = [random.randint(0, 9) for _ in range(length - 1)]
    
    sum = 0
    alt = True
    for i in range(length - 2, -1, -1):
        digit = cc_number[i]
        if alt:
            digit *= 2
            if digit > 9:
                digit -= 9
        sum += digit
        alt = not alt

    check_digit = (10 - (sum % 10)) % 10
    cc_number.append(check_digit)

    return ''.join(map(str, cc_number))

if __name__ == '__main__':
    cc_number = luhn_generate(16)
    print(f"Generated CC Number: {cc_number}")
    print(f"Verification: {'Valid' if luhn_verify(cc_number) else 'Invalid'}")
