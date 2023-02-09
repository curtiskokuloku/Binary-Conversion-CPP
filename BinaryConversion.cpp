/**
 * @brief  Implementations of conversion methods for binary numbers, decimals, octal and hexadecimal
 * @author Curtis Kokuloku   
 * @note Used for one of my classes (CSCI 2021 - Machine Architecture)
 */

#include <iostream>
#include <cmath>

using namespace std;

/**
 * @brief Convert binary numbers to decimal numbers
 * @param  num: representing a binary number
 * @return an integer value as decimal number 
 */
int binaryToDecimal(int num) {
    int decimal = 0, base = 1, remainder = 0;
    while (num > 0) {
        remainder = num % 10;
        decimal += remainder * base;
        num /= 10;
        base *= 2;
    }
    return decimal;
}

/**
 * @brief Convert decimal numbers to binary numbers
 * @param  decimal: representing a decimal number
 * @return None
 */
void decimalToBinary(int decimal) {
    int length = floor(log2(decimal)) + 1;
    int binaryNum[length];
    int i = 0;
    while (decimal > 0) {
        binaryNum[i++] = decimal % 2;
        decimal /= 2;
    }
    cout << decimal << " = ";
    for (int i = length - 1; i >= 0; i--) {
        cout << binaryNum[i];
    }
    cout << "in binary" << endl;
}

/**
 * @brief Convert decimal numbers to octal numbers
 * @param  decimalNum: representing a decimal number
 * @return None
 */
void decimalToOctal(int decimalNum) {
    int octalLength = floor(log10(decimalNum) / log10(8)) + 1;
    int octalNum[octalLength];
    int i = 0;
    while (decimalNum > 0){
        octalNum[i++] = decimalNum % 8;
        decimalNum /= 8;
    }
    cout << decimalNum << " = ";
    for (int i = octalLength - 1; i >= 0; i--) {
        cout << octalNum[i];
    }
    cout << " in octal" << endl;
}

/**
 * @brief Convert octal numbers to decimal numbers
 * @param  octalNum: representing a binary number
 * @return an integer value as decimal number
 */
int octalToDecimal(int octalNum) {
    int decimalNum = 0;
    int i = 0;
    int remainder;
    while (octalNum != 0){
        remainder = octalNum % 10;
        octalNum /= 10;
        decimalNum += remainder * pow(8, i);
        ++i;
    }
    return decimalNum;
}

/**
 * @brief Convert decimal numbers to hexadecimal numbers
 * @param  decimalNum: representing a binary number
 * @return None
 */
void decimalToHexadecimal(int decimalNum) {
    char hexaDecimal[100];
    int i = 0;
    while (decimalNum != 0) {
        int temp = decimalNum % 16;
        if (temp < 10){
            hexaDecimal[i] = temp + 48;
        } else{
            hexaDecimal[i] = temp + 55;
        }
        decimalNum = decimalNum / 16;
        i++;
    }
    cout << decimalNum << " = ";
    for (int j = i - 1; j >= 0; j--) {
        cout << hexaDecimal[j];
    }
    cout << " in hexadecimal" << endl;
}

/**
 * @brief Convert hexadecimal numbers to decimal numbers
 * @param  hexaNum: representing a binary number
 * @return an integer value as decimal number
 */
int hexaToDecimal(char hexaNum[]){
    int len = strlen(hexaNum);
    int decimalNum = 0;
    int base = 1;
    for (int i = len - 1; i >= 0; i--){
        if (hexaNum[i] >= '0' && hexaNum[i] <= '9'){
            decimalNum += (hexaNum[i] - 48) * base;
            base = base * 16;
        } else if (hexaNum[i] >= 'A' && hexaNum[i] <= 'F') {
            decimalNum += (hexaNum[i] - 55) * base;
            base = base * 16;
        }
    }
    return decimalNum;
}