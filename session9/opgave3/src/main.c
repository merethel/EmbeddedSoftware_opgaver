#include <avr/io.h>
#include <avr/delay.h>
#include "led.h"
#include "buttons.h"

/*

Connect LEDs to PA0, PA1, PA2 and PA3. Connect buttons or switches to PA4, PA5, PA6 and PA7.
Write drivers for this setup.
HINTS:
A led driver should be implemented in led.c and led.h.

*/

int main()
{
  Led_init();

  Button_init();

  Led_turnOff(2);
  while (1)
  {
    if (Button_pressed(6))
    {
      Led_toggle(2);
      _delay_ms(1000);
    }
  }
}