// DELAYED RAISE ARM COMMAND -- Converted to C++

#include "DelayedRaiseArm.h"
#include "Robot.h"

DelayedRaiseArm::DelayedRaiseArm(float speed, float time, float delay) {
		Requires(Robot::robotarm);  // Requires RobotArm subsystem (note robotarm is instantiation of RobotArm in Robot.cpp)
		arm_speed = speed;
		arm_delay = delay;
		SetTimeout(time + delay);

	}

	void DelayedRaiseArm::Initialize() {
		Wait(arm_delay);
		Robot::robotarm->Raise(arm_speed);
	}

	void DelayedRaiseArm::Execute() {
	}

	bool DelayedRaiseArm::IsFinished() {
		return IsTimedOut();
	}

	void DelayedRaiseArm::End() {
		Robot::robotarm->Stop();
	}

	void DelayedRaiseArm::Interrupted() {
		End();
	}
