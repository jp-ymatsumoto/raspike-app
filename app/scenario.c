#include "scenario.h"

typedef struct
{
  int time_ms;
  int left_motor_power;
  int right_motor_power;
} scene;

static scene[] scenes = {
    {1000, 60, 0},
    {1000, 0, 60},
    {1000, 40, 40}};
static int scene_index = 0;
static int scene_length = 3;

void scenario_init()
{
}

int scenario_get_current_scene_time()
{
  return scenes[scene_index].time_ms;
}

int scenario_get_current_scene_left_motor_power()
{
  return scenes[scene_index].left_motor_power;
}

int scenario_get_current_scene_right_motor_power()
{
  return scenes[scene_index].right_motor_power;
}

void scenario_next_scene()
{
  scene_index++;
  if (scene_index == scene_length)
  {
    scene_index = 0;
  }
}
