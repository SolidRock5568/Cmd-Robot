#include "RobotArm.h"
#include "RobotMap.h"

RobotArm::RobotArm() :
	Subsystem("RobotArm")
{
	armMotor = new Victor(armMotorPort);
	shootMotor1 = new Victor(shootMotorPort1);
	shootMotor2 = new Victor(shootMotorPort2);
	kickMotor = new Victor(kickMotorPort);
}
	void RobotArm::InitDefaultCommand() {
	}

	void RobotArm::Raise(float speed) {
		armMotor->Set(-speed);
		//Wait(2.2);
		//armMotor.Set(0);
		//armDown = true;
		//armUp = false;
	}

	void RobotArm::Lower(float speed) {
		armMotor->Set(speed);
		//Wait(2.2);
		//armMotor.Set(0);
		//armUp = true;
		//armDown = false;
	}

	void RobotArm::Shoot(float speed, float speedUpTime){
		shootMotor1->Set(speed);
		shootMotor2->Set(-speed);

		Wait(speedUpTime);

		kickMotor->Set(1);
		Wait(0.1);
		kickMotor->Set(-0.5);
		Wait(0.17);
		kickMotor->Set(0);

	}

	void RobotArm::StopShoot(){
		shootMotor1->Set(0);
		shootMotor2->Set(0);
	}

	void RobotArm::Stop() {
		armMotor->Set(0);
	}

//	double * RobotArm::GetArmMotorPtr() {
//		return armMotor;

