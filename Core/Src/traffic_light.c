/*
 * traffic_light.c
 *
 *  Created on: Oct 28, 2025
 *      Author: qwein
 */

#include "traffic_light.h"



void red_green_display() {
	HAL_GPIO_WritePin(RED_WAY_1_GPIO_Port   , RED_WAY_1_Pin   , ON);
	HAL_GPIO_WritePin(GREEN_WAY_1_GPIO_Port , GREEN_WAY_1_Pin , OFF);
	HAL_GPIO_WritePin(AMBER_WAY_1_GPIO_Port , AMBER_WAY_1_Pin , OFF);

	HAL_GPIO_WritePin(RED_WAY_2_GPIO_Port   , RED_WAY_2_Pin   , OFF);
	HAL_GPIO_WritePin(GREEN_WAY_2_GPIO_Port , GREEN_WAY_2_Pin , ON);
	HAL_GPIO_WritePin(AMBER_WAY_2_GPIO_Port , AMBER_WAY_2_Pin , OFF);
}

void green_red_display() {
	HAL_GPIO_WritePin(RED_WAY_1_GPIO_Port   , RED_WAY_1_Pin   , OFF);
	HAL_GPIO_WritePin(GREEN_WAY_1_GPIO_Port , GREEN_WAY_1_Pin , ON);
	HAL_GPIO_WritePin(AMBER_WAY_1_GPIO_Port , AMBER_WAY_1_Pin , OFF);

	// Way 2: RED
	HAL_GPIO_WritePin(RED_WAY_2_GPIO_Port   , RED_WAY_2_Pin   , ON);
	HAL_GPIO_WritePin(GREEN_WAY_2_GPIO_Port , GREEN_WAY_2_Pin , OFF);
	HAL_GPIO_WritePin(AMBER_WAY_2_GPIO_Port , AMBER_WAY_2_Pin , OFF);
}
void amber_red_display() {
	// Way 1: AMBER
	HAL_GPIO_WritePin(RED_WAY_1_GPIO_Port   , RED_WAY_1_Pin   , OFF);
	HAL_GPIO_WritePin(GREEN_WAY_1_GPIO_Port , GREEN_WAY_1_Pin , OFF);
	HAL_GPIO_WritePin(AMBER_WAY_1_GPIO_Port , AMBER_WAY_1_Pin , ON);

	// Way 2: RED
	HAL_GPIO_WritePin(RED_WAY_2_GPIO_Port   , RED_WAY_2_Pin   , ON);
	HAL_GPIO_WritePin(GREEN_WAY_2_GPIO_Port , GREEN_WAY_2_Pin , OFF);
	HAL_GPIO_WritePin(AMBER_WAY_2_GPIO_Port , AMBER_WAY_2_Pin , OFF);
}
void red_amber_display() {
    // Way 1: RED
    HAL_GPIO_WritePin(RED_WAY_1_GPIO_Port   , RED_WAY_1_Pin   , ON);
    HAL_GPIO_WritePin(GREEN_WAY_1_GPIO_Port , GREEN_WAY_1_Pin , OFF);
    HAL_GPIO_WritePin(AMBER_WAY_1_GPIO_Port , AMBER_WAY_1_Pin , OFF);

    // Way 2: AMBER
    HAL_GPIO_WritePin(RED_WAY_2_GPIO_Port   , RED_WAY_2_Pin   , OFF);
    HAL_GPIO_WritePin(GREEN_WAY_2_GPIO_Port , GREEN_WAY_2_Pin , OFF);
    HAL_GPIO_WritePin(AMBER_WAY_2_GPIO_Port , AMBER_WAY_2_Pin , ON);
}
void traffic_light_turn_off_all() {
	HAL_GPIO_WritePin(RED_WAY_1_GPIO_Port, RED_WAY_1_Pin, OFF);
	HAL_GPIO_WritePin(GREEN_WAY_1_GPIO_Port, GREEN_WAY_1_Pin, OFF);
	HAL_GPIO_WritePin(AMBER_WAY_1_GPIO_Port, AMBER_WAY_1_Pin, OFF);
	HAL_GPIO_WritePin(RED_WAY_2_GPIO_Port, RED_WAY_2_Pin, OFF);
	HAL_GPIO_WritePin(GREEN_WAY_2_GPIO_Port, GREEN_WAY_2_Pin, OFF);
	HAL_GPIO_WritePin(AMBER_WAY_1_GPIO_Port, AMBER_WAY_2_Pin, OFF);
}

void traffic_light_turn_on_all() {
	HAL_GPIO_WritePin(RED_WAY_1_GPIO_Port, RED_WAY_1_Pin, ON);
	HAL_GPIO_WritePin(GREEN_WAY_1_GPIO_Port, GREEN_WAY_1_Pin, ON);
	HAL_GPIO_WritePin(AMBER_WAY_1_GPIO_Port, AMBER_WAY_1_Pin, ON);
	HAL_GPIO_WritePin(RED_WAY_2_GPIO_Port, RED_WAY_2_Pin, ON);
	HAL_GPIO_WritePin(GREEN_WAY_2_GPIO_Port, GREEN_WAY_2_Pin, ON);
	HAL_GPIO_WritePin(AMBER_WAY_1_GPIO_Port, AMBER_WAY_2_Pin, ON);
}
void traffic_light_blink_amber() {
	HAL_GPIO_TogglePin(AMBER_WAY_1_GPIO_Port, AMBER_WAY_1_Pin);
	HAL_GPIO_TogglePin(AMBER_WAY_2_GPIO_Port, AMBER_WAY_2_Pin);
}
void traffic_light_blink_green() {
	HAL_GPIO_TogglePin(GREEN_WAY_1_GPIO_Port, GREEN_WAY_1_Pin);
	HAL_GPIO_TogglePin(GREEN_WAY_2_GPIO_Port, GREEN_WAY_2_Pin);
}
void traffic_light_blink_red() {
	HAL_GPIO_TogglePin(RED_WAY_1_GPIO_Port, RED_WAY_1_Pin);
	HAL_GPIO_TogglePin(RED_WAY_2_GPIO_Port, RED_WAY_2_Pin);
}

