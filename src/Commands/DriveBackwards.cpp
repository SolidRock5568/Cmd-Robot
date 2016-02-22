//  DRIVE BACKWARDS COMMAND -- Converted to C++

#include "DriveBackwards.h"
#include "Robot.h"

DriveBackwards::DriveBackwards(float leftSpeed, float rightSpeed, float distance) {
		Requires(Robot::driverobot); // requires DriveRobot subsystem -- instantiated by driverobot in Robot.cpp
		left_motor_speed = leftSpeed;
		right_motor_speed = rightSpeed;
		encoder_distance = distance;
		targetEncoderDistance = 0;
		targetDistanceReached = false;
	}

	void DriveBackwards::Initialize() {
		targetEncoderDistance = Robot::driverobot->ReturnEncoderDistance() - encoder_distance;
		Robot::driverobot->Backwards(left_motor_speed, right_motor_speed);
	}

	void DriveBackwards::Execute() {
		if (Robot::driverobot->ReturnEncoderDistance() >= targetEncoderDistance)
		{
			targetDistanceReached = true;
		}
	}

	bool DriveBackwards::IsFinished() {
		return targetDistanceReached;
	}

	void DriveBackwards::End() {
		Robot::driverobot->Stop();
	}

	void DriveBackwards::Interrupted() {
		End();
	}
