#include <stdio.h>

/*3.1	Implement a small program where you divide 7 with 3 and print the result. Do it for integers, floats and doubles.  
Hint: to insert a float in a string %f should be used instead of %d
*/
int main(void){

    int a;
    float b;
    double c;

    a = 7/3;
    b = (float) 7/3;
    c = (double) 7/3;

    printf("Int: %d\n", a);
    printf("Float: %f\n", b);
    printf("Double: %f\n", c);
}