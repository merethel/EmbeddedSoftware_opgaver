#include "rectangle.h"
#include <stdio.h>

static double height;
static double width;

void rectangle_setWidth(double w){
    width = w;
}

void rectangle_setHeight(double h){
    height = h;
}

double rectangle_getWidth(){
    return width;
}

double rectangle_getHeight(){
    return height;
}

double rectangle_getArea(){
    return width*height;
}

void rectangle_promptUserToGiveDimensions(){
    printf("Write width and height of the rectangle: \n");
    scanf("%lf %lf", &width, &height);
    rectangle_printInfo();
}

void rectangle_printInfo(){
    printf("Width: %f \nHeight: %f \nArea: %f", width, height, rectangle_getArea());
}