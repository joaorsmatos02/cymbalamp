#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

#ifndef LED_DELAY_MS
#define LED_DELAY_MS 250
#endif


int pico_led_init(void) {
    // A device like Pico that uses a GPIO for the LED will define PICO_DEFAULT_LED_PIN
    // so we can use normal GPIO functionality to turn the led on and off
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    return PICO_OK;
}

void pico_set_led(bool led_on) {
    // Just set the GPIO on or off
    gpio_put(PICO_DEFAULT_LED_PIN, led_on);
}

void init() {
    stdio_init_all();
    pico_led_init();
    adc_init();

    // Make sure GPIO is high-impedance, no pullups etc
    adc_gpio_init(28);
    // Select ADC input 0 (GPIO26)
    adc_select_input(2);
}

int main() {
    init();
    int led = 0;
    do {
        sleep_ms(100);
        uint16_t result = adc_read();
        printf("%d\n", result);
        if(result > 2000){
            led = !led;
            pico_set_led(led);
            int i;
            while((i = adc_read()) > 500){
                sleep_ms(100);
                printf("%d\n", i);
            }
        }
    } while(1);
}
