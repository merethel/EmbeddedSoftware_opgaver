#include <avr/io.h>
#include <avr/delay.h>

int main(){
  PORTA=0b00000001;
  DDRA = 0b00000010;

  while (1)
  {
    if(PINA & 0b00000001){
      PORTA=0b00000011;
    }
    else{
      PORTA=0b00000001;  
    }
  }
}