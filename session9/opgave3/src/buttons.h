#include <stdint.h>

void Button_init(); // clear bit for buttons
int Button_pressed(uint8_t button_No); //takes in the value 1, 2, 3 or 4, each number corresponding to a button.
