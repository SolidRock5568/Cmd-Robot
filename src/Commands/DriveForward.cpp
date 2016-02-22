//  DRIVE FORWARD COMMAND -- Converted to C++

#include "DriveForward.h"
#include "Robot.h"
#include "RobotMap.h"

DriveForward::DriveForward(float leftSpeed, float rightSpeed, float distance) {
		Requires(Robot::driverobot); // requires DriveRobot subsystem -- instantiated by driverobot in Robot.cpp
		left_motor_speed = leftSpeed + left_compensation;
		right_motor_speed = rightSpeed + right_compensation;
		encoder_distance = distance;
		targetEncoderDistance = 0;
		targetDistanceReached = false;
	}

	void DriveForward::Initialize() {
		targetEncoderDistance = Robot::driverobot->ReturnEncoderDistance() + encoder_distance;
		Robot::driverobot->Forward(left_motor_speed, right_motor_speed);
	}

	void DriveForward::Execute() {
		if (Robot::driverobot->ReturnEncoderDistance() >= targetEncoderDistance)
		{
			targetDistanceReached = true;
		}
	}

	bool DriveForward::IsFinished() {
		return targetDistanceReached;
	}

	void DriveForward::End() {
		Robot::driverobot->Stop();
	}

	void DriveForward::Interrupted() {
		End();
	}
