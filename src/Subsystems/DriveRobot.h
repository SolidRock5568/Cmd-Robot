#ifndef DRIVEROBOT_H   // Converted to C++
#define DRIVEROBOT_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveRobot: public Subsystem{

public:
	Talon * rightMotor;
	Talon * leftMotor;
	Encoder * rightEncoder;
	Encoder * leftEncoder;
	DriveRobot();
	void InitDefaultCommand();
	void Forward(float leftSpeed, float rightSpeed);
	void Backwards(float leftSpeed, float rightSpeed);
	float ReturnEncoderDistance();
	void ResetEncoderPosition();
	void Stop();
};

#endif
