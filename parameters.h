#ifndef PARAMETERS_H_
#define PARAMETERS_H_

#include "ev3api.h"

/* ********************  注意事項  ******************** */
// ポートマッピングは固定です。ただし、EV3RTとSPIKEでは使用部品が異なります。
// SPIKEの場合は、タッチセンサーの代わりにSPIKE本体のボタンを使用し、ジャイロセンサーは使用しません。
// EV3RTの場合は、以下のポートすべてを使用します。
/* ************************************************** */

/* モーターポートの定義 */
// アームモーターのポート番号
// static const motor_port_t right_motor = EV3_PORT_A;
// 右モーターのポート番号
static const motor_port_t right_motor = EV3_PORT_B;
// 左モーターのポート番号
static const motor_port_t left_motor = EV3_PORT_C;

/* センサーポートの定義 */
// タッチセンサーのポート番号
// static const sensor_port_t touch_sensor = EV3_PORT_1;
// カラーセンサーのポート番号
static const sensor_port_t color_sensor = EV3_PORT_2;
// 超音波センサーのポート番号
static const sensor_port_t ultrasonic_sensor = EV3_PORT_3;
// ジャイロセンサーのポート番号
// static const sensor_port_t gyro_sensor = EV3_PORT_4;

#endif
