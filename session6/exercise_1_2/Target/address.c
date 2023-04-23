#include "address.h"
#include <stdio.h>

void address_print_info(address_t * self){
    printf("Street: %s\nHouse number: %d\nPost-code: %d\n", self->street, self->house_num, self->post_code);
}