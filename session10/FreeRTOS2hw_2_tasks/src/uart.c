

#include <avr/io.h>

void uartInit(int baudrate) {
  unsigned int ubrr = ((F_CPU / (16UL * baudrate)) - 1);
// https://ww1.microchip.com/downloads/en/devicedoc/atmel-2549-8-bit-avr-microcontroller-atmega640-1280-1281-2560-2561_datasheet.pdf
  // Set baud rate Page 203
  UBRR0H = (unsigned char)(ubrr >> 8);
  UBRR0L = (unsigned char)ubrr;

  // Enable receiver and transmitter. Page 220
  UCSR0B = (1 << RXEN0) | (1 << TXEN0);

  // Set frame format: 8 data bits, 1 stop bit, no parity  page 221  
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}


void USART_sendString(char* str)
{
	
    // Send a null-terminated string via USART
    while(*str != '\0')
    {
        // Wait for the transmitter buffer to be empty
        while(!(UCSR0A & _BV(UDRE0))); // UCSRnA – USART Control and Status Register A      UDREn: USART Data Register Empty   ca side 115  https://ww1.microchip.com/downloads/en/devicedoc/atmel-2549-8-bit-avr-microcontroller-atmega640-1280-1281-2560-2561_datasheet.pdf
        UDR0 = *str;
        str++;
    }
}


int getLength(char * str){
    int i=0;
    while(str[i]) i++;
    return i;
}

void sendPicture(){
    
    USART_sendString("                                  _______\n"
"                           _,,ad8888888888bba,_\n"
"                        ,ad88888I888888888888888ba,\n"
"                      ,88888888I88888888888888888888a,\n"
"                    ,d888888888I8888888888888888888888b,\n"
"                   d88888PP\"\"\"\" \"\"YY88888888888888888888b,\n"
"                 ,d88\"'__,,--------,,,,.;ZZZY8888888888888,\n"
"                ,8IIl'\"                ;;l\"ZZZIII8888888888,\n"
"               ,I88l;'                  ;lZZZZZ888III8888888,\n"
"             ,II88Zl;.                  ;llZZZZZ888888I888888,\n"
"            ,II888Zl;.                .;;;;;lllZZZ888888I8888b\n"
"           ,II8888Z;;                 `;;;;;''llZZ8888888I8888,\n"
"           II88888Z;'                        .;lZZZ8888888I888b\n"
"           II88888Z; _,aaa,      .,aaaaa,__.l;llZZZ88888888I888\n"
"           II88888IZZZZZZZZZ,  .ZZZZZZZZZZZZZZ;llZZ88888888I888,\n"
"           II88888IZZ<'(@@>Z|  |ZZZ<'(@@>ZZZZ;;llZZ888888888I88I\n"
"          ,II88888;   `\"\"\" ;|  |ZZ; `\"\"\"     ;;llZ8888888888I888\n"
"          II888888l            `;;          .;llZZ8888888888I888,\n"
"         ,II888888Z;           ;;;        .;;llZZZ8888888888I888I\n"
"         III888888Zl;    ..,   `;;       ,;;lllZZZ88888888888I888\n"
"         II88888888Z;;...;(_    _)      ,;;;llZZZZ88888888888I888,\n"
"         II88888888Zl;;;;;' `--'Z;.   .,;;;;llZZZZ88888888888I888b\n"
"         ]I888888888Z;;;;'   \";llllll;..;;;lllZZZZ88888888888I8888,\n"
"         II888888888Zl.;;\"Y88bd888P\";;,..;lllZZZZZ88888888888I8888I\n"
"         II8888888888Zl;.; `\"PPP\";;;,..;lllZZZZZZZ88888888888I88888\n"
"         II888888888888Zl;;. `;;;l;;;;lllZZZZZZZZW88888888888I88888\n"
"         `II8888888888888Zl;.    ,;;lllZZZZZZZZWMZ88888888888I88888\n"
"          II8888888888888888ZbaalllZZZZZZZZZWWMZZZ8888888888I888888,\n"
"          `II88888888888888888b\"WWZZZZZWWWMMZZZZZZI888888888I888888b\n"
"           `II88888888888888888;ZZMMMMMMZZZZZZZZllI888888888I8888888\n"
"            `II8888888888888888 `;lZZZZZZZZZZZlllll888888888I8888888,\n"
"             II8888888888888888, `;lllZZZZllllll;;.Y88888888I8888888b,\n"
"            ,II8888888888888888b   .;;lllllll;;;.;..88888888I88888888b,\n"
"            II888888888888888PZI;.  .`;;;.;;;..; ...88888888I8888888888,\n"
"            II888888888888PZ;;';;.   ;. .;.  .;. .. Y8888888I88888888888b,\n"
"           ,II888888888PZ;;'                        `8888888I8888888888888b,\n"
"           II888888888'                              888888I8888888888888888b\n"
"          ,II888888888                              ,888888I88888888888888888\n"
"         ,d88888888888                              d888888I8888888888ZZZZZZZ\n"
"      ,ad888888888888I                              8888888I8888ZZZZZZZZZZZZZ\n"
"    ,d888888888888888'                              888888IZZZZZZZZZZZZZZZZZZ\n"
"  ,d888888888888P'8P'                               Y888ZZZZZZZZZZZZZZZZZZZZZ\n"
" ,8888888888888,  \"                                 ,ZZZZZZZZZZZZZZZZZZZZZZZZ\n"
"d888888888888888,                                ,ZZZZZZZZZZZZZZZZZZZZZZZZZZZ\n"
"888888888888888888a,      _                    ,ZZZZZZZZZZZZZZZZZZZZ888888888\n"
"888888888888888888888ba,_d'                  ,ZZZZZZZZZZZZZZZZZ88888888888888\n"
"8888888888888888888888888888bbbaaa,,,______,ZZZZZZZZZZZZZZZ888888888888888888\n"
"88888888888888888888888888888888888888888ZZZZZZZZZZZZZZZ888888888888888888888\n"
"8888888888888888888888888888888888888888ZZZZZZZZZZZZZZ88888888888888888888888\n"
"888888888888888888888888888888888888888ZZZZZZZZZZZZZZ888888888888888888888888\n"
"8888888888888888888888888888888888888ZZZZZZZZZZZZZZ88888888888888888888888888\n"
"88888888888888888888888888888888888ZZZZZZZZZZZZZZ8888888888888888888888888888\n"
"8888888888888888888888888888888888ZZZZZZZZZZZZZZ88888888888888888 Normand  88\n"
"88888888888888888888888888888888ZZZZZZZZZZZZZZ8888888888888888888 Veilleux 88\n"
"8888888888888888888888888888888ZZZZZZZZZZZZZZ88888888888888888888888888888888\n");
    
}

    
    

