#include <avr/io.h>
#include <avr/delay.h>

int main(){
  DDRB=0b10000000;
  PORTB=0b10000000;

  while (1)
  {
    PORTB=0b10000000;
    _delay_ms(1000);
    PORTB=0b00000000;
    _delay_ms(1000);
  }
}