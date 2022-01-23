#include "string.h"
#include "stdio.h"

int my_strcmp(char *str1, char *str2){
    signed int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] < str2[i]) 
        {
            return -1;
        } else if (str1[i] > str2[i])
        {
            return 1;
        }
        i++;
    }

    //CASE : len(str1) != len(str2)
    if (str1[i] == '\0') {
        return -1;
    } else if(str2[i] == '\0') {
        return 1;
    } else {
        return 0;
    }

}