#pragma once
typedef struct
{
    char name[30];
    char email[30];
} author_t;

author_t author_create(char* name, char* email);
char* author_getName(author_t * author);
char* author_getEmail(author_t * author);
void author_setName(author_t * author, char* name);
void author_setEmail(author_t * author, char* email);
