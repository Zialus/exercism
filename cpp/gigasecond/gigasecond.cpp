#include "gigasecond.h"

namespace gigasecond {

const int GIGASECOND = std::pow(10, 9);

ptime advance(ptime original) {
    ptime result = original + seconds(GIGASECOND);
    return result;
}

} // namespace gigasecond
