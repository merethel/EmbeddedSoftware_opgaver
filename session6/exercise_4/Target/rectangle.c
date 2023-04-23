#include "rectangle.h"
#include <stdio.h>
#include <stdlib.h>

rectangle_t rectangle_create(double width, double height){
    rectangle_t rect;
    rect = malloc(sizeof(*rect)); //Why is rect derefferenced?
    rect->height=height;
    rect->width=width;
    return rect;
}


error_code rectangle_setWidth(rectangle_t self, double width){
    if (width<0)
    {
        printf("Negative number not allowed\n");
        return ERROR_WIDTH_IS_NEGATIVE;
    }
    
    self->width = width;
    return OK;
}

error_code rectangle_setHeight(rectangle_t self, double height){
    if (height<0)
    {
        printf("Negative number not allowed\n");
        return ERROR_HEIGHT_IS_NEGATIVE;
    }
    self->height = height;
    return OK;
}

double rectangle_getWidth(rectangle_t self){
    return self->width;
}

double rectangle_getHeight(rectangle_t self){
    return self->height;
}

double rectangle_getArea(rectangle_t self){
    return self->height * self->width;
}

void rectangle_promptUserToGiveDimensions(){
    double a;
    double b;
    printf("Write width and height of the rectangle: \n");
    scanf("%lf %lf", &a, &b);
    rectangle_t rect = rectangle_create(a, b);
    rectangle_printInfo(rect);
    rectangle_destroy(rect);
}

void rectangle_printInfo(rectangle_t self){
    printf("Width: %f \nHeight: %f \nArea: %f\n", self->width, self->height, rectangle_getArea(self));
}

void rectangle_destroy(rectangle_t self){
    if (self != NULL)
    {
        free(self);
    }    
}