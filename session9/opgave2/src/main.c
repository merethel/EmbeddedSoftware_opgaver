#include <avr/io.h>
#include <avr/delay.h>

/*

Connect 2 LEDs to PA6 and PA7.
One LED has its long leg in PA6 and short leg in PA7.
The other LED has its long leg in PA7 and short leg in PA6.
Write code that:
1.	Turns On LED1
2.	Wait for 1 sec.
3.	Turns on LED2, (and thereby turning off LED1).
4.	Wait for 1 sec
5.	Turns off both LED’s
6.	Wait for 1 sec.
7.	Repeats


*/

int main()
{
  // vi konfigurerer til output for PA6 og PA7
  DDRA |= (1 << PA6) | (1 << PA7);

  /* for at tænde led'en i PA0
  PORTA |= (1 << PA0);

  for at slukke led'en i PA0
  PORTA &= ~(1 << PA0);*/

  while (1)
  {
    PORTA |= (1 << PA6);
    PORTA &= ~(1 << PA7);

    _delay_ms(1000);

    PORTA |= (1 << PA7);
    PORTA &= ~(1 << PA6);

    _delay_ms(1000);
    PORTA &= ~(1 << PA7);
    PORTA &= ~(1 << PA6);

    _delay_ms(1000);
  }
}