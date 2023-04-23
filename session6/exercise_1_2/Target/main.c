#include "person.h"
#include <string.h>

int main(void)
{

    address_t myAddress;
    strcpy(myAddress.street, "Home street");
    myAddress.house_num = 12;
    myAddress.post_code = 8660;
    
    address_t workAddress;
    strcpy(workAddress.street, "Work Street");
    workAddress.house_num = 2;
    workAddress.post_code = 8210;

    person_t me;
    strcpy(me.name, "Laurits Ivar");
    me.age=31;
    me.homeAddress=myAddress;
    me.workAddress=&workAddress;

    person_print_info(&me);
}
