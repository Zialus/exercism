#include "two_fer.h"
#include <stdio.h>

#define BUFFER_SIZE 100

void two_fer(char* const buffer, const char* const name) {
    const char* const name_to_print = name ? name : "you";

    snprintf(buffer, BUFFER_SIZE, "One for %s, one for me.", name_to_print);
}
