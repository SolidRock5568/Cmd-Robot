#include "DriveThruChivalDeFrise.h"

DriveThruChivalDeFrise::DriveThruChivalDeFrise() {

	AddSequential(new DriveForward(0.2,0.2,3.75)); //drive to barrier
	AddSequential(new DriveStop());
	Wait(1);
	AddSequential(new LowerArm(1.0, 2.2));
	AddSequential(new DriveForward(1.0,1.0,3.0)); //drive over rocky terrain
	AddSequential(new DriveForward(0.3, 0.3,6.0)); //drive after barrier into endzone
	AddSequential(new DriveStop()); //stop in endzone

}


