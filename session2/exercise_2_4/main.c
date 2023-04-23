#include <stdio.h>
int main(void){
    
    char name[] = "";
    int age;
    FILE *fp;

    printf("Enter your name: ");
    scanf("%s", &name);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Your name is %s and your age is %d", name, age);

    fp = fopen("C:/Users/meret/Desktop/Softwareingeniør/4. semester/ESW/opgaver/txt fil/file.txt", "w");
    //stien virker ikke pga. ø ............. :))))

    fprintf(fp, "Your name is %s and your age is %d", name, age);

    fclose(fp);
}