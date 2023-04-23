#include <stdio.h>
#include "power.h"
#include "multiswap.h"

/*4.1	Implement a program with a main function and two other functions:
        
        int power(int x, int y) should return “x to the power of y”, for instance power(2,3)=8
        
        void multiSwap(int x, int y, int z) should take three integer-parameters x, y and z. 
        After a call to multiSwap, x should be equal to the old y, y should be equal to the 
        old z and z should be equal to the old x. The return type of multiSwap should be void. 
        */

int main(void){

    int a = 2;
    int b = 3;
    int c = 4;

    printf("%d",power(a,b));

    //værdier før swap
    printf("Before swap: a=%d and b=%d and c=%d\n", a, b, c);

    multiSwap(&a,&b,&c);  /*Vi skal swappe addresserne, hvor vi i swap funktionen bruger pointers, 
                       til at peje på værdierne på adresserne. 
                       På den måde bytter vi ikke rundt på adresserne for hver data type, men kun
                       på værdierne de holder*/

    //Værdier efter swap
    printf("After swap: a=%d and b=%d and c=%d\n", a, b, c);
}