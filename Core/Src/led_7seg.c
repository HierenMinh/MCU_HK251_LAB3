/*
 * led_7seg.c
 *
 *  Created on: Sep 29, 2025
 *      Author: qwein
 */
#include "led_7seg.h"

#define SEG_OFF 0
#define SEG_ON 1

#define LED_OFF 1
#define LED_ON 0

static int led_7seg_index = 0;

static int led7seg[4] = {0, 0, 0, 0};
GPIO_TypeDef* way1_digit0_port = EN0_GPIO_Port;
GPIO_TypeDef* way1_digit1_port = EN1_GPIO_Port;
GPIO_TypeDef* way2_digit0_port = EN2_GPIO_Port;
GPIO_TypeDef* way2_digit1_port = EN3_GPIO_Port;


uint16_t way1_digit0_pin = EN0_Pin;
uint16_t way1_digit1_pin = EN1_Pin;
uint16_t way2_digit0_pin = EN2_Pin;
uint16_t way2_digit1_pin = EN3_Pin;

uint8_t numArray[10] = {
	0x3F, // 0: a b c d e f
	0x06, // 1:   b c
	0x5B, // 2: a b   d e   g
	0x4F, // 3: a b c d     g
	0x66, // 4:   b c     f g
	0x6D, // 5: a   c d   f g
	0x7D, // 6: a   c d e f gled
	0x07, // 7: a b c
	0x7F, // 8: a b c d e f g
	0x6F  // 9: a b c d   f g
};

void led_7_seg_scan() {
	if (led_7seg_index == 0) {
		HAL_GPIO_WritePin(way1_digit1_port, way1_digit1_pin, LED_OFF);
		HAL_GPIO_WritePin(way2_digit1_port, way2_digit1_pin, LED_OFF);
		led_7_seg_display(led7seg[led_7seg_index], led7seg[led_7seg_index + 2]);
		HAL_GPIO_WritePin(way1_digit0_port, way1_digit0_pin, LED_ON);
		HAL_GPIO_WritePin(way2_digit0_port, way2_digit0_pin, LED_ON);
		led_7seg_index = 1;
	} else {
		HAL_GPIO_WritePin(way1_digit0_port, way1_digit0_pin, LED_OFF);
		HAL_GPIO_WritePin(way2_digit0_port, way2_digit0_pin, LED_OFF);
		led_7_seg_display(led7seg[led_7seg_index], led7seg[led_7seg_index + 2]);

		if(led7seg[led_7seg_index] != 0) HAL_GPIO_WritePin(way1_digit1_port, way1_digit1_pin, LED_ON);
		if(led7seg[led_7seg_index + 2] != 0) HAL_GPIO_WritePin(way2_digit1_port, way2_digit1_pin, LED_ON);
		led_7seg_index = 0;
	}
}

void led_7_seg_display(int digit_way1, int digit_way2) {
	uint8_t pattern_way1 = (digit_way1 >= 0 && digit_way1 <= 9) ? numArray[digit_way1] : 0x79;
	uint8_t pattern_way2 = (digit_way2 >= 0 && digit_way2 <= 9) ? numArray[digit_way2] : 0x79;

	HAL_GPIO_WritePin(SEG0_WAY1_GPIO_Port, SEG0_WAY1_Pin, (pattern_way1 & (0x01 << 0)) ? SEG_ON : SEG_OFF); // a
	HAL_GPIO_WritePin(SEG1_WAY1_GPIO_Port, SEG1_WAY1_Pin, (pattern_way1 & (0x01 << 1)) ? SEG_ON : SEG_OFF); // b
	HAL_GPIO_WritePin(SEG2_WAY1_GPIO_Port, SEG2_WAY1_Pin, (pattern_way1 & (0x01 << 2)) ? SEG_ON : SEG_OFF); // c
	HAL_GPIO_WritePin(SEG3_WAY1_GPIO_Port, SEG3_WAY1_Pin, (pattern_way1 & (0x01 << 3)) ? SEG_ON : SEG_OFF); // d
	HAL_GPIO_WritePin(SEG4_WAY1_GPIO_Port, SEG4_WAY1_Pin, (pattern_way1 & (0x01 << 4)) ? SEG_ON : SEG_OFF); // e
	HAL_GPIO_WritePin(SEG5_WAY1_GPIO_Port, SEG5_WAY1_Pin, (pattern_way1 & (0x01 << 5)) ? SEG_ON : SEG_OFF); // f
	HAL_GPIO_WritePin(SEG6_WAY1_GPIO_Port, SEG6_WAY1_Pin, (pattern_way1 & (0x01 << 6)) ? SEG_ON : SEG_OFF); // g

	HAL_GPIO_WritePin(SEG0_WAY2_GPIO_Port, SEG0_WAY2_Pin, (pattern_way2 & (0x01 << 0)) ? SEG_ON : SEG_OFF); // a
	HAL_GPIO_WritePin(SEG1_WAY2_GPIO_Port, SEG1_WAY2_Pin, (pattern_way2 & (0x01 << 1)) ? SEG_ON : SEG_OFF); // b
	HAL_GPIO_WritePin(SEG2_WAY2_GPIO_Port, SEG2_WAY2_Pin, (pattern_way2 & (0x01 << 2)) ? SEG_ON : SEG_OFF); // c
	HAL_GPIO_WritePin(SEG3_WAY2_GPIO_Port, SEG3_WAY2_Pin, (pattern_way2 & (0x01 << 3)) ? SEG_ON : SEG_OFF); // d
	HAL_GPIO_WritePin(SEG4_WAY2_GPIO_Port, SEG4_WAY2_Pin, (pattern_way2 & (0x01 << 4)) ? SEG_ON : SEG_OFF); // e
	HAL_GPIO_WritePin(SEG5_WAY2_GPIO_Port, SEG5_WAY2_Pin, (pattern_way2 & (0x01 << 5)) ? SEG_ON : SEG_OFF); // f
	HAL_GPIO_WritePin(SEG6_WAY2_GPIO_Port, SEG6_WAY2_Pin, (pattern_way2 & (0x01 << 6)) ? SEG_ON : SEG_OFF); // g
}

void led_7_seg_set(int counter_way1, int counter_way2) {
	led7seg[0] = counter_way1 % 10;
	led7seg[1] = counter_way1 / 10;
	led7seg[2] = counter_way2 % 10;
	led7seg[3] = counter_way2 / 10;
}

void led_7_seg_turn_off() {
	HAL_GPIO_WritePin(way1_digit1_port, way1_digit1_pin, LED_OFF);
	HAL_GPIO_WritePin(way2_digit1_port, way2_digit1_pin, LED_OFF);
	HAL_GPIO_WritePin(way1_digit0_port, way1_digit0_pin, LED_OFF);
	HAL_GPIO_WritePin(way2_digit0_port, way2_digit0_pin, LED_OFF);
}





