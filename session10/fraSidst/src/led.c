#include <led.h>
#include <avr/io.h>
#include <avr/delay.h>

void Led_init() // initialize the LED’s to be output.
{
    // konfigurerer outputs (LED'er)
    DDRA |= (1 << PA0) | (1 << PA1) | (1 << PA2) | (1 << PA3);
}
void Led_turnOn(uint8_t led_No) // takes in the value 1, 2, 3 or 4, each number corresponding to a LED.
{
    if (led_No < 5)
    {
        PORTA |= (1 << (led_No - 1));
    }
}
void Led_turnOff(uint8_t led_No) // takes in the value 1, 2, 3 or 4, each number corresponding to a LED.
{
    if (led_No < 5)
    {
        PORTA &= ~(1 << (led_No - 1));
    }
}
void Led_toggle(uint8_t led_No) // takes in the value 1, 2, 3 or 4, each number corresponding to a LED.
{
    if (led_No < 5)
    {
        PORTA ^= (1 << (led_No - 1));
    }
}
