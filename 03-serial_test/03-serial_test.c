#include <stdio.h>
#include "pico/stdlib.h"


int main()
{
    stdio_init_all();

    for(int i = 0; i < 10; i++)
    {
        printf("Hello, world! %d\n", i);
        sleep_ms(1000);
    }

    return 0;
}
