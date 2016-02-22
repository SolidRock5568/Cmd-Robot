#ifndef DriveForward_H
#define DriveForward_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveForward: public CommandBase
{
	float left_motor_speed;
	float right_motor_speed;
	float encoder_distance;
	float targetEncoderDistance;
	bool targetDistanceReached;


public:
	DriveForward(float leftSpeed, float rightSpeed, float distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
