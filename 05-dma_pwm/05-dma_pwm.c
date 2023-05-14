/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Output PWM signals on pins 0 and 1

#include "pico/stdlib.h"
#include "hardware/pwm.h"

int main() {
    /// \tag::setup_pwm[]

    // Tell GPIO 0 and 1 they are allocated to the PWM
    gpio_set_function(6, GPIO_FUNC_PWM);

    // Find out which PWM slice is connected to GPIO 0 (it's slice 0)
    uint slice_num = pwm_gpio_to_slice_num(6);

    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 50000.f);
    pwm_init(slice_num, &config, true);

    for(int i = 0; i < 255; i++) {
        pwm_set_gpio_level(6, i * i);// Set the PWM running
    }
}
