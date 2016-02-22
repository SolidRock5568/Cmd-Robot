#include "DriveRobot.h"
#include "../RobotMap.h"

DriveRobot::DriveRobot() : Subsystem("DriveRobot")
{

	rightMotor = new Talon(rightDriveMotorPort),
	leftMotor = new Talon(leftDriveMotorPort),
	rightEncoder = new Encoder(0, 1, false, Encoder::k4X),
	leftEncoder = new Encoder(2, 3, false, Encoder::k4X);
	bool DidIRun = false;

	//SetDefaultCommand(new MySpecialCommand());
	{
		rightEncoder->SetSamplesToAverage(5);
		leftEncoder->SetSamplesToAverage(5);
		// Defines how far the mechanism attached to the encoder moves per pulse.
		// In this case, we assume that a 360 count encoder is directly attached
		//   to a 3 inch diameter (1.5inch radius) wheel, and that we want to
		//   measure distance in inches.
		rightEncoder->SetDistancePerPulse((1.0 / 497.0 * 3.1415 * 4.0) / 100.0);
		leftEncoder->SetDistancePerPulse((1.0 / 497.0 * 3.1415 * 4.0) / 100.0);

		rightEncoder->SetMinRate(1.0);
		leftEncoder->SetMinRate(1.0);
		DidIRun = true;
		SmartDashboard::PutBoolean("Did I Run?", DidIRun);
	}

}

void DriveRobot::InitDefaultCommand()
{
	// Set the default command for a subsystem here.

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveRobot::Forward(float leftSpeed, float rightSpeed) {
		rightMotor->Set(rightSpeed*-1);
		leftMotor->Set(leftSpeed);
	}

 	void DriveRobot::Backwards(float leftSpeed, float rightSpeed) {
		rightMotor->Set(rightSpeed);
		leftMotor->Set(leftSpeed*-1);
	}

	float DriveRobot::ReturnEncoderDistance() {

		float encoderDistance;

		//encoderDistance = (rightEncoder->GetDistance() + leftEncoder->GetDistance())/2;
		encoderDistance = (rightEncoder->GetDistance());

		return encoderDistance;
	}


	void DriveRobot::ResetEncoderPosition() {
		rightEncoder->Reset();
		leftEncoder->Reset();
	}


	void DriveRobot::Stop() {
		rightMotor->Set(0);
		leftMotor->Set(0);
	}


