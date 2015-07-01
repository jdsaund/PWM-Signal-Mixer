#ifndef Input_cpp
#define	Input_cpp

#include "Input.h"

Input input;

void Input::init()
{
}

void Input::calcRoll()
{
if(digitalRead(ROLL_IN_PIN) == HIGH)
{
RollStartTime = micros();
}
else
{
RollInShared = (uint16_t)(micros() - RollStartTime);
}
}

void Input::calcPitch()
{
if(digitalRead(PITCH_IN_PIN) == HIGH)
{
PitchStartTime = micros();
}
else
{
PitchInShared = (uint16_t)(micros() - PitchStartTime);
}
}

void Input::calcYaw()
{
if(digitalRead(YAW_IN_PIN) == HIGH)
{
YawStartTime = micros();
}
else
{
YawInShared = (uint16_t)(micros() - YawStartTime);
}
}

void Input::finalise_input()
{
  noInterrupts();

  RollInProcessed  = RollInShared;
  PitchInProcessed = PitchInShared;
  YawInProcessed   = YawInShared;

  interrupts(); 
}

#endif
