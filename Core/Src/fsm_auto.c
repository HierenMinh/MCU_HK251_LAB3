/*
 * fsm_auto.c
 *
 *  Created on: Oct 30, 2025
 *      Author: qwein
 */
#include "fsm_auto.h"

/**
 * @brief Run automatic traffic light state machine.
 *
 * AUTO FSM cycles through the sequence:
 *   AUTO_INIT → AUTO_RED_GREEN → AUTO_RED_AMBER → AUTO_GREEN_RED → AUTO_AMBER_RED
 *
 * Transitions are triggered by software timers or long button presses.
 * Long press on button_1 switches to MANUAL config.
 */

auto_state_t auto_status = AUTO_INIT;


void fsm_auto_run() {
	switch (auto_status) {
	case AUTO_INIT:
		timer_set(TIMER_COUNTDOWN, green_time_ms);
		timer_set(TIMER_SEC, TIME_SEC_MS);
		auto_status = AUTO_RED_GREEN;
		break;
	case AUTO_RED_GREEN:
		red_green_display();
		if (timer_is_expired(TIMER_SEC)) { // 1 second passed
			timer_set(TIMER_SEC, TIME_SEC_MS);
			counter_way1_s--;
			counter_way2_s--;
			led_7_seg_set(counter_way1_s, counter_way2_s); //display new number on led 7-segment
			auto_status = AUTO_RED_GREEN;
		}
		if (timer_is_expired(TIMER_COUNTDOWN)) { // finish green time
			timer_set(TIMER_COUNTDOWN, amber_time_ms); //initial for new state
			timer_set(TIMER_SEC, TIME_SEC_MS);
			counter_way2_s = amber_time_s;
			led_7_seg_set(counter_way1_s, counter_way2_s);
			auto_status = AUTO_RED_AMBER;
		}
		if (is_long_pressed(&button_1)) {
			clear_long_press(&button_1);
			led_7_seg_set(MAX_NUMBER, MAX_NUMBER);
			manual_status = MAN_RED_GREEN;
			auto_status = AUTO_IDLE;
		}
		break;
	case AUTO_RED_AMBER:
		red_amber_display();
		if (timer_is_expired(TIMER_SEC)) {
			timer_set(TIMER_SEC, TIME_SEC_MS);
			counter_way1_s--;
			counter_way2_s--;
			led_7_seg_set(counter_way1_s, counter_way2_s);
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
		if (is_long_pressed(&button_1)) {
			clear_long_press(&button_1);
			timer_set(TIMER_COUNTDOWN, amber_time_ms);
			led_7_seg_set(MAX_NUMBER, MAX_NUMBER);
			auto_status = AUTO_IDLE;
			manual_status = MAN_RED_AMBER;
		}
		break;
	case AUTO_GREEN_RED:
		green_red_display();
		if (timer_is_expired(TIMER_SEC)) {
			timer_set(TIMER_SEC, TIME_SEC_MS);
			counter_way1_s--;
			counter_way2_s--;
			led_7_seg_set(counter_way1_s, counter_way2_s);
			auto_status = AUTO_GREEN_RED;
		}
		if (timer_is_expired(TIMER_COUNTDOWN)) {
			timer_set(TIMER_COUNTDOWN, amber_time_ms);
			timer_set(TIMER_SEC, TIME_SEC_MS);
			counter_way1_s = amber_time_s;
			led_7_seg_set(counter_way1_s, counter_way2_s);
			auto_status = AUTO_AMBER_RED;
		}
		if (is_long_pressed(&button_1)) {
			clear_long_press(&button_1);
			led_7_seg_set(MAX_NUMBER, MAX_NUMBER);
			manual_status = MAN_GREEN_RED;
			auto_status = AUTO_IDLE;
		}
		break;
	case AUTO_AMBER_RED:
		amber_red_display();
		if (timer_is_expired(TIMER_SEC)) {
			timer_set(TIMER_SEC, TIME_SEC_MS);
			counter_way1_s--;
			counter_way2_s--;
			led_7_seg_set(counter_way1_s, counter_way2_s);
			auto_status = AUTO_AMBER_RED;
		}
		if (timer_is_expired(TIMER_COUNTDOWN)) {
			timer_set(TIMER_COUNTDOWN, green_time_ms);
			timer_set(TIMER_SEC, TIME_SEC_MS);
			counter_way1_s = red_time_s;
			counter_way2_s = green_time_s;
			led_7_seg_set(counter_way1_s, counter_way2_s);
			auto_status = AUTO_RED_GREEN;
		}
		if (is_long_pressed(&button_1)) {
			clear_long_press(&button_1);
			timer_set(TIMER_COUNTDOWN, amber_time_ms);
			led_7_seg_set(MAX_NUMBER, MAX_NUMBER);
			auto_status = AUTO_IDLE;
			manual_status = MAN_AMBER_RED;
		}
		break;
	case AUTO_IDLE:
		;
		break;
		default:
			break;
	}

}



