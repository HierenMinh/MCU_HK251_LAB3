/*
 * button.c
 *
 *  Created on: Oct 28, 2025
 *      Author: qwein
 */

#include "button.h"

void get_key_input(button_t *button) {
	button->reg2 = button->reg1;
	button->reg1 = button->reg0;
	button->reg0 = HAL_GPIO_ReadPin(button->btn_port, button->btn_pin);
	if(button->reg0 == button->reg1 && button->reg1 == button->reg2) {
		button->stable = button->reg0;
		if(button->stable != button->prev_stable) {
			button->prev_stable = button->stable;
			if(button->stable == PRESSED_STATE) {

			}
		}
	}
}

void is_pressed(button_t *button) {
	if (button->btn_is_pressed == 1) {
		button->btn_is_pressed = 0;
		return 1;
	}
	return 0;
}
void is_long_pressed(button_t *button) {
	if (button->btn_is_long_pressed == 1) {
		button->btn_is_long_pressed = 0;
		return 1;
	}
	return 0;
}
void is_doubled_pressed(button_t *button) {
	if (button->btn_is_doubled_pressed == 1) {
		button->btn_is_doubled_pressed = 0;
		return 1;
	}
	return 0;
}
