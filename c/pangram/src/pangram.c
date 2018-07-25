#include "pangram.h"
#include <ctype.h>
#include <string.h>

#define ALPHABET_SIZE 26

bool is_pangram(const char *sentence) {

    if (sentence == NULL) {
        return NULL;
    }

    bool alphabet[ALPHABET_SIZE];
    memset(alphabet, false, sizeof(bool) * ALPHABET_SIZE);

    int length = strlen(sentence);
    for (int i = 0; i < length; ++i) {
        char lower_case_char = tolower(sentence[i]);
        int char_code = (int)lower_case_char - (int)'a';

        if (char_code < 0 || char_code > 25) {
            continue; // skip chars not between [a-z]
        }

        alphabet[char_code] = true;
    }

    bool answer = true;
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (alphabet[i] == false) {
            answer = false; // if a char is not present, the sentence is not a pangram
        }
    }

    return answer;
}
