#include <stdio.h>
int main(void){
    
    char name[] = "";
    int age;

    printf("Enter your name: ");
    scanf("%s", &name);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Your name is %s and your age is %i", name, age);

}