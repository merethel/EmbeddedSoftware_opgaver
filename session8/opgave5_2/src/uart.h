#include <avr/io.h>
#include <util/delay.h>

void uartInit(int baudrate);
void uartSend(char *data);
