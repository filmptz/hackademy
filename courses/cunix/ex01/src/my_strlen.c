#include "string.h"

unsigned int my_strlen(char *str) {
    signed int i = 0;
    signed int count = 0;
    while(str[i] != '\0'){
        count++;
        i++;
    }
    return count;
}