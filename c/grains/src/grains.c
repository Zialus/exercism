#include "grains.h"
#include <math.h>

unsigned long long square(int n) {
    if (n > BOARD_SIZE) {
        return 0;
    }
    return powl(2, n - 1);
}

unsigned long long total() {
    return powl(2, BOARD_SIZE) - 1;
}
