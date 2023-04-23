#include "person.h"
#include <stdio.h>

void person_print_info(person_t * person){
    printf("Name: %s\nAge: %d\nHome address: \n", person->name, person->age);
    address_print_info(&(person->homeAddress));
    printf("Work address: \n");
    address_print_info(person->workAddress);
    printf("\n");
}