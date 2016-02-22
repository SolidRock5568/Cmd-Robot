#ifndef ROBOTARM_H       // Converted to C++
#define ROBOTARM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class RobotArm: public Subsystem{

public:
	Victor * armMotor;
	Victor * shootMotor1;
	Victor * shootMotor2;
	Victor * kickMotor;

	RobotArm();
	void InitDefaultCommand();
	void Raise(float speed);
	void Lower(float speed);
	void Shoot(float speed, float time);
	void StopShoot();
	void Stop();
	// double * GetArmMotorPtr();
};

#endif
