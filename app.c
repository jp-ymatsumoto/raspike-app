#include "app.h"
#include <stdio.h>
#include "hackspi.h"
#include "parameters.h"

static void init_ports();
static void init_classes();

/**
 * メインタスクで実行する関数
 */
void main_task(intptr_t exinf)
{
  init_ports();
  init_classes();

  printf("\n\n\nSTART\n\n\n");

  // 周期タスクを開始する
  sta_cyc(TRACER_TASK_CYC);

  // メインタスクを待機状態にする
  slp_tsk();

  // 周期タスクを停止する
  stp_cyc(TRACER_TASK_CYC);

  printf("\n\n\nEND\n\n\n");

  // タスクを終了する
  ext_tsk();
}

/**
 * トレーサータスクで実行する関数
 */
void tracer_task(intptr_t exinf)
{
  // 右ボタンの押下状態を取得する
  if (ev3_button_is_pressed(RIGHT_BUTTON))
  {
    // 左モーターを停止する
    ev3_motor_stop(left_motor, true);
    // 右モーターを停止する
    ev3_motor_stop(right_motor, true);
    // メインタスクの待機状態を解除する
    wup_tsk(MAIN_TASK);
  }
  else
  {
    // printf("run\n");
    hackspi_run();
  }

  // タスクを終了する
  ext_tsk();
}

static void init_ports()
{
  // 左モーターのポートを設定する
  ev3_motor_config(left_motor, MEDIUM_MOTOR);
  // 右モーターのポートを設定する
  ev3_motor_config(right_motor, MEDIUM_MOTOR);

  // カラーセンサーのポートを設定する
  ev3_sensor_config(color_sensor, COLOR_SENSOR);
}

static void init_classes()
{
  // クラスを初期化する
  hackspi_init();
}
