#include "hamming.h"
#include <string.h>

int diff_chars(char* dna_str1, char* dna_str2, int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (dna_str1[i] != dna_str2[i]) {
            count+=1;
        }
    }
    return count;
}

int compute(char* dna_str1, char* dna_str2) {
    int answer;
    if (dna_str1 && dna_str2 && strlen(dna_str1) == strlen(dna_str2)) {
        answer = diff_chars(dna_str1, dna_str2, strlen(dna_str1));
    } else {
        answer = -1;
    }
    return answer;
}
