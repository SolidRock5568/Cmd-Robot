#include "ShootBall.h"
#include "Robot.h"

ShootBall::ShootBall(float time) //time should include both speedUpTime kick time (somewhere around 2 seconds)
{
	Requires(Robot::robotarm);// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	SetTimeout(time);
}

// Called just before this Command runs the first time
void ShootBall::Initialize()
{
	Robot::robotarm->Shoot(1.0, 1.0); // Shoot(speed, speedUpTime)
}

// Called repeatedly when this Command is scheduled to run
void ShootBall::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ShootBall::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void ShootBall::End()
{
	Robot::robotarm->StopShoot();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootBall::Interrupted()
{

}
