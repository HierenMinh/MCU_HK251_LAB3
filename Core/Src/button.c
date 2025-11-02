/*
 * button.c
 *
 *  Created on: Oct 28, 2025
 *      Author: qwein
 */

#include "button.h"

button_t button_1 = {
    .btn_port = BTN1_GPIO_Port,
    .btn_pin  = BTN1_Pin,

    .reg0 = NORMAL_STATE,
    .reg1 = NORMAL_STATE,
    .reg2 = NORMAL_STATE,
    .stable = NORMAL_STATE,
    .prev_stable = NORMAL_STATE,
    .btn_timeout_ms = 0,

    .btn_is_pressed = 0,
    .btn_is_long_pressed = 0,
 //   .btn_is_trigger_long_press = 0,
};

button_t button_2 = {
    .btn_port = BTN2_GPIO_Port,
    .btn_pin  = BTN2_Pin,
    .reg0 = NORMAL_STATE,
    .reg1 = NORMAL_STATE,
    .reg2 = NORMAL_STATE,
    .stable = NORMAL_STATE,
    .prev_stable = NORMAL_STATE,
	.btn_timeout_ms = 0,
	.btn_is_pressed = 0,
	.btn_is_long_pressed = 0,
//	.btn_is_trigger_long_press = 0,
};

button_t button_3 = {
    .btn_port = BTN3_GPIO_Port,
    .btn_pin  = BTN3_Pin,
    .reg0 = NORMAL_STATE,
    .reg1 = NORMAL_STATE,
    .reg2 = NORMAL_STATE,
    .stable = NORMAL_STATE,
    .prev_stable = NORMAL_STATE,
	.btn_timeout_ms = 0,
	.btn_is_pressed = 0,
	.btn_is_long_pressed = 0,
//	.btn_is_trigger_long_press = 0,
};

void get_key_input(button_t *button) {
	button->reg2 = button->reg1;
	button->reg1 = button->reg0;
	button->reg0 = HAL_GPIO_ReadPin(button->btn_port, button->btn_pin);
	if (button->reg0 == button->reg1 && button->reg1 == button->reg2) {
		button->stable = button->reg0;
		if (button -> stable != button -> prev_stable) {
			button -> prev_stable = button -> stable;
			if (button -> stable == PRESSED_STATE) {
				button -> btn_is_pressed = 1;
				button -> btn_timeout_ms = TIME_LONG_PRESS / TIME_CYCLE;
			}
		} else {
			button -> btn_timeout_ms --;
			if (button -> btn_timeout_ms <= 0) {
				button -> btn_timeout_ms = TIME_LONG_PRESS / TIME_CYCLE;
				if (button -> prev_stable == PRESSED_STATE) {
					button -> btn_is_long_pressed = 1;
				}
			}

		}
 	}
}

uint8_t is_pressed(button_t *button) {
	if (button->btn_is_pressed == 1) {
		return 1;
	}
	return 0;
}

void clear_press(button_t *button) {
	button->btn_is_pressed = 0;
}
uint8_t is_long_pressed(button_t *button) {
	if (button->btn_is_long_pressed == 1) {
		button->btn_is_long_pressed = 0;
		return 1;
	}
	return 0;
}
void clear_long_press(button_t *button) {
	button->btn_is_long_pressed = 0;
}

//void is_doubled_pressed(button_t *button) {
//	if (button->btn_is_doubled_pressed == 1) {
//		button->btn_is_doubled_pressed = 0;
//		return 1;
//	}
//	return 0;
//}
