#include "cycle_timer.h"

static int current_time = 0;
static int target_time = 0;

void cycle_timer_init()
{
}

void cycle_timer_set_time(int _target_time)
{
  target_time = _target_time;
}

void cycle_timer_start()
{
  current_time = 0;
}

void cycle_timer_stop()
{
  current_time = 0;
  target_time = 0;
}

bool_t cycle_timer_is_time_over()
{
  current_time++;
  const bool_t is_time_over = target_time < current_time ? true : false;
  return is_time_over;
}
