#ifndef LINE_MONITOR_H_
#define LINE_MONITOR_H_

#include "ev3api.h"
#include "parameters.h"

void line_monitor_init(int _threshold);
bool_t line_monitor_is_on_line();

#endif
