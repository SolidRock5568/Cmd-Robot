#ifndef MY_ROBOT_H
#define MY_ROBOT_H

#include "WPILib.h"
#include "Subsystems/RobotArm.h"
#include "Subsystems/DriveRobot.h"
#include "OI.h"

class Robot : public IterativeRobot {

public:
	//create static objects of the subsystems
	static DriveRobot * driverobot;
	static RobotArm * robotarm;
	//static SendableChooser * chooser;
	//static Command *autonomousCommand;
	SendableChooser *chooser;
	//Command *autonomousCommand;
	std::unique_ptr<Command> autonomousCommand;
	Joystick * controller;

	IMAQdxSession session;
	Image *frame;
	IMAQdxError imaqError;


private:
	void RobotInit();
	void DisabledInit();
	void DisabledPeriodic();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
};

#endif
