#include "difference_of_squares.h"
#include <math.h>

int square_of_sum(const int num) {
    int result = 0;
    for (int i = 1; i <= num; ++i) {
        result += i;
    }

    return pow(result, 2);
}

int sum_of_squares(const int num) {
    int result = 0;
    for (int i = 1; i <= num; ++i) {
        result += pow(i, 2);
    }

    return result;
}

int difference_of_squares(const int num) {
    return square_of_sum(num) - sum_of_squares(num);
}
