#include <stdint.h>

void Led_init(); // initialize the LED’s to be output. 
void Led_turnOn(uint8_t led_No); //takes in the value 1, 2, 3 or 4, each number corresponding to a LED. 
void Led_turnOff(uint8_t led_No); //takes in the value 1, 2, 3 or 4, each number corresponding to a LED.
void Led_toggle(uint8_t led_No); //takes in the value 1, 2, 3 or 4, each number corresponding to a LED.
