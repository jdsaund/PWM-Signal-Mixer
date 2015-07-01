#ifndef Output_h
#define	Output_h

#include <Servo.h>
#include <Arduino.h>
#include "config.h"

class Output
{
  public:
  void init();
  void write_servos(uint16_t rollin, uint16_t pitchin, uint16_t yawin);
  void calc_mixing();

  // properties
  volatile uint16_t servo_1_out;
  volatile uint16_t servo_2_out;
  volatile uint16_t servo_3_out;
  volatile uint16_t servo_4_out;
  volatile uint16_t servo_5_out;

  private:
  Servo servo_1;
  Servo servo_2;
  Servo servo_3;
  Servo servo_4;
  Servo servo_5;
};
extern Output output;
#endif
