// Copyright 2022 Victor Lucachi (@victorlucachi)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "zeopad.h"

void matrix_init_kb(void) {
    // disable pro micro LEDs
    DDRD &= ~(1<<5);
    PORTD &= ~(1<<5);

    DDRB &= ~(1<<0);
    PORTB &= ~(1<<0);

    matrix_init_user();
}

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    {  0 },
}, {
    {0  ,  0},
}, {
    4,
} };
#endif