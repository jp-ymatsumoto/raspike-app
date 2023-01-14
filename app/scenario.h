#ifndef SCENARIO_H_
#define SCENARIO_H_

#include "ev3api.h"

void scenario_init();
int scenario_get_current_scene_time();
int scenario_get_current_scene_left_motor_power();
int scenario_get_current_scene_right_motor_power();
void scenario_next_scene();

#endif
