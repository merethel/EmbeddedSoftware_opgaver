#include "person.h"
#include <string.h>

int main(void)
{
    address_t workAddress;
    strcpy(workAddress.street, "Work Street");
    workAddress.house_num = 2;
    workAddress.post_code = 8210;


    person_t me = person_create("Laurist Ivar", 31, "Home street", 12, 8660, &workAddress);

    person_print_info(&me);
}
