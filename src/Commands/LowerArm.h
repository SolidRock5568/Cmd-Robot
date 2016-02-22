#ifndef LowerArm_H
#define LowerArm_H

#include "../CommandBase.h"
#include "WPILib.h"

class LowerArm: public CommandBase
{
	float arm_speed;
	float arm_time;
public:
	LowerArm(float speed, float time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
