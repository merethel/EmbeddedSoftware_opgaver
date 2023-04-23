#pragma once
#include "address.h"

typedef struct
{
    char name[30];
    int age;
    address_t homeAddress;
    address_t * workAddress;
} person_t;

person_t person_create(char * name, int age, char * street, int houseNum, int post_code, address_t *workaddress);
void person_print_info(person_t * person);
