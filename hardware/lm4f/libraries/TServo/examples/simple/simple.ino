#include "TServo.h"

TServo s;
int angle = 0;
int dir = 1;

void setup()
{
  s.attach(PD_1);
}

void loop()
{
  s.moveto(angle);

  //update angle, reverse direction at boundaries
  angle += dir;
  if (angle == -90 || angle == 90) dir = -dir;

  delay (30);
}
