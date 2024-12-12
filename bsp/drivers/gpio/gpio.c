// Copyright Capabilities Limited 2024

#include "gpio.h"

volatile char *LED_GPIO = (volatile char*) 0x40000000;
volatile char *SWITCH_GPIO = (volatile char*) 0x40000008;

void set_leds(char lit_mask) {
    *LED_GPIO = lit_mask;
}

char get_switches(void) {
    return *SWITCH_GPIO;
}
