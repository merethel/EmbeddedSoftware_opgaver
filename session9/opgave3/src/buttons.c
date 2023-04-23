#include "buttons.h"
#include <avr/io.h>
#include <avr/delay.h>

void Button_init() // clear bit for buttons
{
    // først skal vi clear bit 3, 4, 5 og bit 6
    DDRA &= ~(1 << PA4) & ~(1 << PA5) & ~(1 << PA6) & ~(1 << PA7);

    // sørg for at enable pull-up resistor (indvendige tænd sluk ting)
    PORTA |= (1 << PA4) | (1 << PA5) | (1 << PA6) | (1 << PA7);
}

int Button_pressed(uint8_t button_No) // takes in the value 4, 5, 6 & 7, each number corresponding to a button.
{
    if (PINA & (1 << (button_No)))
    {
        return 1;
    }
    return 0;
}
