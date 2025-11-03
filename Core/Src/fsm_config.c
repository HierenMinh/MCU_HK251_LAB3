/*
 * fsm_config.c
 *
 *  Created on: Oct 30, 2025
 *      Author: qwein
 */
#include "fsm_config.h"

config_state_t config_status = CONF_IDLE;
static uint32_t tmp_red_time_s;
static uint32_t tmp_green_time_s;
static uint32_t tmp_amber_time_s;

/**
 * @brief Run configuration state machine.
 *
 * CONFIG FSM adjusts timing parameters for red/green/amber phases.
 * Button_2 increases time, button_3 confirms, button_1 moves to next phase.
 * If valid configuration (red > green && red - green == amber), new values are saved.
 */
void fsm_config_run() {
	switch (config_status) {
	case CONF_IDLE:
		if (1) {
//			config_status = CONF_INIT;
		}
		break;
	case CONF_INIT:
		tmp_red_time_s = red_time_s;
		tmp_green_time_s = green_time_s;
		tmp_amber_time_s = amber_time_s;
		timer_set(TIMER_LED_BLINK, TIME_LED_BLINK_MS);
		traffic_light_blink_red_init();
		config_status = CONF_RED;
		break;
	case CONF_RED:
		led_7_seg_set(tmp_red_time_s, tmp_red_time_s);
		if(timer_is_expired(TIMER_LED_BLINK)) {
			traffic_light_blink_red();
			timer_set(TIMER_LED_BLINK, TIME_LED_BLINK_MS);
		}
		if(is_pressed(&button_2)) {
			clear_press(&button_2);
			tmp_red_time_s ++;
			if (tmp_red_time_s > 99) {
				tmp_red_time_s = 0;
			}
		}
		if(is_pressed(&button_3)) {
			clear_press(&button_3);
			clear_press(&button_1); //prevent pressing accidentally
			traffic_light_turn_off_all();
			config_status = CONF_RED_LATCH;
		}
		break;
	case CONF_RED_LATCH:
		traffic_light_turn_on_red();
		led_7_seg_set(tmp_red_time_s, tmp_red_time_s);
		if(is_pressed(&button_1)) {
			clear_press(&button_1);
			clear_press(&button_2);
			timer_set(TIMER_LED_BLINK, TIME_LED_BLINK_MS);
			traffic_light_blink_green_init();
			config_status = CONF_GREEN;
		}
		if(is_pressed(&button_3)) {
			clear_press(&button_3);
			clear_press(&button_2);//prevent pressing accidentally
			timer_set(TIMER_LED_BLINK, TIME_LED_BLINK_MS);
			traffic_light_blink_red_init();
			config_status = CONF_RED;
		}
		break;
	case CONF_GREEN:
		led_7_seg_set(tmp_green_time_s, tmp_green_time_s);
		if (timer_is_expired(TIMER_LED_BLINK)) {
			traffic_light_blink_green();
			timer_set(TIMER_LED_BLINK, TIME_LED_BLINK_MS);
		}
		if (is_pressed(&button_2)) {
			clear_press(&button_2);
			tmp_green_time_s ++;
			if (tmp_green_time_s > 99) {
				tmp_green_time_s = 0;
			}
		}
		if (is_pressed(&button_3)) {
			clear_press(&button_3);
			clear_press(&button_1);//prevent pressing accidentally
			traffic_light_turn_off_all();
			config_status = CONF_GREEN_LATCH;
		}
		break;
	case CONF_GREEN_LATCH:
		traffic_light_turn_on_green();
		led_7_seg_set(tmp_green_time_s, tmp_green_time_s);
		if (is_pressed(&button_1)) {
			clear_press(&button_1);
			clear_press(&button_2);//prevent pressing accidentally
			timer_set(TIMER_LED_BLINK, TIME_LED_BLINK_MS);
			traffic_light_blink_amber_init();
			config_status = CONF_AMBER;
		}
		if (is_pressed(&button_3)) {
			clear_press(&button_3);
			clear_press(&button_2);//prevent pressing accidentally
			timer_set(TIMER_LED_BLINK, TIME_LED_BLINK_MS);
			traffic_light_blink_green_init();
			config_status = CONF_GREEN;
		}
		break;
	case CONF_AMBER:
		led_7_seg_set(tmp_amber_time_s, tmp_amber_time_s);
		if (timer_is_expired(TIMER_LED_BLINK)) {
			traffic_light_blink_amber();
			timer_set(TIMER_LED_BLINK, TIME_LED_BLINK_MS);
		}
		if (is_pressed(&button_2)) {
			clear_press(&button_2);
			tmp_amber_time_s ++;
			if (tmp_amber_time_s > 99) {
				tmp_amber_time_s = 0;
			}
		}
		if (is_pressed(&button_3)) {
			clear_press(&button_3);
			clear_press(&button_1);//prevent pressing accidentally
			traffic_light_turn_off_all();
			config_status = CONF_AMBER_LATCH;
		}
		break;
	case CONF_AMBER_LATCH:
		traffic_light_turn_on_amber();
		led_7_seg_set(tmp_amber_time_s, tmp_amber_time_s);
		if (is_pressed(&button_1)) {
			clear_press(&button_1);
			config_status = CONF_ALL_LATCH;
			// else do not change anything
//			config_status = CONF_IDLE;
//			auto_status = AUTO_INIT;
		}
		if (is_pressed(&button_3)) {
			clear_press(&button_3);
			clear_press(&button_2);//prevent pressing accidentally
			timer_set(TIMER_LED_BLINK, TIME_LED_BLINK_MS);
			traffic_light_blink_amber_init();
			config_status = CONF_AMBER;
		}

	case CONF_ALL_LATCH:
		traffic_light_turn_on_all();
		if((tmp_red_time_s > tmp_green_time_s) && (tmp_red_time_s - tmp_green_time_s == tmp_amber_time_s)) {
			red_time_s = tmp_red_time_s;
			red_time_ms = red_time_s * 1000;

			green_time_s = tmp_green_time_s;
			green_time_ms = green_time_s * 1000;

			amber_time_s = tmp_amber_time_s;
			amber_time_ms = amber_time_s * 1000;
		} else {
			led_7_seg_set(amber_time_s, amber_time_s);
		}
		if (is_long_pressed(&button_2)) {
			clear_long_press(&button_2);
			clear_press(&button_2); //prevent pressing accidentally
			timer_set(TIMER_COUNTDOWN, amber_time_ms);
			led_7_seg_set(MAX_NUMBER, MAX_NUMBER);
			manual_status = manual_status_prev; //return the previous manual state
			config_status = CONF_IDLE; //become idle
		}
		break;
	default:
		break;
	}

}

