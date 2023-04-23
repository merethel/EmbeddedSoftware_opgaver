#include <stdio.h>
/*
1.1	Read characters and numbers from the terminal and print out 
the character and the number to the terminal. 
*/

int main(void){
    char a;
    int number, length, width;
    
    printf("Insert 3 numbers and a character: \n"); 
    scanf(" %d", &number);
    scanf(" %d", &length);
    scanf(" %d", &width);
    scanf(" %c", &a); 

    printf("Value %d\n", number);
    printf("Value %d\n", length);
    printf("Value %d\n", width);
    printf("Value %c\n", a);

}