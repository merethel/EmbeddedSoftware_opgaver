#include <stdio.h>
int main(void){
    
    char c;
    FILE *fp;

    fp = fopen("C:/Users/meret/Desktop/Softwareingeniør/4. semester/ESW/opgaver/txt fil/file.txt", "r");
    if (fp == NULL) { // check if the file exist. 
        printf("Error opening file\n");
        return 1;
    }

    while (fscanf(fp, "%c", &c) != EOF) { //reads character until (EOF) end of file
        printf("%c", c);
    }

}