#include "hamming.h"
#include <string.h>

int diff_chars(char* dna_str1, char* dna_str2, int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (dna_str1[i] != dna_str2[i]) {
            count += 1;
        }
    }
    return count;
}

int compute(char* dna_str1, char* dna_str2) {
    int answer;
    if (dna_str1 && dna_str2) {
        int len_a = strlen(dna_str1);
        int len_b = strlen(dna_str2);
        if (len_a != len_b) {  // dna strings size wasn't the same
            answer = -1;
        } else {  // case where we can compare them
            answer = diff_chars(dna_str1, dna_str2, len_a);
        }
    } else {  // one of the two pointers was NULL
        answer = -1;
    }
    return answer;
}
