/*
 * traffic_light.h
 *
 *  Created on: Oct 28, 2025
 *      Author: qwein
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "main.h"
#include "global.h"

void red_green_display();
void green_red_display();
void amber_red_display();
void red_amber_display();

void traffic_light_turn_off_all();
void traffic_light_turn_on_all();

void traffic_light_blink_amber();
void traffic_light_blink_green();
void traffic_light_blink_red();

void traffic_light_turn_on_amber();
void traffic_light_turn_on_green();
void traffic_light_turn_on_red();

void traffic_light_blink_red_init();
void traffic_light_blink_green_init();
void traffic_light_blink_amber_init();


#endif /* INC_TRAFFIC_LIGHT_H_ */
