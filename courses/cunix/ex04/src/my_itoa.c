#include "stdlib.h"
#include "string.h"

char* my_itoa(int nmb) {
    char temp[32];
    int i = 0;
    int check = 0;
    if (nmb < 0) {
        nmb = -nmb;
        check = 1;
    }
    do 
    {
        temp[i] = nmb % 10 + '0';
        nmb /= 10;
        i++;
    } while (nmb != 0);
    int size = i+check+1;
    char *str = malloc(size);

    if (check) {
        str[0] = '-';
    }
    //reverse loop
    for (int j= i-1; j>= 0; j--) 
    {
        str[i-j-1 + check] = temp[j];
    }
    str[i+check] = '\0';
    return str;
}