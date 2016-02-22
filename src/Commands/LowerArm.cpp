// LOWER ARM COMMAND -- Converted to C++

#include "LowerArm.h"
#include "Robot.h"

LowerArm::LowerArm(float speed, float time) {
		Requires(Robot::robotarm);  // Requires subsystem RobotArm
		SetTimeout(time);
		arm_speed = speed;
		arm_time = time;
	}

	void LowerArm::Initialize() {
		Robot::robotarm->Lower(arm_speed);
	}

	void LowerArm::Execute() {
	}

	bool LowerArm::IsFinished() {
		return IsTimedOut();
	}

	void LowerArm::End() {
		Robot::robotarm->Stop();
	}

	void LowerArm::Interrupted() {
		End();
	}
