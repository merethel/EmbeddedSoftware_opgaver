#include "uart.h"
#include <stdio.h>

int main()
{
  uartInit(9600);
  char counter[10];
  int count = 0;
  PORTA = 0b00000001;
  DDRA = 0b00000010;

  while (1)
  {
    char *s = uartReceive();
    count = atoi(s);

    for (int i = 0; i < count; i++)
    {
      PORTA = 0b00000010;
      _delay_ms(200);
      PORTA = 0b00000000;
      _delay_ms(200);
    }
  }
}
