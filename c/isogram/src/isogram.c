#include "isogram.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ALPHABET_SIZE 26

bool is_isogram(const char phrase[])
{

    bool alphabet[ALPHABET_SIZE];

    memset(alphabet, false, sizeof(bool) * ALPHABET_SIZE);

    int length = strlen(phrase);
    for (int i = 0; i < length; ++i)
    {
        char lower_case_char = tolower(phrase[i]);
        int char_code = (int) lower_case_char - (int) 'a';

        if (char_code < 0 || char_code > 25) { // char not between [a-z]
            continue;
        }

        if (alphabet[char_code] == true) { // char has already appeared
            return false;
        }

        alphabet[char_code] = true; // set char as seen

    }
    return true;
}
