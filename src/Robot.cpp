#include "WPILib.h"
#include "CommandBase.h"
#include "Robot.h"
#include "Commands/DriveToBarrier.h"
#include "Commands/DriveThruLowBar.h"
#include "Commands/DriveThruRockyTerrain.h"
#include "Commands/DriveThruChivalDeFrise.h"
#include "Commands/DriveThruPortcullis.h"
#include "Commands/DriveThruRamparts.h"
#include "OI.h"
#include "Subsystems/RobotArm.h"
#include "Subsystems/DriveRobot.h"
#define A_BUTTON 1
#define B_BUTTON 2
#define X_BUTTON 3
#define Y_BUTTON 4
#define L_BUMPER 5
#define R_BUMPER 6
#define SELECT_BUTTON 7
#define START_BUTTON 8

	float squareDrive(float);


	RobotArm * Robot::robotarm = NULL;
	DriveRobot * Robot::driverobot = NULL;

	void Robot::RobotInit()
	{
		CommandBase::init();

		//Create new objects of subsystems
		robotarm = new RobotArm;
		driverobot = new DriveRobot;
		chooser = new SendableChooser();
		controller = new Joystick(0);

		chooser->AddDefault("Drive to Barrier", new DriveToBarrier());
		chooser->AddObject("Low Bar", new DriveThruLowBar());
		chooser->AddObject("Rocky Terrain", new DriveThruRockyTerrain());
		chooser->AddObject("Chival De Frise", new DriveThruChivalDeFrise());
		chooser->AddObject("Portcullis", new DriveThruPortcullis());
		chooser->AddObject("Ramparts", new DriveThruRamparts());
		SmartDashboard::PutData("Auto Modes", chooser);

		// create an image
		frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
		//the camera name (ex "cam0") can be found through the roborio web interface
		imaqError = IMAQdxOpenCamera("cam0", IMAQdxCameraControlModeController, &session);
		if(imaqError != IMAQdxErrorSuccess) {
			DriverStation::ReportError("IMAQdxOpenCamera error: " + std::to_string((long)imaqError) + "\n");
		}
		imaqError = IMAQdxConfigureGrab(session);
		if(imaqError != IMAQdxErrorSuccess) {
			DriverStation::ReportError("IMAQdxConfigureGrab error: " + std::to_string((long)imaqError) + "\n");
		}
	}

	/**
     * This function is called once each time the robot enters Disabled mode.
     * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
     */
	void Robot::DisabledInit()
	{
	}

	void Robot::DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString code to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional commands to the chooser code above (like the commented example)
	 * or additional comparisons to the if-else structure below with additional strings & commands.
	 */
	void Robot::AutonomousInit()
	{
		/* std::string autoSelected = SmartDashboard::GetString("Auto Selector", "Default");
		if(autoSelected == "My Auto") {
			autonomousCommand.reset(new MyAutoCommand());
		} else {
			autonomousCommand.reset(new ExampleCommand());
		} */

		autonomousCommand.reset((Command *)chooser->GetSelected());
		//autonomousCommand = ((Command *)chooser->GetSelected());

		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void Robot::AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void Robot::TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();


	}

	void Robot::TeleopPeriodic()
	{
		// acquire images
		IMAQdxStartAcquisition(session);

		// grab an image, draw the circle, and provide it for the camera server which will
		// in turn send it to the dashboard.
		while(IsOperatorControl() && IsEnabled()) {
			IMAQdxGrab(session, frame, true, NULL);
			if(imaqError != IMAQdxErrorSuccess) {
					DriverStation::ReportError("IMAQdxGrab error: " + std::to_string((long)imaqError) + "\n");
			} else {
					imaqDrawShapeOnImage(frame, frame, { 190, 250, 100, 100 }, DrawMode::IMAQ_DRAW_VALUE, ShapeMode::IMAQ_SHAPE_RECT, 0.0f);
					//				 Shape parameters: {x-axis, y axis, length, width}
					CameraServer::GetInstance()->SetImage(frame);
			}

		//Scheduler::GetInstance()->Run();
		if(controller->GetRawAxis(3) > 0 )
					{
						Robot::robotarm->shootMotor1->Set(1);
						Robot::robotarm->shootMotor2->Set(-1);
					}
					else if(controller->GetRawAxis(2) > 0 )
					{
						Robot::robotarm->shootMotor1->Set(-0.4);
						Robot::robotarm->shootMotor2->Set(0.4);

					}
					else
					{
						Robot::robotarm->shootMotor1->Set(0);
						Robot::robotarm->shootMotor2->Set(0);
					}

		if (controller->GetRawAxis(1) < -0.2)
					{
						float speed = controller->GetRawAxis(1) * controller->GetRawAxis(1);
						Robot::robotarm->Raise(speed);
					}
					else if (controller->GetRawAxis(1) > 0.2)
					{
						float speed = controller->GetRawAxis(1) * controller->GetRawAxis(1);
						Robot::robotarm->Lower(speed);
					}
					else
					{
						Robot::robotarm->Stop();
					}

		if(controller->GetRawButton(B_BUTTON) == true)
					{
						Robot::robotarm->kickMotor->Set(1);
						Wait(0.1);
						Robot::robotarm->kickMotor->Set(-0.5);
						Wait(0.17);
						Robot::robotarm->kickMotor->Set(0);
					}


		float yIn = controller->GetRawAxis(5);
		float xIn = controller->GetRawAxis(4);

		if(controller->GetRawButton(R_BUMPER)){

			Robot::driverobot->rightMotor->Set((squareDrive(yIn) + squareDrive(xIn)));
			Robot::driverobot->leftMotor->Set((squareDrive(xIn) - squareDrive(yIn)));

		}
		else{

			Robot::driverobot->rightMotor->Set((squareDrive(yIn) + squareDrive(xIn)) / 2);
			Robot::driverobot->leftMotor->Set((squareDrive(xIn) - squareDrive(yIn)) / 2);

		}
		// wait for a motor update time
		Wait(0.005);
		}

		// stop image acquisition
		IMAQdxStopAcquisition(session);

	}
START_ROBOT_CLASS(Robot);

float squareDrive(float val) {
	if(val > 0.05) {
		val = val*val;
		return val;
	}
	else if(val < -0.05) {
		val = -(val*val);
		return val;
	}
	else {
		return 0;
	}
}
