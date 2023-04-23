#include "person.h"
#include <string.h>

int main(void)
{

    address_t myAddress;
    strcpy(myAddress.street, "Anes Bakke");
    myAddress.house_num = 12;
    myAddress.post_code = 8660;

    person_t me;
    strcpy(me.name, "Laurits Ivar");
    me.age=31;
    me.homeAddress=myAddress;

    person_print_info(&me);
}
