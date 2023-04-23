#include <stdio.h>
#include <stdlib.h>

/*
5	Malloc() and free()
Write a program that prompts the user to enter the size of an array, and then allocates 
memory for an array of that size using malloc. 
The program should then prompt the user to enter integer values for each element of the array, 
and store these values in the array. 
Finally, the program should print the sum of all the values in the array. 
*/

int main(void){
    int length, *a, sum = 0;
    printf("Type in array length: \n");
    scanf("%d", &length); //& bruges til at indikere adressen på variablen

    // Allocate memory for the array using malloc
    a = (int*) malloc(length * sizeof(int));

   // Prompt the user to enter integer values for each element of the array
    for (int i = 0; i < length; i++) {
        printf("Enter a value for element %d: ", i);
        scanf(" %d", &a[i]);
    }

    //Sum
    for (int i = 0; i < length; i++) {
        sum = a[i]+sum;
    }
    printf("The sum of the array is: %d\n", sum);

    // Free the memory allocated by malloc
    free(a);

    return 0;
}