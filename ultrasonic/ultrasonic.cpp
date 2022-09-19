#include "ultrasonic.h"

int main()
{
    uint LEDs[] = {13, 14, 15}, ultrasonicEcho = 0, ultrasonicTrig = 1, y = 0;

    gpio_put(LEDs[y], true);
    sleep_ms(500);
    gpio_put(LEDs[y], false);
    sleep_ms(500);
    y++;
    if (y == 3)
    {
        y = 0;
    }

    for (int x = 0; x <= sizeof(LEDs); x++)
    {
        gpio_init(LEDs[x]);
        gpio_set_dir(LEDs[x], GPIO_OUT);
    }
    gpio_init(ultrasonicEcho);
    gpio_init(ultrasonicTrig);
    gpio_set_dir(ultrasonicEcho, GPIO_IN);
    gpio_set_dir(ultrasonicTrig, GPIO_OUT);
    while(1)
    {
        std::cout << "\n" << getRange(ultrasonicTrig, ultrasonicEcho) << " cm";
        sleep_ms(100);
    }
}


int getRange(uint ultrasonicTrig, uint ultrasonicEcho)
{
    uint64_t pulseTime, delta = 0, convertToCM, convertToInch;
    absolute_time_t initTime, termTime;
    gpio_put(ultrasonicTrig, 1);
    sleep_us(10);
    gpio_put(ultrasonicTrig, 0);

    while (gpio_get(ultrasonicEcho) == 0) tight_loop_contents();
    initTime = get_absolute_time();
    while (gpio_get(ultrasonicEcho) == 1)
    {
        delta++;
        sleep_us(1);
        if (delta > 26100) return 0;
    }
    termTime = get_absolute_time();
    pulseTime = absolute_time_diff_us(initTime, termTime);
    convertToCM = pulseTime / 29 / 2;
    convertToInch = (long)pulseTime / 74.f / 2.f; 

    return convertToCM;
}
