#ifndef RaiseArm_H
#define RaiseArm_H

#include "../CommandBase.h"
#include "WPILib.h"

class RaiseArm: public CommandBase
{
	float arm_speed;
	float arm_time;

public:
	RaiseArm(float speed, float time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
