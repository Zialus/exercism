#include "binary_search.h"
#include <stdlib.h>
#include <stdio.h>

const int* binary_search(const int num,const int arr[], const int length) {
    const int* answer = NULL;

    int start = 0;
    int end = length - 1;

    while (answer == NULL && start <= end) {
        int middle = (end + start) / 2;
        // printf("%d\n", middle);
        if (num == arr[middle]) {
            answer = &arr[middle];
        } else if (num < arr[middle]) {
            end = middle - 1;
        } else if (num > arr[middle]) {
            start = middle + 1;
        }
    }

    return answer;
}
