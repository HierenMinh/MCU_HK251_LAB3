/*
 * global.h
 *
 *  Created on: Oct 28, 2025
 *      Author: qwein
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "software_timer.h"
#include "traffic_light.h"
#include "fsm.h"

typedef enum {
	MODE_AUTO,
	MODE_CONFIG,
	MODE_MANUAL
} mode_t;
typedef enum {
	AUTO_INIT,
	AUTO_AMBER_RED,
	AUTO_GREEN_RED,
	AUTO_RED_AMBER,
	AUTO_RED_GREEN,
	AUTO_IDLE
} auto_state_t;
typedef enum {
	MAN_IDLE,
	MAN_INIT,
	MAN_AMBER_RED,
	MAN_GREEN_RED,
	MAN_RED_AMBER,
	MAN_RED_GREEN
} manual_state_t;
typedef enum {
	CONFIG_IDLE,
	CONFIG_INIT,
	CONFIG_AMBER,
	CONFIG_GREEN,
	CONFIG_RED
} config_state_t;

#define TIME_CYCLE 10
#define TIMER_NUM 5
#define TIMER_COUNTDOWN 0
#define TIMER_LED_7_SEG_SCAN 1
#define TIME_LED_7_SEG_SCAN 500
#define TIMER_SEC 2
#define TIME_SEC_MS 1000

#define LED_OFF GPIO_PIN_SET
#define LED_ON GPIO_PIN_RESET

#define WAY1 1
#define WAY2 2

extern mode_t current_mode;
extern auto_state_t auto_status;
extern manual_state_t manual_status;
extern config_state_t config_status;

extern uint8_t red_time_s;
extern uint8_t red_time_ms;
extern uint8_t green_time_s;
extern uint8_t green_time_ms;
extern uint8_t amber_time_s;
extern uint8_t amber_time_ms;
extern uint8_t counter_way1;
extern uint8_t counter_way2;

#endif /* INC_GLOBAL_H_ */
