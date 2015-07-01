#ifndef CLI_h
#define	CLI_h

#include <Arduino.h>
#include "Input.h"
#include "Output.h"

class CLI
{
  public:
/*
  CLI (const Input& input, const Output& output):
  _input(input),
  _output(output)
  {} */

  // properties
  String cmd = "";
  boolean stringComplete = false;

  // methods
  void init();
  void do_console();
  void serial_event();
  String pwm_bar(int16_t pulse_width);

  protected:
/*
  const Input& _input;
  const Output& _output;
*/
};
extern CLI cli;
#endif
