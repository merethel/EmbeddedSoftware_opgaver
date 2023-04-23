/*
4	More about strings

This exercise demonstrates how to manipulate strings (character arrays); compute length of a string, 
as well as working with loops. Based on the below skeleton, complete the program to do the following:
1.	Convert each line being input to upper case and print it.
2.	Compute the length of each line being input and print the length.
3.	Combine the above two.

4.	Implement the function my_to_upper and test it on a simple string such as “Hello World!”
5.	Implement the main loop to print the line length and the upper-cased version of the input lines – use the file from above as your input file.

*/
#include <stdio.h>
#include "my_string_func.h"
#define MAX_LENGTH 1000
int main()
{
  char line[MAX_LENGTH];
  char upper[MAX_LENGTH];
  int line_length;
  /* Use a while loop to read input lines as long as there are any.
  For each input line, print the length of the line as well as
  the upper case version of the line
  NOTE You are NOT allowed to use the standard toupper(...)
  function in string.h
  */
  while (read_line(line)) //i implementeringen læser den inputs, så den læser indtil man laver new line
  {
    printf("String is: %s\n", line);

    line_length = my_length(line); //Sætter linjelængden udfra funktionen
    my_to_upper(line,upper); //sætter upper array'et til line arrayet gjort til caps

    printf("Length: %d\t%s\n", line_length, upper);
  }
  return 0;
}
