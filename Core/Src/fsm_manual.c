/*
 * fsm_manual.c
 *
 *  Created on: Oct 30, 2025
 *      Author: qwein
 */
#include "fsm_manual.h"

manual_state_t manual_status = MAN_IDLE;
manual_state_t manual_status_prev = MAN_IDLE;

/**
 * @brief Run manual traffic light state machine.
 *
 * MANUAL FSM lets the user control traffic light states manually.
 * Double press / long press on different buttons trigger state transitions.
 * Long press on button_1 enters CONFIG config.
 */
void fsm_manual_run() {
	switch (manual_status) {
	case MAN_IDLE:
		if (1) {
//			led_7_seg_set(MAX_NUMBER, MAX_NUMBER);
//			manual_status = MAN_RED_GREEN;
			;
		}
		break;
	case MAN_RED_GREEN:
		red_green_display();
		if (is_pressed(&button_2)) {
			clear_press(&button_2);
			timer_set(TIMER_COUNTDOWN, amber_time_ms);
			manual_status = MAN_RED_AMBER;
		}
		if (is_long_pressed(&button_3)) {
			clear_long_press(&button_3);
			timer_set(TIMER_COUNTDOWN, green_time_ms);
			timer_set(TIMER_SEC, TIME_SEC_MS);
			counter_way1_s = red_time_s;
			counter_way2_s = green_time_s;
			led_7_seg_set(counter_way1_s, counter_way2_s);
			auto_status = AUTO_RED_GREEN;
			manual_status = MAN_IDLE;
		}
		if (is_long_pressed(&button_1)) {
			clear_long_press(&button_1);
			traffic_light_turn_off_all();
			manual_status_prev = MAN_AMBER_RED;
			manual_status = MAN_IDLE;
			config_status = CONF_INIT;
		}
		break;
	case MAN_RED_AMBER:
		red_amber_display();
		if (timer_is_expired(TIMER_COUNTDOWN)) {
			manual_status = MAN_GREEN_RED;
		}
		break;
	case MAN_GREEN_RED:
		green_red_display();
		if (is_pressed(&button_2)) {
			clear_press(&button_2);
			timer_set(TIMER_COUNTDOWN, amber_time_ms);
			manual_status = MAN_AMBER_RED;
		}
		if (is_long_pressed(&button_3)) {
			clear_long_press(&button_3);
			timer_set(TIMER_COUNTDOWN, green_time_ms);
			timer_set(TIMER_SEC, TIME_SEC_MS);
			counter_way1_s = green_time_s;
			counter_way2_s = red_time_s;
			led_7_seg_set(counter_way1_s, counter_way2_s);
			auto_status = AUTO_GREEN_RED;
			manual_status = MAN_IDLE;
		}
		if (is_long_pressed(&button_1)) {
			clear_long_press(&button_1);
			traffic_light_turn_off_all();
			manual_status_prev = MAN_GREEN_RED;
			manual_status = MAN_IDLE;
			config_status = CONF_INIT;
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


