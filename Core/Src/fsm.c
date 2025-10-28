/*
 * fsm.c
 *
 *  Created on: Oct 28, 2025
 *      Author: qwein
 */

#include "fsm.h"

mode_t mode_current = MODE_AUTO;
auto_state_t auto_status = AUTO_INIT;
manual_state_t manual_status = MAN_IDLE;
config_state_t config_status = CONFIG_IDLE;

uint8_t counter_way1_s = red_time_s;
uint8_t counter_way2_s = green_time_s;
void fsm_auto_run() {
	switch (auto_status) {
	case AUTO_INIT:
		auto_status = AUTO_RED_GREEN;
		timer_set(TIMER_COUNTDOWN, green_time_ms);
		timer_set(TIMER_SEC, TIME_SEC_MS);
		break;
	case AUTO_RED_GREEN:
		red_green_display();
		if (timer_is_expired(TIMER_SEC)) {
			counter_way1_s--;
			counter_way2_s--;
			led_7_seg_set(counter_way1_s, counter_way2_s);
			timer_set(TIMER_SEC, TIME_SEC_MS);
			auto_status = AUTO_RED_GREEN;
		}
		if (timer_is_expired(TIMER_STATUS_LIGHT)) {
			timer_set(TIMER_COUNTDOWN, amber_time_ms);
			timer_set(TIMER_SEC, TIME_SEC_MS);
			counter_way2_s = amber_time_s;
			led_7_seg_set(counter_way1_s, counter_way2_s);
			auto_status = AUTO_RED_AMBER;
		}
		if (btn_is_long_pressed(&button_1)) {
			manual_status = MAN_RED_GREEN;
			auto_status = AUTO_HALT;
			led_7_seg_turn_off();
//			red_green_display();
		}
		break;
	case AUTO_RED_AMBER:
		red_amber_display();
		if (timer_is_expired(TIMER_SEC)) {
			counter_way1_s--;
			counter_way2_s--;
			led_7_seg_set(counter_way1_s, counter_way2_s);
			timer_set(TIMER_SEC, TIME_SEC_MS);
			auto_status = AUTO_RED_AMBER;
		}
		if (timer_is_expired(TIMER_COUNTDOWN)) {
			timer_set(TIMER_COUNTDOWN, green_time_ms);
			timer_set(TIMER_SEC, TIME_SEC_MS);
			counter_way1_s = green_time_s;
			counter_way2_s = red_time_s;
			led_7_seg_set(counter_way1_s, counter_way2_s);
			auto_status = AUTO_GREEN_RED;
		}
		if (btn_is_long_pressed(&button_1)) {
			auto_status = AUTO_IDLE;
			timer_set(TIMER_COUNTDOWN, counter_way2_s / 1000);
			manual_status = MAN_RED_AMBER;
		}
		break;
	case AUTO_GREEN_RED:
		green_red_display();
		if (timer_is_expired(TIMER)) {
			counter_way1_s--;
			counter_way2_s--;
			led_7_seg_set(counter_way1_s, counter_way2_s);
			timer_set(TIMER_SEC, TIME_SEC_MS);
			auto_status = AUTO_GREEN_RED;
		}
		if (timer_is_expired(TIMER_COUNTDOWN)) {
			timer_set(TIMER_COUNTDOWN, amber_time_ms);
			timer_set(TIMER_SEC, TIME_SEC_MS);
			counter_way1_s = amber_time_s;
			led_7_seg_set(counter_way1_s, counter_way2_s);
			auto_status = AUTO_AMBER_RED;
		}
//		if (btn_is_long_pressed(&button_1)) {
//					manual_status = MAN_RED_GREEN;
//					auto_status = AUTO_HALT;
//					led_7_seg_turn_off();
//		//			red_green_display();
//				}
		break;
	case AUTO_AMBER_RED:
		amber_red_display();
		if (timer_is_expired(TIMER_SEC)) {
			counter_way1_s--;
			counter_way2_s--;
			led_7_seg_set(counter_way1_s, counter_way2_s);
			timer_set(TIMER_SEC, TIME_SEC_MS);
			auto_status = AUTO_AMBER_RED;
		}
		if (timer_is_expired(TIMER_COUNTDOWN)) {
			auto_status = RED_GREEN;
			timer_set(TIMER_COUNTDOWN, green_time_ms);
			timer_set(TIMER_SEC, TIME_SEC_MS);
			counter_way1_s = red_time_s;
			counter_way2_s = green_time_s;
			led_7_seg_set(counter_way1_s, counter_way2_s);
		}
//		if (btn_is_long_pressed(&button_1)) {
//					manual_status = MAN_RED_GREEN;
//					auto_status = AUTO_HALT;
//					led_7_seg_turn_off();
//		//			red_green_display();
//				}
		break;
	}
	case AUTO_IDLE:
		if (1) {
			;
		}
		break;
	default:
		break;
}

void fsm_manual_run() {
	switch (manual_status) {
	case MAN_IDLE:
		if (1);
		break;
	case MAN_RED_GREEN:
		red_green_display();
		if (is_double_pressed(&button_2)) {
			timer_set(TIMER_COUNTDOWN, amber_time_ms);
			manual_status = MAN_RED_AMBER;
		}
		if (is_long_pressed(&button_3)) {
			timer_set(TIMER_COUNTDOWN, green_time_ms);
			timer_set(TIMER_SEC, TIME_SEC_MS);
			counter_way1_s = red_time_s;
			counter_way2_s = green_time_s;
			led_7_seg_set(counter_way1_s, counter_way2_s);
			auto_status = AUTO_RED_GREEN;
			manual_status = MAN_IDLE;
		}
		//if (is_long_pressed(button))
		break;
	case MAN_RED_AMBER:
		red_amber_display();
		if (timer_is_expired(TIMER_COUNTDOWN)) {
			manual_status = MAN_GREEN_RED;
		}
		break;
	case MAN_GREEN_RED:
		green_amber_display();
		if (is_doubled_pressed(&button_2)) {
			timer_set(TIMER_COUNTDOWN, amber_time_ms);
			manual_status = MAN_AMBER_RED;
		}
		if (is_long_pressed(&button_3)) {
			timer_set(TIMER_COUNTDOWN, green_time_ms);
			timer_set(TIMER_SEC, TIME_SEC_MS);
			counter_way1_s = green_time_s;
			counter_way2_s = red_time_s;
			led_7_seg_set(counter_way1_s, counter_way2_s);
			auto_status = AUTO_GREEN_RED;
			manual_status = MAN_IDLE;
		}
		break;
	case MAN_AMBER_RED:
		amber_red_display();
		if (timer_is_expired(TIMER_COUNTDOWN)) {
			manual_status = MAN_RED_GREEN;
		}
		break;
	default:
		break;
	}
}

void fsm_config_run() {
	switch (config_status) {
	case CONFIG_IDLE:
		if (1) {
			;
		}
	}
}


