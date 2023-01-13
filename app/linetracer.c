#include "linetracer.h"
#include "linemonitor.h"
#include "wheel.h"
#include "ev3api.h"

void line_tracer_init()
{
  wheel_init();
  line_monitor_init();
}

void line_tracer_run()
{
  const bool_t is_on_line = line_monitor_is_on_line();

  if (is_on_line)
  {
    wheel_set_power(30, 70);
  }
  else
  {
    wheel_set_power(70, 30);
  }

  wheel_run();
}
