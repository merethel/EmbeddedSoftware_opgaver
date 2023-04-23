#include <avr/io.h>
#include <avr/delay.h>

int main()
{
  PORTA = 0b00000001; //hvilken port skal lyttes på
  DDRA = 0b00000010; //registrer inpput/output porte (her er PA1 output, og resten er input)

  while (1)
  {
    if (PINA & 0b00000001) //hvis PA0 er tændt (ikke trykket ned (switchen)), så skal PA1 lyse
    {
      PORTA = 0b00000011; //Her er altså både PA0 og PA1 tændt
    }
    else /*blink SOS i morsekode*/
    {
      for (int i = 0; i < 3; i++)
      {
        /* lang */
        PORTA = 0b00000001; //PA1 er slukket
        _delay_ms(200);
        PORTA = 0b00000011; //PA1 er tændt
        _delay_ms(1000);
      }

      _delay_ms(500);

      for (int i = 0; i < 3; i++)
      {
        /* kort */
        PORTA = 0b00000001;
        _delay_ms(200);
        PORTA = 0b00000011;
        _delay_ms(200);
      }

      _delay_ms(500);

      for (int i = 0; i < 3; i++)
      {
        /* lang */
        PORTA = 0b00000001;
        _delay_ms(200);
        PORTA = 0b00000011;
        _delay_ms(1000);
      }
    }
  }
}