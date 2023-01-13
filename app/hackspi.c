#include "hackspi.h"
#include "parameters.h"
#include "starter.h"
#include "linetracer.h"

// 実行状態の列挙体
typedef enum
{
  RUN_UNDEFINED,
  RUN_STARTER,
  RUN_TRACER
} run_mode;

// 実行モード
static run_mode mode = RUN_UNDEFINED;

static void hackspi_run_undefined();
static void hackspi_run_starter();
static void hackspi_run_tracer();

void hackspi_init()
{
  // クラスを初期化する
  starter_init();
  line_tracer_init();
}

void hackspi_run()
{
  switch (mode)
  {
  case RUN_UNDEFINED:
    hackspi_run_undefined();
    break;
  case RUN_STARTER:
    hackspi_run_starter();
    break;
  case RUN_TRACER:
    hackspi_run_tracer();
    break;
  default:
    printf("NO CASE\n");
  }
}

static void hackspi_run_undefined()
{
  mode = RUN_STARTER;
}

static void hackspi_run_starter()
{
  // スタートボタンが押下されたか取得する
  if (starter_is_pressed())
  {
    mode = RUN_TRACER;
  }
}

static void hackspi_run_tracer()
{
  line_tracer_run();
}
