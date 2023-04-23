#pragma once
typedef struct
{
    char street[30];
    int house_num;
    int post_code;
} address_t;

void address_print_info(address_t * address);
