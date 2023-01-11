#include "starter.h"

void starter_init()
{
}

bool_t starter_is_pressed()
{
  return ev3_button_is_pressed(ENTER_BUTTON);
}
