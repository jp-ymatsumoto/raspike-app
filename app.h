#ifdef __cplusplus
extern "C"
{
#endif

#include "ev3api.h"

/* タスク優先度の定義 */
// メインタスクの優先度
#define MAIN_PRIORITY (TMIN_APP_TPRI + 1)
// トレーサータスクの優先度
#define TRACER_PRIORITY (TMIN_APP_TPRI + 2)

/* タスク周期の定義 */
#define TRACER_PERIOD (10 * 1000)

/* スタックサイズの定義 */
#ifndef STACK_SIZE
#define STACK_SIZE (4096)
#endif

/* タスクで実行する関数の定義 */
#ifndef TOPPERS_MACRO_ONLY
  extern void main_task(intptr_t exinf);
  extern void tracer_task(intptr_t exinf);
#endif

#ifdef __cplusplus
}
#endif
