#include "ev3api.h"
#include "wheel.h"
#include "parameters.h"

static int left_motor_power = 0;
static int right_motor_power = 0;

void wheel_init()
{
}

void wheel_set_power(int left_power, int right_power)
{
  left_motor_power = left_power;
  right_motor_power = right_power;
}

void wheel_run()
{
  // 左モーターを回転する
  ev3_motor_set_power(left_motor, left_motor_power);
  // 右モーターを回転する
  ev3_motor_set_power(right_motor, right_motor_power);
}

void wheel_stop()
{
  // 左モーターを停止する
  ev3_motor_stop(left_motor, true);
  // 右モーターを停止する
  ev3_motor_stop(right_motor, true);
}
