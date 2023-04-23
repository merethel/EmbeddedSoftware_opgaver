#include "rectangle.h"
#include <stdio.h>

void set_dimensions(rectangle_t * self, int width, int height){
    self->width = width;
    self->height = height;
}

int get_area(rectangle_t self){
    return self.height*self.width;
}

int get_perimeter(rectangle_t self){
    return (2*self.height)+(2*self.width);
}

void print_rectangle_info(rectangle_t self){
    printf("Height: %d \n Width: %d", self.height, self.width);
}