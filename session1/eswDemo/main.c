#include <stdio.h>
#include "calc.h"
int main(void){
    setbuf(stdout,NULL);
    printf("I love math:  3+4 =  %d ! \n", calc_add(3,4));
    printf("I love math:  4-2 =  %d ! \n", calc_sub(4,2));
    printf("I love math:  2*5 =  %d ! \n", calc_mul(2,5));
return 0;
}
