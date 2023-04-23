#include <stdio.h>
#include "rectangle.h"

int main(){
    rectangle_t myRect;
    rectangle_promptUserToGiveDimensions(&myRect);
    rectangle_printInfo(&myRect);
}