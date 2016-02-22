#ifndef DelayedRaiseArm_H
#define DelayedRaiseArm_H

#include "../CommandBase.h"
#include "WPILib.h"

class DelayedRaiseArm: public CommandBase
{
	float arm_speed;
	float arm_delay;

public:
	DelayedRaiseArm(float speed, float time, float delay);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
