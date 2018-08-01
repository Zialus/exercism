#include "space_age.h"

#define SECONDS_TO_YEARS(int) (int / 60 / 60 / 24 / 365.25)

double convert_planet_age(const enum planets planet, const long age) {
    double answer;
    const double earth_years = SECONDS_TO_YEARS(age);

    switch (planet) {
        case EARTH:
            answer = (earth_years / 1);
            break;
        case MERCURY:
            answer = (earth_years / 0.2408467);
            break;
        case VENUS:
            answer = (earth_years / 0.61519726);
            break;
        case MARS:
            answer = (earth_years / 1.8808158);
            break;
        case JUPITER:
            answer = (earth_years / 11.862615);
            break;
        case SATURN:
            answer = (earth_years / 29.447498);
            break;
        case URANUS:
            answer = (earth_years / 84.016846);
            break;
        case NEPTUNE:
            answer = (earth_years / 164.79132);
            break;
    }

    return answer;
}
