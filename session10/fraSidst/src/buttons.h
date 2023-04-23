#include <stdint.h>

void Button_init(); // initialize the LED’s to be output. 
void Button_turnOn(uint8_t led_No); //takes in the value 1, 2, 3 or 4, each number corresponding to a LED. 
void Button_turnOff(uint8_t led_No); //takes in the value 1, 2, 3 or 4, each number corresponding to a LED.
void Button_toggle(uint8_t led_No); //takes in the value 1, 2, 3 or 4, each number corresponding to a LED.
