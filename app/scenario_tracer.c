#include "scenario_tracer.h"

typedef enum
{
  STATE_TIMER_STARTING,
  STATE_RUNNING,
  STATE_TIMER_STOPPING
} status_mode;

static status_mode mode = STATE_TIMER_STARTING;

static void scenario_tracer_run_timer_starting();
static void scenario_tracer_run_running();
static void scenario_tracer_run_timer_stopping();

void scenario_tracer_init()
{
  wheel_init();
  scenario_init();
  cycle_timer_init();
}

void scenario_tracer_run()
{
  switch (mode)
  {
  case STATE_TIMER_STARTING:
    scenario_tracer_run_timer_starting();
    break;
  case STATE_RUNNING:
    scenario_tracer_run_running();
    break;
  case STATE_TIMER_STOPPING:
    scenario_tracer_run_timer_stopping();
    break;
  }
}

static void scenario_tracer_run_timer_starting()
{
  const int time = scenario_get_current_scene_time();
  cycle_timer_set_time(time / 10);
  cycle_timer_start();
  mode = STATE_RUNNING;
}

static void scenario_tracer_run_running()
{
  const int left_motor_power = scenario_get_current_scene_left_motor_power();
  const int right_motor_power = scenario_get_current_scene_right_motor_power();
  wheel_set_power(left_motor_power, right_motor_power);
  wheel_run();

  const bool_t is_time_over = cycle_timer_is_time_over();
  if (is_time_over)
  {
    mode = STATE_TIMER_STOPPING;
  }
}

static void scenario_tracer_run_timer_stopping()
{
  cycle_timer_stop();
  scenario_next_scene();
  mode = STATE_TIMER_STARTING;
}
