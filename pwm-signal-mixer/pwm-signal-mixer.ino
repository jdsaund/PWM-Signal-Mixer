#include <PinChangeInt.h>
#include "CLI.h"
#include "Output.h"
#include "Input.h"
#include "config.h"
#include <Servo.h>

void setup()
{
  Serial.begin(9600); 
  Serial.println();
  
  cli.init();
  output.init();
  
  PCintPort::attachInterrupt(ROLL_IN_PIN, calcRoll, CHANGE); 
  PCintPort::attachInterrupt(PITCH_IN_PIN, calcPitch, CHANGE); 
  PCintPort::attachInterrupt(YAW_IN_PIN, calcYaw, CHANGE);
}

void loop()
{
  cli.do_console();
  input.finalise_input();
  output.write_servos(input.RollInProcessed, input.PitchInProcessed, input.YawInProcessed);
}

void calcRoll(){input.calcRoll();}
void calcPitch(){input.calcPitch();}
void calcYaw(){input.calcYaw();}
