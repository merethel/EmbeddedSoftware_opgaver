#pragma once
#include "address.h"

typedef struct
{
    char name[30];
    int age;
    address_t homeAddress;
    address_t * workAddress;
} person_t;

void person_print_info(person_t * person);
