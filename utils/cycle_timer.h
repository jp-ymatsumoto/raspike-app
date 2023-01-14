#ifndef CYCLE_TIMER_H_
#define CYCLE_TIMER_H_

#include "ev3api.h"

void cycle_timer_init();
void cycle_timer_set_time(int _current_time, int _target_time);
void cycle_timer_start();
void cycle_timer_stop();
bool_t cycle_timer_is_time_over();

#endif
