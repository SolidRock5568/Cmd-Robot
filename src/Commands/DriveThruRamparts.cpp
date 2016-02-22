#include "DriveThruRamparts.h"

DriveThruRamparts::DriveThruRamparts()
{
	AddSequential(new DriveForward(0.5,0.5,5.4)); //drive to barrier
		AddSequential(new DriveForward(0.57,0.57,4.0)); //drive over rocky terrain
		AddSequential(new DriveForward(0.3, 0.3,3.0)); //drive after barrier into endzone
		AddSequential(new DriveStop()); //stop in endzone
}
