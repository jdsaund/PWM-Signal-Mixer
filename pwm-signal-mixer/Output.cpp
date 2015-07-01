#ifndef Output_cpp
#define	Output_cpp

#include "Output.h"

Output output;

void Output::init()
{
  servo_1.attach(SERVO_1_PIN);
  servo_2.attach(SERVO_2_PIN);
  servo_3.attach(SERVO_3_PIN);
  servo_4.attach(SERVO_4_PIN);
  servo_5.attach(SERVO_5_PIN);
}

void Output::write_servos(uint16_t rollin, uint16_t pitchin, uint16_t yawin)
{
  rollin  -= 1500;
  pitchin -= 1500;
  yawin   -= 1500;
  
  // perform channel mixing
  servo_1_out = SERVO_1_REV * (SERVO_1_ROLL_MIX * rollin + SERVO_1_PITCH_MIX * pitchin) + SERVO_1_TRIM;
  servo_2_out = SERVO_2_REV * (SERVO_2_ROLL_MIX * rollin + SERVO_2_PITCH_MIX * pitchin) + SERVO_2_TRIM;
  servo_3_out = SERVO_3_REV * (SERVO_3_ROLL_MIX * rollin + SERVO_3_PITCH_MIX * pitchin) + SERVO_3_TRIM;
  servo_4_out = SERVO_4_REV * (SERVO_4_ROLL_MIX * rollin + SERVO_4_PITCH_MIX * pitchin) + SERVO_4_TRIM;
  servo_5_out = SERVO_5_REV * SERVO_5_YAW_MIX * yawin + SERVO_5_TRIM;
  
  // apply limits
  servo_1_out = constrain(servo_1_out, SERVO_1_MIN, SERVO_1_MAX);
  servo_2_out = constrain(servo_2_out, SERVO_2_MIN, SERVO_2_MAX);
  servo_3_out = constrain(servo_3_out, SERVO_3_MIN, SERVO_3_MAX);
  servo_4_out = constrain(servo_4_out, SERVO_4_MIN, SERVO_4_MAX);
  servo_5_out = constrain(servo_5_out, SERVO_5_MIN, SERVO_5_MAX);

  // write the output
  servo_1.writeMicroseconds(servo_1_out);
  servo_2.writeMicroseconds(servo_2_out);
  servo_3.writeMicroseconds(servo_3_out);
  servo_4.writeMicroseconds(servo_4_out);
  servo_5.writeMicroseconds(servo_5_out);
}


#endif
