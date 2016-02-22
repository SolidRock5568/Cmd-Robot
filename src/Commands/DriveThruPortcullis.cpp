#include "DriveThruPortcullis.h"

DriveThruPortcullis::DriveThruPortcullis()
{
	AddSequential(new LowerArm(1.0,2.2));
	AddParallel(new DelayedRaiseArm(1.0, 1.2, 2.0));
	AddSequential(new DriveForward(0.5,0.5,13.5)); //drive to barrier

}
