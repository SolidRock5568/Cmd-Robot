#include "DriveThruLowBar.h"

DriveThruLowBar::DriveThruLowBar() {
	AddSequential(new LowerArm(1.0,2.2));
	AddSequential(new DriveForward(0.4,0.4,4.4)); //drive to barrier
	AddSequential(new DriveForward(0.57,0.57,5.0)); //drive to over lower arm barrier
	AddSequential(new DriveForward(0.3, 0.3, 6.0)); //drive after barrier into endzone
	AddSequential(new DriveStop()); //stop in endzone
	/*Wait(3);
	AddSequential(new RaiseArm(1.0, 1.75));
	AddSequential(new DriveBackwards(-0.4, 0.0, 1.0));
	AddSequential(new DriveStop());
	AddSequential(new RaiseArm(1.0, 1.75));
	AddSequential(new ShootBall(2.0));
	*/
}

