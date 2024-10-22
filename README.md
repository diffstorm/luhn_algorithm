# Luhn Algorithm and Credit Card Numbers

## Table of Contents
1. [Introduction](#introduction)
2. [Luhn Algorithm](#luhn-algorithm)
3. [Credit Card Number Structure](#credit-card-number-structure)
4. [Example](#example)
5. [Applications](#applications)
6. [Implementations](#implementations)

---

## Introduction

The **Luhn algorithm**, also known as the "modulus 10" or "mod 10" algorithm, is a simple checksum formula used to validate various identification numbers such as credit card numbers, IMEI numbers, and more. It is primarily designed to protect against accidental errors, such as mistyped or swapped digits.

This README explains the Luhn algorithm, how credit card numbers are structured, and the logic behind validating them.

---

## Luhn Algorithm

The Luhn algorithm checks whether a given number (typically a credit card number) is valid based on a simple checksum calculation. Here’s how the algorithm works:

### Steps:
1. **Starting from the right**, double every second digit. If the result is greater than 9, subtract 9 from it.
2. **Sum all the digits**, including the modified ones.
3. If the total sum is divisible by 10, the number is **valid**; otherwise, it is **invalid**.

### Formal Definition:
Given a number `d1 d2 d3 ... dn` (where each `d` is a digit in the number):
- Starting from the rightmost digit, double every second digit.
- If the result of doubling any digit is greater than 9, subtract 9 from the result.
- Sum all the digits.
- If the total modulo 10 is 0, the number is valid.

---

## Credit Card Number Structure

A typical credit card number consists of **16 digits** and is divided into three parts:

1. **Issuer Identification Number (IIN)**: The first 6 digits identify the issuer of the card (e.g., Visa, MasterCard).
2. **Account Number**: The next 9 digits represent the individual account number.
3. **Check Digit**: The final digit is a checksum value generated using the Luhn algorithm to ensure the validity of the card number.

### Example:
A hypothetical credit card number looks like this:

`4567 1234 5678 1234`

- **Issuer Identification**: `4567 12`
- **Account Number**: `3456 7812 34`
- **Check Digit**: `4`

### Purpose of the Check Digit:
The check digit ensures that the credit card number is valid according to the Luhn algorithm. If the number is mistyped or contains a transcription error, the Luhn check will fail, indicating an invalid card number.

---

## Example

Let’s manually validate the number `79927398713` using the Luhn algorithm:

1. Start from the right and double every second digit:  
   Original number: `7 9 9 2 7 3 9 8 7 1 3`  
   After doubling every second digit: `7 18 9 4 7 6 9 16 7 2 3`
   
2. If any product is greater than 9, subtract 9:  
   Adjusted values: `7 9 9 4 7 6 9 7 7 2 3`
   
3. Sum all the digits:  
   Sum = `7 + 9 + 9 + 4 + 7 + 6 + 9 + 7 + 7 + 2 + 3 = 70`
   
4. Check if the total is divisible by 10:  
   Since `70 % 10 == 0`, the number is **valid**.

---

## Applications

The Luhn algorithm is used in a variety of industries for validating identification numbers. Here are some of the most common applications beyond credit card numbers:

### 1. **Credit and Debit Card Numbers**
   - **Visa**, **MasterCard**, **American Express**, and other major credit card providers use the Luhn algorithm to validate card numbers before transactions.
   
### 2. **Bank Account Numbers**
   - Some countries use the Luhn algorithm to validate **bank account numbers**, especially for systems that require ensuring the correctness of customer data during entry.
   - Examples include:
     - **Canadian Social Insurance Numbers (SIN)**
     - **South African national identification numbers**

### 3. **IMEI Numbers (Mobile Phones)**
   - The **International Mobile Equipment Identity (IMEI)** number used to uniquely identify mobile phones uses the Luhn algorithm for error checking. Every GSM device has a unique IMEI number that can be validated using Luhn.

### 4. **National Identification Numbers**
   - Some national identification numbers use the Luhn algorithm to prevent transcription errors. Examples include:
     - **Israel ID Numbers**
     - **Greek Social Security Numbers (AMKA)**
     - **Estonian Personal Identification Numbers**
     
### 5. **Airline Ticket Numbers**
   - The algorithm is sometimes used to validate **airline ticket numbers** to prevent incorrect entries, ensuring that the ticket numbers follow the required format.

### 6. **Health Insurance Numbers**
   - **Australian Medicare** numbers and some other health insurance identification numbers utilize the Luhn algorithm to ensure data integrity.

### 7. **Canadian Social Insurance Numbers (SIN)**
   - The Luhn algorithm is used to validate Canadian SINs, helping to prevent entry errors when processing government benefits and taxes.

### 8. **UPC (Universal Product Code) and EAN (European Article Number)**
   - In retail, the Luhn algorithm (or a similar mod 10 algorithm) is sometimes applied to validate product codes such as **UPC** or **EAN**, helping to ensure that the barcodes scanned at checkout are valid.

### 9. **Government Numbers (e.g., VAT IDs)**
   - Some countries use Luhn or similar checksum algorithms to validate **VAT (Value Added Tax)** identification numbers. This helps ensure that the IDs are entered correctly in official documents.

### 10. **Gift Card and Loyalty Program Numbers**
   - Many **gift card numbers**, **loyalty program numbers**, and **discount codes** are validated using the Luhn algorithm to prevent entry errors during checkout.

### 11. **Prepaid and Virtual Credit Cards**
   - **Virtual credit card** and **prepaid card** providers often use Luhn to validate card numbers as they are generated and used for transactions.

### 12. **EU Health Insurance Card (EHIC)**
   - The Luhn algorithm is used for validating European Health Insurance Card (EHIC) numbers issued within the EU to ensure accurate data entry during healthcare access.

While the Luhn algorithm is widely used for simple **error detection**, it's important to note that it is **not intended for security purposes**. Its primary purpose is to catch accidental input errors (like typographical mistakes), not to prevent fraudulent activities or sophisticated attacks.

---

## Implementations

Below are implementations in different languages to generate and validate credit card numbers using the Luhn algorithm:

- [C Implementation](luhn.c)
- [C++ Implementation](luhn.cpp)
- [Java Implementation](luhn.java)
- [C# Implementation](luhn.cs)
- [Python Implementation](luhn.py)

Each implementation includes functions to:
1. **Generate** a valid credit card number.
2. **Verify** whether a given number is valid based on the Luhn algorithm.

--- 

## :snowman: Author
Eray Öztürk ([@diffstorm](https://github.com/diffstorm))
