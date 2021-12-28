#include "roman_numerals.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

#define MAX_SIZE 100

char* answer(const char* start_roman_char,
             const char* middle_roman_char,
             const char* end_roman_char,
             const int arab_digit) {
    char* roman_numeral = (char*)malloc(sizeof(char) * MAX_SIZE);

    roman_numeral[0] = '\0';

    switch (arab_digit) {
        case 1:
            strcat(roman_numeral, start_roman_char);
            break;
        case 2:
            strcat(roman_numeral, start_roman_char);
            strcat(roman_numeral, start_roman_char);
            break;
        case 3:
            strcat(roman_numeral, start_roman_char);
            strcat(roman_numeral, start_roman_char);
            strcat(roman_numeral, start_roman_char);
            break;
        case 4:
            strcat(roman_numeral, start_roman_char);
            strcat(roman_numeral, middle_roman_char);
            break;
        case 5:
            strcat(roman_numeral, middle_roman_char);
            break;
        case 6:
            strcat(roman_numeral, middle_roman_char);
            strcat(roman_numeral, start_roman_char);
            break;
        case 7:
            strcat(roman_numeral, middle_roman_char);
            strcat(roman_numeral, start_roman_char);
            strcat(roman_numeral, start_roman_char);
            break;
        case 8:
            strcat(roman_numeral, middle_roman_char);
            strcat(roman_numeral, start_roman_char);
            strcat(roman_numeral, start_roman_char);
            strcat(roman_numeral, start_roman_char);
            break;
        case 9:
            strcat(roman_numeral, start_roman_char);
            strcat(roman_numeral, end_roman_char);
            break;
    }

    return roman_numeral;
}

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

    char* converted_part_C = answer("C", "D", "M", C_total);
    strcat(roman_numeral, converted_part_C);
    free(converted_part_C);

    int X_total = C_remainder / 10;
    int X_remainder = C_remainder % 10;
    // printf("X_total: %d\n", X_total);
    // printf("X_remainder: %d\n", X_remainder);

    char* converted_part_X = answer("X", "L", "C", X_total);
    strcat(roman_numeral, converted_part_X);
    free(converted_part_X);

    int I_total = X_remainder / 1;
    // printf("I_total: %d\n", I_total);

    char* converted_part_I = answer("I", "V", "X", I_total);
    strcat(roman_numeral, converted_part_I);
    free(converted_part_I);

    return roman_numeral;
}
