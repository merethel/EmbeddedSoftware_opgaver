#include "humidity.h"

static float hum;

void humidity_set(float humidity){
    hum = humidity;
}

float humidity_get(){
    return hum;
}