#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

#ifndef DEBUG
#define DEBUG 0
#endif

#ifndef SENSOR_PIN
#define SENSOR_PIN 28
#endif

#ifndef SENSOR_PIN_2
#define SENSOR_PIN_2 2
#endif

#ifndef MOSFET_PIN
#define MOSFET_PIN 0
#endif

void init() {
    stdio_init_all();
    adc_init();
    // analog digital converter (vibration sensor)
    adc_gpio_init(SENSOR_PIN);
    adc_select_input(SENSOR_PIN_2);
    // mosfet
    gpio_init(MOSFET_PIN);
    gpio_set_dir(MOSFET_PIN, GPIO_OUT);
}

int main() {
    init();
    int led = 0; // start turned off
    do {
        sleep_ms(100);
        uint16_t result = adc_read();
        if(DEBUG) {
            printf("awaiting bang: %d\n", result);
        }
        if(result < 300){
            led = !led;
            gpio_put(MOSFET_PIN, led);
            int i;
            while((i = adc_read()) < 500){
                sleep_ms(100);
                if(DEBUG){
                    printf("awaiting cooldown: %d\n", i);
                }
            }
        }
    } while(1);
    return 0;
}
