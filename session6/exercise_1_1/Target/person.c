#include "person.h"
#include <stdio.h>

void person_print_info(person_t * person){
    printf("Name: %s\nAge: %d\nAddress: ", person->name, person->age);
    address_print_info(&(person->homeAddress));
}