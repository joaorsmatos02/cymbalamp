#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

#ifndef SENSOR_PIN
#define SENSOR_PIN 28
#endif

#ifndef SENSOR_PIN_2
#define SENSOR_PIN_2 2
#endif

#ifndef RELAY_PIN
#define RELAY_PIN 0
#endif

void init() {
    stdio_init_all();
    adc_init();
    // analog digital converter (vibration sensor)
    adc_gpio_init(SENSOR_PIN);
    adc_select_input(SENSOR_PIN_2);
    // relay
    gpio_init(RELAY_PIN);
    gpio_set_dir(RELAY_PIN, GPIO_OUT);
}

int main() {
    init();
    int led = 1;
    do {
        sleep_ms(100);
        uint16_t result = adc_read();
        printf("%d\n", result);
        if(result > 40){
            led = !led;
            gpio_put(RELAY_PIN, led);
            int i;
            while((i = adc_read()) > 15){
                sleep_ms(100);
                printf("%d\n", i);
            }
        }
    } while(1);
    return 0;
}
