#include "stdlib.h"
#include "stdio.h"

int my_atoi(const char *nptr){
    int sign = 1;
    int i = 0;
    int number = 0;
    int power = 10;

    if (nptr[0] == '-') {
        sign = -1;
        i++;
    }
    
    while (nptr[i] >= '0' && nptr[i] <='9' && nptr[i] != '\0' ) {
        number = (number * power) + (nptr[i] - '0');
        i++;
    }
    return number * sign;
    
}