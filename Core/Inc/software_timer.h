/*
 * software_timer.h
 *
 *  Created on: Oct 28, 2025
 *      Author: qwein
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "global.h"
#include "main.h"

typedef struct {
	uint32_t timer_counter;
	uint8_t timer_flag;
} sw_timer_t;

void timer_run();
void timer_set(uint8_t flag_timer, uint32_t duration);
uint8_t timer_is_expired(uint8_t timer_idx);



#endif /* INC_SOFTWARE_TIMER_H_ */
