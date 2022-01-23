#include "string.h"
#include "stdio.h"

char *my_strcpy(char *dest, const char *src){
    signed int i = 0;
    while(src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    return dest;
}