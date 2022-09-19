#include <stdio.h>
#include <iostream>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

int main()
{
    led = 25
    gpio_init(led);
    gpio_set_dir(led, GPIO_OUT);
    while(1)
    {
        gpio_put(led, true);
        sleep_ms(100);
        gpio_put(led, false); 
        sleep_ms(100); 
    }
    return 0;
}
