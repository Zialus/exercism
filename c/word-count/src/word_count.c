#include "word_count.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <assert.h>

void check_word(char* word, word_count_word_t * words, int* index) {

    for (int i = 0; i < MAX_WORDS; ++i)
    {
        if (strcmp(words[i].text, word) == 0) {
            // printf("Already exists: %s at index %d\n",word,i);
            words[i].count += 1;
            return;
        }
    }

    int idx = *index;
    // printf("Added word: \"%s\" at index %d\n", word, idx);
    strcpy(words[idx].text, word);
    words[idx].count += 1;
    (*index)+=1;

}

int count_words(word_count_word_t * words) {
    int count = 0;

    for (int i = 0; i < MAX_WORDS; ++i)
    {
        if (strncmp(words[i].text,"",1) != 0) {
            // printf("words: %s,%d\n", words[i].text,i);
            count+=1;
        }
    }
    return count;
}

void string_to_lower_case(char* str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void remove_quotation(char* str) {
    assert(strlen(str) > 0);
    if (str[0] == '\'' && str[strlen(str)-1] == '\'') {
        memmove(str, str+1, strlen(str));
        str[strlen(str)-1] = '\0';
    }
}

void clean_token(char* str){
    string_to_lower_case(str);
    remove_quotation(str);
}

int word_count(const char *input_text, word_count_word_t * words){

    memset(words, 0, (sizeof(*words)*MAX_WORDS));

    char* s = malloc(sizeof(char)*strlen(input_text)+1);
    strcpy(s, input_text);
    char* token_list = " ,.:!&@$%^\n";
    char* token = strtok(s, token_list);

    int index = 0;
    int answer_count = 0;
    while (token) {
        // printf("token: %s\n", token);
        clean_token(token);
        if (strlen(token) > MAX_WORD_LENGTH) {
            answer_count = EXCESSIVE_LENGTH_WORD;
            break;
        }
        if (index == MAX_WORDS) {
            answer_count = EXCESSIVE_NUMBER_OF_WORDS;
            break;
        }
        check_word(token, words, &index);
        token = strtok(NULL, token_list);
    }

    free(s);

    if ( answer_count == 0) {
        answer_count = count_words(words);
    }
    // printf("Answer is %d!\n", answer_count);
    return answer_count;
}
