#include <avr/io.h>
#include <avr/delay.h>
#include "led.h"

/*

Connect LEDs to PA0, PA1, PA2 and PA3. Connect buttons or switches to PA4, PA5, PA6 and PA7.
Write drivers for this setup.
HINTS:
A led driver should be implemented in led.c and led.h.

*/

int main()
{
  Led_init();
  _delay_ms(1000);
  Led_turnOn(1);
  _delay_ms(1000);
  Led_turnOn(2);
  _delay_ms(1000);
  Led_turnOn(3);
  _delay_ms(1000);
    Led_turnOn(4);
  _delay_ms(1000);


  Led_turnOff(1);
  _delay_ms(1000);
  Led_turnOff(2);
  _delay_ms(1000);
  Led_turnOff(3);
  _delay_ms(1000);
  Led_turnOff(4);
}