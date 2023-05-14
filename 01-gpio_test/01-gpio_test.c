#include <stdio.h>
#include "pico/stdlib.h"


int main()
{
    for(int i = 6; i <= 13; i++) {
        gpio_init(i);
        gpio_set_dir(i, GPIO_OUT);
    }
    while (true) {
        for(int i = 6; i <= 13; i++) {
            gpio_put(i, 1);
            sleep_ms(150);
        }
        for(int i = 6; i <= 13; i++) {
            gpio_put(i, 0);
            sleep_ms(150);
        }
    }

    return 0;
}