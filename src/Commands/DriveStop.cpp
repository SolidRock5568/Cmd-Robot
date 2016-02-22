// DRIVE STOP COMMAND -- Converted to C++

#include "DriveStop.h"
#include "Robot.h"

DriveStop::DriveStop() {
		Requires(Robot::driverobot); // requires DriveRobot subsystem -- instantiated by driverobot in Robot.cpp
	}


	void DriveStop::Initialize() {
	}

	void DriveStop::Execute() {
	}

	bool DriveStop::IsFinished() {
		return true;
	}

	void DriveStop::End() {
		Robot::driverobot->Stop();
	}

	void DriveStop::Interrupted() {
		End();
	}
