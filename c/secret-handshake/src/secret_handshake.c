#include "secret_handshake.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_first_null(const char** array_of_strings) {
    int i = 0;
    while (array_of_strings[i] != NULL) {
        i++;
    }
    return i;
}

void append(const char** array_of_strings, char* string) {
    int index = find_first_null(array_of_strings);
    array_of_strings[index] = string;
}

void reverse(const char** array_of_strings) {
    int start = 0;
    int end = find_first_null(array_of_strings) - 1;

    while (start < end) {
        const char* temp = array_of_strings[end];
        array_of_strings[end] = array_of_strings[start];
        array_of_strings[start] = temp;
        start++;
        end--;
    }
}

void to_bitstring(int num, char* buffer, int size) {
    assert(num <= ((1 << (size-1)) - 1)); // make sure num fits in binary representation for the given size.

    buffer[--size] = '\0';
    while (size > 0) {
        buffer[--size] = ( (num % 2) ? '1' : '0');
        num = num >> 1;
    }
}

const char** commands(const int number) {
    char binary_string[6];
    to_bitstring(number, binary_string, 6);
    printf("%s\n", binary_string);

    const char** result = malloc(sizeof(char) * 50);

    memset(result, 0, sizeof(char) * 50);

    if (binary_string[4] == '1') {
        append(result, "wink"); // 1 = wink
    }
    if (binary_string[3] == '1') {
        append(result, "double blink"); // 10 = double blink
    }
    if (binary_string[2] == '1') {
        append(result, "close your eyes"); // 100 = close your eyes
    }
    if (binary_string[1] == '1') {
        append(result, "jump"); // 1000 = jump
    }
    if (binary_string[0] == '1') {
        reverse(result); // 10000 = Reverse the order of the operations in the secret handshake.
    }

    return result;
}
