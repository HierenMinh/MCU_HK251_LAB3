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
#include "fsm_auto.h"
#include "fsm_manual.h"
#include "fsm_config.h"
#include "main.h"

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
	CONF_IDLE,
	CONF_INIT,
	CONF_AMBER,
	CONF_AMBER_LATCH,
	CONF_GREEN,
	CONF_GREEN_LATCH,
	CONF_RED,
	CONF_RED_LATCH,
	CONF_ALL_LATCH
} config_state_t;

#define TIME_CYCLE 10
#define TIME_LONG_PRESS 2000

#define MAX_NUMBER 99

#define TIMER_NUM 6

#define TIMER_COUNTDOWN 0

#define TIMER_LED_7_SEG_SCAN 1
#define TIME_LED_7_SEG_SCAN 250

#define TIMER_SEC 2
#define TIME_SEC_MS 1000

#define TIMER_LED_BLINK 3
#define TIME_LED_BLINK_MS 500

#define LED_OFF GPIO_PIN_SET
#define LED_ON GPIO_PIN_RESET

#define OFF GPIO_PIN_SET
#define ON GPIO_PIN_RESET

#define WAY1 1
#define WAY2 2

extern auto_state_t auto_status;
extern manual_state_t manual_status;
extern manual_state_t manual_status_prev;
extern config_state_t config_status;

extern uint32_t red_time_s;
extern uint32_t red_time_ms;
extern uint32_t green_time_s;
extern uint32_t green_time_ms;
extern uint32_t amber_time_s;
extern uint32_t amber_time_ms;
extern uint32_t counter_way1_s;
extern uint32_t counter_way2_s;

#endif /* INC_GLOBAL_H_ */
