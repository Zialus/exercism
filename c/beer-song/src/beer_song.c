#include "beer_song.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

char* plural_vs_singular_bottle(const int bottle_amount) {
    assert(bottle_amount >= 0);

    char* answer = (char*) malloc(sizeof(char) * BUFFER_SIZE);

    if (bottle_amount > 1) {
        snprintf(answer, BUFFER_SIZE, "%d bottles", bottle_amount);
    } else if (bottle_amount == 1) {
        snprintf(answer, BUFFER_SIZE, "%d bottle", bottle_amount);
    } else { // bottle_amount = 0
        snprintf(answer, BUFFER_SIZE, "no more bottles");
    }

    return answer;
}

char* buy_or_not(const int bottle_amount) {
    assert(bottle_amount >= 0);

    char* answer = (char*) malloc(sizeof(char) * BUFFER_SIZE);

    if (bottle_amount > 1) {
        snprintf(answer, BUFFER_SIZE, "Take one down and pass it around,");
    } else if (bottle_amount == 1) {
        snprintf(answer, BUFFER_SIZE, "Take it down and pass it around,");
    } else { // bottle_amount = 0
        snprintf(answer, BUFFER_SIZE, "Go to the store and buy some more,");
    }

    return answer;
}

void verse(char* buffer, const int bottle_amount) {
    assert(bottle_amount >= 0);

    int bottle_amount_next; 
    if (bottle_amount == 0) {
        bottle_amount_next = 99;
    } else {
        bottle_amount_next = bottle_amount - 1;
    }

    const char first_component[] = "of beer on the wall,";
    const char second_component[] = "of beer.\n";
    char* third_component = buy_or_not(bottle_amount);
    const char forth_component[] = "of beer on the wall.\n";

    char* pre_bottle_amount = plural_vs_singular_bottle(bottle_amount);
    char* post_bottle_amount = plural_vs_singular_bottle(bottle_amount_next);
    char* pre_bottle_amount_Uppercase = strdup(pre_bottle_amount);
    pre_bottle_amount_Uppercase[0] = toupper(pre_bottle_amount_Uppercase[0]);


    snprintf(buffer, BUFFER_SIZE, "%s %s %s %s%s %s %s",
             pre_bottle_amount_Uppercase, first_component,
             pre_bottle_amount, second_component,
             third_component,
             post_bottle_amount, forth_component);


    free(pre_bottle_amount);
    free(post_bottle_amount);
    free(third_component);
    free(pre_bottle_amount_Uppercase);

    return;
}

void sing(char* buffer, const int from, const int up_to) {
    buffer[0] = '\0';

    for (int i = from; i > up_to; --i) {
        char store[BUFFER_SIZE];
        verse(store, i);
        strcat(buffer, store);
        strcat(buffer, "\n");
    }
    char store[BUFFER_SIZE];
    verse(store, up_to);
    strcat(buffer, store);

    return;
}
