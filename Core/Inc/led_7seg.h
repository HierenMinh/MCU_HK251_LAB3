/*
 * led_7seg.h
 *
 *  Created on: Oct 28, 2025
 *      Author: qwein
 */

#ifndef INC_LED_7SEG_H_
#define INC_LED_7SEG_H_

#include "global.h"
#include "main.h"


void led_7_seg_display(int pos, int num);
void led_7_seg_scan(); //call every 250ms
void led_7_seg_set(int counter_way1, int counter_way2);
void led_7_seg_turn_off_all();

#endif /* INC_LED_7SEG_H_ */
