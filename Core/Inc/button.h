/*
 * button.h
 *
 *  Created on: Oct 28, 2025
 *      Author: qwein
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

typedef struct {
    /* Hardware binding */

    GPIO_TypeDef *btn_port;   // STM32 GPIO port
    uint16_t btn_pin;    // STM32 pin number

    /* === Internal Debounce State === */
    uint8_t reg0, reg1, reg2;
	uint8_t stable = NORMAL_STATE;
	uint8_t prev_stable = NORMAL_STATE;     // Rolling buffer for sampling
    uint32_t btn_timeout_ms = 0;       // Debounce / long-press timeout

    /* === Logical Flags === */
    uint8_t btn_is_pressed = 0;        // 1 = short press detected
    uint8_t btn_is_long_pressed = 0;    // 1 = long press event
    uint8_t btn_is_trigger_long_press = 0;     // Prevent repeat long event
    uint8_t btn_is_doubled_pressed = 0;

} button_t;

#define PRESSED_STATE RESET
#define NORMAL_STATE SET

#define LONG_TICKS       5000   // ~5 s
#define DOUBLE_TICKS     250   // ~250 ms

void is_pressed(button_t *button);
void is_long_pressed(button_t *button);
void is_doubled_pressed(button_t *button);


#endif /* INC_BUTTON_H_ */
