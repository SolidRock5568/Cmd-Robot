// RAISE ARM COMMAND -- Converted to C++

#include "RaiseArm.h"
#include "Robot.h"

RaiseArm::RaiseArm(float speed, float time) {
		Requires(Robot::robotarm);  // Requires RobotArm subsystem (note robotarm is instantiation of RobotArm in Robot.cpp)
		SetTimeout(time);
		arm_speed = speed;
		arm_time = time;

	}

	void RaiseArm::Initialize() {
		Robot::robotarm->Raise(arm_speed);
	}

	void RaiseArm::Execute() {
	}

	bool RaiseArm::IsFinished() {
		return IsTimedOut();
	}

	void RaiseArm::End() {
		Robot::robotarm->Stop();
	}

	void RaiseArm::Interrupted() {
		End();
	}
