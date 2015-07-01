#ifndef CLI_cpp
#define CLI_cpp

#include "CLI.h"

CLI cli;

void CLI::init()
{
  // reserve 200 bytes for the cmd:
  cmd.reserve(200);
}

void CLI::do_console()
{
  serial_event();

  if (cmd=="cli" || cmd=="help")
  {
  Serial.println("COMMAND LINE INTERFACE");
  Serial.println();
  Serial.println("Enter one of the following options:");
  Serial.println("input");
  Serial.println("output");
  Serial.println("pinout");
  Serial.println();
  cmd="";
  }


  //////////////////////////////////////
  // WRITE INPUT TO CONSOLE ////////////
  //////////////////////////////////////
  
  if (cmd=="input")
  {
    Serial.print("INPUT - ");
    Serial.print("\tRoll: ");
    Serial.print(pwm_bar(input.RollInProcessed));
    Serial.print("\tPitch: ");
    Serial.print(pwm_bar(input.PitchInProcessed));
    Serial.print("\tYaw: ");
    Serial.print(pwm_bar(input.YawInProcessed));
    Serial.println();
  }

  //////////////////////////////////////
  // WRITE OUTPUT TO CONSOLE ///////////
  //////////////////////////////////////
  
    if (cmd=="output")
  {
    Serial.print("OUTPUT - ");
    Serial.print("\tServo 1: ");
    Serial.print(pwm_bar(output.servo_1_out));
    Serial.print("\tServo 2: ");
    Serial.print(pwm_bar(output.servo_2_out));    
    Serial.print("\tServo 3: ");
    Serial.print(pwm_bar(output.servo_3_out));    
    Serial.print("\tServo 4: ");
    Serial.print(pwm_bar(output.servo_4_out));
    Serial.print("\tServo 5: ");
    Serial.print(pwm_bar(output.servo_5_out));
    Serial.println();
  }
  
  //////////////////////////////////////
  // DISPLAY PIN CONFIGURATION /////////
  //////////////////////////////////////
  
    if (cmd=="pinout")
  {
    Serial.println("CURRENT PIN CONFIGURATION");
    Serial.println();
    
    Serial.println("INPUT");
    Serial.print("Roll pin: \t");
    Serial.println(ROLL_IN_PIN);
    Serial.print("Pitch pin: \t");
    Serial.println(PITCH_IN_PIN);    
    Serial.print("Yaw pin: \t");
    Serial.println(YAW_IN_PIN);    
    Serial.println();
    
    Serial.println("OUTPUT");
    Serial.print("Servo 1 pin: \t");
    Serial.println(SERVO_1_PIN);
    Serial.print("Servo 2 pin: \t");
    Serial.println(SERVO_2_PIN);    
    Serial.print("Servo 3 pin: \t");
    Serial.println(SERVO_3_PIN);    
    Serial.print("Servo 4 pin: \t");
    Serial.println(SERVO_4_PIN);
    Serial.print("Servo 5 pin: \t");
    Serial.println(SERVO_5_PIN);
    Serial.println();
    
    cmd = "";
  } 
}

void CLI::serial_event() {
  if (stringComplete) 
  {
    Serial.println(cmd);
    // clear the string:
    cmd = "";
    stringComplete = false;
  }

  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    cmd += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

String CLI::pwm_bar(int16_t pulse_width)
{
  String pwm_bar = "";
  
  if (pulse_width <= 1000)
  {
    pwm_bar = "|-----------|";
    return pwm_bar;
  } else 
  
    if (pulse_width > 1000 && pulse_width <= 1100)
  {
    pwm_bar = "||----------|";
    return pwm_bar;
  } else
  
    if (pulse_width > 1100 && pulse_width <= 1200)
  {
    pwm_bar = "|||---------|";
    return pwm_bar;
  } else
  
    if (pulse_width > 1200 && pulse_width <= 1300)
  {
    pwm_bar = "||||--------|";
    return pwm_bar;
  } else
  
    if (pulse_width > 1300 && pulse_width <= 1400)
  {
    pwm_bar = "|||||-------|";
    return pwm_bar;
  } else
  
    if (pulse_width > 1400 && pulse_width <= 1500)
  {
    pwm_bar = "||||||------|";
    return pwm_bar;
  } else
      
    if (pulse_width > 1500 && pulse_width <= 1600)
  {
    pwm_bar = "|||||||-----|";
    return pwm_bar;
  } else
  
    if (pulse_width > 1600 && pulse_width <= 1700)
  {
    pwm_bar = "||||||||----|";
    return pwm_bar;
  } else
  
    if (pulse_width > 1700 && pulse_width <= 1800)
  {
    pwm_bar = "|||||||||---|";
    return pwm_bar;
  } else
  
    if (pulse_width > 1800 && pulse_width <= 1900)
  {
    pwm_bar = "||||||||||--|";
    return pwm_bar;
  } else
  
    if (pulse_width > 1900 && pulse_width <= 2000)
  {
    pwm_bar = "|||||||||||-|";
    return pwm_bar;
  } else {
    pwm_bar = "|||||||||||||";
    return pwm_bar;
  }
}
#endif
