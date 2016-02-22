#ifndef ROBOTMAP_H
#define ROBOTMAP_H

// Driver motors

const int rightDriveMotorPort = 0;
const int leftDriveMotorPort = 1;


// Arm motor

const int armMotorPort= 2;


// Shooter motors

const int shootMotorPort1 = 3;
const int shootMotorPort2 = 4;


// Kick motor

const int kickMotorPort= 5;


// Encoders

const float left_compensation = 0.0;
const float right_compensation = 0.08;

// const int rightEncoderPort = ???;   // encoderRight(0, 1, false, Encoder::k4x)
// const int leftEncoderPort = ???;   // encoderLeft(2, 3, false, Encoder::k4x)
#endif
