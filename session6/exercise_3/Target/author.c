#include "author.h"
#include <stdio.h>


author_t author_create(char* name, char* email){
    author_t author;

    strcpy(author.name, name);
    strcpy(author.email, email);

    return author;
}

char* author_getName(author_t * author){
    return author->name;
}

char* author_getEmail(author_t * author){
    return author->email;
}

void author_setName(author_t * author, char* name){
}

void author_setEmail(author_t * author, char* email){
    
}