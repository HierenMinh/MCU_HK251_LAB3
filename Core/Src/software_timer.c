/*
 * software_timer.c
 *
 *  Created on: Oct 28, 2025
 *      Author: qwein
 */

#include "software_timer.h"

static sw_timer_t sw_timers[TIMER_NUM];

void timer_set(uint8_t index, uint32_t duration) {
	sw_timers[index].timer_flag = 0;
	sw_timers[index].timer_counter = duration / TIME_CYCLE; // 10ms -> 1ms
}

void timer_run() {
	for(uint8_t i = 0; i < TIMER_NUM; i++) {
		if(sw_timers[i].timer_counter > 0) {
			sw_timers[i].timer_counter--;
			if(sw_timers[i].timer_counter <= 0) {
				sw_timers[i].timer_flag = 1;
			}
		}
	}
}

uint8_t timer_is_expired(uint8_t index) {
	if(sw_timers[index].timer_flag == 1) {
		return 1;
	}
	return 0;
}
