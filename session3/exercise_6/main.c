/*
6	my_strcmp, my_strlen, my_strcpy, my_strdup

Look at the standard library functions strlen, strcmp, strcpy, strdup your functions should 
have the same signatures!! (https://cplusplus.com/reference/cstring/  
and https://en.cppreference.com/w/c/experimental/dynamic/strdup )
 
1.	Implement my_strlen first.
2.	Implement a function my_strcmp. You are not allowed to use built-in library functions to implement this function.
3.	Make these tests of the function, using constant strings as parameters:
Compare “Hello World” with “Hello World”
Compare “Hello World” with the empty string.
Compare two empty strings.
Compare “Hello World” with “Hello, world”
4.	Implement your own versions of the functions strcpy, and strdup (be inspired by Kernighan and Ritchie). You are not allowed to use built-in library functions to implement these functions.
5.	Make some basic tests of the functions.

*/

#include <stdio.h>
#include <string.h>

int main (void)
{

//tester my_strlen
  char szInput[256];
  printf ("Enter a sentence: ");
  gets (szInput);
  printf ("The sentence entered is %u characters long.\n",(unsigned)my_strlen(szInput));
  return 0;

  //tester my_strcmp
  //TODO
}