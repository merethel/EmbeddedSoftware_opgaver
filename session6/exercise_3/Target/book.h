#pragma once
#include "author.h"

typedef struct book
{
    char title[30];
    char isbn[30];
    author_t author;
} book_t;
