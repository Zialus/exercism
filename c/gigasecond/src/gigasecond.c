#include "gigasecond.h"
#include <stdio.h>
#include <math.h>

#define GIGASECOND pow(10,9)

time_t gigasecond_after(time_t date){
    time_t new_date = date + GIGASECOND;
    //printf("%s", ctime(&new_date));
    return new_date;
}
