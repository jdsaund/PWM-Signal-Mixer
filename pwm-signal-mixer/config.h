#ifndef config_h
#define	config_h

// input config
#define ROLL_IN_PIN       14
#define PITCH_IN_PIN      16
#define YAW_IN_PIN        10

// output config
#define SERVO_1_PIN       5
#define SERVO_2_PIN       6
#define SERVO_3_PIN       7
#define SERVO_4_PIN       8
#define SERVO_5_PIN       9

// mixing config
/*

   -ve  |     0     |  +ve

             / \            
            |   |
     _______|   |_______
    |_______     _______|
    |___1___|   |___2___|     ---  +ve
            |   |
            |CoG|             ---   0
            |   |
            |   |
            |   |
   _________|   |_________
  |_________     _________|
  |____3____|_5_|____4____|   ---  -ve

*/

// servo roll mixing
#define SERVO_1_ROLL_MIX  -1
#define SERVO_2_ROLL_MIX   1
#define SERVO_3_ROLL_MIX  -1
#define SERVO_4_ROLL_MIX   1

// servo pitch mixing
#define SERVO_1_PITCH_MIX  1
#define SERVO_2_PITCH_MIX  1
#define SERVO_3_PITCH_MIX -1
#define SERVO_4_PITCH_MIX -1

// servo yaw mixing
#define SERVO_5_YAW_MIX    1

// servo reverse - -1 or 1
#define SERVO_1_REV        1
#define SERVO_2_REV        1
#define SERVO_3_REV        1
#define SERVO_4_REV        1
#define SERVO_5_REV        1

// servo trim
#define SERVO_1_TRIM       1500
#define SERVO_2_TRIM       1500
#define SERVO_3_TRIM       1500
#define SERVO_4_TRIM       1500
#define SERVO_5_TRIM       1500

// servo min
#define SERVO_1_MIN        900
#define SERVO_2_MIN        900
#define SERVO_3_MIN        900
#define SERVO_4_MIN        900
#define SERVO_5_MIN        900

// servo max
#define SERVO_1_MAX        2100
#define SERVO_2_MAX        2100
#define SERVO_3_MAX        2100
#define SERVO_4_MAX        2100
#define SERVO_5_MAX        2100

#endif
