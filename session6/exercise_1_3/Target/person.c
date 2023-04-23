#include "person.h"
#include <stdio.h>

person_t person_create(char * name, int age, char * street, int houseNum, int post_code, address_t *workaddress){
    person_t person;

    strcpy(person.name, name);
    person.age = age;
    strcpy(person.homeAddress.street, street);
    person.homeAddress.house_num = houseNum;
    person.homeAddress.post_code = post_code;
    person.workAddress = workaddress;

    return person;
}

void person_print_info(person_t * person){
    printf("Name: %s\nAge: %d\nHome address: \n", person->name, person->age);
    address_print_info(&(person->homeAddress));
    printf("Work address: \n");
    address_print_info(person->workAddress);
    printf("\n");
}