#include <stdio.h>

/*3.2	Find the remainder of a division by using the modulo operator. 
        Try it both using integer and float. 
*/
int main(void){

    int a;
    float b;
    a = 7%3;
    b = 7%3; /*pointen med opgaven er at remainder altid er et heltal, så man kan ikke somsådan bruge float
                i denne sammenhæng */
    
    printf("Int: %d\n", a);
    printf("Float: %f\n", b);
}