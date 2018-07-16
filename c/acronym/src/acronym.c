#include "acronym.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 10000

char *abbreviate(const char *phrase){

    if (phrase == NULL || strncmp(phrase,"",1) == 0 || strlen(phrase) >= MAX_SIZE)
    {
        return NULL; // return NULL if input string is null, empty, or too big
    }

    char s[MAX_SIZE];
    char* acronym = (char*) malloc(sizeof(char)*MAX_SIZE);
    strcpy(s, phrase);
    // printf("Initial String: %s\n", s);
    char* token_list = " -,:";
    char* token = strtok(s, token_list);

    int idx = 0;
    while (token)
    {
        // printf("token: %s\n", token);
        char first_char_upper_case = toupper(token[0]);
        acronym[idx] = first_char_upper_case;
        token = strtok(NULL, token_list);
        idx++;
    }
    acronym[idx] = '\0'; // Add string terminator at the final position
    
    // printf("Final String: %s\n", acronym);
    return acronym;

}
