#include <stdio.h>
#include <iostream>
#include "pico/stdlib.h"
#include "hardware/gpio.h" //gpio pins
//#include "hardware/clocks.h" //clock-time
//#include "pico/float.h" //floater

int main()
{
    int LEDs[] = {13, 14, 15};
    int y = 0;

    //for(int y = 0; y <= sizeof(LEDs); y++)
    while(1)
    {
        std::cout << "Hello world!\n";
        gpio_init(LEDs[y]);
        gpio_set_dir(LEDs[y], GPIO_OUT);
        gpio_put(LEDs[y], true);
        sleep_ms(500);
        gpio_put(LEDs[y], false);
        sleep_ms(500);
        y++;
        if (y == 3)
        {
            y = 0;
        }
    }
    return 0;
    /*
    int led = 13;
    while(1)
    {
        gpio_init(led);
        gpio_set_dir(led, GPIO_OUT);
        gpio_put(led, true);
        sleep_ms(500);
        gpio_put(led, false);
        sleep_ms(500);  
    }
    for(int x = 0; x <= sizeof(LEDs); x++)
    {

    }

    return 0;*/
}