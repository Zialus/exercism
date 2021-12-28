#include "raindrops.h"
#include <stdio.h>
#include <string.h>

void convert(char* const buffer, const int drops) {
    buffer[0] = '\0';

    if (drops % 3 == 0) { strcat(buffer, "Pling"); }
    if (drops % 5 == 0) { strcat(buffer, "Plang"); }
    if (drops % 7 == 0) { strcat(buffer, "Plong"); }

    if (buffer[0] == '\0') {
        sprintf(buffer, "%d", drops);
    }

    return;
}
