#ifndef DriveBackwards_H
#define DriveBackwards_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveBackwards: public CommandBase
{
	float left_motor_speed;
	float right_motor_speed;
	float encoder_distance;
	float targetEncoderDistance;
	bool targetDistanceReached;

public:
	DriveBackwards(float leftSpeed, float rightSpeed, float distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
