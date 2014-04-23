#include "TServo.h"

TServo s[3];

float angle[3];
float dir[3];
int t_upd[3];
int t_del[3];

void setup()
{
  //attach servos
  s[0].attach(PD_0);
  s[1].attach(PD_1);
  //this servo uses 200Hz PWM frequency, OK for many analog and all digital servos
  s[2].attach(PD_2, 200, 1520, 600); 
  
  //init everything
  for (int i = 0; i < 3; i++) {
    angle[i] = 0.;
    dir[i] = 0.1;
    t_upd[i] = 0;
  }
  
  //init servo angle update intervals (ms)
  t_del[0] = 2;
  t_del[1] = 3;
  t_del[2] = 5;
}

void loop()
{
  int t = millis();
  
  for (int i = 0; i < 3; i++) {
    //wait until the angle update time
    if (t < t_upd[i]) continue;
    t_upd[i] = t + t_del[i];

    //angle could be float or integer from -90 to 90
    s[i].moveto(angle[i]);
    
    //update angle, reverse direction at boundaries 
    angle[i] += dir[i];
    if (angle[i] <= -90 || angle[i] >= 90)
       dir[i] = -dir[i]; 
  }
}
