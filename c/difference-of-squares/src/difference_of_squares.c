#include "difference_of_squares.h"

int square_of_sum(const int num) {
    // https://en.wikipedia.org/wiki/Arithmetic_progression#Sum
    int tmp = (num * (num + 1)) / 2;
    return tmp * tmp;
}

int sum_of_squares(const int num) {
    // https://en.wikipedia.org/wiki/Square_pyramidal_number#Formula
    return (num * (num + 1) * (2 * num + 1)) / 6;
}

int difference_of_squares(const int num) {
    return square_of_sum(num) - sum_of_squares(num);
}
