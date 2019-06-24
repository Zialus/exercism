#include "roman_numerals.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

#define MAX_SIZE 100

char* to_roman_numeral(const int number) {
    char* roman_numeral = (char*)malloc(sizeof(char) * MAX_SIZE);

    roman_numeral[0] = '\0';

    int M_total = number / 1000;
    int M_remainder = number % 1000;
    // printf("M_total: %d\n", M_total);
    // printf("M_remainder: %d\n", M_remainder);

    for (int i = 0; i < M_total; ++i) {
        strcat(roman_numeral, "M");
    }

    int C_total = M_remainder / 100;
    int C_remainder = M_remainder % 100;
    // printf("C_total: %d\n", C_total);
    // printf("C_remainder: %d\n", C_remainder);

    switch (C_total) {
        case 1:
            strcat(roman_numeral, "C");
            break;
        case 2:
            strcat(roman_numeral, "CC");
            break;
        case 3:
            strcat(roman_numeral, "CCC");
            break;
        case 4:
            strcat(roman_numeral, "CD");
            break;
        case 5:
            strcat(roman_numeral, "D");
            break;
        case 6:
            strcat(roman_numeral, "DC");
            break;
        case 7:
            strcat(roman_numeral, "DCC");
            break;
        case 8:
            strcat(roman_numeral, "DCCC");
            break;
        case 9:
            strcat(roman_numeral, "CM");
            break;
    }

    int X_total = C_remainder / 10;
    int X_remainder = C_remainder % 10;
    // printf("X_total: %d\n", X_total);
    // printf("X_remainder: %d\n", X_remainder);

    switch (X_total) {
        case 1:
            strcat(roman_numeral, "X");
            break;
        case 2:
            strcat(roman_numeral, "XX");
            break;
        case 3:
            strcat(roman_numeral, "XXX");
            break;
        case 4:
            strcat(roman_numeral, "XL");
            break;
        case 5:
            strcat(roman_numeral, "L");
            break;
        case 6:
            strcat(roman_numeral, "LX");
            break;
        case 7:
            strcat(roman_numeral, "LXX");
            break;
        case 8:
            strcat(roman_numeral, "LXXX");
            break;
        case 9:
            strcat(roman_numeral, "XC");
            break;
    }

    int I_total = X_remainder / 1;
    // printf("I_total: %d\n", I_total);

    switch (I_total) {
        case 1:
            strcat(roman_numeral, "I");
            break;
        case 2:
            strcat(roman_numeral, "II");
            break;
        case 3:
            strcat(roman_numeral, "III");
            break;
        case 4:
            strcat(roman_numeral, "IV");
            break;
        case 5:
            strcat(roman_numeral, "V");
            break;
        case 6:
            strcat(roman_numeral, "VI");
            break;
        case 7:
            strcat(roman_numeral, "VII");
            break;
        case 8:
            strcat(roman_numeral, "VIII");
            break;
        case 9:
            strcat(roman_numeral, "IX");
            break;
    }

    return roman_numeral;
}
