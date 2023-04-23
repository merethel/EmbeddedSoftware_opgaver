#include <avr/io.h>
#include <avr/delay.h>

int main(){
  DDRA=0b00000010;
  PORTA=0b00000010;


  while (1)
  {
    PORTA=0b00000010;
    _delay_ms(1000);
    PORTA=0b00000000;
    _delay_ms(1000);
  }
}