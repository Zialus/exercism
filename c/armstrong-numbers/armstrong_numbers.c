#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "armstrong_numbers.h"

#define BUFFER_SIZE 100000

bool is_armstrong_number(const int candidate) {
    char buffer[BUFFER_SIZE];

    snprintf(buffer, BUFFER_SIZE, "%d", candidate);

    const int number_digits = strlen(buffer);
    // printf("number_of_digits = %d\n", number_digits);

    double result = 0;

    for (int i = 0; i < number_digits; i++) {
        char tmp_char[2];
        tmp_char[0] = '\0';
        strncpy(tmp_char, &buffer[i], 1);
        int digit = atoi(tmp_char);
        // printf("%f=%d**%d\n", pow(digit, number_digits), digit, number_digits);
        result += pow(digit, number_digits);
    }

    // printf("%f == %d?\n", result, candidate);
    return result == candidate;
}
