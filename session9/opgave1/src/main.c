#include <avr/io.h>
#include <avr/delay.h>

/*

Connect a the LEDs to PA0 and PA1, and the buttons to PA2 and PA3.
Write a program that implements the following functionality:
While pressing the button placed at PA2 the LED placed at PA0 should turn on.
While pressing the button placed at PA3 the LED placed at PA1 should turn on.

*/

int main()
{
  // først skal vi clear bit 2 og bit 3
  DDRA &= ~(1 << PA2) & ~(1 << PA3);

  // vi konfigurerer til output for PA0 og PA1
  DDRA |= (1 << PA0) | (1 << PA1);

  // sørg for at enable pull-up resistor (indvendige tænd sluk ting )
  PORTA |= (1 << PA2);
  PORTA |= (1 << PA3);

  /* for at tænde led'en i PA0
  PORTA |= (1 << PA0);

  for at slukke led'en i PA0
  PORTA &= ~(1 << PA0);*/

  while (1)
  {

    // først PA2 switch
    if (PINA & (1 << PA2))
    {
      PORTA |= (1 << PA0);
    }
    else
    {
      PORTA &= ~(1 << PA0);
    }

    // så PA3 switch
    if (PINA & (1 << PA3))
    {
      PORTA |= (1 << PA1);
    }
    else
    {
      PORTA &= ~(1 << PA1);
    }
  }
}