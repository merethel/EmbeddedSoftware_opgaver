typedef struct{
    char *item; //pointer til en char, eller en string af characters
                    //eksempel; hvis man har en string, så pejer den første char på den næste, osv.
    struct LinkedList_t *next; //det element som vores item skal peje på
                            //det er altsp en pointer til det næste element
}LinkedList_t;

LinkedList_t* linkedList_create();
void linkedList_destroy(LinkedList_t*);
void linkedList_append(LinkedList_t*, int);
void linkedList_print(LinkedList_t*);

