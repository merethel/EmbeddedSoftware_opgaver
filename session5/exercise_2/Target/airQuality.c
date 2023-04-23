#include "airQuality.h"
#include "humidity.h"
#include "temperature.h"
#include <stdio.h>


static float airQuality;

static void airQuality_calculate(){
    airQuality = temperature_get() * humidity_get();
}

void airQuality_setTemp(float temp){
    temperature_set(temp);
}

void airQuality_setHumidity(float hum){
    humidity_set(hum);
}

void airQuality_print(){
    float a;
    float b;
    printf("Type in temperature and humidity:\n");
    scanf("%f %f", &a, &b);
    airQuality_setTemp(a);
    airQuality_setHumidity(b);
    airQuality_calculate();
    printf("Temperature: %f\nHumidity: %f\nAir quality: %f", temperature_get(), humidity_get(), airQuality);
}
