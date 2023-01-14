#include "cycle_timer.h"
#include <stdio.h>

static int current_time_ms = 0; // 経過時間
static int target_time_ms = 0;  // 指定時間
static int cycle_time_ms = 10;  // １周期の時間

/** 初期化 */
void cycle_timer_init(int _cycle_time_ms)
{
  const bool_t is_ranged = (10 <= _cycle_time_ms && _cycle_time_ms <= 50) ? true : false;
  cycle_time_ms = is_ranged ? _cycle_time_ms : 10;
}

/** 指定時間を設定する */
void cycle_timer_set_time(int _target_time)
{
  target_time_ms = _target_time;
}

/** 開始する */
void cycle_timer_start()
{
  current_time_ms = 0;
}

/** 停止する */
void cycle_timer_stop()
{
  current_time_ms = 0;
  target_time_ms = 0;
}

/** 指定時間経過しているか */
bool_t cycle_timer_is_time_over()
{
  current_time_ms += cycle_time_ms;
  const bool_t is_time_over = target_time_ms < current_time_ms ? true : false;
  return is_time_over;
}
