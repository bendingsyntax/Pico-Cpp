#include <stdio.h>
#include <iostream>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

int getRange(uint ultrasonicTrig, uint ultrasonicEcho);