void traffic_light_turn_on_red() {
	HAL_GPIO_WritePin(RED_WAY_1_GPIO_Port   , RED_WAY_1_Pin   , ON);
//	HAL_GPIO_WritePin(GREEN_WAY_1_GPIO_Port , GREEN_WAY_1_Pin , OFF);
//	HAL_GPIO_WritePin(AMBER_WAY_1_GPIO_Port , AMBER_WAY_1_Pin , OFF);

	HAL_GPIO_WritePin(RED_WAY_2_GPIO_Port   , RED_WAY_2_Pin   , ON);
//	HAL_GPIO_WritePin(GREEN_WAY_2_GPIO_Port , GREEN_WAY_2_Pin , OFF);
//	HAL_GPIO_WritePin(AMBER_WAY_2_GPIO_Port , AMBER_WAY_2_Pin , OFF);
}


void traffic_light_turn_on_amber() {
	HAL_GPIO_WritePin(RED_WAY_1_GPIO_Port   , RED_WAY_1_Pin   , OFF);
	HAL_GPIO_WritePin(GREEN_WAY_1_GPIO_Port , GREEN_WAY_1_Pin , OFF);
	HAL_GPIO_WritePin(AMBER_WAY_1_GPIO_Port , AMBER_WAY_1_Pin , ON);

	HAL_GPIO_WritePin(RED_WAY_2_GPIO_Port   , RED_WAY_2_Pin   , OFF);
	HAL_GPIO_WritePin(GREEN_WAY_2_GPIO_Port , GREEN_WAY_2_Pin , OFF);
	HAL_GPIO_WritePin(AMBER_WAY_2_GPIO_Port , AMBER_WAY_2_Pin , ON);
}


void traffic_light_turn_on_green() {
	HAL_GPIO_WritePin(RED_WAY_1_GPIO_Port   , RED_WAY_1_Pin   , OFF);
	HAL_GPIO_WritePin(GREEN_WAY_1_GPIO_Port , GREEN_WAY_1_Pin , ON);
	HAL_GPIO_WritePin(AMBER_WAY_1_GPIO_Port , AMBER_WAY_1_Pin , OFF);

	HAL_GPIO_WritePin(RED_WAY_2_GPIO_Port   , RED_WAY_2_Pin   , OFF);
	HAL_GPIO_WritePin(GREEN_WAY_2_GPIO_Port , GREEN_WAY_2_Pin , ON);
	HAL_GPIO_WritePin(AMBER_WAY_2_GPIO_Port , AMBER_WAY_2_Pin , OFF);
}

void traffic_light_blink_red_init() {
	HAL_GPIO_WritePin(RED_WAY_1_GPIO_Port   , RED_WAY_1_Pin   , ON);
	HAL_GPIO_WritePin(GREEN_WAY_1_GPIO_Port , GREEN_WAY_1_Pin , OFF);
	HAL_GPIO_WritePin(AMBER_WAY_1_GPIO_Port , AMBER_WAY_1_Pin , OFF);

	HAL_GPIO_WritePin(RED_WAY_2_GPIO_Port   , RED_WAY_2_Pin   , OFF);
	HAL_GPIO_WritePin(GREEN_WAY_2_GPIO_Port , GREEN_WAY_2_Pin , OFF);
	HAL_GPIO_WritePin(AMBER_WAY_2_GPIO_Port , AMBER_WAY_2_Pin , OFF);
}

void traffic_light_blink_green_init() {
	HAL_GPIO_WritePin(RED_WAY_1_GPIO_Port   , RED_WAY_1_Pin   , OFF);
	HAL_GPIO_WritePin(GREEN_WAY_1_GPIO_Port , GREEN_WAY_1_Pin , ON);
	HAL_GPIO_WritePin(AMBER_WAY_1_GPIO_Port , AMBER_WAY_1_Pin , OFF);

	HAL_GPIO_WritePin(RED_WAY_2_GPIO_Port   , RED_WAY_2_Pin   , OFF);
	HAL_GPIO_WritePin(GREEN_WAY_2_GPIO_Port , GREEN_WAY_2_Pin , OFF);
	HAL_GPIO_WritePin(AMBER_WAY_2_GPIO_Port , AMBER_WAY_2_Pin , OFF);
}

void traffic_light_blink_amber_init() {
	HAL_GPIO_WritePin(RED_WAY_1_GPIO_Port   , RED_WAY_1_Pin   , OFF);
	HAL_GPIO_WritePin(GREEN_WAY_1_GPIO_Port , GREEN_WAY_1_Pin , OFF);
	HAL_GPIO_WritePin(AMBER_WAY_1_GPIO_Port , AMBER_WAY_1_Pin , ON);

	HAL_GPIO_WritePin(RED_WAY_2_GPIO_Port   , RED_WAY_2_Pin   , OFF);
	HAL_GPIO_WritePin(GREEN_WAY_2_GPIO_Port , GREEN_WAY_2_Pin , OFF);
	HAL_GPIO_WritePin(AMBER_WAY_2_GPIO_Port , AMBER_WAY_2_Pin , OFF);
}




