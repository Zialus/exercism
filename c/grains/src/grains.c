#include "grains.h"
#include <math.h>

unsigned long long square(int n) {
    if (n < 1 || n > 64) {
        return 0; // only operate whithin the chess boards(and data type) limits.
    }
    return (1ul << (n - 1)); // shifting bits to the left is the same as multiplying by 2.
}

unsigned long long total() {
    // (2**64)-1 is the largest number that can be represented by an unsigned 64-bits int,
    // since this is an unsigned type, -1 works the same as (LARGEST_NUM_REPRESENTABLE-1).
    return -1;
}
