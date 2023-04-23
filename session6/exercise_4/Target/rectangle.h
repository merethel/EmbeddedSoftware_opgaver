#pragma once

typedef struct
{
    double width;
    double height;
} * rectangle_t;

typedef enum
{
    OK,
    ERROR_WIDTH_IS_NEGATIVE,
    ERROR_HEIGHT_IS_NEGATIVE
}error_code;

rectangle_t rectangle_create(double width, double height);
error_code rectangle_setWidth(rectangle_t rectangle, double);
error_code rectangle_setHeight(rectangle_t rectangle, double);
double rectangle_getWidth(rectangle_t rectangle);
double rectangle_getHeight(rectangle_t rectangle);
double rectangle_getArea(rectangle_t rectangle);
void rectangle_promptUserToGiveDimensions();
void rectangle_printInfo(rectangle_t rectangle);
void rectangle_destroy(rectangle_t rectangle);