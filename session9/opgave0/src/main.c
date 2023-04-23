#include <avr/io.h>
#include <avr/delay.h>

/*Two switches is connected to PA3 and PA4. Two LEDS are connected to PA0 and PA1. 
You dont know what th rest of PortA is used for... 
Initialize porta. 
*/

int main()
{
  //først skal vi clear bit 3 og bit 4
  DDRA&=~(1<<PA3)&~(1<<PA4);

  //vi konfigurerer til output for PA0 og PA1
  DDRA|=(1<<PA0)|(1<<PA1);

  //for at tænde led'en i PA0
  PORTA|=(1<<PA0); 

  //for at slukke led'en i PA0
  PORTA|=~(1<<PA0);

  //De to ovenfor gælder hvis de er aktiv høj
  /*Hvis der er tale om aktiv lav, skal man tænde og slukke ved at gøre det omvendt, 
  så sluk bliver   PORTA|=(1<<PA0); og tænd bliver   PORTA|=~(1<<PA0);*/

  //KNAPPEN VI BRUGER ER AKTIV LAV

}