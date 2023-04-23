#include <stdio.h>
#include "rectangle.h"
/*
Create a rectangle ”class”
Use a struct to define the type rectangle_t
The class has the following UML diagram: 

Create a bunch of tests, to test all the methods. 

*/

int main(){
    rectangle_t myRectangle;
    set_dimensions(&myRectangle, 2, 2);
    printf("Area: %d \n", get_area(myRectangle));
    printf("Perimeter: %d \n", get_perimeter(myRectangle));
    print_rectangle_info(myRectangle);
}