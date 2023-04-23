#include <stdio.h>
/*
1.2	Create a program where the user writes the length and breadth of a rectangle 
and the program prints area of the rectangle. 
*/

int main(void){
    int length, width;
    
    printf("Insert length and width: \n"); 
    scanf(" %d", &length);
    scanf(" %d", &width);

    printf("Area of rectangle is %d\n", length*width);
}