#include "temperature.h"

static float temp;

void temperature_set(float temperature){
    temp = temperature;
}

float temperature_get(){
    return temp;
}