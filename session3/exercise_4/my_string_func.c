#include <stdio.h>
#include "my_string_func.h"
/* read_line: read a line into s, return length */

int my_length(char* text){
/*
Implement this function so it returns the number of characters it is. 
*/
  int i = 0;
  while (text[i]!='\0')
    {
      i++;
    }
  return ++i;
}

void my_to_upper(char *str_in, char *str_out)
{
  /* You must implement your own version of toupper using the two strings
  str_in and str_out.
  Loop over the str_in (as long as it "contains" something).
  Look at the "current" character and check if its a lowercase letter.
  If it is, convert it to the upper case version and add that to the
  str_out character array
  */
 for (int i = 0; i < my_length(str_in); i++)
  {
    if (str_in[i]>='a' && str_in[i]<='z') //tjekker om vi arbejder med lowercase letter
    {
      str_out[i]=str_in[i]-32;
    }/*for at gøre værdierne store, så skal vi sige -32, da det passer med at små 
    bogstaver i ascii tabellen bliver til store bogstaver i ascii*/

    else str_out[i]=str_in[i]; //hvis de allerede store, så sætter vi bare lig med
  }
}


int read_line(char s[])
{
  int c = 0;
  int i = 0;
  int done = 0;
  do
  {
    c = getchar(); //læser fra konsollen
    if (c == EOF || c == '\n') //bliver ved med at læse, indtil vi rammer new line 
    {
      done = 1;
    }
    else
    {
      s[i++] = c;
    }
  } while (!done);
  s[i] = '\0';
  return i;
}
