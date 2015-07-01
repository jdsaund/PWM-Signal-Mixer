#ifndef Input_h
#define	Input_h

#include <Arduino.h>
#include "config.h"

class Input
{
  public:
  // properties
  volatile uint16_t RollInShared;
  volatile uint16_t PitchInShared;
  volatile uint16_t YawInShared;
  uint16_t RollInProcessed;
  uint16_t PitchInProcessed;
  uint16_t YawInProcessed;
  uint32_t RollStartTime;
  uint32_t PitchStartTime;
  uint32_t YawStartTime;

  // methods
  void init();
  void calcRoll();
  void calcPitch();
  void calcYaw();
  void finalise_input();
};
extern Input input;
#endif
