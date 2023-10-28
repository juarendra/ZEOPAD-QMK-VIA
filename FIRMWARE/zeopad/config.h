#pragma once

#define MATRIX_ROWS  4
#define MATRIX_COLS  6

// wiring of each half
#define MATRIX_ROW_PINS       { F4, B1, B3, B2 }
#define MATRIX_COL_PINS       { C6, D7, E6, B4, B5, NO_PIN } // A virtual pin is needed for the encoder key matrix in via.

#define DIODE_DIRECTION COL2ROW

#define TAP_CODE_DELAY  10
/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
#define ENCODERS_PAD_A { D1 , F6}
#define ENCODERS_PAD_B { D0 , B6}
#define ENCODER_RESOLUTIONS       { 4 , 4}
/* disable these deprecated features by default */

/* ws2812 RGB LED */
#define RGB_DI_PIN D3 //D3 - underglow C7 - backlight
#define RGBLED_NUM 1    // Number of L