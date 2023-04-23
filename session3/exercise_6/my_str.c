#include <stdio.h>
#include "my_str.h"

int my_strlen(const char* str){
    int i = 0;

    while (str[i]!='\0')
    {
        i++;
    }
    return i;
}