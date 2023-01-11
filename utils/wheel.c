#include "ev3api.h"
#include "wheel.h"
#include "parameters.h"

void wheel_init()
{
}

void wheel_run()
{
  // 左モーターを回転する
  ev3_motor_set_power(left_motor, 30);
  // 右モーターを回転する
  ev3_motor_set_power(right_motor, 30);
}

void wheel_stop()
{
  // 左モーターを停止する
  ev3_motor_stop(left_motor, true);
  // 右モーターを停止する
  ev3_motor_stop(right_motor, true);
}
