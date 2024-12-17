// Copyright Capabilities Limited 2024

#include "gpio.h"
#include "fpga_platform_config.h"

volatile char *LED_GPIO = (volatile char*) GPIO_LED_BASE;
volatile char *SWITCH_GPIO = (volatile char*) GPIO_SWITCH_BASE;

void set_leds(char lit_mask) {
    *LED_GPIO = lit_mask;
}

char get_switches(void) {
    return *SWITCH_GPIO;
}
