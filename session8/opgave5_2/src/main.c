#include "uart.h"
#include <stdio.h>

int main()
{
  uartInit(9600);
  char counter[10];
  int count = 0;

  while (1)
  {
    sprintf(counter, "%d\n", count++);
    uartSend(counter);
    _delay_ms(1000);
  }
  return 0;
}
