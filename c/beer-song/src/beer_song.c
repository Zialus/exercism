#include "beer_song.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void plural_vs_singular_bottle(const int bottle_amount, char* answer_buffer) {
    assert(bottle_amount >= 0);

    if (bottle_amount > 1) {
        snprintf(answer_buffer, BUFFER_SIZE, "%d bottles", bottle_amount);
    } else if (bottle_amount == 1) {
        snprintf(answer_buffer, BUFFER_SIZE, "%d bottle", bottle_amount);
    } else { // bottle_amount = 0
        snprintf(answer_buffer, BUFFER_SIZE, "no more bottles");
    }

}

void buy_or_not(const int bottle_amount, char* answer_buffer) {
    assert(bottle_amount >= 0);

    if (bottle_amount > 1) {
        snprintf(answer_buffer, BUFFER_SIZE, "Take one down and pass it around,");
    } else if (bottle_amount == 1) {
        snprintf(answer_buffer, BUFFER_SIZE, "Take it down and pass it around,");
    } else { // bottle_amount = 0
        snprintf(answer_buffer, BUFFER_SIZE, "Go to the store and buy some more,");
    }

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
    char third_component[BUFFER_SIZE];
    buy_or_not(bottle_amount, third_component);
    const char forth_component[] = "of beer on the wall.\n";

    char pre_bottle_amount[BUFFER_SIZE];
    plural_vs_singular_bottle(bottle_amount, pre_bottle_amount);

    char post_bottle_amount[BUFFER_SIZE];
    plural_vs_singular_bottle(bottle_amount_next, post_bottle_amount);

    char pre_bottle_amount_Uppercase[BUFFER_SIZE];
    strncpy(pre_bottle_amount_Uppercase, pre_bottle_amount, BUFFER_SIZE);
    pre_bottle_amount_Uppercase[0] = toupper(pre_bottle_amount_Uppercase[0]);


    snprintf(buffer, BUFFER_SIZE, "%s %s %s %s%s %s %s",
             pre_bottle_amount_Uppercase, first_component,
             pre_bottle_amount, second_component,
             third_component,
             post_bottle_amount, forth_component);


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
