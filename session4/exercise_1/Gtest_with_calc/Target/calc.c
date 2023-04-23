#include "calc.h"


//change the functions so the tests passes. 
double calc_add(double a, double b){
    return a+b;
}

double calc_subtract(double a, double b){
    return a-b;
}

double calc_multiply(double a, double b){
    return a*b;
}

double calc_divide(double a, double b){
    return a/b;
}

double calc_squareroot(double a){
    return sqrt(a);
}

double calc_power(double a, double b){
    return pow(a,b);
}

double calc_factorial(double a){
    double result = 1;

    for (double i = 1; i <= a; i++)
    {
        result = result * i;
    }

    return result;   
}