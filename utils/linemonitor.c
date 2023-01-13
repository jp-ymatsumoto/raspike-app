#include "linemonitor.h"
#include "parameters.h"

static int threshold = 50;

void line_monitor_init(int _threshold)
{
  threshold = _threshold;
}

bool_t line_monitor_is_on_line()
{
  const int reflect = ev3_color_sensor_get_reflect(color_sensor);
  const bool_t is_on_line = reflect < threshold;
  return is_on_line;
}
