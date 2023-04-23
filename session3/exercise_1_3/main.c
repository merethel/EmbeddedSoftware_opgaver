#include <stdio.h>
/*
1.3	Read a string. Try out the code:
*/

int main(void){
    char text[20];
    printf("Write a text: \n");
    scanf("%s[^\n]",text);

    printf("String is: %s\n", text);
}