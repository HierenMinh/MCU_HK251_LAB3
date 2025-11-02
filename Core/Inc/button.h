/*
 * button.h
 *
 *  Created on: Oct 28, 2025
 *      Author: qwein
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "global.h"

typedef struct {
    /* Hardware binding */

    GPIO_TypeDef *btn_port;   // STM32 GPIO port
    uint16_t btn_pin;    // STM32 pin number

    /* === Internal Debounce State === */
    uint8_t reg0, reg1, reg2;
	uint8_t stable;
	uint8_t prev_stable; // Rolling buffer for sampling
    uint32_t btn_timeout_ms;    // Debounce / long-press timeout

    /* === Logical Flags === */
    uint8_t btn_is_pressed ;        // 1 = short press detected
    uint8_t btn_is_long_pressed;    // 1 = long press event
    uint8_t btn_is_hold;			// detecting for a hold but not long press

} button_t;

#define PRESSED_STATE GPIO_PIN_RESET
#define NORMAL_STATE GPIO_PIN_SET

#define LONG_TICKS       5000   // ~5 s
#define DOUBLE_TICKS     250   // ~250 ms

uint8_t is_pressed(button_t *button);
uint8_t is_long_pressed(button_t *button);
uint8_t is_doubled_pressed(button_t *button);
void clear_press(button_t *button);
void clear_long_press(button_t *button);

void get_key_input(button_t *button);

extern button_t button_1;
extern button_t button_2;
extern button_t button_3;


#endif /* INC_BUTTON_H_ */
